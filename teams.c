#include "datastructure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"

int TeamCounter = 0;
int sort = 0;
TTeam Teams[100];


/***************************************************************************
*  createTeam
*  Speichert Laegt eine Manschaft an
*  Parameter:
*  Ergebnis :
****************************************************************************/
void createTeam()
{


   printf("Erfassung einer neuen Mannschaft\n");
   printLine('=',50);


   getText("den Namen der Mannschaft ", 50, 0, &((Teams + TeamCounter)->Name));
   getText("den Namen des Trainers ", 50, 1, &Teams[TeamCounter].Trainer);//optional



   Teams[TeamCounter].Playernumber = 0;

   do
   {
      addPlayer();


   }while (askYesOrNo());

   TeamCounter++;
	printf("Das Team wurde erstellt.");
}

void deleteTeam()
{
   printf("deleteTeam\n");
}

/***************************************************************************
*  addPlayer
*  Speichert Laegt eine Spieler an
*  Parameter:
*  Ergebnis :
****************************************************************************/
void addPlayer()
{
   int    ok = 0;

   printf("Erfassung der Spieler\n");
   printLine('-',25);
   printf("\n   Spieler %i:\n",(Teams[TeamCounter].Playernumber+1));
   getText("Namen des Spielers",20,0,&Teams[TeamCounter].Player[Teams[TeamCounter].Playernumber].Name);
   getDate("Geburtsdatum des Spielers",1,&Teams[TeamCounter].Player[Teams[TeamCounter].Playernumber].Bdate);

   while(!getNumber("Trikot-Nr. ", &Teams[TeamCounter].Player[Teams[TeamCounter].Playernumber].Number, 1, 99))
      printf("Eingabe ist ungültig!\n");

   printf("Spieler wurde erstellt.\n");
   Teams[TeamCounter].Player[Teams[TeamCounter].Playernumber].Goal=0;
   Teams[TeamCounter].Playernumber++;
   }

void deletePlayer()
{
   printf("deletePlayer\n");
}

void searchPlayer()
{
    printf("searchPlayer\n");
}


/***************************************************************************
*  listTeams
*  Speichert Listet eine Manschaften Auf
*  Parameter:
*  Ergebnis :
****************************************************************************/
void listTeams()
{
    if(!TeamCounter)
	{
		printf("Es wurde bisher noch keine Mannschaft angelegt. Sie gelangen ins Hauptmenü. ");
		return;
	}
	else
   {
	int j;
	printf("Liste der Mannschaften\n");
	printf("-------------\n");

     for(j = 0; j < TeamCounter;j++)
      {
         listTeam(j);
      }
   }
}



void listTeam (int j)
{
         int i;

         printf("Mannschaft #%i		 \n\n",j+1);
         printf("Name		  :  %s\n",Teams[j].Name);
         printf("Trainer	          :  %s\n",Teams[j].Trainer);
         printf("Anzahl der Spieler:  %i\n", Teams[j].Playernumber);
         printf("Spieler \n");

         for(i=0;i<Teams[j].Playernumber;i++)
         {
				listPlayer(j,i);
         }


}


void listPlayer (int j ,int i)
{
   printf("%20i. %s (",i+1,Teams[j].Player[i].Name);
   printDate(&Teams[j].Player[i].Number,&Teams[j].Player[i].Bdate);
}




int out()
{
    printf("out\n");

}

int VerglName(TPlayer *A, TPlayer *B,  int r)
{
	int i = 0;
	char c;

	while( (c = toupper(*(A->Name + i)) - toupper(*(B->Name + i)) ) == 0 && (*(A->Name + i) != '\0') )//тут хуйня
		i++;

	if(r)
		return c;
	return c *-1;
}

/*int VerglTrain(TTeam * A, TTeam * B,  int r)
{
	int i = 0;
	char c;

	while( (c = toupper(*(A->Trainer + i)) - toupper(*(B->Trainer + i)) ) == 0 && (*(A->Trainer + i) != '\0') )
		i++;

	if(r)
		return c;
	return c *-1;
}*/

void sortPlayer()
{
   char * menuepunkte[] = {"Name", "Geburtsdatum", "Trikotn.","Tore"};
	char * richtung[] = {"Auf (0-9 / A-Z)", "Ab (9-0 / Z-A)"};
	int  r = 0;

	printLine('=', printf("\nSortieren der Teams\n")-2);


	int i=getMenu(2,"Sortieren der Teams\nIn welche Richtung soll Sortiert werden?", richtung);
	if(i)
		r = 1;


	printLine('=', printf("\nSortieren der Teams nach...\n")-2);
	printf("\n");

	switch (getMenu(4,"Sortieren nach",menuepunkte))
	{
		case 1:
			QSort(Teams->Player, Teams->Playernumber, VerglName, r);
			if(r)
				sort = 1;
			break;
		/*case 2:
			QSort(Teams, TeamCounter, VerglTrain, r);
			if(r)
				sort = 2;
			break;
		case 3:
			QSort(CDData, countCDs, VerglLieder, r);
			break;*/
	}

	//listCDs();
}

