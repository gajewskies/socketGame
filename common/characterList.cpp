/***************************************************************************
 * characterList.cpp
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
 *  implementation, references in in the header.
 *
 * TODO:
 *
 * CHANGELOG:
 * DATE-------------AUTHOR--------------REASON
 * 07/24/16			TBG					Original Release
 ***************************************************************************/

/* standard headers */
#include <iostream>

/* Local headers */
#include "characterList.h"

/* Declare the instance NULL on compilation */
characterList *characterList::instance = NULL;

characterList::characterList(void)
{} /* END characterList */

characterList::~characterList(void)
{} /* END characterList */

characterList * characterList::getInstance()
{
      if (instance == NULL)
      {
    	  instance = new characterList();
      } /* END instance */
      return instance;
} /* END getInstance */

/* This will show all the characters */
void characterList::showCharacters(void)
{
    for (int i = 0; i < amount; i++)
    {
      std::cout << "Name " << charList[i].name << std::endl;
    } /* END for */
} /* END showCharacters */

/* This will add a character to the list */
void characterList::add(character *argCharacterPtr, std::string argName)
{
  charList[amount].characterPtr = argCharacterPtr;
  charList[amount].name = argName;
  amount++;
} /* END add */

/* This will select a character for targeting */
character *characterList::select(std::string argName)
{
  character *returnValue;

  for (int i = 0; i < amount; i++)
  {
    if (charList[i].name == argName)
    {}
    else
    {
      returnValue = charList[i].characterPtr;
    } /* END if */
  } /* END for */
  return returnValue;
} /* END select */
