#pragma once

#include <vector>

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
		for (bool bit : syncWord)
		{
			std::cout << bit;
		}

		return syncWord;
	}

	std::vector<bool> reorganizeSyncWord(std::vector<bool> syncWord)
	{
		int inputLength{ static_cast<int>(syncWord.size()) };
		bool lastSyncWordBit = syncWord[inputLength - 1];

		for (int i{ inputLength - 1 }; i > 0; i--)
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
		std::vector<bool> syncWord{ createSyncWord(inputLength) };

		std::vector<bool> scrambledInput;

		bool lastSyncWordBit{};
		for (int i{}; i < inputLength; i++)
		{
			lastSyncWordBit = syncWord[inputLength - 1];
			bool scrambledBit{moduloTwoAddition(input[i], lastSyncWordBit)};
			scrambledInput.push_back(scrambledBit);

			syncWord = reorganizeSyncWord(syncWord);			
		}
		return scrambledInput;
	}

	~Scrambling() {}
};
