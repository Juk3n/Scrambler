#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>
#include <bitset>
#include <vector>
#include <iostream>

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
			file.close();
            throw "Error while reading file";
		}
		
		file.seekg(0);
		char c{};
		while (file.get(c))
		{
			std::string stringOfBits{ convertSetOfBitsOfCharToString(c) };
			
			addStringOfBitsToBits(stringOfBits);		
		}
		
		file.close();
		return bits;
	}

	void saveToFile(std::vector<bool> dataToSave, std::string fileName)
	{
		std::ofstream file{ fileName, std::ios::out | std::ios::binary };

		if (!file.is_open())
		{
			throw "Error while reading file";
		}

		//bity do zapisania kumuluje do 16bitowych/2bajtowych stringow
		std::string stringOfBits{};
		for (bool bit : dataToSave)
		{
			stringOfBits.push_back((bit ? '1' : '0'));
			if (stringOfBits.length() == 16)
			{
				//potem te stringi convertuje do charow
				auto byte = std::bitset<16>(stringOfBits);
				char byteChar = byte.to_ulong();
				
				//chary wrzuca do pliku i powinno byc ok
				file.put(byteChar);
				stringOfBits.clear();
			}
		}

		file.close();
	}

	~FileReader() {}
};



#endif
