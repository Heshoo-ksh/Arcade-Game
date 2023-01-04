#include "Player.h"

Player::Player(std::string name,int score,int attempts)
{
    this-> name = name;
    this-> score = score;
    this-> attempts = attempts;
}

Player::~Player()
{
    //dtor
}

void Player::displayPlayerReport(){
    std::cout<<"\nPlayer "<<name<<" scored "<<score<<" points and used "<< 3-attempts<<" attempts"<<std::endl;
}
