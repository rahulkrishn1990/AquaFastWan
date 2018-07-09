#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_sensorDataMonitor(nullptr)
{
    ui->setupUi(this);
    ui->m_showValue->setReadOnly(true);
    m_sensorDataMonitor = new aquasensors::visualizer::SensorDataMonitor(this);

    QObject::connect( m_sensorDataMonitor, SIGNAL( setCandidateInfoText( const QString & )), ui->m_showValue,     SLOT( setInfoText( const QString & )));
    QObject::connect( m_sensorDataMonitor, SIGNAL( appendCandidateInfoText( const QString & )), ui->m_showValue,  SLOT( appendText( const QString & )));
}

MainWindow::~MainWindow()
{
    delete m_sensorDataMonitor;
    delete ui;
}

void MainWindow::setInfoText( const QString& Text)
{
   ui->m_showValue->insertPlainText( Text);
}

void MainWindow::appendText(const QString &text)
{
    ui->m_showValue->insertPlainText(text);
}
