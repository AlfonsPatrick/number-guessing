#include <iostream>
#include <cstdlib>
#include <ctime>

char playAgain;

int main() {
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess it?" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    do {
    std::cout << "Please select your difficulty level (1 for easy, 2 for medium, 3 for hard): ";

    int difficulty;
    std::cin >> difficulty;
    int maxAttempts;
    switch (difficulty) {
        case 1:
            maxAttempts = 10;
            break;
        case 2:
            maxAttempts = 7;
            break;
        case 3:
            maxAttempts = 5;
            break;
        default:
            std::cout << "Invalid difficulty level. Defaulting to easy." << std::endl;
            maxAttempts = 10;
    }

    int secretNumber = std::rand() % 100 + 1;
    int attempts = 0;
    bool guessedCorrectly = false;
    while (attempts < maxAttempts && !guessedCorrectly) {
        std::cout << "Attempt " << (attempts + 1) << " of " << maxAttempts << ": ";
        int guess;
        std::cin >> guess;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            guessedCorrectly = true;
            std::cout << "Congratulations! You've guessed the number!" << std::endl;
        }
        attempts++;
    }
    if (!guessedCorrectly) {
        std::cout << "Sorry, you've used all your attempts. The number was: " << secretNumber << std::endl;
    }
    if (guessedCorrectly) {
        std::cout << "You guessed the number in " << attempts << " attempts!" << std::endl;
    }
    std::cout << "Play again? (y/n): ";
    std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}