#pragma once

#include <vector>
#include <memory>

class Scrambling
{
	std::vector<bool> createSyncWord(int length)
	{
		std::vector<bool> syncWord;
		
		syncWord.push_back(0);
		for (int i = 1; i < length; i++)
		{
			syncWord.push_back(!syncWord[i - 1]);
		}
		return syncWord;
	}

	std::vector<bool> reorganizeData(std::vector<bool> data)
	{
		int dataLength{ static_cast<int>(data.size()) };
		bool lastdataBit = data[dataLength - 1];

		for (int i{ dataLength - 1 }; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
		data[0] = lastdataBit;

		return data;
	}

	bool moduloTwoAddition(bool firstBit, bool secondBit)
	{
		return static_cast<bool>(((int)firstBit + (int)secondBit) % 2);
	}

public:
	Scrambling() {}

	std::vector<bool> scrambleAdditive(std::vector<bool> input)
	{
		int inputLength{ static_cast<int>(input.size()) };
		std::vector<bool> syncWord{ createSyncWord(15) };
		

		std::vector<bool> scrambledInput;

		bool bitToScrambleWith{};
		for (int i{}; i < inputLength; i++)
		{
			bitToScrambleWith = syncWord[14];
			bool scrambledBit{moduloTwoAddition(input[i], bitToScrambleWith)};

			scrambledInput.push_back(scrambledBit);	
			syncWord = reorganizeData(syncWord);
		}
		return scrambledInput;
	}

	std::vector<bool> scrambleMultiplicative(std::vector<bool> input)
	{
		int inputLength{ static_cast<int>(input.size()) };
		std::vector<bool> scrambledInput;

		for (int i{}; i < inputLength; i++)
		{
			bool scrambledBit{static_cast<bool>(input[17] * input[22]) };

			scrambledInput.push_back(scrambledBit);
			reorganizeData(input);
		}

		return scrambledInput;
	}

	~Scrambling() {}
};