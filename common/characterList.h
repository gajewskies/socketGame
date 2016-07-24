/***************************************************************************
 * characterList.h
 *
 * DESCRIPTION:
 *  This class will handle the storage of all created characters.
 *  a character will be added with the call to add and selected with the call
 *  to select.  The select call is used to target a player, passed into the
 *  attack call.
 *
 * NOTES:
 *  This will be a singleton class, meaning that we will only allow one
 *  creation of this class.  This is to have only one character list.
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

#ifndef _CHARACTER_LIST_H_
#define _CHARACTER_LIST_H_

/* Standard library */
#include <string>

/* Local headers */
#include "character.h"

/* This is the amount of characters registered */
static int amount;

class characterList
{
  public:
	/* Destructor */
    ~characterList(void);

    /*
     * This is the singleton get instance.  It will return the only instance of
     * this class
     */
    static characterList *getInstance();

    /* This will show all the characters */
    void showCharacters(void);

    /*
     * This will add a character to the list
     * Takes the character as a pointer and the name of the character
     */
    void add(character *argCharacterPtr, std::string argName);

    /*
     * This will select a character for targeting
     * Takes the argName not to select from the list.  Returns the character pointer
     */
    character *select(std::string argName);

  private:
    /* A static instance of the class */
    static characterList *instance;

    /* Delcare constructors private for singleton */
    characterList(void);
    characterList(characterList const&);
    void operator=(characterList const&);

    /* This is the struct to hold all the characters */
    typedef struct
    {
    	/* Character pointer */
    	character *characterPtr;

    	/* Character name */
    	std::string name;
    } allCharacters;

    /* Character list */
    allCharacters charList[5];
}; /* END characterList */

#endif /* _CHARACTER_LIST_H_ */
