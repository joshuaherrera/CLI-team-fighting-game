/*********************************************************************
** Program name:utilities.cpp
** Author:Joshua Herrera
** Date:04/15/2017
** Description: A collection of various helper functions for CS162.
** Each function has it's own description.
*********************************************************************/
#include "utilities.hpp"
#include <iostream>
#include <string>

/*********************************************************************
**isIntValid
**This code checks if a user's input is an int within a specified range.
**it takes as its arguments a string and the upper and lower bounds of 
**the desired range. It should return either true if it meets specifications
**or false if it does not. 
**********************************************************************/


bool isIntValid(std::string str, int lowerBound, int upperBound)
{
     int placeholder;

     /*loop through the string and check if each char is an
     **integer or not. We also check if the input is negative.
     **We only check if the string with a leading negative sign
     **is larger than 1, otherwise it is not an int.
     */
     if (str[0] == '-' && str.length() > 1)
     {
       while(str[0] == '-')
       {
        //skip the negative sign and check the rest of the
        //string.
        for(unsigned int i = 1; i < str.length(); i++)
        {
          if(isdigit(str.at(i)) == false)
          {
            return false;
          }
        }
           

         /* if it passes the previous loop, it is a negative integer. 
         **Now we change the string to an int.
         */
         placeholder = std::stoi(str);
         
         // check if within range. 
         if(placeholder < lowerBound || placeholder > upperBound)
         {
              return false;
         }

         return true;
         }
      }

     /*When the string does not start with a negative sign, we check
     **starting from the first character.
     */
     else
     {
       for(unsigned int i = 0; i < str.length(); i++)
       {
        if(isdigit(str.at(i)) == false)
        {
          return false;
        }
       }

       /* if it passes the previous loop, it is an integer. 
       **Now we change the string to an int
       */
       placeholder = std::stoi(str);
       
       // check if within range. 
       if(placeholder < lowerBound || placeholder > upperBound)
       {
            return false;
       }
      } 

    return true;      
}

/************************************************************
**getUserInt
**This code prompts the accepts the user input for an integer.
**It stores the int as a string and checks to make sure the
**string is not empty, and then uses the function isIntValid 
**to check if the int is valid. It takes in the upper and lower
**bounds of the desired integer and it returns the integer
**that passes the tests.
*************************************************************/

int getUserInt(int min, int max)
{
     std::string userInput;

     //check to make sure the string is not empty
     do {
          std::getline(std::cin, userInput);
     } while (userInput.empty());

     //if the integer does not follow specifications
     //reprompt user for appropriate int. 
     while(isIntValid(userInput, min, max) == false) 
     {
              do
          {
               std::cout << "Invalid input. Please enter an integer between "
                           << min << " and " << max << std::endl;
               std::getline(std::cin, userInput);
          } while (userInput.empty());
     }
     //if the input is within specifications, convert string to int. 
     return std::stoi(userInput);
}

/********************************************************************************************
** clearScreen function
** (source: http://www.cplusplus.com/articles/4z18T05o/)
** Purpose: "Clears" the console by printing new lines.
** Takes in no arguments and does not return anything.
*********************************************************************************************/
void clearScreen()
{
    std::cout << std::string( 100, '\n' );
}
/********************************************************************************************
** getUserString function
** This code obtains and validates a string. It takes no arguments and returns a string.
** The main purpose is to make sure a nonempty string is input
********************************************************************************************/
std::string getUserString()
{
     std::string userString;

     // loop to ensure non-empty string is input
     do
     {
          std::getline(std::cin, userString);
     } while (userString.empty());

     return userString;
}

/*****************************************************************************************************************
** isDoubleValid
** modified from:http://stackoverflow.com/questions/4271315/c-how-to-check-an-input-float-variable-for-valid-input
** This code returns a bool and takes as input a string, and two double values. The purpose is to check is a user's
** input is a double.
*****************************************************************************************************************/
bool isDoubleValid(std::string input, double lower, double upper)
{
    double placeholder = 0.0;
    //This version does not accept negative numbers
    if( input.find_first_not_of("1234567890.") != std::string::npos )
    {
        return false;
    }
    //if passes loop, it is a double.
    placeholder = std::stod(input);
    if (placeholder < lower || placeholder > upper)
    {
        return false;
    }
    return true;
}

/**********************************************************************************************
** getUserDouble
** This code returns a double and takes as arguments two doubles. It's purpose is to receive
** user input, convert to a string and use the isDoubleValid function to validate and accept
** a double. 
**********************************************************************************************/
double getUserDouble(double min, double max)
{
     std::string userInput;

     //check to make sure the string is not empty
     do {
          std::getline(std::cin, userInput);
     } while (userInput.empty());

     //if the double does not follow specifications
     //reprompt user for appropriate double. 
     while(isDoubleValid(userInput, min, max) == false) 
     {
              do
          {
               std::cout << "Invalid input. Please enter a double between "
                           << min << " and " << max << std::endl;
               std::getline(std::cin, userInput);
          } while (userInput.empty());
     }
     //if the input is within specifications, convert string to double and return. 
     return std::stod(userInput);
}


/**********************************************************************************************
** fight
** This code takes as its arguments two pointers to Creature and compares there attack values
** until one's value gets to zero. returns nothing
**********************************************************************************************/
std::string fight(Creature* first, Creature* second)
{
    int turn = 1;
    int dmgToFirst = 0,
    dmgToSecond = 0;

    while (first->getStr() > 0 && second->getStr() > 0)
    {

        std::cout << "*******************************************************************************\n";
        std::cout << "Turn " << turn << ":\n";
        if (turn % 2 == 1)
        {
            std::cout << first->getName() << " attacks.\n";
            int att = first->attack();
            std::cout << first->getName() << "'s attack value is " << att << '\n';
            int def = second->defend(att);
            std::cout << "After defending, the damage inflicted to " << second->getName() << " is " << def << '\n';
            second->damage(def);
            dmgToSecond += def;
        }
        //the other half of the time, turn is even,
        else
        {
            std::cout << second->getName() << " attacks.\n";
            int att2 = second->attack();
            std::cout << second->getName() << "'s attack value is " << att2 << '\n';
            int def2 = first->defend(att2);
            std::cout << "After defending, the damage inflicted to " << first->getName() << " is " << def2 << '\n';
            first->damage(def2);
            dmgToFirst += def2;
        }
        std::cout << first->getName() << "'s strength points after round " << turn << ": " << first->getStr() << '\n';
        std::cout << second->getName() << "'s strength points after round " << turn << ": " << second->getStr() << '\n';
        std::cout << "*******************************************************************************\n";
        turn++;
    }
    //second attacker won
    if (first->getStr() == 0)
    {
        std::cout << '\n' << first->getName() << " has been defeated. The winner is " << second->getName() << '\n';
        std::cout << second->getName() << " has won with " << second->getArm() << " armor points left,\n"
                  << "and " << second->getStr() << " strength points left.\n";
        second->restoreDmg(dmgToSecond);
        return second->getName();
    }
    //first attacker won
    else if (second->getStr() == 0)
    {
        std::cout << '\n' << second->getName() << " has been defeated. The winner is " << first->getName() << '\n';
        std::cout << first->getName() << " has won with " << first->getArm() << " armor points left,\n"
                  << "and " << first->getStr() << " strength points left.\n";
        first->restoreDmg(dmgToFirst);
        return first->getName();
    }
    return "Error";
}
