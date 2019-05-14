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
	int acceptableLengthBitSeries{};
	int numberOfRandomData{};

	std::vector<bool> data;
	std::vector<bool> dataAfterSimulation;

	std::function<int(int)> isNumOfRepetitionsReachedLimit = [&](int number) {return int(number >= acceptableLengthBitSeries); };
	
	void clearInformations()
	{
		dataAfterSimulation.clear();
		numberOfRandomData = 0;
	}
public:
	DataTransferSimulator(int length) :acceptableLengthBitSeries(length){}

	void setDataToSend(std::vector<bool> data)
	{
		this->data = data;
	}

	void simulateSendingData()
	{
		clearInformations();

		dataAfterSimulation.clear();
		numberOfRandomData = 0;

		bool lastBit{0};
		int numOfRepetitions{};

		for (bool bit : data )
		{
			if (bit == lastBit)
			{
				numOfRepetitions++;

				if (isNumOfRepetitionsReachedLimit(numOfRepetitions))
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



