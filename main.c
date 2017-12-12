#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "date_time.h"
#include "database.h"
#include "tools.h"
#include "teams.h"
#include "menu.h"
#define mpunktezahl 8




int main()
{
   freeStruct();
   loadTeams();

   int choise;
   int goout = 0;

  // char titel[] = "Mannschaften-Verwaltung Beta";
   char *mpunkte[mpunktezahl] = {"Neue Mannschaft anlegen","Spieler hinzufuegen","Spieler loeschen","Mannschaft loeschen","Suchen","Sortieren","Auflisten","Programm beenden"};

   do
   {
      printf("Mannschaften-Verwaltung Beta");
      choise = getMenu(mpunktezahl,mpunkte);

      switch(choise)
      {
         case 1: createTeam();
         break;

         case 2: addPlayer();
         break;

         case 3: deleteTeam();
         break;

         case 4: deletePlayer();
         break;

         case 5:searchPlayer();
         break;

         case 6: sortTeams();
         break;

         case 7: listTeams();
         break;

         case 8: out();
         goout = 1;
         break;
      }

   waitForEnter();

   }while (!goout);

   saveTeams();
   freeStruct();

}
