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

    ui->plainTextEdit->ensureCursorVisible();
    ui->plainTextEdit->insertPlainText(">" + text + "\n");
    ui->plainTextEdit->ensureCursorVisible();
}

void MainWindow::simulateWith(std::vector<bool> data) {
    DataTransferSimulator simulation{};


    //printOnLogPanel("data size: " + data.size());
    //printOnLogPanel(std::string().append("number of bits lost: ").append(simulation.getNumberOfRandomData()));
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    //Przesłanie danych ze scramblerem
    //std::cout << "data size: " << dataAfterScrambling.size() << std::endl;
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;


    //Przesłanie danych bez scramblera

    //std::cout << "data size: " << data.size() << std::endl;
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    //Przesłanie danych ze scramblerem


    //std::cout << "data size: " << dataAfterScrambling.size() << std::endl;
    //std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

    //std::cout << "\nHistogramy\n";
}

void MainWindow::onLoadButtonClicked() {
    printOnLog("Loading data");
    QString dataType{ getDataTypeFromUser() };    
    loadData(dataType);
    printOnLog(dataType + " loaded");
    printOnLog("Data size: " + QString::fromStdString(std::to_string(data.size())));
}

QString MainWindow::getDataTypeFromUser() {
    QStringList dataTypes{{"MP3", "Only zeros", "Only ones"}};
    bool ok;
    QString dataType{QInputDialog::getItem(this, "Choose data type", tr("Types:"), dataTypes, 0, false, &ok)};

    if(ok && !dataType.isEmpty())
        return dataType;
    else
        return "invalid type";
}

void MainWindow::loadData(QString dataType) {
    if(dataType == "MP3")
        data = FileReader::readFile("file.mp3");
    else if (dataType == "Only zeros")
        data = SimpleBitDataGenerator::generateData(0, 1000);
    else if (dataType == "Only ones")
        data = SimpleBitDataGenerator::generateData(1, 1000);
}

void MainWindow::onScrambleButtonClicked() {
    printOnLog("Scrambling data");
    data = Scrambling::scrambleAdditive(data);
    printOnLog("Data scrambled");
}

void MainWindow::onSendButtonClicked(){
    printOnLog("Sending data");
    startSimulation();
    printOnLog("Data sent");
}

void MainWindow::startSimulation() {
    DataTransferSimulator simulation{};

    simulation.simulateSendingData(SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence, data);
    printOnLog("Number of lost bits: " + QString::fromStdString(std::to_string(simulation.getNumberOfRandomData())));
}
