#ifndef SIMPLEBITDATAGENERATOR_H
#define SIMPLEBITDATAGENERATOR_H

#include <vector>

class SimpleBitDataGenerator
{
public:
	static std::vector<bool> generateData(bool whatInside, int dataLength)
	{
		return std::vector<bool>(dataLength, whatInside);
	}
};

#endif
