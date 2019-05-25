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

	//chanceOfDisruption - w ci¹gu ilu wartoœci jest szansa na jedno przek³amanie
	void sendThroughTransmissionCanal(int chanceOfDisruption)
	{
		int iterator{};

		for (bool bit : data)
		{
			iterator++;
			if (iterator >= chanceOfDisruption)
			{
				dataAfterSimulation.push_back(random(0, 1));
				iterator = 0;
			}
			else
			{
				dataAfterSimulation.push_back(bit);
			}
		}
	}

	//kiedy zbyt wiele bitów obok siebie jest takich samych, nastêpuje przek³amanie
	void sendThroughTransmissionCanal(int acceptableLengthBitSeries)
	{
		bool lastBit{ 0 };
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

	void simulateSendingData()
	{
		clearInformations();
		//sendThroughTransmissionCanal();	
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



