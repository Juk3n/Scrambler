#pragma once

#include <vector>
#include <iostream>

class Histogram
{
	
public:
	Histogram() {}

	void create(std::vector<bool> data, bool whatToCount)
	{
		std::vector<int> numberOfRepetitionsOfEachSize;
		auto longestSerie{ 0 };
		int sizeOfSerie{};

		//find the longest
		for (auto bit : data)
		{
			if (bit == whatToCount)
			{
				sizeOfSerie++;
			}
			else
			{
				if (sizeOfSerie > longestSerie) longestSerie = sizeOfSerie;
				sizeOfSerie = 0;
			}
		}
		if (sizeOfSerie > longestSerie) longestSerie = sizeOfSerie;
		sizeOfSerie = 0;		

		for (int i = 1; i <= longestSerie; i++)
		{
			numberOfRepetitionsOfEachSize.push_back(0);
		}

		for (auto bit : data)
		{
			if (bit == whatToCount)
			{
				sizeOfSerie++;
			}
			else if (sizeOfSerie > 0)
			{
				numberOfRepetitionsOfEachSize[sizeOfSerie - 1] = numberOfRepetitionsOfEachSize[sizeOfSerie - 1] + 1;
				sizeOfSerie = 0;
			}
		}

		if (sizeOfSerie > 0) numberOfRepetitionsOfEachSize[sizeOfSerie - 1] = numberOfRepetitionsOfEachSize[sizeOfSerie - 1] + 1;

		std::cout << "\nSize of series | How many\n";
		int iterator{};
		for (auto numOfSeries : numberOfRepetitionsOfEachSize)
		{
			if(numOfSeries > 0) std::cout << iterator + 1 << " | " << numOfSeries << std::endl;
			iterator++;
		}
	}

	~Histogram() {}
};