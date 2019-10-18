#include <iostream>
#include <vector>
#include <list>
#include <ctime>
using namespace std;

bool playGame(int difficulty) {
	int a = rand() % difficulty + difficulty;
	int b = rand() % difficulty + difficulty;
	int c = rand() % difficulty + difficulty;

	int sum = a + b + c;
	int product = a * b * c;

	int guessA = 0;
	int guessB = 0;
	int guessC = 0;

	bool success = false;

	int numbers[3] = { a, b, c };

	cout << "The sum of the numbers is equal to " << sum << endl;
	cout << "The product of the numbers is equal to " << product << endl;
	//for (int x = 0; x < 3; x++)
	//{
	//	cout << numbers[x] << endl;
	//}
	cout << "input: ";

	cin >> guessA >> guessB >> guessC;

	//I tried using lists, I tried using Vectors,
	//I'm so used to Java with its pointer usage that
	//I just couldn't figure out how to get this to work,
	//I so sleapt on it, and had a Eureka moment at like 5:00am
	//to use an array and just set the "guessed numbers" to
	//zero because none of the random numbers are ever zero.
	//I suppose it would be more elegant to set them equal to
	//-1 or something.
	//I also got it working with a long series of if statements...
	//but that was a little much, now I will move on to watching
	//the instructional video to see what I could have done better.

	/*if (guessA == a)
	{
		if (guessB == b)
		{
			if (guessC == c)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (guessB == c)
		{
			if (guessC == b)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (guessA == b)
	{
		if (guessB == a)
		{
			if (guessC == c)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (guessB == c)
		{
			if (guessC == a)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (guessA == c)
	{
		if (guessB == a)
		{
			if (guessC == b)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (guessB == b)
		{
			if (guessC == a)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}*/

	for (int i = 0; i < 3; i++) 
	{
		if (guessA == numbers[i])
		{
			numbers[i] = 0;
			for (int j = 0; j < 3; j++)
			{
				if (guessB == numbers[j])
				{
					numbers[j] = 0;
					for (int k = 0; k < 3; k++)
					{
						if (guessC == numbers[k])
						{
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}


int main()
{
	int difficulty = 2;
	int maxDifficulty = 10;
	while (difficulty <= maxDifficulty)
	{
		cout << "You are now at difficulty: " << difficulty << ", good luck!" << endl;
		cout << "You must now input 3 numbers that abide by the following rules:\n";
		if (playGame(difficulty) == true)
		{
			cout << "good job, lets up the difficutly.\n";
			difficulty += 1;
		}
		else
		{
			cout << "you done screwed up, try again.\n";
		}
	}
	return 0;
}