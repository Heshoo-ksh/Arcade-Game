#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player
{
    private:
        std::string name;
        int score;
        int attempts;

    public:
        Player(std::string name,int score,int attempts);
        virtual ~Player();

        //----------getters------------//
        int getScore(){ return score;}
        std::string getName(){return name;}
        int getAttempts (){return attempts;}

        //--------setters--------------//
        void setScore(int score){ this->score = score;}
        void setName(std::string){ this->name = name;}
        void setAttempts(int attempts){this->attempts = attempts;}
        void displayPlayerReport();

        //-----OverLoading operators-------//
        Player& operator++(int x)
		{
			score++;
			return (*this);
		}
		Player& operator--(int x)
		{
			attempts--;
			return (*this);
		}

};

#endif // PLAYER_H
