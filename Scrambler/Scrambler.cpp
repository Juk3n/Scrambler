// Scrambler.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <string>
#include <vector>


std::string changeSequency(int pulse)
{
	if (pulse == 1)
		return "00011011";
	else
		return "00011011";
}


//bipolar with 8-zeros substitution
std::vector<bool> B8ZS(std::vector<bool> binaryInput)
{
	int lastPulse{ -1 };
	int zeros; 
	int digitIndex; 
	
	for (bool binaryDigit : binaryInput)
	{
		if (binaryDigit == 0)
		{
			zeros++;
			if (zeros >= 8)
				changeSequency(lastPulse);
		}
		else
		{
			lastPulse *= -1;
			zeros = 0;
		}

		digitIndex++; 
	}
	return; 
}


int main()
{

    return 0;
}

