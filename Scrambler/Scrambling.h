#pragma once

#include <vector>

class Scrambling
{
	std::vector<bool> createSyncWord()
	{
		std::vector<bool> syncWord{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 };

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
		std::vector<bool> syncWord{ createSyncWord() };

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
