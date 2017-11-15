/*********************************************************************
** Program name:Menu.cpp
** Author:Joshua Herrera
** Date:04/15/2017
** Description: The menu class will be used throughout CS162 When
** a menu is needed.
*********************************************************************/
#include "Menu.hpp"
#include <iostream>

/********************************************************************************************
** Menu constructor
** This function takes in as a string the first option for the menu. It does not return anything.
*********************************************************************************************/
Menu::Menu(std::string option1)
{
	options.push_back(option1);
}

/********************************************************************************************
** addEntry
** This function takes as an argument a string and appends it to our vector to use in our menu.
** It does not return anything.
*********************************************************************************************/
void Menu::addEntry(std::string otherOption)
{
	options.push_back(otherOption);
}

/********************************************************************************************
** display
** This function displays the menu. It takes in no arguments and returns nothing.
*********************************************************************************************/
void Menu::display()
{
	int optionNumber = 0;
	std::cout << "\n\nPlease choose an option below.\n";
	std::cout << "Enter the integer associated with your desired choice.\n";
	for (unsigned int i = 0; i < options.size(); ++i)
	{
		optionNumber = i + 1;
		std::cout << optionNumber << ". " << options[i] << std::endl;
	}
}

/********************************************************************************************
** sizeOf
** This function returns as an integer the size of the vector. It takes in no arguments.
** It would be used when I need to verify input in main. 
*********************************************************************************************/
int Menu::sizeOf()
{
	return options.size();
}

