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

	std::vector<bool> reorganizeSyncWord(std::vector<bool> syncWord)
	{
		int syncWordLength{ static_cast<int>(syncWord.size()) };
		bool lastSyncWordBit = syncWord[syncWordLength - 1];

		for (int i{ syncWordLength - 1 }; i > 0; i--)
		{
			syncWord[i] = syncWord[i - 1];
		}
		syncWord[0] = lastSyncWordBit;

		return syncWord;
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
			syncWord = reorganizeSyncWord(syncWord);
		}
		return scrambledInput;
	}

	~Scrambling() {}
};