
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_ATEMPTS = 3;

int main()
{
	setlocale(LC_ALL, "ukr");

	vector<vector<char>> WORDS = {
		{'t','h','i','s'},
		{'w','o','r','d'},
		{'r','e','a','d'}
	};

	srand(static_cast<unsigned>(time(0)));
	int wordIndex = rand() % WORDS.size();
	vector<char> selectedWord = WORDS[wordIndex];
	vector<char> hiddenWord(selectedWord.size(), '*');

	int attempts = 0;
	bool wordGuessed = false;

	cout << "Початок гри 'Вгадай Слово'!\n";

	while (attempts < MAX_ATEMPTS && !wordGuessed)
	{
		for (char c : hiddenWord)
		{
			cout << c << ' ';
		}
		cout << '\n';

		char letter;
		int position;
		cout << "Введіть літеру: ";
		cin >> letter;
		cout << "Введіть позицію (0 - " << selectedWord.size() - 1 << "): ";
		cin >> position;

		if (position >= 0 && position < selectedWord.size() && selectedWord[position] == letter)
		{
			hiddenWord[position] = letter;
			cout << "Правильно!\n";
		}
		else
		{
			attempts++;
			cout << "Неправильно! Невдалих спроб: " << attempts << "/" << MAX_ATEMPTS << '\n';
		}

		wordGuessed = true;
		for (int i = 0; i < hiddenWord.size(); i++) {
			if (hiddenWord[i] == '*') {
				wordGuessed = false;
				break;
			}
		}
	}

	if (wordGuessed) {
		std::cout << "Вітаємо! Ви вгадали слово: ";
		for (char c : selectedWord) {
			std::cout << c;
		}
		std::cout << "\n";
	}
	else {
		std::cout << "Гра закінчена. Ви вичерпали кількість спроб.\n";
		std::cout << "Слово було: ";
		for (char c : selectedWord) {
			std::cout << c;
		}
		std::cout << "\n";
	}
}
