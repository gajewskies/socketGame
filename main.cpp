/***************************************************************************
 * main.cpp
 *
 * DESCRIPTION:
 *  This is the main entry point for the game.
 *
 * NOTES:
 *
 * REFERENCES:
 *
 * TODO:
 *
 * CHANGELOG:
 * DATE-------------AUTHOR--------------REASON
 * 07/24/16			TBG					Original Release
 * 07/24/16         TBG                 Convert enum to struct for attack
 * 										power
 ***************************************************************************/


/* Standard library */
#include <iostream>

/* Local headers */
#include "common/character.h"
#include "common/characterList.h"

int main(void)
{
	/* Get the instance to the characterList object */
	characterList *charListPtr = characterList::getInstance();

	/* Create a new character named Tyler */
	character *tyler = new character("Tyler", ORC, SHAMAN);

	/* Add Tyler to the list */
	charListPtr->add(tyler, "Tyler");

	/* Initialize Tyler */
	tyler->init();

	/* Create a new character name Chris */
	character *chris = new character("Chris", TROLL, WARRIOR);

	/* Add Chris to the list */
	charListPtr->add(chris, "Chris");

	/* Initialize Chris */
	chris->init();

	/* show all characters */
	charListPtr->showCharacters();

	/* show Tylers spells */
	tyler->showSpells();

	/* Show tyles stats */
	tyler->showStats();

	/* Show chris's spells */
	chris->showSpells();

	/* show chris stats */
	chris->showStats();

	/* Enter game loop */
	while (true)
	{
		/* Check is tyler is alive */
		tyler->checkKill();

		/* check if chris is alive */
		chris->checkKill();

		/* Tyler attack chris will ATTACK */
		tyler->attack(charListPtr->select("Tyler"),
				      tyler->characterSpells[1].spellAttackPower);

	} /* END while */

	/* Delete chris pointer */
	delete tyler;

	/* Delete tyler pointer */
	delete chris;

	return 0;
} /* END main */
