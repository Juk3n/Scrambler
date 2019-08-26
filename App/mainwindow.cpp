#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->LoadDataButton, SIGNAL(clicked(bool)), this, SLOT(onLoadButtonClicked()));
    connect(ui->ScrambleButton, SIGNAL(clicked(bool)), this, SLOT(onScrambleButtonClicked()));
    connect(ui->SendDataButton, SIGNAL(clicked(bool)), this, SLOT(onSendButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printOnLog(QString text) {
    logText += ">";
    logText += text;
    logText += "\n";

    ui->plainTextEdit->insertPlainText(">" + text + "\n");
    ui->plainTextEdit->ensureCursorVisible();
}

void MainWindow::simulateWith(std::vector<bool> data) {
    DataTransferSimulator simulation{};

    printOnLog("Begin simulation 1");
    //Przesłanie danych bez scramblera
    printOnLog("Preparing data to send..");
    simulation.setDataToSend(data);
    printOnLog("Sending..");
    simulation.simulateSendingData(SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence);
    printOnLog("Data sent.");

    //printOnLogPanel("data size: " + data.size());
    //printOnLogPanel(std::string().append("number of bits lost: ").append(simulation.getNumberOfRandomData()));
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    //Przesłanie danych ze scramblerem
    printOnLog("Scrambling..");
    auto dataAfterScrambling = Scrambling::scrambleAdditive(data);
    printOnLog("Preparing data to send..");
    simulation.setDataToSend(dataAfterScrambling);
    printOnLog("Sending..");
    simulation.simulateSendingData(SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence);
    printOnLog("Data sent.");

    //std::cout << "data size: " << dataAfterScrambling.size() << std::endl;
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    printOnLog("Begin simulation 2");
    //Przesłanie danych bez scramblera
    printOnLog("Preparing data to send..");
    simulation.setDataToSend(data);
    printOnLog("Sending..");
    simulation.simulateSendingData(SimulationType::SimulationWithTheChanceOfDisruption);
    printOnLog("Data sent.");

    //std::cout << "data size: " << data.size() << std::endl;
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    //Przesłanie danych ze scramblerem
    printOnLog("Scrambling..");
    dataAfterScrambling = Scrambling::scrambleAdditive(data);
    printOnLog("Preparing data to send..");
    simulation.setDataToSend(dataAfterScrambling);
    printOnLog("Sending..");
    simulation.simulateSendingData(SimulationType::SimulationWithTheChanceOfDisruption);
    printOnLog("Data sent.");

    //std::cout << "data size: " << dataAfterScrambling.size() << std::endl;
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    //std::cout << "\nHistogramy\n";
}

void MainWindow::onLoadButtonClicked() {
    printOnLog("Loading data");
    QString dataType{ getDataTypeFromUser() };
    printOnLog(dataType + " loaded");
    loadData(dataType);
}

QString MainWindow::getDataTypeFromUser() {
    QStringList dataTypes;
    dataTypes << tr("MP3") << tr("Only zeros") << tr("Only ones");
    bool ok;
    QString dataType{QInputDialog::getItem(this, "Choose data type", tr("Types:"), dataTypes, 0, false, &ok)};

    if(ok && !dataType.isEmpty()) {
        return dataType;
    }
    else {
        return "invalid type";
    }
}

void MainWindow::loadData(QString dataType) {
    if(dataType == "MP3") {
        FileReader reader;
        data = reader.readFile("D://Programowanie 2019//C++//Scrambler//App//file.mp3");
    }
    else if (dataType == "Only zeros") {
        data = SimpleBitDataGenerator::generateData(0, 1000);
    }
    else if (dataType == "Only ones") {
        data = SimpleBitDataGenerator::generateData(1, 1000);
    }
}

void MainWindow::onScrambleButtonClicked() {
    printOnLog("Scrambling data");
    data = Scrambling::scrambleAdditive(data);
    printOnLog("Data scrambled");
}
void MainWindow::onSendButtonClicked(){
    printOnLog("Sending data");
}
