/***************************************************************************
 * stats.h
 *
 * DESCRIPTION:
 *  This header contains the stat's for the characters
 *
 * NOTES:
*
 * REFERENCES:
 *  character, main
 *
 * TODO:
 *
 * CHANGELOG:
 * DATE-------------AUTHOR--------------REASON
 * 07/24/16			TBG					Original Release
 ***************************************************************************/

#ifndef _STATS_H_
#define _STATS_H_

/* Standard library */
#include <string>

/*
* This is the enum for the characters race
*/
typedef enum raceEnum
{
	HUMAN,
	ORC,
	TROLL,
	UNDEAD
} m_race;

/*
* This is the enum for the characters class
*/
typedef enum classEnum
{
	SHAMAN,
	WARRIOR,
	WARLOCK,
	PRIEST,
	ROUGUE
} m_class;

/*
* This is the num for the class health addition
*/
enum classHealth
{
	SHAMAN_HEALTH  = 112,
	WARRIOR_HEALTH = 145,
	WARLOCK_HEALTH = 95,
	PRIEST_HEALTH  = 86,
	ROUGUE_HEALTH  = 124
}; /* END classHealth */


/*
* This is the struct for the characters stats
*/
struct stats
{
	stats(std::string argName,
		  int argLevel,
		  int argHealth,
		  m_race argRace,
		  m_class argClass) : characterName(argName),
		                      characterLevel(argLevel),
		                      characterHealth(argHealth),
							  characterRace(argRace),
							  characterClass(argClass)
	{}

	/* This is the characters name */
	std::string characterName;

	/* This is the characters level */
	int characterLevel;

	/* This is the characters health */
	int characterHealth;

	/* This is the characters race */
	m_race characterRace;

	/* This is the characters class */
	m_class characterClass;
}; /* END stats */

#endif /* _STATS_H_ */
