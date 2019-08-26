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
    //ui->plainTextEdit->setPlainText(logText);
    ui->plainTextEdit->insertPlainText(">" + text + "\n");
    ui->plainTextEdit->ensureCursorVisible();

}

void MainWindow::startSimulation() {
    FileReader reader;
    printOnLog("MP3 File Simulation");
    simulateWith(reader.readFile("file.mp3"));

    printOnLog("Only Zeros Series Simulation");
    simulateWith(SimpleBitDataGenerator::generateData(0, 1000));

    printOnLog("Only Ones Series Simulation");
    simulateWith(SimpleBitDataGenerator::generateData(1, 1000));
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
}
void MainWindow::onScrambleButtonClicked() {
    printOnLog("Scrambling data");
}
void MainWindow::onSendButtonClicked(){
    printOnLog("Sending data");
}
