#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <Game.h>


class Obstacle : public Game
{
    protected:
        sf::RectangleShape rectangle;
        sf::Vector2f dementions;
    public:
        Obstacle(std::pair<double, double> position,std::pair<double, double> velocity,sf::Vector2f dementions);
        virtual ~Obstacle();

        //---------setters---------//
        void setDemetions(sf::Vector2f dementions){this-> dementions = dementions; rectangle.setSize(dementions);}
        void setPosition(std::pair<double, double> position) {this-> position = position; rectangle.setPosition(position.first,position.second);}

        void setRectPosition(sf::Vector2f position){rectangle.setPosition(position);}
        //---------getters---------//
        sf::Vector2f getDementions(){return dementions;}
        sf::RectangleShape getRectangle(){return rectangle;}
        sf::Vector2f getRectPosition(){return rectangle.getPosition();}


        //----member functions-----//
        void drawObject(sf::RenderWindow & window);
        void moveObject();
        void updateVelocity(sf::Vector2f coordinates);
        void collisionDetection(Obstacle & anObstacle);
};

#endif // OBSTACLE_H
