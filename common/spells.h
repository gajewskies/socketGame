/***************************************************************************
 * spells.h
 *
 * DESCRIPTION:
 *  This header contains the spells that the character will have access to.
 *
 * NOTES:
*
 * REFERENCES:
 *  character, main
 *
 * TODO:
 *	1. Find a better way to store all the spells.
 *
 * CHANGELOG:
 * DATE-------------AUTHOR--------------REASON
 * 07/24/16			TBG					Original Release
 * 07/24/16         TBG                 Convert enum to struct for attack
 * 										power
 ***************************************************************************/

#ifndef _SPELLS_H_
#define _SPELLS_H_

typedef enum
{
  /* Base */
  ATTACK,

  /* Warrior */
  WHIRL_WIND,
  SHOUT,

  /* Warlock */
  SHADOW_BOLT,
  CURSE,

  /* Shaman */
  FIRE_WEAPON,
  REJUVINATE,

  /* Priest */
  HEAL,
  SMITE,

  /* rougue */
  BACK_STAB,
  SLICE
} spells;


/*
* This is the struct to hold the character spells
*/
struct characterSpellsStruct
{
	/*
	 * This is the enum value of the spell
	 * Will be used to convert to the spellName
	 */
	spells spell;

	/* This is the spell name */
	std::string spellName;

	/* This is the attack power of the spell */
	int spellAttackPower;
};

/*
 * TODO 1. Find a better way to store all the spells.
 * Store the spell name, min attack power, max attack power.
 */


#endif /* _SPELLS_H_ */
