// main.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"

#include "FileReader.h"
#include "Scrambling.h"
#include "DataTransferSimulator.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <bitset>


int main()
{
	std::vector<bool> binarySeries{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0};

	DataTransferSimulator simulation{ 3 };
	simulation.setDataToSend(binarySeries);
	simulation.simulateSendingData();
	
	std::vector<bool> binarySeriesAfterSim{ simulation.getDataAfterSimulation() };

	std::cout << std::endl << "SIMULATION BEFORE SCRAMBLING" << std::endl;
	for (bool bit : binarySeries)
	{
		std::cout << bit;
	}
	std::cout << std::endl;
	for (bool bit : binarySeriesAfterSim)
	{
		std::cout << bit;
	}
	std::cout << std::endl << "Number of random data: " << simulation.getNumberOfRandomData() << std::endl;

	std::cout << "Scrambling..." << std::endl;
	Scrambling scrambling{};
	auto binarySeriesAfterScrmabling{ scrambling.scrambleAdditive(binarySeries) };

	simulation.setDataToSend(binarySeriesAfterScrmabling);
	simulation.simulateSendingData();
	auto binarySeriesAfterScramblingAfterSimulation{ simulation.getDataAfterSimulation() };

	std::cout << std::endl << "SIMULATION AFTER SCRAMBLING" << std::endl;
	for (bool bit : binarySeriesAfterScrmabling)
	{
		std::cout << bit;
	}
	std::cout << std::endl;
	for (bool bit : binarySeriesAfterScramblingAfterSimulation)
	{
		std::cout << bit;
	}
	std::cout << std::endl << "Number of random data: " << simulation.getNumberOfRandomData() << std::endl;

	
}

