#include "Wheel.h"
#include "HardModeWheel.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


void playGame(bool isHardMode) {

    int minBet = 6;
    int maxBet = 20;
    int maxPlayerValue = 10;

    Player player;
    HardModeWheel houseWheel(maxPlayerValue);

    int bet;
    int initialMoney;
    std::cout << "Enter your initial amount of money: ";
    std::cin >> initialMoney;
    player.setMoney(initialMoney);

    while (player.getMoney() > 0) {
        std::cout << "Current money: $" << player.getMoney() << std::endl;
        std::cout << "Enter your bet (between " << minBet << " and " << maxBet << "): ";
        std::cin >> bet;

        if (bet < minBet || bet > maxBet) {
            std::cout << "Invalid bet! Please try again." << std::endl;
            continue;
        }

        char wagerChoice;
        std::cout << "Choose your wager (d = double, h = halve, any other key = same): ";
        std::cin >> wagerChoice;

        if (wagerChoice == 'd' || wagerChoice == 'D') {
            bet *= 2;
        }
        else if (wagerChoice == 'h' || wagerChoice == 'H') {
            bet /= 2;
        }

        int playerResult = player.spinWheel();
        int houseResult;

        if (isHardMode)
            houseResult = houseWheel.spin(playerResult);
        else
            houseResult = houseWheel.spin();

        std::cout << "Player result: " << playerResult << ", House result: " << houseResult << std::endl;

        if (playerResult > houseResult) {
            std::cout << "Player wins!" << std::endl;
            player.setMoney(player.getMoney() + bet);
        }
        else if (playerResult < houseResult) {
            std::cout << "Player loses!" << std::endl;
            player.setMoney(player.getMoney() - bet);
        }
        else {
            std::cout << "It's a tie. House wins!" << std::endl;
            player.setMoney(player.getMoney() - bet);
        }

        char playAgain;
        std::cout << "Do you want to play another round? (y/n): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y')
            break;
    }

    std::cout << "Game over. You cashed out with $" << player.getMoney() << std::endl;
}

int main() {
    char choice;
    std::cout << "Do you want to play in hard mode? (y/n): ";
    std::cin >> choice;

    bool isHardMode = (choice == 'y' || choice == 'Y');
    playGame(isHardMode);

    return 0;
}


















