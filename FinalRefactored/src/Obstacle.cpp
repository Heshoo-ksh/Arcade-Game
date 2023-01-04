#include "Obstacle.h"
#include <iostream>
Obstacle::Obstacle(std::pair <double, double> position,std::pair <double, double> velocity,sf::Vector2f dementions) :
    Game(position, velocity)
{
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setOutlineColor(sf::Color::Yellow);
    rectangle.setOutlineThickness(5);
    rectangle.setSize(dementions);
    rectangle.setPosition(position.first, position.second);
    setVelocity(velocity);
    setPosition(position);
    setDemetions(dementions);

}

Obstacle::~Obstacle()
{
    //dtor
}

void Obstacle::drawObject(sf::RenderWindow & window)
{
    window.draw(rectangle);
}

void Obstacle::moveObject()
{
    if (std::abs(velocity.first) > 0){

        if (position.first <= 0 || position.first >= 1280 - dementions.x)
            velocity.first *= -1;

        position.first += velocity.first;
    }
    if (std::abs(velocity.second) > 0){

        if (position.second <= 0 || position.second >= 720 - dementions.y)
            velocity.second *= -1;

        position.second += velocity.second;

    }
    rectangle.setPosition(position.first,position.second);
    setVelocity(velocity);
}
void Obstacle::updateVelocity(sf::Vector2f coordinates){}

void Obstacle::collisionDetection(Obstacle  & anObstacle){

    if (rectangle.getGlobalBounds().intersects(anObstacle.rectangle.getGlobalBounds()))
        {
            anObstacle.velocity.first *= -1;
            anObstacle.velocity.second *= -1;
            //anObstacle.setVelocity(anObstacle.velocity);

            velocity.first *= -1;
            velocity.second *= -1;
            //setVelocity(velocity);
        }

}

