#include "AtDbWriter.h"

AtDbWriter::AtDbWriter()
: _sqlite3(NULL),
  _dbFile(QString(DB_PATH) + "/" + QString(DB_FILE))
{
	InitializeDbFile();
}

AtDbWriter::~AtDbWriter()
{
	if (_sqlite3 == 0)
	{
		return;
	}
	sqlite3_close(_sqlite3);
	return;
}

bool AtDbWriter::Insert(QString inTable, QString inValue)
{
	char *zErrMsg = NULL;
	if (sqlite3_exec(_sqlite3, Schema(inTable, inValue).toStdString().c_str(), NULL, 0, &zErrMsg) != SQLITE_OK)
	{
		qDebug() << "AtDbWriter::Insert SQL FAILED: " << zErrMsg;
		sqlite3_free(zErrMsg);
		return false;
	}
	return true;
}

bool AtDbWriter::InitializeDbFile()
{
	QDir dir;
	if (dir.exists(QString(DB_PATH)) == false)
	{
		dir.mkpath(QString(DB_PATH));
		qDebug() << "AtDbWriter::InitializeDbFile Directory created: " << QString(DB_PATH);
	}

	QFile file(_dbFile);
	if (file.exists() == false)
	{
		if (file.open(QIODevice::ReadWrite))
		{
			qDebug() << "AtDbWriter::InitializeDbFile File created: " << _dbFile;
		}
	}
	if (sqlite3_open(_dbFile.toStdString().c_str(), &_sqlite3) != SQLITE_OK)
	{
		qDebug() << "AtDbWriter::InitializeDbFile FAILED to open: %s" << sqlite3_errmsg(_sqlite3);
		return false;
	}
	return true;
}

QString AtDbWriter::Schema(QString inTable, QString inValue)
{
	QString out;
	out = "CREATE TABLE IF NOT EXISTS "
			+ inTable
			+ " (ID INTEGER PRIMARY KEY AUTOINCREMENT,"
			+ "Value TEXT,"
			+ "TimeStamp DATETIME DEFAULT CURRENT_TIMESTAMP NOT NULL);"
			+ "INSERT INTO "
			+ inTable
			+ " (Value) VALUES ("
			+ inValue
			+ ");";
	return out;
}
