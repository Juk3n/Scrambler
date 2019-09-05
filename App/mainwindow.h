#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

#include "histogram.h"
#include "FileReader.h"
#include "Scrambling.h"
#include "DataTransferSimulator.h"
#include "SimpleBitDataGenerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onLoadButtonClicked();
    void onScrambleButtonClicked();
    void onSendButtonClicked();
    void onSaveButtonClicked();

private slots:
    void on_HistogramButton_clicked();

private:
    Ui::MainWindow *ui;
    Histogram *histogram;

    QString logText;
    std::vector<bool> data;

    QString getDataTypeFromUser();
    void loadData(QString dataType);
    void startSimulation();

    void printOnLog(QString text);
};

#endif // MAINWINDOW_H
