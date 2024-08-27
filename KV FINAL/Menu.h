#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/**
 \file
 \brief Menu for console
*/
/**
 \brief Menu analysis argc and argv
 \param n argc
 \param Ar[] argv
*/
int Menu(int n, char* Ar[]);

/**
 \brief IsGoodMenu checks argc and argv for invalid values
 \param Ar[] argv
 */
int IsGoodMenu(char* Ar[]);

#endif // MENU_H_INCLUDED
