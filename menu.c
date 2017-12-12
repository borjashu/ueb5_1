#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
/**************************************************
 *  Gibt das Titel und Menue Punkte aus aus       *
**************************************************/
int getMenu (int mpunktezahl,char titel[],const char **mpunkte)
{
int i;
int eingabe = 0;
int ok      = 0;
   do
   {
      clearScreen();
      fflush(stdin);
      printf("%s\n",titel);
      printLine('-', 50);

      for(i = 0;i <= mpunktezahl - 1;i++)
         {
            printf("%d.%s\n",(i + 1),mpunkte[i]);

         }

      printf("\nIhre Wahl:");
      scanf("%d",&eingabe);

      if(eingabe >= 1 && eingabe <= mpunktezahl) ok = 1;

      else
         ok = 0;

      clearBuffer();

   }while(!ok);

   return eingabe;
}
