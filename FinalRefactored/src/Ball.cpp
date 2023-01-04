#include "Ball.h"
#include <iostream>
Ball::Ball(std::pair<double, double> position,std::pair<double, double> velocity, int radius) :
    Game(position, velocity)
{
    circle.setPointCount(50);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(5);
    circle.setRadius(radius);
    circle.setPosition(position.first,position.second);

    setPosition(position);
    setVelocity(velocity);
    this->radius = radius;
}

Ball::~Ball()
{
    //dtor
}

void Ball::drawObject(sf::RenderWindow & window)
{
    window.draw(circle);
}

void Ball::moveObject()
{

    if (std::abs(velocity.first) > 0 && std::abs(velocity.second) > 0 ){

        if (position.first < 0 || position.first > 1280 - (2 * radius ))
            velocity.first *= -1;

        if (position.second < 0 || position.second > 720 - (2 * radius ))
            velocity.second *= -1;

        position.first += velocity.first;
        position.second += velocity.second;

        if (velocity.first > 0 )
            velocity.first= std::abs((velocity.first) - ( .033));

        else if (velocity.first < 0 )
            velocity.first = (velocity.first) + ( .033);

        if (velocity.second > 0 )
            velocity.second = std::abs((velocity.second) - ( .033));

        else if (velocity.second < 0 )
            velocity.second = (velocity.second) + ( .033);


        circle.setPosition(position.first,position.second);

        setVelocity(velocity);
    }
}
void Ball::updateVelocity(sf::Vector2f mousePosition)
{
    mousePosition.y =  mousePosition.y - (720 -(2*radius));
    double distance = std::sqrt(std::abs(((position.first - mousePosition.x) * (position.first - mousePosition.x)) + ((position.second - mousePosition.y) * (position.second - mousePosition.y))));
    if (distance > 800)
    {
        distance = 800;
    }
    velocity.first = (mousePosition.x/(1280) * distance)/20;
    velocity.second = (mousePosition.y/(720 - (2 * radius)) * distance)/20;

    /*
    if (velocity.first > 35)
    {
        velocity.first = 35;
    }
    if (velocity.second > 35)
    {
        velocity.second = 35;
    }
    */

    setVelocity(velocity);
}


void Ball::collisionDetection(Obstacle & anObstacle){

    sf::RectangleShape rect = anObstacle.getRectangle();
    if (circle.getGlobalBounds().intersects(rect.getGlobalBounds()))
        {
            std::pair<double, double>  obstacleVelocity = anObstacle.getVelocity();
            obstacleVelocity.first *= -1;
            obstacleVelocity.second *= -1;
            anObstacle.setVelocity(obstacleVelocity);


            velocity.first *= -1;
            velocity.second *= -1;
            setVelocity(velocity);
        }
}



