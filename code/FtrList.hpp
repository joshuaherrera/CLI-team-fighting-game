/*********************************************************************
** Program name:FtrList.hpp
** Author:Joshua Herrera
** Date:05/28/2017
** Description: The menu header contains the member variabls and prototype
** functions for FtrList.cpp
*********************************************************************/


#ifndef FTR_LIST_HPP
#define FTR_LIST_HPP
#include <iostream>
#include "Creatures.hpp"


class FtrList
{
protected:
  struct ListNode
  {
    Creature* fighter;
    ListNode* next;
    ListNode* previous;
    ListNode(Creature* fighter1, ListNode* next1 = NULL, ListNode* previous1 = NULL)
    {
      fighter = fighter1;
      next = next1;
      previous = previous1;
    }
  };
  ListNode* head;
  ListNode* tail;
  std::string teamName = "Loser";
public:
  FtrList();
  ~FtrList();
  Creature* getFtr();
  std::string getTeamName();
  void headAdd(Creature*);
  void tailAdd(Creature*);
  void headRemove();
  void tailRemove();
  void selectTeams(int);
  void moveBack();
  void resetTeams();
  void tournFight(FtrList&, FtrList&);
  void display() const;
  bool isEmpty() const;

};


#endif // FTR_LIST_HPP
