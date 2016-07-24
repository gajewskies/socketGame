/***************************************************************************
 * character.cpp
 *
 * DESCRIPTION:
 *  This class will handle the creation of a new character.
 *  The character is created with the call to the constructor.
 *  Then the character is setup with the call to init
 *
 * REFERENCES:
 *  implementation, references in in the header.
 *
 * TODO:
 *
 * CHANGELOG:
 * DATE-------------AUTHOR--------------REASON
 * 07/24/16			TBG					Original Release
 * 07/24/16         TBG                 Convert enum to struct for attack
 * 										power
 ***************************************************************************/

/* standard headers */
#include <iostream>
#include <cstdlib>

/* Local headers */
#include "character.h"

character::character(std::string argName,
                     m_race argRace,
                     m_class argClass)
                     : characterStats (argName,
                                       1,
                                       100,
                                       argRace,
                                       argClass)
{
	characterSpells = new characterSpellsStruct[3];

	std::cout << "Character " << getName() << " created" << std::endl;
	std::cout << "[*] Base traits [*]" << std::endl;
	std::cout << "Level " << getLevel() << std::endl;
	std::cout << "Health " << getHealth() << std::endl;
	std::cout << "Race " << raceToString(getRace()) << std::endl;
	std::cout << "Class " << classToString(getClass()) << std::endl;
} /* END character */

character::~character(void)
{
  std::cout << "Character " << getName() << " Killed" << std::endl;
} /* END ~character */

/* This initialize the character */
void character::init(void)
{
    std::cout << "Initializing " << getName() << std::endl;

    switch(getClass())
    {
    	case SHAMAN:
   		    characterSpells[0].spell = ATTACK;
   		    characterSpells[1].spell = FIRE_WEAPON;
   		    characterSpells[2].spell = REJUVINATE;

   		    setHealth(SHAMAN_HEALTH);
   		    break;
   	   case WARRIOR:
   		   characterSpells[0].spell = ATTACK;
   		   characterSpells[1].spell = WHIRL_WIND;
   		   characterSpells[2].spell = SHOUT;

   		   setHealth(WARRIOR_HEALTH);
   		   break;
   	   case WARLOCK:
   		   characterSpells[0].spell = ATTACK;
   		   characterSpells[1].spell = SHADOW_BOLT;
   		   characterSpells[2].spell = CURSE;

   		   setHealth(WARLOCK_HEALTH);
   		   break;
   	   case PRIEST:
   		   characterSpells[0].spell = ATTACK;
   		   characterSpells[1].spell = SMITE;
   		   characterSpells[2].spell = HEAL;

   		   setHealth(PRIEST_HEALTH);
   		   break;
   	   case ROUGUE:
   		   characterSpells[0].spell = ATTACK;
   		   characterSpells[1].spell = BACK_STAB;
   		   characterSpells[2].spell = SLICE;

   		   setHealth(ROUGUE_HEALTH);
   		   break;
  } /* END getClass */

  switch (getRace())
  {
    case HUMAN:
      break;
    case ORC:
      break;
    case TROLL:
      break;
    case UNDEAD:
      break;
  } /* END getRace */
} /* END init */

/* This will return the characters name */
std::string character::getName(void)
{ return characterStats.characterName; } /* END getName */

/* This will return the characters level */
int character::getLevel(void)
{ return characterStats.characterLevel; } /* END getLevel */

/* This will return the characters health */
int character::getHealth(void)
{ return characterStats.characterHealth; } /* END getHealth */

/* This will return the characters race */
m_race character::getRace(void)
{ return characterStats.characterRace; } /* END getRace */

/* This will retur	n the characters class */
m_class character::getClass(void)
{ return characterStats.characterClass; } /* END getClass */

std::string character::classToString(m_class argClass)
{
	std::string returnValue = "NONE";

  switch (argClass)
  {
    case WARRIOR:
      returnValue =  "WARRIOR";
      	  break;
    case WARLOCK:
    	returnValue =  "WARLOCK";
    	break;
    case SHAMAN:
    	returnValue =  "SHAMAN";
    	break;
    case PRIEST:
    	returnValue =  "PRIEST";
    	break;
    case ROUGUE:
    	returnValue =  "ROUGUE";
    	break;
  } /* END switch */
  return returnValue;
} /* END classToString */

std::string character::raceToString(m_race argRace)
{
	std::string returnValue = "NONE";
    switch (argRace)
    {
      case HUMAN:
    	  returnValue =  "HUMAN";
    	  break;
      case ORC:
    	  returnValue =  "ORC";
    	  break;
      case TROLL:
    	  returnValue =  "TROLL";
    	  break;
      case UNDEAD:
    	  returnValue =  "UNDEAD";
    	  break;
    } /* END switch */
    return returnValue;
} /* END raceToString */

std::string character::spellToString(spells argSpell)
{
	std::string returnValue = "NONE";
	switch(argSpell)
	{
    	case ATTACK:
    		returnValue =  "ATTACK";
    		break;
		case WHIRL_WIND:
			returnValue =  "WHIRL_WIND";
			break;
		case SHOUT:
			returnValue =  "SHOUT";
			break;
		case SHADOW_BOLT:
			returnValue =  "SHADOW_BOLT";
			break;
		case CURSE:
			returnValue = "CURSE";
			break;
		case FIRE_WEAPON:
			returnValue =  "FIRE_WEAPON";
			break;
		case REJUVINATE:
			returnValue =  "REJUVINATE";
			break;
		case HEAL:
			returnValue =  "HEAL";
			break;
		case SMITE:
			returnValue =  "SMITE";
			break;
		case BACK_STAB:
			returnValue =  "BACK_STAB";
			break;
		case SLICE:
			returnValue =  "SLICE";
			break;
	} /* END switch */
	return returnValue;
} /* END spellToString */

void character::showSpells(void)
{
    for (int i = 0; i < 3; i++)
    {
      std::cout << characterSpells[i].spell << std::endl;
    } /* END for */
} /* END showSpells */

void character::showStats(void)
{
  std::cout << "Name " << getName() << std::endl;
  std::cout << "Level " << getLevel() << std::endl;
  std::cout << "Health " << getHealth() << std::endl;
  std::cout << "Race " << raceToString(getRace()) << std::endl;
  std::cout << "Class " << classToString(getClass()) << std::endl;
} /* END showStats */

void character::setHealth(int argHealth)
{ characterStats.characterHealth = argHealth; } /* END setHealth */

/* This will be used to take damage from an attack */
void character::damage(int argDamage)
{
  characterStats.characterHealth -= argDamage;
} /* END damage */

void character::attack(character *argEnemy, int argSpellDamage)
{
  argEnemy->damage(argSpellDamage);
} /* END attack */

/* This will check to see if it should kill the character */
void character::checkKill(void)
{
  if (getHealth() <= 0)
  {
    setHealth(0);
    std::cout << "Character " << getName() << " Killed" << std::endl;
    exit(1);
  } /* END getHealth */
} /* END chackKill */
