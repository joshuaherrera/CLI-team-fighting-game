/*********************************************************************
** Program name:Die.cpp
** Author:Joshua Herrera
** Date:04/23/2017
** Description: The Die.cpp file contains the functions used in the Die
** class that is used to make our die for the game. 
*********************************************************************/

#include "Die.hpp"

/*************************************************************
** Die constructor (default)
** This function neither returns nor takes any arguments.
** it should never be used. and is only here as a safeguard. 
*************************************************************/
Die::Die()
{
    //should never use this case
    numSides = -1;
}

/*************************************************************
** Die constructor
** This function takes in an integer as its argument and does
** not return anything. It uses the function setNumSides to set
** the number of sides for the die. 
*************************************************************/
Die::Die(int diceSides)
{
    setNumSides(diceSides);
}

/*************************************************************
** roll
** This function takes no arguments and returns an integer, 
** specifically, it returns a random number between 1 and the
** number of sides of the die. 
*************************************************************/
int Die::roll()
{

    return rand() % numSides + 1;
}

/*************************************************************
**setNumSides
** returns nothing and takes an int which is set to the number
** of sides of the die.
*************************************************************/
void Die::setNumSides(int diceSides)
{
    numSides = diceSides;
}

/*************************************************************
** getNumSides
** takes no arguments and returns the number of sides of the die
** (an int)
*************************************************************/
int Die::getNumSides()
{
    return numSides;
}
