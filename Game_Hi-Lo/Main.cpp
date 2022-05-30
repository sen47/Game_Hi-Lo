#include<iostream>
#include<cstdint>
#include<random>

static const std::int16_t MAX_TRYES(7), MIN(0), MAX(100);

std::int16_t CheckInput(std::int16_t min, std::int16_t max);

int main()
{
	std::random_device rd;
	std::mt19937 mers(rd());
	
	std::cout << "Hello, let\'s play a game.\n";
	while (true)
	{
		std::uniform_int_distribution<std::int16_t> distr(MIN, MAX);
		std::int16_t tryes(0), pcNumber(distr(mers));
		std::cout << "I\'m think a number from " << MIN << " to " << MAX
			<< ". You have " << MAX_TRYES << " to guess what is it.";

		std::int16_t answer;
		while (tryes < MAX_TRYES)
		{
			++tryes;
			std::cout << "\n\nGuess #" << tryes << ": ";
			answer = CheckInput(MIN, MAX);

			if (answer < pcNumber)
				std::cout << "Your guess is too low.";
			else if (answer > pcNumber)
				std::cout << "Your guess is too high.";
			else
				break;
		}
		
		if (answer == pcNumber && tryes <= MAX_TRYES)
			std::cout << "\nCongratulations, you win!";
		else
			std::cout << "\n\nOh shit, i think you lose!";
		std::cout << " Number is " << pcNumber;

		char playAgain(' ');
		while(true)
		{
			std::cout << "\n\nDo you want to play again(y/n)? ";
			std::cin >> playAgain;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
			}
			if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N')
				break;
		}
		if (playAgain == 'n' || playAgain == 'N')
			break;

		system("cls");
	}

	std::cout << "\nGood bye!" << std::endl;

	return 0;
}

std::int16_t CheckInput(std::int16_t min, std::int16_t max)
{
	std::int16_t input(0);
	while (true)
	{
		std::cin >> input;
		std::cin.ignore(32767, '\n');
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(23767, '\n');
			std::cout << "\nTry again!"
				<< "\nGuess number in range from " << min << " to " << max
				<< "\nEnter: ";
		}
		else if (input<min || input>max)
		{
			std::cout << "\nTry again!"
				<< "\nGuess number in range from " << min << " to " << max
				<< "\nEnter: ";
		}
		else
			return input;
	}
}
