/*********************************************************************
** Program name:Menu.hpp
** Author:Joshua Herrera
** Date:04/15/2017
** Description: The menu header contains the vector that stores the 
** menu options as well as prototypes for the menu function.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

class Menu
{
private:
	std::vector<std::string> options;

public:
	Menu(std::string);
	void addEntry(std::string);
	void display();
	int sizeOf();
	int getChoice();
};


#endif // MENU_HPP
