#pragma once

#include <vector>

class DataTransferSimulator
{
	int acceptableLengthBitSeries{};
	std::vector<bool> data;

public:
	DataTransferSimulator(int length) :acceptableLengthBitSeries(length){}

	void setDataToSend(std::vector<bool> data)
	{
		this->data = data;
	}

	void simulateSendingData()
	{
		std::vector<bool> dataAfterSimulation;
		bool lastBit{2};
		int numOfRepetitions{};

		for (bool bit : data )
		{
			if (bit == lastBit)
			{
				numOfRepetitions++;
				dataAfterSimulation.push_back(bit);
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
		return data;
	}

	~DataTransferSimulator() {}
};



