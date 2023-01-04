Final Project C++
Student Name: Hisham Odeh

Progect Idea: An arcade game, the objective is to get the highest score by using the minimum number of attempts. 
You score my hitting your target by the ball.
You lose an attempt every time the balls stops without hitting the traget. 
You have Three attempts in total.

To aim the ball you press at the direction you wish to push it towards.
The further in the screen you press the faster the ball is.
The ball will be bouncing off of moving obstacles and the frame of the screen.


Objects:

Ball: Circle, Red color with a Blue border line.
Obstacle: Rectangular, Pink color with Yellow border line.
Target: Rectangular, Green color with Yellow border line.


How I used:

Strings: for basic input and output.

Vectors: 
1- I used the built in vector of float pairs to store (x,y) coordinants for either velocity or position.
2- I used vectors to build several levels of this game, as I stored all the obstacle objects in them, depending on what level the user is playing.

Templates:
I used pairs to store (x,y) coordinants (Pairs are technically templates)

Inheritance (Is - A relationship):
Inharated 
	1- Ball from Game
	2- Obstacle from Game
	3-Target from Obstacle

Composition (Has- A relationship)
Created an instance of
	1- The Circle class in ball
	2- rectangle class in obstacle
I expanded apon these classes and added properties the shaped, like velocity and position. Any by that the shape in now a game object.

initialization lists
I used initialization lists to properly inherent classes (in child classes)
	1-In the Ball and Obsstacle class (child of game)
	2-In the target class (child of obstacle)

Files
To print out a game report to a file called (result.txt)
the reposrt inclued the players name, score and attempts used.

Data validation
I made sure that the program cant break and validated all input to make sure the correct value and type of data was provided.

The Virtual keyWord
	1- I created an abstract class (Game) that has virtual functions (function =0)
	2-A virtual function in Obstacle, redifined in targeet

OverLoading:
This game in full with over laoded methods for both member and non member methods.
I also overloaded the (++) and the (--) operators in the Player class to increment and decremnt certain private fields

SFML
I used the SFML library for many things
1- to draw objects
2- to use built in classes and expand apon them
3- to use built in functions and expand apon them

Polymorphism
As I mentioned, a lot of vetual methods are included. As well as an abstract class.
I also made sure to override several member functions in the ball, tareget and obstacle class

Impotrant notes:
If anything is unclear please ask, I would love to hear from you.
To exit press the (ESC) key or the (x) Icon on the top right cornet of the terminal
The obstacles won't move as they are supposed to (that broke when i decided to use vectors to create several levels) but i will be fixing it soon
If you have any notes or comments please let me know.

How to run:
Please make sure to download
1- The SFML library (the right one that matches your compiler)
2- MinGW (not sure if you need this)
3- CMake (cmake-gui)
4- Any IDE (codeBlocks is preferred)


HelpFul links to set upo sfml:

https://www.youtube.com/watch?v=fcZFaiGFIMA

https://www.youtube.com/watch?v=DZigLFdSGeY&list=LL&index=9&t=4s

or simply search how to set up sfml w code blocks


