#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sensordatamonitor.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private slots:
    void setInfoText( const QString & Text);
    void appendText(const QString & value);

private:
    Ui::MainWindow *ui;
    aquasensors::visualizer::SensorDataMonitor * m_sensorDataMonitor;
};

#endif // MAINWINDOW_H
