/***************************************************************************
 * character.h
 *
 * DESCRIPTION:
 *  This class will handle the creation of a new character.
 *  The character is created with the call to the constructor.
 *  Then the character is setup with the call to init
 *
 * REFERENCES:
 *  characterList, main
 *
 * TODO:
 *
 * CHANGELOG:
 * DATE-------------AUTHOR--------------REASON
 * 07/24/16			TBG					Original Release
 * 07/24/16         TBG                 Convert enum to struct for attack
 * 										power
 ***************************************************************************/

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

/* Local headers */
#include "spells.h"
#include "stats.h"

class character
{
	public:
		/*
		 * Constructor:
		 * Takes the name of the character, race and class as arguments
         */
    	character(std::string argName,
    			  m_race argRace,
    			  m_class argClass);

    	/* Destructor */
    	~character(void);

		/* This will initialize the character */
		void init(void);

		/* This will return the characters name */
		std::string getName(void);

		/* This will return the characters level */
		int getLevel(void);

		/* This will return the characters health */
		int getHealth(void);

		/* This will return the characters race */
		m_race getRace(void);

		/* This will return	n the characters class */
		m_class getClass(void);

		/* This will show all the spells for the character */
		void showSpells(void);

		/* This will show all the stat's for a character */
		void showStats(void);

		/*
		 * This will be used to take damage from an attack
		 * Takes the damage to apply as an argument.
		 */
		void damage(int argDamage);

		/*
		 * This will convert the race enum to a string
		 * Takes the race as an argument and returns the string conversion
		 */
		std::string raceToString(m_race argRace);

		/*
		 * This will convert the class enum to a string
		 * Takes the class as an argument and returns the string conversion
		 */
		std::string classToString(m_class argClass);

		/*
		 * This will convert the spell enum to a string
		 * Takes the spell as an argument and returns the string conversion
		 */
		std::string spellToString(spells argSpell);

		/*
		 * This will apply argSpell damage to argEnemy health
		 * Takes the enemy character points and spell as arguments
		 */
		void attack(character *argEnemy, int argSpellDamage);

		/* This will check weather the characters health is 0 and will exit if so */
		void checkKill(void);

		/* This is the characters spells */
		struct characterSpellsStruct *characterSpells;

	private:
		/*
		 * This will set the health for the character
		 * Takes the health to apply as the argument
		 */
		void setHealth(int argHealth);

		/* This is the characters stats */
		stats characterStats;
}; /* END character */

#endif /* _CHARACTER_H_ */
