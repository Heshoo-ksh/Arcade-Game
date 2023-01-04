#include <SFML/Graphics.hpp>
#include <Obstacle.h>
#include <Ball.h>
#include <iostream>
#include <Target.h>
#include <Player.h>
#include <fstream>

void moveObjectWithCollision(std::vector <Obstacle> & gameObjects , Target & can);
void moveObjectWithCollision(std::vector <Obstacle> & gameObjects , Target & can, Ball & theBall);
void playGame(std::vector <Obstacle> & gameObjects,Target & can, Ball & theBall,  Player & thePlayer, int & level);
void makeTargetObject( Target & can, int level);
void makeGameLevels(std::vector <Obstacle> & gameObjects,int level);
void setGameObjects(std::vector <Obstacle> & gameObjects,int level, Target & can);
void validateNumaricData(int &choice, int min, int max);
void printTofile(Player & thePlayer);

int main()
{
    std::cout<<"\nWelcome to this game";
    int choice =1;
    while (choice != 0){
    std::cout<<"\nSelect your option:\n1-Play\n2-Quit\n3-Help (how to play)\nSelection:\t";
    std::cin>>choice;
    validateNumaricData(choice,1,3);
    Player thePlayer("",0,3);

    if(choice == 1)
    {
	std::cin.ignore();
    std::string name;
    std::cout<<"\nEnter player name:\t";
    getline(std::cin,name);

    thePlayer.setName(name);
    int level = 1;
    while (thePlayer.getAttempts() > 0 && level != 4 )
    {
    //------------Ball-Doesnt-change----------//
    int radius = 30;
    std::pair <double,double> position(5, (720 - (2*radius )-5)); // 5 ==Border thickness
    std::pair <double,double> velocity(0,0);
    sf::Vector2f dementions;
    Ball theBall (position,velocity,radius);

    Target can(position,velocity,dementions);

    std::vector <Obstacle> gameObjects;

    setGameObjects(gameObjects,level,can);

    playGame(gameObjects, can, theBall,thePlayer,level);
    }
    thePlayer.displayPlayerReport();
    printTofile(thePlayer);
    }
    else if (choice == 2)
    {
        printTofile(thePlayer);
        choice = 0;
    }
    else if (choice == 3)
    {
        std::cout<<"\nPlease view the ReadMe.txt file for help and instructions.\n";
        std::cout<<"\nAt any time if you wish to quit just press the ESC key";
    }
    }
    return 0;
}
void playGame(std::vector <Obstacle> & gameObjects,Target & can, Ball & theBall,  Player & thePlayer, int & level)
{
    bool pressed = false;
    bool started = false;
    std::pair <double,double> velocity;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "HIT THE TARGET!");
    window.setFramerateLimit(120);

        while (window.isOpen())
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (thePlayer.getAttempts() == 0 || level == 4)
                {
                    std::cout<<"\nYou have used all your attempts.\n"<<std::endl;
                    window.close();
                }
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    thePlayer.setAttempts(0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                    thePlayer.setAttempts(0);
                }
            }

            moveObjectWithCollision(gameObjects, can);
            if (event.type == sf::Event::MouseButtonPressed)
            {
                    if (event.mouseButton.button == sf::Mouse::Left && pressed == false)
                    {
                        sf::Vector2i direction = sf::Mouse::getPosition(window);
                        sf::Vector2f mousePosition = window.mapPixelToCoords(direction);

                        theBall.updateVelocity(mousePosition);
                        velocity = theBall.getVelocity();

                        if (velocity.first < .52)
                            velocity.first = .52;
                        if (velocity.second < .52)
                            velocity.second = .52;

                        pressed  = true;
                    }
                }

            while(event.type == sf::Event::MouseButtonReleased && (std::abs(velocity.first) > .51 && std::abs(velocity.second) > .51))
            {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        moveObjectWithCollision(gameObjects,can,theBall);
                        velocity = theBall.getVelocity();

                        if(can.getHitTarget() == true)
                        {
                            velocity.first = 0;
                            velocity.second = 0;
                        }
                        else
                            started = true;

                        window.clear();
                        can.drawObject(window);
                        theBall.drawObject(window);
                        for (Obstacle aGameObject : gameObjects)
                        {
                            aGameObject.drawObject(window);
                            aGameObject.drawObject(window);
                        }
                        window.display();
                    }
                }

            if(can.getHitTarget() == true)
            {
                    std::cout<<"\nYou Win!"<<std::endl;
                    thePlayer++;
                    level++;
                    //thePlayer.displayPlayerReport();
                    window.close();
                }
            else if (started == true)
            {
                    std::cout<<"\nYou lost"<<std::endl;
                    thePlayer--;
                    //thePlayer.displayPlayerReport();
                    window.close();
                }

            window.clear();
            can.drawObject(window);
            for (Obstacle aGameObject : gameObjects)
                {
                    aGameObject.drawObject(window);
                    aGameObject.drawObject(window);
                }
            theBall.drawObject(window);
            window.display();
        }

}
void makeGameLevels(std::vector <Obstacle> & gameObjects,int  level)
{
    std::pair <double,double> position ;
    std::pair <double,double> velocity;
    sf::Vector2f dementions;

    Obstacle gameObject (position,velocity,dementions);

        //------setting up level one----//
        if (level == 1)
            {
            //----Moving vertically-------//
            position.first = 300;
            position.second = 200;
            velocity.first = 0;
            velocity.second = 4;
            dementions.x = 90;
            dementions.y = 35;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObject.setVelocity(velocity);
            gameObjects.push_back(gameObject);

            //--------Moving horizontally-----//
            position.first = 800;
            position.second = 200;
            velocity.first = 4;
            velocity.second = 0;
            dementions.x = 90;
            dementions.y = 30;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObject.setVelocity(velocity);
            gameObjects.push_back(gameObject);

            }
        //------setting up level two--------//
        if (level == 3)
            {
            //----Moving vertically-------//
            dementions.x = 90;
            dementions.y = 35;
            position.first = 1000;
            position.second = 300;
            velocity.first = 0;
            velocity.second = 6;


            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObjects.push_back(gameObject);

            //--------Moving horizontally-----//
            dementions.x = 90;
            dementions.y = 35;
            position.first = 1000;
            position.second = 500;
            velocity.first = 6;
            velocity.second = 0;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObjects.push_back(gameObject);

            //-------Not moving (vertical)----//
            dementions.x = 10;
            dementions.y = 222;
            position.first = 650;
            position.second = 720 - 222;
            velocity.first = 0;
            velocity.second = 0;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObjects.push_back(gameObject);
            }
        //------setting up level three----//
        if (level == 2)
            {
            //----Moving vertically-------//
            dementions.x = 15;
            dementions.y = 100;
            position.first = 700;
            position.second = 100;
            velocity.first = 0;
            velocity.second = 7;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObject.setVelocity(velocity);
            gameObjects.push_back(gameObject);

            //--------Moving horizontally-----//
            position.first = 700;
            position.second = 100;
            velocity.first = 8;
            velocity.second = 0;
            dementions.x = 15;
            dementions.y = 100;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObject.setVelocity(velocity);
            gameObjects.push_back(gameObject);

            //-------Not moving (vertical)----//
            dementions.x = 15;
            dementions.y = 50;
            position.first = 250;
            position.second = 720 - 250;
            velocity.first = 0;
            velocity.second = 0;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObjects.push_back(gameObject);

            //-------Not moving (horizontal)----//
            dementions.x = 15;
            dementions.y = 50;
            position.first = 650;
            position.second = 222;
            velocity.first = 0;
            velocity.second = 0;

            gameObject.setDemetions(dementions);
            gameObject.setPosition(position);
            gameObjects.push_back(gameObject);
            }

}
void setGameObjects(std::vector <Obstacle> & gameObjects,int level, Target & can)
{
    std::cout<<"\nYou are now playing level:\t"<<level;
    makeGameLevels(gameObjects, level);
    makeTargetObject(can, level);

}

void makeTargetObject( Target & can, int level)
{
    sf::Vector2f position;
    std::pair <double,double> canPosition;
    std::pair <double,double> velocity;
    sf::Vector2f dementions;

    switch (level)
    {
        case 1:
        {
            position.x = 800;
            position.y = 300;
            canPosition.first = 800;
            canPosition.second = 300;
            velocity.first = 0;
            velocity.second = 0;
            dementions.x = 25;
            dementions.y = 45;

            break;
        }

        case 2:
        {
            position.x = 1200;
            position.y = 600;
            canPosition.first =1200;
            canPosition.second = 600;
            velocity.first = 0;
            velocity.second = 0;
            dementions.x = 20;
            dementions.y = 35;

            break;
        }
        case 3:
        {
            position.x = 1100;
            position.y = 600;
            canPosition.first =1100;
            canPosition.second = 600;
            velocity.first = 0;
            velocity.second = 0;
            dementions.x = 10;
            dementions.y = 20;

            break;
        }
    }
    can.setPosition(canPosition);
    can.setDemetions(dementions);
    can.setVelocity(velocity);

}
void moveObjectWithCollision(std::vector <Obstacle> & gameObjects , Target & can)
{
        for (Obstacle aGameObject : gameObjects)
        {
            aGameObject.moveObject();
        }
        for (Obstacle aGameObject : gameObjects)
        {
            for (Obstacle otherGameObject : gameObjects)
            {
                aGameObject.collisionDetection(otherGameObject);
            }
            can.collisionDetection(aGameObject);
        }

}

void moveObjectWithCollision(std::vector <Obstacle> & gameObjects , Target & can, Ball & theBall)
{
   for (Obstacle aGameObject : gameObjects)
        {
            for (Obstacle otherGameObject : gameObjects)
            {
                aGameObject.collisionDetection(otherGameObject);
            }
            can.collisionDetection(aGameObject);
            theBall.collisionDetection(aGameObject);
        }
        theBall.moveObject();
        can.collisionDetection(theBall);
        for (Obstacle aGameObject : gameObjects)
        {
            aGameObject.moveObject();
        }
}

void validateNumaricData(int &choice, int min, int max)
{
	while(std::cin.fail()){

			std::cout<<"\nERROR:\tInvalid input Due to the wrong Data type, try again \nChoice:\t";
	  		std::cin.clear();
	   		std::cin.ignore( std::numeric_limits<std::streamsize>::max(),'\n');
	   		std::cin>>choice;
	}
	while ( choice > max || choice < min)
	{
		std::cout<<"\nERROR:\tOption selected is not valid, try again.\nChoice:\t";
		std::cin>>choice;
		validateNumaricData( choice,  min,  max);
	}
}
void printTofile(Player & thePlayer)
{
    std::ofstream myfile;
    myfile.open ("result.txt");
    myfile<<"\n"<<thePlayer.getName()<<" scored "<<thePlayer.getScore()<<" using "<<thePlayer.getAttempts();
    myfile<<"\n--------------------------\n";
    myfile.close();

}
