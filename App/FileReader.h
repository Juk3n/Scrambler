#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <fstream>
#include <bitset>
#include <vector>
#include <iostream>

class FileReader
{
    static std::string convertSetOfBitsOfCharToString(char c)
	{
        return std::bitset<16>(static_cast<int16_t>(c)).to_string();
	}

    static void addStringOfBitsToBits(std::string stringOfBits, std::vector<bool> bits)
	{
		for (char bit : stringOfBits)
		{
			bits.push_back(((bit == '1') ? 1 : 0));
		}
	}

public:

    static std::vector<bool> readFile(std::string fileName)
	{
        std::vector<bool> bits{};
        std::ifstream file{ "D://Programowanie 2019//C++//Scrambler//App//" + fileName, std::ios::in | std::ios::binary };

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
			
            addStringOfBitsToBits(stringOfBits, bits);
		}
		
		file.close();
		return bits;
	}

    static void saveToFile(std::vector<bool> dataToSave, std::string fileName)
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

};
#endif
