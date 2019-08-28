#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

#include "FileReader.h"
#include "Scrambling.h"
#include "DataTransferSimulator.h"
#include "SimpleBitDataGenerator.h"
#include "Histogram.h"

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

private:
    Ui::MainWindow *ui;
    QString logText{};
    std::vector<bool> data;

    QString getDataTypeFromUser();
    void loadData(QString dataType);
    void startSimulation();

    void printOnLog(QString text);
    void simulateWith(std::vector<bool> data);


};

#endif // MAINWINDOW_H
