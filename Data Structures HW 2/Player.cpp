#include "Player.h"

Player::Player() : money(0), wheel() {}

void Player::setMoney(int initialMoney) {
    money = initialMoney;
}

int Player::getMoney() const {
    return money;
}

int Player::spinWheel() {
    return wheel.spin();
}
