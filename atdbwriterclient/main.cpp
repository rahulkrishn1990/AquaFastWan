#include <iostream>
using namespace std;

#include <QDebug>
#include <QString>

#include "AtDbWriter.h"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		qDebug() << "Usage: " << argv[0] << " Table Value";
		return -1;
	}
	AtDbWriter atDbWriter;
	atDbWriter.Insert(QString::fromStdString(argv[1]), QString::fromStdString(argv[2]));
	return 0;
}
