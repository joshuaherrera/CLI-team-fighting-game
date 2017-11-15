/**********************************************************************************
** Program name: Creatures.hpp
** Author name: Joshua Herrera
** Date: 05/14/2017
** Description: This class contains the member variables and the prototypes for
** Creature.cpp
**********************************************************************************/

#ifndef CREATURES_HPP
#define CREATURES_HPP

#include <string>
#include <iostream>
#include "Die.hpp"

class Creature
{
protected:
  int armor = 0,
    strength = 0,
    //attack die
    dieSidesA = 0,
    //defend die
    dieSidesD = 0;
  Die* dieAtt = NULL;
  Die* dieDef = NULL;


public:
  //default constructor
  Creature();
  Creature(int armor, int strength, int attSides, int defSides);
  int getStr();
  void setStr(int);
  int getArm();
  void restoreDmg(int);
  virtual void setName(std::string) = 0;
  virtual std::string getName() = 0;
  virtual std::string getType() = 0;
  virtual int attack();
  virtual int defend(int);
  //had int int, but could just have single int which is output of def fcn
  virtual void damage(int) = 0;
  virtual ~Creature();
};

/**************************************************************************
** Beginning of derived header classes
**************************************************************************/
class Barbarian : public Creature
{
public:
    Barbarian();
    Barbarian(int, int, int, int);
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual void damage(int);
private:
    std::string type = "Barbarian",
                name;
};

class Bluemen : public Creature
{
public:
    Bluemen();
    Bluemen(int, int, int, int);
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual int defend(int);
    virtual void damage(int);
private:
    std::string type = "Blue Men",
                name;
};

class HarryPotter : public Creature
{
public:
    HarryPotter();
    HarryPotter(int, int, int, int);
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual void damage(int);
private:
    bool revived = false;
    std::string type = "Harry Potter",
                name;
};

class Medusa : public Creature
{
public:
    Medusa();
    Medusa(int, int, int, int);
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual int attack();
    virtual int defend(int);
    virtual void damage(int);
private:
    std::string type = "Medusa",
                name;
};

class Vampire : public Creature
{
public:
    Vampire();
    Vampire(int, int, int, int);
    virtual std::string getName();
    virtual void setName(std::string);
    virtual std::string getType();
    virtual int attack();
    virtual int defend(int);
    virtual void damage(int);
private:
    std::string type = "Vampire",
                name;
};
/**********************************************************************
** End of derived classes
**********************************************************************/
#endif // CREATURES_HPP