/*********************************************************************
** Program name:FtrList.cpp
** Author:Joshua Herrera
** Date:05/17/2017
** Description: FtrList contains the code to make a double linked list
** for the teams and loser container. It also contains the code to
** select the teams and play the tournament
*********************************************************************/

#include <iostream>
#include "FtrList.hpp"
#include "utilities.hpp"
#include "Menu.hpp"

/********************************************************************************************
** constructor
** sets head and tail to null
*********************************************************************************************/
FtrList::FtrList()
{
  head = NULL;
  tail = NULL;
}
/********************************************************************************************
** deconstructor
** deletes the head and tail as well as the next and previous pointers.
*********************************************************************************************/
FtrList::~FtrList()
{
 // std::cout << "\n\n\nInside Destructor !!!\n\n\n";
  ListNode* nodeH = head;
  while(nodeH)
  {
      //std::cout << "\n\n\nInside Destructor loop !!!\n\n\n";

      ListNode* garbageH = nodeH;
      Creature* temp = garbageH->fighter;
      nodeH = nodeH->next;
      delete temp;
      delete garbageH;
      temp = NULL;
      garbageH = NULL;
  }
}
/********************************************************************************************
** headAdd
** adds an int to the head of the linked list. first checks if the pointer is null, if it is
** we add the value there. else we add it to the head
*********************************************************************************************/
//USE WITH LOSER STACK
void FtrList::headAdd(Creature* crtPtr)
{
  if (isEmpty())
  {
    //std::cout << "ADDING TO HEAD WHEN EMPTY\n";

    head = new ListNode(crtPtr);
    tail = head;
  }
  else
  {
    //std::cout << "ADDING TO HEAD\n";
    //since we want to add to front, we need to copy the head pointer
    //and add a previous to the new value, and
    ListNode *nodePtr = head;
    //make a new node that is before the old head
    nodePtr->previous = new ListNode(crtPtr);
    //this new node is now the head
    head = nodePtr->previous;
    //the new head connects to the old head.    
    head->next = nodePtr;
  }
 display();
}
/********************************************************************************************
** tailAdd
** adds an int to the tail of the linked list. first checks if the pointer is null, if it is
** we add the value there. else we add it to the tail
*********************************************************************************************/
//USE WITH SET TEAMS
void FtrList::tailAdd(Creature* crtPtr)
{
  if (isEmpty())
  {
    //std::cout << teamName << "ADDING TO TAIL WHEN EMPTY\n";

    head = new ListNode(crtPtr);
    tail = head;
  }
  else
  {
    //std::cout << teamName << "ADDING TO TAIL\n";

    ListNode* nodePtr = tail;
    nodePtr->next = new ListNode(crtPtr);
    tail = nodePtr->next;
    tail->previous = nodePtr;
  }
 display();
}
/********************************************************************************************
** headRemove
** removes the head value from the linked list. it first checks if it is empty, then if it is just 
** one value, and lastly if more than one.
*********************************************************************************************/
//MODIFY TO RETURN THE POINTER TO BE MOVED? TO LOSER?
//MAKE ANOTHER TO MOVE TO END OF LIST?
void FtrList::headRemove()
{
  if (isEmpty())
  {
    std::cout << "Error. No items in list.\n";
    return;
  }
  //if just one item set head and tail to null
  
  else if (!head->previous && !head->next)
  {
    //std::cout << teamName << "SETTING ONLY OBJECT TO NULL\n";
    ListNode* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
  }

  //just delete the head
  else
  {
   // std::cout << teamName << "REMOVING HEAD\n";
    ListNode* tempHead = head;
    head = tempHead->next;
    delete tempHead;
    head->previous = NULL;
    tempHead = NULL;
  }
  display();
}

/********************************************************************************************
** display
** displays the linked list if it is not empty. It does this by looping through the loop using the 
** next pointer
*********************************************************************************************/
//MODIFY TO DISPLAY CREATURE TYPE AND NAME
void FtrList::display() const
{
  if (isEmpty())
  {
    std::cout << "Error. No items in " << teamName << "'s linked list.\n";
  }
  else
  {
    ListNode* copy = head;
    std::cout << teamName <<"'s linked list: ";
    //std::cout << getTeamName() <<"currently consists of: ";

    while(copy)
    {
        std::cout << copy->fighter->getName() << " of Creature type " << copy->fighter->getType() << '\n';
        copy = copy->next;
    }
  }
}
/********************************************************************************************
** isEmpty
** checks if the list is empty
*********************************************************************************************/
bool FtrList::isEmpty() const
{
    //if the pointer is null it is empty
    if (!head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**********************************************************************************************
** selectTeams
** selects the teams in the tournament of Creatures. Takes the address of a FtrList object, and an int
** returns nothing
**********************************************************************************************/
void FtrList::selectTeams(int max)
{
    const int VAMP_ATT = 12, VAMP_DEF = 6, VAMP_ARM = 1, VAMP_STR = 18,
              BARB_ATT = 6, BARB_DEF = 6, BARB_ARM = 0, BARB_STR = 12,
              BLUE_ATT = 10, BLUE_DEF = 6, BLUE_ARM = 3, BLUE_STR = 12,
              MDSA_ATT = 6, MDSA_DEF = 6, MDSA_ARM = 3, MDSA_STR = 8,
              POTR_ATT = 6, POTR_DEF = 6, POTR_ARM = 0, POTR_STR = 10;
    Menu ftr1("Vampire");
    ftr1.addEntry("Barbarian");
    ftr1.addEntry("Blue Men");
    ftr1.addEntry("Medusa");
    ftr1.addEntry("Harry Potter");
    Creature* tempFtr = NULL;
    //set team name
    std::cout << "\n\nWhat is your team name?\n";
    teamName = getUserString();
    clearScreen();
    std::cout << "The team name is: " << teamName;
    
    for(int i = 1; i <= max; i++)
    {
      std::cout << "Please select the character for position " << i << "\n\n";
      ftr1.display();
      int ft1Choice = getUserInt(1, ftr1.sizeOf());
      switch (ft1Choice)
      {
        //vamp use tail add to add each mo3nster
        case 1:
        {
          clearScreen();
          tempFtr = new Vampire(VAMP_ARM, VAMP_STR, VAMP_ATT, VAMP_DEF);
          std::cout << "\nPlease enter a name for the creature: ";
          std::string ftrName = getUserString();
          tempFtr->setName(ftrName);
          std::cout << "Fighter " << i << ": Vampire\n";
          this->tailAdd(tempFtr);
          tempFtr = NULL;
          break;
        }
        //bar
        case 2:
        {
          clearScreen();
          //check

          tempFtr = new Barbarian(BARB_ARM, BARB_STR, BARB_ATT, BARB_DEF);
          std::cout << "Please enter a name for the creature: ";
          std::string ftrName = getUserString();
          tempFtr->setName(ftrName);
          std::cout << "Fighter " << i << ": Barbarian\n";
          this->tailAdd(tempFtr);
          tempFtr = NULL;
          break;
        }
        //blue
        case 3:
        {
          clearScreen();

          tempFtr = new Bluemen(BLUE_ARM, BLUE_STR, BLUE_ATT, BLUE_DEF);
          std::cout << "Please enter a name for the creature: ";
          std::string ftrName = getUserString();
          tempFtr->setName(ftrName);
          std::cout << "Fighter " << i << ": Blue Men\n";
          this->tailAdd(tempFtr);
          tempFtr = NULL;
          break;
        }
          //medusa
          case 4:
          {
            clearScreen();

            tempFtr = new Medusa(MDSA_ARM, MDSA_STR, MDSA_ATT, MDSA_DEF);
            std::cout << "Please enter a name for the creature: ";
            std::string ftrName = getUserString();
            tempFtr->setName(ftrName);
            std::cout << "Fighter " << i << ": Medusa\n";
            this->tailAdd(tempFtr);
            tempFtr = NULL;
            break;
          }
          //haryy potter
          case 5:
          {
            clearScreen();

            tempFtr = new HarryPotter(POTR_ARM, POTR_STR, POTR_ATT, POTR_DEF);
            std::cout << "Please enter a name for the creature: ";
            std::string ftrName = getUserString();
            tempFtr->setName(ftrName);
            std::cout << "Fighter " << i << ": Harry Potter\n";
            this->tailAdd(tempFtr);
            tempFtr = NULL;
            break;
          }

      }
    }

    delete tempFtr;
}

/********************************************************************************************
** getFtr
** returns a Creature pointer and takes no arguments. returns the fighter at the head
*********************************************************************************************/
Creature* FtrList::getFtr()
{
  return head->fighter;
}
/********************************************************************************************
** getTeamName
** returns a string that represents the team name
*********************************************************************************************/
std::string FtrList::getTeamName()
{
  return teamName;
}
/********************************************************************************************
** moveBack
** this takes no arguments and returns nothing. It is used to move the head of a list to the
** back.
*********************************************************************************************/
void FtrList::moveBack()
{
  if (isEmpty())
  {
    std::cout << "Error. List is empty.\n";
    return;
  }
  else if (!head->next && !head->previous)
  {
    //list of one item, dont do anything.
  }
  else
  {
   // std::cout << "Only when more than one item in list\n";
    ListNode* copy = head;
    head = head->next;
    tail->next = copy;
    copy->previous = tail;
    copy->next = NULL;
    tail = copy;
  }
  display();
}
/********************************************************************************************
** tournFight
** This function takes as a parameter references to 2 FtrList objects and returns nothing. 
** It is used to run the tournament
*********************************************************************************************/
void FtrList::tournFight(FtrList& opponent, FtrList& loserPile)
{  
  int counter = 1,
      tm1Pts = 0,
      tm2Pts = 0;
  //points for game
  const int WIN = 2,
            LOSE = -1;
  //for use in tournament
  Creature* p1 = NULL;
  Creature* p2 = NULL;
  //as long as both team have players
  while(isEmpty() == false && opponent.isEmpty() == false)
  {
      p1 = getFtr();
      //std::cout << p1->getName();
      p2 = opponent.getFtr();
      //two creatures fight
      std::string winner = fight(p1, p2);
      if (winner == p1->getName())
      {
        std::cout << "\n\n" << getTeamName() << " have won round " << counter << '\n';
        tm1Pts += WIN;
        tm2Pts += LOSE;
        std::cout << "\n\nScores for:\n" << getTeamName() << ": " << tm1Pts
                  << "\n\n" << opponent.getTeamName() << ": " << tm2Pts;
        //winner gets put back in line
        moveBack();
        //move loser to other list
        loserPile.headAdd(p2);
        opponent.headRemove();
      }
      else if (winner == p2->getName())
      {
        std::cout << "\n\n" << opponent.getTeamName() << " have won round " << counter << '\n';
        tm1Pts += LOSE;
        tm2Pts += WIN;
        std::cout << "\n\nScores for:\n" << getTeamName() << ": " << tm1Pts
                  << "\n\n" << opponent.getTeamName() << ": " << tm2Pts << "\n\n\n";
        opponent.moveBack();
        //move loser to other list
        loserPile.headAdd(p1);
        headRemove();        
      }
      counter++;
      //reset pointers for next iteration
      p1 = NULL;
      p2 = NULL;
  }
  std::cout << "\n\nTournament results:\n" << getTeamName() << ": " << tm1Pts << '\n'
            << opponent.getTeamName() << ": " << tm2Pts << '\n';
  if (tm1Pts > tm2Pts)
  {
    std::cout << "\n\nThe winner is " << getTeamName() << "!\n\n";
  }
  else if (tm2Pts > tm1Pts)
  {
    std::cout << "\n\nThe winner is " << opponent.getTeamName() << "!\n\n";
  }
  //left here for debugging purposes.
  else
  {
    std::cout << "\n\nEither an error or tie game, most like an error\n\n";
  }
  //temp pointers no longer needed
  delete p1;
  delete p2;
}
/********************************************************************************************
** resetTeams
** takes no arguments and returns nothing
** it is used to 
*********************************************************************************************/
void FtrList::resetTeams()
{
  ListNode* nodeH = head;
  while(nodeH)
  {
      ListNode* garbageH = nodeH;
      Creature* temp = garbageH->fighter;
      nodeH = nodeH->next;
      delete temp;
      delete garbageH;
      temp = NULL;
      garbageH = NULL;
  }
  head = NULL;
}