#pragma once

#include <string>
#include <fstream>
#include <bitset>
#include <vector>

class FileReader
{
	std::vector<bool> bits{};

	std::string convertSetOfBitsOfCharToString(char c)
	{
		return std::bitset<16>(static_cast<int16_t>(c)).to_string();
	}

	void addStringOfBitsToBits(std::string stringOfBits)
	{
		for (char bit : stringOfBits)
		{
			bits.push_back(((bit == '1') ? 1 : 0));
		}
	}

public:
	FileReader() {}

	std::vector<bool> readFile(std::string fileName)
	{
		std::ifstream file{ fileName, std::ios::in | std::ios::binary };

		if (!file.is_open())
		{
			throw "Error while reading file";
		}
		
		file.seekg(0);
		char c{};
		while (file.get(c))
		{
			std::string stringOfBits{ convertSetOfBitsOfCharToString(c) };
			addStringOfBitsToBits(stringOfBits);		
		}
		
		return bits;
	}

	~FileReader() {}
};



