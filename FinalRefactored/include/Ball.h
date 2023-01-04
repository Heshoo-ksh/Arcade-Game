#ifndef BALL_H
#define BALL_H
#include <Obstacle.h>
#include <Game.h>


class Ball : public Game
{
    private:
        sf::CircleShape circle;
        int radius;
        std::pair <double,double> distance;
    public:
        Ball(std::pair<double, double> position,std::pair<double, double> velocity, int radius);
        virtual ~Ball();

        void setDistance(std::pair <double,double> distance){this->distance = distance;}

        sf::CircleShape getCircle(){return circle;}
        int getRadius (){return radius;}

        void drawObject(sf::RenderWindow & window);
        void moveObject();
        void updateVelocity(sf::Vector2f mousePosition);
        void collisionDetection(Obstacle & anObstacle);
};

#endif // BALL_H
