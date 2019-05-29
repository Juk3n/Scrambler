#pragma once

#include <vector>

class SimpleBitDataGenerator
{
public:
	SimpleBitDataGenerator() {}

	static std::vector<bool> generateData(bool whatInside, int dataLength)
	{
		std::vector<bool> data;

		for (int i = 0; i < dataLength; i++)
		{
			data.push_back(whatInside);
		}

		return data;
	}

	~SimpleBitDataGenerator() {}
};

