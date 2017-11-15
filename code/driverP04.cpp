/**********************************************************************************
** Program name: driverP04
** Author name: Joshua Herrera
** Date: 05/14/2017
** Description: This class makes the menu that allows the user to choose two teams to fight.
**********************************************************************************/

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Creatures.hpp"
#include "Menu.hpp"
#include "utilities.hpp"
#include "FtrList.hpp"

int main()
{




    
    int mainChoice = 0;
    //creature values

    //Creature* p2 = new Barbarian(BARB_ARM, BARB_STR, BARB_ATT, BARB_DEF);
    //tempFtr->setName("Vamp");
    //p2->setName("Conan");
    unsigned seed = time(0);
    srand(seed);
    //std::cout << "testing...\n";
    FtrList team1;
    FtrList team2;
    FtrList losers;
    
    Menu main("Fight");
    main.addEntry("Select teams");
    main.addEntry("Display losers");
    main.addEntry("Exit");
    
    std::cout << "\n\nThis is a text based fighting game. The user selects two teams of creatures to fight,\n"
              << "and they fight until one team has no fighters left.\n";

    do
    {
        main.display();
        mainChoice = getUserInt(1, main.sizeOf());

        switch (mainChoice)
        {
            //fight, then display losers
            case 1:
            {
              
                clearScreen();
                //check to see if either of our pointers point to NULL
                if (team1.isEmpty() || team2.isEmpty())
                {
                    std::cout << "Error. One or more teams have not been chosen.\n";
                }
                //half the time first player attacks first
                else if (rand() % 2 + 1 == 1)
                {
                    std::cout << team1.getTeamName() << " attacks first!\n";
                    team1.tournFight(team2, losers);
                    std::cout << "\n\nChoose new characters and play again?\n";
                }
                //other half second player does
                else
                {
                    std::cout << team2.getTeamName() << " attacks first!\n";
                    team2.tournFight(team1, losers);
                    std::cout << "\n\nChoose new characters and play again?\n";
                }       
                break;
            }
            //choose teams
/*******************************************************************************************************************/
            case 2:
            {
                //clearScreen();
                int subChoice = 0;
                int numFtrs = 0;
                const int MIN_FIGHTERS = 1, 
                          MAX_FIGHTERS = 20;
                Menu sub("Choose number of fighters per team");
                sub.addEntry("Choose teams");
                sub.addEntry("Back to main menu");

                do
                {
                    sub.display();
                    subChoice = getUserInt(1, sub.sizeOf());

                    switch (subChoice)
                    {
                        //choose number of fighter
                        case 1:
                        {
                            clearScreen();
                            std::cout << "\n\nEnter the number of fighters per team, between " << MIN_FIGHTERS << " and " << MAX_FIGHTERS << '\n';
                            numFtrs = getUserInt(MIN_FIGHTERS, MAX_FIGHTERS);
                            break;
                        }
                        //Choose teams
                        case 2:
                        {
                            team1.resetTeams();
                            team2.resetTeams();
                            losers.resetTeams();
                            if (numFtrs == 0)
                            {
                              std::cout << "\n\nPlease select the number of fighters.\n";
                            }
                            else
                            {
                                clearScreen();
                                int teamChoice = 0;
                                Menu subTeam("Fighters for team 1");
                                subTeam.addEntry("Fighters for team 2");
                                subTeam.addEntry("Back to options");                            
                                do
                                {
                                    subTeam.display();
                                    teamChoice = getUserInt(1, subTeam.sizeOf());
                                    
                                    switch (teamChoice)
                                    {
                                        //team 1
                                        case 1:
                                        {
                                          clearScreen();
                                            team1.selectTeams(numFtrs);
                                            break;
                                        }
                                        //team 2
                                        case 2:
                                        {
                                            clearScreen();
                                            team2.selectTeams(numFtrs);
                                            break;
                                        }
                                        //Exit
                                        case 3:
                                        {
                                            break;
                                        }
                                    }
                                } while (teamChoice != subTeam.sizeOf());
                                break;
                            }
                        }
                        //exit
                        case 3:
                        {
                            clearScreen();
                            break;
                        }
                    }
                } while (subChoice != 3);
                break;
            }
            //display losers
            case 3:
            {
                if (losers.isEmpty())
                {
                    std::cout << "No losers to display.\n";
                }
                else
                {
                    losers.display();
                }
                break;
            }
            //exit game
            case 4:
            {
                std::cout << "Exitting...\n";
                break;
            }

        }
    } while (mainChoice != 4);
  
    std::cout << "Exit successful. Thanks for playing.\n";

    return 0;
    
}