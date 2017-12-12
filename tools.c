#include <stdio.h>
#include <string.h>
#include "tools.h"
#define clear() printf("\033[H\033[J")
#include "datastructure.h"

/***************************************************************************
*  clearBuffer
*  Löscht den Tastaturpuffer!
*  Parameter: keine
*  Ergebnis : nichts
***************************************************************************/
void clearBuffer()
{
    char dummy;

    do
    {
        scanf("%c",&dummy);
    } while (dummy != '\n');
}
/***************************************************************************
*  askAgain
*  Fragt den Anwender ob das Programm wiederholt werden soll.
*  Parameter: keine
*  Ergebnis : Erg: Gibt ein int wert aus.(Nein = 0 | Ja = 1)
****************************************************************************/
int askYesOrNo()
{
   int Erg,
       Eingabe;
   char ans;

   do
   {
      do
      {
         printf("\nMoechten Sie noch einmal (j/n) ? ");
         Eingabe = scanf("%c",&ans);

         if (ans != '\n')

         clearBuffer();

      } while (!Eingabe);

         if ( (ans =='j') || (ans == 'J') )
         {
            Erg = 1;
         }

         else if ((ans == 'n') || (ans == 'N'))
         {
            Erg = 0;
         }

         else
         {
            Erg = 2;
         }

   } while (Erg == 2);

   return Erg;
}
/***************************************************************************
*  clearScreen
*  Löscht die ausgabe
*  Parameter: keine
***************************************************************************/
   void clearScreen()
   {
    clear();
   }
/***************************************************************************
*  printLine
*  zeichnet eine Linie aus Symbole
*  Parameter: zeichen,zahl
***************************************************************************/

    void printLine(char zeichen,int zahl)
{
   int i;

   for(i = 0;i <= zahl;i++)
   {
      printf("%c",zeichen);
   }

   printf("\n");
}

/***************************************************************************
*  waitForEnter
*  Auf Eingabetaste warten
*  Parameter: --
***************************************************************************/

void waitForEnter()
{
	printf("\nbitte Eingabetaste druecken ... ");
	clearBuffer();
}


/***************************************************************************
*  getText
*  text fuer struckt einlesen, Speicher reservieren
*  Parameter: Ausgabenmodificator, maximale eingabelaenge, leere eingabe switch, adresse des Elementes
***************************************************************************/

int getText(char* Text, int anzahl,int Empty, char** zeichenkette)
{
	char Format[20];
	char* Input = calloc(anzahl + 1, sizeof(char));

	do
	{
		sprintf(Format, "%%%i[^\n]", anzahl);
		printf("Geben Sie bitte %s ein: ",Text);
		scanf(Format, Input);
		clearBuffer();

		if (*Input == '\0')
		{
			if (!Empty)
			{
				printf("Leere unerlaubte Eingabe\n");
			}
			else
			{
				zeichenkette=NULL;
				break;
			}
		}
		else
		{
			*zeichenkette = calloc(strlen(Input) + 1, sizeof(char));
			if (*zeichenkette)
			{
				strncpy(*zeichenkette, Input, strlen(Input));
				break;
			}
		}
	} while (1);
	free(Input);
	return 1;
}

   /***************************************************************************
*  getNumber
*  text fuer struckt einlesen, Speicher reservieren
*  Parameter: Ausgabenmodificator, adresse des Elementes, min. Wert, Max. Wert
***************************************************************************/
int getNumber (char *Inputname,char **adress,int von, int bis)
{

   int i = 0;

   printf("Geben Sie bitte %s ein: ",Inputname);
   scanf("%i", &i);
   clearBuffer();
   if(i >= von && i <= bis)
   {
      *adress = i;

      return 1;
   }

   else
   {
      return 0;
   }


}



void freeStruct()
{

	int i;
	int j=0;

	for(j = 0;j < TeamCounter;j++)
	{
		//раложить на элементы
		for(i = 0;i < Teams[i].Playernumber;i++)
		{
			free(Teams[j].Player[i].Name);
					}
		Teams[j].Playernumber=0;

		free(Teams[j].Name);
		free(Teams[j].Trainer);
	}

	printf("Die Daten wurden gelöscht.");
}
