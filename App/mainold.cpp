// main.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//
/*
#include "stdafx.h"

#include "FileReader.h"
#include "Scrambling.h"
#include "DataTransferSimulator.h"
#include "SimpleBitDataGenerator.h"
#include "Histogram.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>


bool areBothDataSame(std::vector<bool> data1, std::vector<bool> data2) {
	return data1 == data2;
}

void showData(std::vector<bool> data)
{
	for (auto bit : data)
	{
		std::cout << bit << " ";
	}
	std::cout << std::endl;
}

void simulateWith(std::vector<bool> data)
{
	DataTransferSimulator simulation{};
	Histogram histogram;
	
	std::cout << "\n\nBegin simulation 1\n";
	//Przesłanie danych bez scramblera
	std::cout << "Preparing data to send.." << std::endl;
	simulation.setDataToSend(data);
	std::cout << "Sending.." << std::endl;
	simulation.simulateSendingData(SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence);
	std::cout << "Data sent." << std::endl;

	std::cout << "data size: " << data.size() << std::endl;
	std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

	//Przesłanie danych ze scramblerem
	std::cout << "Scrambling.." << std::endl;
	auto dataAfterScrambling = Scrambling::scrambleAdditive(data);
	std::cout << "Preparing data to send.." << std::endl;
	simulation.setDataToSend(dataAfterScrambling);
	std::cout << "Sending.." << std::endl;
	simulation.simulateSendingData(SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence);
	std::cout << "Data sent." << std::endl;

	std::cout << "data size: " << dataAfterScrambling.size() << std::endl;
	std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

	std::cout << "\n\nBegin simulation 2\n";
	//Przesłanie danych bez scramblera
	std::cout << "Preparing data to send.." << std::endl;
	simulation.setDataToSend(data);
	std::cout << "Sending.." << std::endl;
	simulation.simulateSendingData(SimulationType::SimulationWithTheChanceOfDisruption);
	std::cout << "Data sent." << std::endl;

	std::cout << "data size: " << data.size() << std::endl;
	std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

	//Przesłanie danych ze scramblerem
	std::cout << "Scrambling.." << std::endl;
	dataAfterScrambling = Scrambling::scrambleAdditive(data);
	std::cout << "Preparing data to send.." << std::endl;
	simulation.setDataToSend(dataAfterScrambling);
	std::cout << "Sending.." << std::endl;
	simulation.simulateSendingData(SimulationType::SimulationWithTheChanceOfDisruption);
	std::cout << "Data sent." << std::endl;

	std::cout << "data size: " << dataAfterScrambling.size() << std::endl;
	std::cout << "number of bits lost: " << simulation.getNumberOfRandomData() << std::endl;

	std::cout << "\nHistogramy\n";
	histogram.create(data, 1);
	histogram.show();
	histogram.create(dataAfterScrambling, 1);
	histogram.show();
}

int main()
{
	FileReader reader;
	std::cout << "MP3 File Simulation\n";
	simulateWith(reader.readFile("file.mp3"));

	std::cout << "Only Zeros Series Simulation\n";
	simulateWith(SimpleBitDataGenerator::generateData(0, 1000));

	std::cout << "Only Ones Series Simulation\n";
	simulateWith(SimpleBitDataGenerator::generateData(1, 1000));
	
	return 0;
}

*/
