/**********************************************************************************
** Program name: Creatures.cpp
** Author name: Joshua Herrera
** Date: 05/14/2017
** Description: This class contains the functions to be used in the abstract
** class Creatures.hpp
**********************************************************************************/

#include "Creatures.hpp" 

/**********************************************************************************
** default constructor
** default constructor does nothing
**********************************************************************************/
Creature::Creature()
{
}
/**********************************************************************************
** constructor
** takes int arguments for the armor, strength, attack die sides, and defend die sides
** and makes the die. returns nothing.
**********************************************************************************/
Creature::Creature(int a, int s, int dA, int dF)
{
    armor = a;
    strength = s;
    dieSidesA = dA;
    dieSidesD = dF;
    dieAtt = new Die(dieSidesA);
    dieDef = new Die(dieSidesD);
}

/**********************************************************************************
** attack
** roll the die twice to attack and returns that value. since most creatures roll twice
** this is default
**********************************************************************************/
int Creature::attack()
{
    int temp = dieAtt->roll();
    temp += dieAtt->roll();
    return temp;
}

/**********************************************************************************
** defend
** rolls die twice since most creatures roll twice and returns int as defend value
**********************************************************************************/
int Creature::defend(int att)
{
    int defRoll = dieDef->roll();
    defRoll += dieDef->roll();
    //what if the attack is smaller than the defense? we should return 0.
    std::cout << "The defense is " << defRoll << '\n';
    if (defRoll >= att)
    {  
        return 0;
    }
    else
    {
        return att - defRoll;
    }
}
/**********************************************************************************
** setStr
** return strength value
**********************************************************************************/
void Creature::setStr(int temp)
{
    strength += temp;
}
/**********************************************************************************
** getStr
** return strength value
**********************************************************************************/
int Creature::getStr()
{
    return strength;
}
/**********************************************************************************
** restoreDmg
** gets a random number between 1 and the damage given, and depending on that number,
** recover that amount of damage points.
**********************************************************************************/
void Creature::restoreDmg(int dmg)
{
  if (dmg > 0)
  {
    std::cout << "Restoring some of the damage taken...\n";
    int roll = rand() % dmg + 1;
    int restored = dmg / roll;
    setStr(restored);
    std::cout << restored << " damage points have been restored.\n";
  }

}
/**********************************************************************************
** getArm
** returns armor val
**********************************************************************************/
int Creature::getArm()
{
    return armor;
}
/**********************************************************************************
** deconstructor
** frees the memory allocated to the die
**********************************************************************************/
Creature::~Creature()
{
    delete dieAtt;
    delete dieDef;
}

//
//Barbarian
//MAKE GET TYPE FOR ALL CREATURES
//

/**********************************************************************************
** default constructor
** default constructor does nothing
**********************************************************************************/
Barbarian::Barbarian()
{
}
/**********************************************************************************
** constructor
** takes values to set to the armor, strength, attack die sides, defend die sides
** using creature constructor
**********************************************************************************/
Barbarian::Barbarian(int a, int s, int dA, int dF) : Creature(a, s, dA, dF)
{
}
/**********************************************************************************
** setName
** sets the name 
**********************************************************************************/
void Barbarian::setName(std::string temp)
{
    name = temp;
}
/**********************************************************************************
** getName
** returns the name
**********************************************************************************/
std::string Barbarian::getName()
{
    return name;
}
/**********************************************************************************
** getType
** returns the type
**********************************************************************************/
std::string Barbarian::getType()
{
    return type;
}
/**********************************************************************************
** damage
** this class displays the creatures armor before the attack and after. it takes 
** in the damage to be given to the creature and subtracts the armor to find
** what will ultimately be dealt to creature.
**********************************************************************************/
void Barbarian::damage(int dmg)
{
    //when armor is more than the damage from the def fcn, no dmg done
    std::cout << this->getName() <<"'s armor is " << armor << " before the attack\n";
    if (armor >= dmg)
    {
        //since dmg is smaller than armor, the creature uses that many 
        //armor points to nullify the attack. 
        //e.g. if dmg is 2 and armor is 3, 2 armor points are used to absorb
        //the potential damage, leaving one armor point left
        armor -= dmg;
        //the damage is nullified, represented as a zero.
        dmg = 0;
        //left this in for consistency's sake
        strength -= dmg;
    }
    //the armor points are less then the dmg, all armor points are used.
    else
    {
        //all the armor points are used
        dmg -= armor;
        std::cout << "After using armor, the damage to " << this->getName() << "'s strength points is " << dmg << '\n';
        armor = 0;
        strength -= dmg;
        if (strength <= 0)
        {
            strength = 0;
        }
    }
    std::cout << this->getName() <<"'s armor is " << armor << " after the attack\n";
}

//
//Bluemen
//

/**********************************************************************************
** default constructor
** default constructor does nothing
**********************************************************************************/
Bluemen::Bluemen()
{
}
/**********************************************************************************
** constructor
** takes values to set to the armor, strength, attack die sides, defend die sides
** using creature constructor
**********************************************************************************/
Bluemen::Bluemen(int a, int s, int dA, int dF) : Creature(a, s, dA, dF)
{
}
/**********************************************************************************
** setName
** sets the name for the bluemen
**********************************************************************************/
void Bluemen::setName(std::string temp)
{
    name = temp;
}
/**********************************************************************************
** getName
** returns the name
**********************************************************************************/
std::string Bluemen::getName()
{
    return name;
}
/**********************************************************************************
** getType
** returns the type
**********************************************************************************/
std::string Bluemen::getType()
{
    return type;
}
/**********************************************************************************
** defend
** this class returns and int and takes an int. It rolls the defend die at least once,
** depending on the strength of the bluemen. if the str is b/w 5-8 it rolls a second time
** and b/w 9-12 a third time. 
**********************************************************************************/
int Bluemen::defend(int att)
{
    //no matter the strength, each iteration of bluemen is guaranteed one roll
    int defRoll = dieDef->roll();
    //the next two conditionals simulate the losing of a die
    //the first conditional is only true whenever the strength is bigger or equal
    //to 5, so a second roll is allowed. The second conditional ensures that when 
    //the strength is between 9 and the max (12) a third roll is used.
    if (strength >= 5)
    {
        defRoll += dieDef->roll();
    }
    if (strength >= 9)
    {
        defRoll += dieDef->roll();
    }
    std::cout << "The defense is " << defRoll << '\n';
    //what if the attack is smaller than the defense? we should return 0.
    if (defRoll >= att)
    {
        return 0;
    }
    else
    {
        return att - defRoll;
    }

}
/**********************************************************************************
** damage
** this class displays the barbarians armor before the attack and after. it takes 
** in the damage to be given to the barbarian and subtracts the armor to find
** what will ultimately be dealt to barbarian.
**********************************************************************************/
void Bluemen::damage(int dmg)
{
    //when armor is more than the damage from the def fcn, no dmg done
    std::cout << this->getName() <<"'s armor is " << armor << " before the attack\n";
    if (armor >= dmg)
    {
        //since dmg is smaller than armor, the creature uses that many 
        //armor points to nullify the attack. 
        //e.g. if dmg is 2 and armor is 3, 2 armor points are used to absorb
        //the potential damage, leaving one armor point left
        armor -= dmg;
        //the damage is nullified, represented as a zero.
        dmg = 0;
        //left this in for consistency's sake
        strength -= dmg;
    }
    //the armor points are less then the dmg, all armor points are used.
    else
    {
        //all the armor points are used
        dmg -= armor;
        std::cout << "After using armor, the damage to " << this->getName() << "'s strength points is " << dmg << '\n';
        armor = 0;
        strength -= dmg;
        if (strength <= 0)
        {
            strength = 0;
        }
    }
    std::cout << this->getName() <<"'s armor is " << armor << " after the attack\n";
}

//
//HarryPotter
//

/**********************************************************************************
** default constructor
** default constructor does nothing
**********************************************************************************/
HarryPotter::HarryPotter()
{
}
/**********************************************************************************
** constructor
** takes values to set to the armor, strength, attack die sides, defend die sides
** using creature constructor
**********************************************************************************/
HarryPotter::HarryPotter(int a, int s, int dA, int dF) : Creature(a, s, dA, dF)
{
}
/**********************************************************************************
** setName
** sets the name 
**********************************************************************************/
void HarryPotter::setName(std::string temp)
{
    name = temp;
}
/**********************************************************************************
** getName
** returns the name
**********************************************************************************/
std::string HarryPotter::getName()
{
    return name;
}
/**********************************************************************************
** getType
** returns the type
**********************************************************************************/
std::string HarryPotter::getType()
{
    return type;
}
/**********************************************************************************
** damage
** this class displays harry's armor before the attack and after. it takes 
** in the damage to be given to the harry and subtracts the armor to find
** what will ultimately be dealt to harry. harry revives if killed.
**********************************************************************************/
void HarryPotter::damage(int dmg)
{
    std::cout << this->getName() <<"'s armor is " << armor << " before the attack\n";
    //when armor is more than the damage from the def fcn, no dmg done
    if (armor >= dmg)
    {
        //since dmg is smaller than armor, the creature uses that many 
        //armor points to nullify the attack. 
        //e.g. if dmg is 2 and armor is 3, 2 armor points are used to absorb
        //the potential damage, leaving one armor point left
        armor -= dmg;
        //the damage is nullified, represented as a zero.
        dmg = 0;
        //left this in for consistency's sake
        strength -= dmg;
    }
    //the armor points are less then the dmg, all armor points are used.
    else
    {
        //all the armor points are used
        dmg -= armor;
        std::cout << "After using armor, the damage to " << this->getName() << "'s strength points is " << dmg << '\n';
        armor = 0;
        strength -= dmg;
        if (strength <= 0)
        {
            if (revived == false)
            {
                revived = true;
                std::cout << this->getName() <<" uses Hogwarts! He is revived with double strength!\n";
                strength = 20;
            }
            else
            {
                strength = 0;
            }
        }
    }
    std::cout << this->getName() <<"'s armor is " << armor << " after the attack\n";
}

//
//Medusa
//

/**********************************************************************************
** default constructor
** default constructor does nothing
**********************************************************************************/
Medusa::Medusa()
{
}
/**********************************************************************************
** constructor
** takes values to set to the armor, strength, attack die sides, defend die sides
** using creature constructor
**********************************************************************************/
Medusa::Medusa(int a, int s, int dA, int dF) : Creature(a, s, dA, dF)
{
}
/**********************************************************************************
** setName
** sets the name 
**********************************************************************************/
void Medusa::setName(std::string temp)
{
    name = temp;
}
/**********************************************************************************
** getName
** returns the name
**********************************************************************************/
std::string Medusa::getName()
{
    return name;
}
/**********************************************************************************
** getType
** returns the type
**********************************************************************************/
std::string Medusa::getType()
{
    return type;
}
/**********************************************************************************
** attack
** rolls the die twice and if the total value is 12 medusa returns an attack of 999
** instantly killing the oponent (turn to stone)
**********************************************************************************/
int Medusa::attack()
{
    int temp = dieAtt->roll();
    temp += dieAtt->roll();
    if (temp == 12)
    {
        std::cout <<this->getName() <<" uses glare! The opponent is turned to stone!\n";
        return 999;
    }
    else
    {
        return temp;
    }
}
/**********************************************************************************
** defend
** rolls the die once to return the dfend value
**********************************************************************************/
int Medusa::defend(int att)
{
    int defRoll = dieDef->roll();
    std::cout << "The defense is " << defRoll << '\n';
    if (defRoll >= att)
    {  
        return 0;
    }
    else
    {
        return att - defRoll;
    }
}
/**********************************************************************************
** damage
** this class displays the barbarians armor before the attack and after. it takes 
** in the damage to be given to the barbarian and subtracts the armor to find
** what will ultimately be dealt to barbarian.
**********************************************************************************/
void Medusa::damage(int dmg)
{
    //when armor is more than the damage from the def fcn, no dmg done
    std::cout << this->getName() <<"'s armor is " << armor << " before the attack\n";
    if (armor >= dmg)
    {
        //since dmg is smaller than armor, the creature uses that many 
        //armor points to nullify the attack. 
        //e.g. if dmg is 2 and armor is 3, 2 armor points are used to absorb
        //the potential damage, leaving one armor point left
        armor -= dmg;
        //the damage is nullified, represented as a zero.
        dmg = 0;
        //left this in for consistency's sake
        strength -= dmg;
    }
    //the armor points are less then the dmg, all armor points are used.
    else
    {
        //all the armor points are used
        dmg -= armor;
        std::cout << "After using armor, the damage to " << this->getName() << "'s strength points is " << dmg << '\n';
        armor = 0;
        strength -= dmg;
        if (strength <= 0)
        {
            strength = 0;
        }
    }
    std::cout << this->getName() <<"'s armor is " << armor << " after the attack\n";
}

//
//Vampire
//

/**********************************************************************************
** default constructor
** default constructor does nothing
**********************************************************************************/
Vampire::Vampire()
{
}
/**********************************************************************************
** constructor
** takes values to set to the armor, strength, attack die sides, defend die sides
** using creature constructor
**********************************************************************************/
Vampire::Vampire(int arm, int str, int dA, int dF) : Creature(arm, str, dA, dF)
{
}
/**********************************************************************************
** getName
** returns the name
**********************************************************************************/
std::string Vampire::getName()
{
    return name;
}

/**********************************************************************************
** setName
** sets the name 
**********************************************************************************/
void Vampire::setName(std::string temp)
{
    name = temp;
}
/**********************************************************************************
** getType
** returns the type
**********************************************************************************/
std::string Vampire::getType()
{
    return type;
}   
/**********************************************************************************
** attack
** rolls the die once to get attack value
**********************************************************************************/
int Vampire::attack()
{
    return dieAtt->roll();
}
/**********************************************************************************
** defned
** rolls die once and half the time the vamp uses charm nullifying opponents attack
**********************************************************************************/
int Vampire::defend(int att)
{
    //half the time the vampire chamrs the attacker into not attacking.
    //In other words, no damage is done to the vampire
    if (rand() % 2 + 1 == 1)
    {
        std::cout << this->getName() <<" uses charm!\n";
        std::cout << "Tje opponent is charmed into not attacking!\n";
        return 0;
    }
    //the other half of the time, defense works as normal
    else
    {
        int defRoll = dieDef->roll();
        std::cout << "The defense is " << defRoll << '\n';
        //what if the attack is smaller than the defense? we should return 0.
        if (defRoll >= att)
        {
            return 0;
        }
        else
        {
            return att - defRoll;
        }
    }
}
/**********************************************************************************
** damage
** this class displays the creatures armor before the attack and after. it takes 
** in the damage to be given to the creature and subtracts the armor to find
** what will ultimately be dealt to creature.
**********************************************************************************/
void Vampire::damage(int dmg)
{
    //when armor is more than the damage from the def fcn, no dmg done
    std::cout << this->getName() <<"'s armor is " << armor << " before the attack\n";
    if (armor >= dmg)
    {
        //since dmg is smaller than armor, the creature uses that many 
        //armor points to nullify the attack. 
        //e.g. if dmg is 2 and armor is 3, 2 armor points are used to absorb
        //the potential damage, leaving one armor point left
        armor -= dmg;
        //the damage is nullified, represented as a zero.
        dmg = 0;
        //left this in for consistency's sake
        strength -= dmg;
    }
    //the armor points are less then the dmg, all armor points are used.
    else
    {
        //all the armor points are used
        dmg -= armor;
        std::cout << "After using armor, the damage to " << this->getName() << "'s strength points is " << dmg << '\n';
        armor = 0;
        strength -= dmg;
        if (strength <= 0)
        {
            strength = 0;
        }
    }
    std::cout << this->getName() <<"'s armor is " << armor << " after the attack\n";
}
