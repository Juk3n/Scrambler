#ifndef DATATRANSFERSIMULATION_H
#define DATATRANSFERSIMULATION_H

#include <vector>
#include <functional>
#include <random>

#include <iostream>

//thread_local std::mt19937 gen{ std::random_device{}() };

//random function by Pierun
//template<typename T>
//T random(T min, T max) {
    //return std::uniform_int_distribution<T>{min, max}(gen);
//}


enum class SimulationType {
	SimulationWithTheChanceOfDisruption,
	SimulationWithTheDataDisruptionDependedOnOccurrence
};

class DataTransferSimulator
{
	int numberOfRandomData{};

    std::vector<bool> dataAfterSimulation{};
	
	void clearInformations()
	{
		dataAfterSimulation.clear();
		numberOfRandomData = 0;
	}

    void simulateWithTheChanceOfDisruption(int chanceOfDisruption, std::vector<bool> data)
	{
		for (bool bit : data)
		{
            if (1)//random(0, chanceOfDisruption - 1) >= 1)
			{
				dataAfterSimulation.push_back(bit);
			}
			else
			{
				numberOfRandomData++;
                dataAfterSimulation.push_back(1);//random(0, 1));
			}
		}
	}

    void simulateWithTheDataDisruptionDependedOnOccurrence(int acceptableLengthBitSeries, std::vector<bool> data)
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
                    dataAfterSimulation.push_back(1);//random(0, 1));
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

    void simulateSendingData(SimulationType typeOfTransfer, std::vector<bool> data)
	{
        clearInformations();

        switch (typeOfTransfer) {
		case SimulationType::SimulationWithTheChanceOfDisruption:
            simulateWithTheChanceOfDisruption(1000, data);
			break;
		case SimulationType::SimulationWithTheDataDisruptionDependedOnOccurrence:
            simulateWithTheDataDisruptionDependedOnOccurrence(5, data);
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


#endif
