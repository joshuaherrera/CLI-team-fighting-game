/*********************************************************************
** Program name:Die.hpp
** Author:Joshua Herrera
** Date:04/23/2017
** Description: The Die header class contains the prototypes for the
** Die class. It also includes member variables. The class abstracts
** away the code that make the regular die. In depth descriptions of the
** functions can be found with the Die.cpp file.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>

class Die
{
private:
	//holds the number of sides per die
    int numSides = 0;
public:
    Die();
    Die(int);
    int roll();
    void setNumSides(int);
    int getNumSides();
};


#endif // DIE_HPP
