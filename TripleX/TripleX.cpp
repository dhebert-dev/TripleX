#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
	std::cout << " secure server room...\nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "+ There are 3 numbers in the code ";
	std::cout << "\n+ The codes add up to: " << CodeSum;
	std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n*** Well done agent! Let's move to the next server room. *** ";
		return true;
	}
	else
	{
		std::cout << "\nCareful Agent! You have entered the wrong codes. Try again!";
		return false;
	}
}

int main() 
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	int const MaxLevel = 5;
	while (LevelDifficulty <= MaxLevel)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << std::endl;
	std::cout << "*** Congrats! You completed the game! ***";
	return 0;
}