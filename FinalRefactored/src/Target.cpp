#include "Target.h"
#include <iostream>

Target::Target(std::pair <double, double> position,std::pair <double, double> velocity,sf::Vector2f dementions) :
    Obstacle( position, velocity, dementions)
{
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineColor(sf::Color::Yellow);
    rectangle.setOutlineThickness(2.5);
    rectangle.setSize(dementions);
    rectangle.setPosition(position.first, position.second);
    setVelocity(velocity);
    setPosition(position);
    setDemetions(dementions);
    hitTraget = false;
}

Target::~Target()
{
    //dtor
}
void Target::collisionDetection(Ball & aBall){
    hitTraget = false;
    sf::CircleShape circleObject = aBall.getCircle();
    if (Target::rectangle.getGlobalBounds().intersects(circleObject.getGlobalBounds()))
        {
            hitTraget = true;
        }

}
void Target::collisionDetection(Obstacle & anObstacle){

    sf::RectangleShape rect = anObstacle.getRectangle();

    if (rectangle.getGlobalBounds().intersects(rect.getGlobalBounds()))
        {
            std::pair<double, double>  obstacleVelocity = anObstacle.getVelocity();

            obstacleVelocity.first *= -1;
            obstacleVelocity.second *= -1;
            anObstacle.setVelocity(obstacleVelocity);

            velocity.first *= -1;
            velocity.second *= -1;
        }
}
