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
	void sendThroughTransmissionCanalA(int chanceOfDisruption)
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

	//kiedy zbyt wiele bitów obok siebie jest takich samych, nastêpuje przek³amanie
	void sendThroughTransmissionCanalB(int acceptableLengthBitSeries)
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

	void simulateSendingData(char typeOfTransfer)
	{
		clearInformations();

		if (typeOfTransfer == 'A')
			sendThroughTransmissionCanalA(1000);
		else if (typeOfTransfer == 'B')
			sendThroughTransmissionCanalB(5);
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



