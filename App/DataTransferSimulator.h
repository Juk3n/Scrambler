#pragma once

#include <vector>
#include <functional>
#include <random>

#include <iostream>

thread_local std::mt19937 gen{ std::random_device{}() };

//random function by Pierun
template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}


enum class SimulationType {
	SimulationWithTheChanceOfDisruption,
	SimulationWithTheDataDisruptionDependedOnOccurrence
};

class DataTransferSimulator
{
	int numberOfRandomData{};

	std::vector<bool> data;
	std::vector<bool> dataAfterSimulation;
	
	void clearInformations()
	{
		dataAfterSimulation.clear();
		numberOfRandomData = 0;
	}

	void simulateWithTheChanceOfDisruption(int chanceOfDisruption)
	{
		for (bool bit : data)
		{
			if (random(0, chanceOfDisruption - 1) >= 1)
			{
				dataAfterSimulation.push_back(bit);
			}
			else
			{
				numberOfRandomData++;
				dataAfterSimulation.push_back(random(0, 1));
			}
		}
	}

	void simulateWithTheDataDisruptionDependedOnOccurrence(int acceptableLengthBitSeries)
	{
		bool lastBit{ !data[0] };
		int numOfRepetitions{};

		for (bool bit : data)
		{
			if (bit == lastBit)
			{
				numOfRepetitions++;

				if (numOfRepetitions >= acceptableLengthBitSeries)
				{
					numberOfRandomData++;
					dataAfterSimulation.push_back(random(0, 1));
				}
				else
				{
					dataAfterSimulation.push_back(bit);
				}
			}
			else
			{
				lastBit = bit;
				numOfRepetitions = 0;
				dataAfterSimulation.push_back(bit);
			}
		}
	}

public:
	DataTransferSimulator() {}

	void setDataToSend(std::vector<bool> data)
	{
		this->data = data;
	}

	void simulateSendingData(SimulationType typeOfTransfer)
	{
		clearInformations();

		switch (typeOfTransfer) {
		case SimulationType::SimulationWithTheChanceOfDisruption:
			simulateWithTheChanceOfDisruption(1000);
			break;
		case SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence:
			simulateWithTheDataDisruptionDependedOnOccurrence(5);
			break;
		}
	}

	std::vector<bool> getDataAfterSimulation()
	{
		return dataAfterSimulation;
	}

	int getNumberOfRandomData()
	{
		return numberOfRandomData;
	}

	~DataTransferSimulator() {}
};



