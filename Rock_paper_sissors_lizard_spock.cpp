#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() {
    int userWins = 0;
    int computerWins = 0;
    int ties = 0;

    while (true) {
        int userNumber = -1;
        std::string userInput;

        //promt user to select their choice
        std::cout << "Please choose: rock, paper, scissors, lizard, or Spock (or type 'exit' to quit): ";
        std::getline(std::cin, userInput);

        //exists program if user inputed exit
        if (userInput == "exit") {
            break;
        }

        // Convert user input to lowercase for case-insensitive comparison
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        if (userInput == "rock") {
            userNumber = 0;
        } else if (userInput == "spock") {
            userNumber = 1;
        } else if (userInput == "paper") {
            userNumber = 2;
        } else if (userInput == "lizard") {
            userNumber = 3;
        } else if (userInput == "scissors") {
            userNumber = 4;
        } else {//if the input does not match any of the expected values, then notify user and try again
            std::cout << "The provided input is incorrect, please try again." << std::endl;
            std::cout << "Ties: " << ties << " Your Wins: " << userWins << " Computer Wins: " << computerWins << std::endl;
            continue;
        }

        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Generate a random number between 0 and 4 to represent the computer's choice
        int computerChoice = std::rand() % 5;

        std::string computerChoiceString;
        //based on the number, assign the computers "decision"
        switch (computerChoice) {
            case 0:
                computerChoiceString = "rock";
                break;
            case 1:
                computerChoiceString = "spock";
                break;
            case 2:
                computerChoiceString = "paper";
                break;
            case 3:
                computerChoiceString = "lizard";
                break;
            case 4:
                computerChoiceString = "scissors";
                break;
        }

        std::cout << "Computer chose: " << computerChoiceString << std::endl;
        //crown the winner and update counters
        if (userNumber == computerChoice) {
            std::cout << "Tie! You both chose " << userInput << std::endl;
            ties++;
        } else if (((userNumber - computerChoice + 5) % 5) <= 2) {
            std::cout << "You WIN!" << std::endl;
            userWins++;
        } else {
            std::cout << "Computer WINS!" << std::endl;
            computerWins++;
        }

        std::cout << "Ties: " << ties << " Your Wins: " << userWins << " Computer Wins: " << computerWins << std::endl;
    } // end of while loop

    return 0;
}