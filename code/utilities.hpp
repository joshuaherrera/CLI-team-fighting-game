/*********************************************************************
** Program name:utilities.hpp
** Author:Joshua Herrera
** Date:04/08/2017
** Description: This is the header for the helper functions for 162.
** It contains the prototypes for the helper functions to be used.
*********************************************************************/
#include <string>
#include "Creatures.hpp"

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

bool isIntValid(std::string, int, int);

bool isDoubleValid(std::string, double, double);

int getUserInt(int, int);

double getUserDouble(double, double);

void clearScreen();

std::string getUserString();

std::string fight(Creature*, Creature*);


#endif // UTILITIES_HPP
