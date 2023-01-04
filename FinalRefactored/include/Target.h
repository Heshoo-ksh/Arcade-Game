#ifndef TARGET_H
#define TARGET_H

#include <Obstacle.h>
#include <Ball.h>

class Target : public Obstacle
{
    private:
        bool hitTraget;
    public:
        Target(std::pair<double, double> position,std::pair<double, double> velocity,sf::Vector2f dementions);
        virtual ~Target();

        void collisionDetection(Obstacle & anObstacle);
        void collisionDetection(Ball & aBall);

        bool getHitTarget(){return hitTraget;}
};

#endif // TARGET_H
