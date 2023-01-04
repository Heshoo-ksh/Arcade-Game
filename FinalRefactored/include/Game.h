#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>    //Graphics Library
#include <utility>              // Pair
#include <cmath>            // std::abs

class Game
{
    protected:
        std::pair<double, double> position;
        std::pair<double, double> velocity;
    public:
        Game(std::pair<double, double> position,std::pair<double, double> velocity);
        virtual ~Game();

        //------getters------//
        std::pair <double, double> getPosition(){return position;}
        std::pair <double, double> getVelocity(){return velocity;}

        //-----setters-------//
        virtual void setPosition(std::pair <double, double> position){this-> position = position;}
        virtual void setVelocity(std::pair <double, double> velocity){this-> velocity = velocity;}

        //----Member Functions-----//
        virtual void drawObject(sf::RenderWindow & window) = 0;
        virtual void moveObject() = 0;
        virtual void updateVelocity(sf::Vector2f coordinates) = 0;
        //virtual void collisionDetection() = 0;
};

#endif // GAME_H
