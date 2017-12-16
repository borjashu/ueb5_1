#include <stdio.h>
#include "datastructure.h"

int fclearBuffer(FILE* );



//TTeam Teams[100];

/***************************************************************************
*  saveTeams
*  Speichert Mannschaften, Ruft Speicherung von eine Mannschaft auf
*  Parameter: keine
*  Ergebnis : void
****************************************************************************/
void saveTeams()
{
	int i;
	FILE* Datei = fopen("teams.xml", "w");
	printf("%i",TeamCounter);
	if (Datei == NULL)
		printf("Datei konnte nicht geöffnet werden!\n");
	else
		fprintf(Datei,"<Data>\n");

	printf("<Data> geschrieben\n");


	for(i = 0; i < TeamCounter; i++)
   {
     saveTeam(i,Datei);

   }

	fprintf(Datei,"</Data>\n\n");

}


/***************************************************************************
*  saveTeam
*  Speichert eine Mannschaft
*  Parameter: Anzahl der Teams, Datei
*  Ergebnis : void
****************************************************************************/
void saveTeam(int TeamNr,FILE* Datei)
{

	if (Datei == NULL)
		printf("Datei konnte nicht geöffnet werden!\n");
	else
	{
		fprintf(Datei," <Team>\n");

		if(Teams[TeamNr].Name)
			fprintf(Datei," <Name>%s</Name>\n",Teams[TeamNr].Name);
		printf("<Name> geschrieben\n");

		if(Teams[TeamNr].Trainer)
			fprintf(Datei," <Trainer>%s</Trainer>\n",Teams[TeamNr].Trainer);
		printf("<Trainer> geschrieben\n");

		if(Teams[TeamNr].Playernumber)
			fprintf(Datei," <Playernumber>%i</Playernumber>\n",Teams[TeamNr].Playernumber);
		printf("<Playernumber> geschrieben\n");
		savePlayers(TeamNr,Datei);
		fprintf(Datei," </Team>\n\n\n");
	}
}

/***************************************************************************
*  savePlayers
*  Speichert Players, Ruft Speicherung von eine Player auf
*  Parameter: anzahl der Spieler, Datei
*  Ergebnis : void
****************************************************************************/
void savePlayers(int TeamNr,FILE* Datei)
{
	int i;
	for(i = Teams[TeamNr].Playernumber; i > 0; i--)
		savePlayer(i - 1,TeamNr,Datei);
}

/***************************************************************************
*  savePlayer
*  Speichert Player,
*  Parameter: Anzahl der Spieler, Anzahl der Teams, Datei
*  Ergebnis : void
****************************************************************************/
void savePlayer(int PlayerNr, int TeamNr, FILE* Datei)
{
	char Datum [9];
	int Year,Day,Month;

	if(Datei != NULL)
	{
		fprintf(Datei,"  <Player>\n");

		if(Teams[TeamNr].Player[PlayerNr].Name)
			fprintf(Datei,"   <Name>%s</Name>\n",Teams[TeamNr].Player[PlayerNr].Name);
		printf("<Name> geschrieben\n");


		if(Teams[TeamNr].Player[PlayerNr].Number)
			fprintf(Datei,"   <TricotNr>%i</TricotNr>\n",Teams[TeamNr].Player[PlayerNr].Number);
		printf("<TricotNr> geschrieben\n");


			fprintf(Datei,"   <Goals>%i</Goals>\n",Teams[TeamNr].Player[PlayerNr].Goal);
		printf("<Goals> geschrieben\n");



		Year  = Teams[TeamNr].Player[PlayerNr].Bdate.Year;
		Month = Teams[TeamNr].Player[PlayerNr].Bdate.Month;
		Day   = Teams[TeamNr].Player[PlayerNr].Bdate.Day;
		printf("Datum lesen. . \n");


		printf("%02i.%02i.%4i\n ",Day,Month,Year);
		sprintf(Datum,"%02i.%02i.%4i",Day,Month,Year);

		fprintf(Datei,"   <Birthday>%s</Birthday>\n",Datum);
		fprintf(Datei,"  </Player>\n");
	}
}


int fclearBuffer(FILE *Datei)
{
	char Dummy;
	do
	{
      fscanf(Datei,"%c", &Dummy);

		if(feof(Datei))
			break;

	} while ( Dummy != '\n' );
	return 1;
}


/***************************************************************************
*  loadTeams
*  Speichert Laedt aus der Datei
*  Parameter:
*  Ergebnis : 1 oder 0
****************************************************************************/
int loadTeams()
{
	FILE *Datei;
	char Text[101];
	char *Zeilenanfang;
	int NameFlag  = 0;
	int Len       = 0;


	Datei = fopen("teams.xml", "r");
	if (Datei == NULL)
		printf("Datei konnte nicht geöffnet werden!\n");
	else
	{
		do
		{
         fscanf(Datei, "%100[^\n]", Text);
			fclearBuffer(Datei);
			Zeilenanfang = Text;

			while(*Zeilenanfang==' ')
				Zeilenanfang++;
			while(*Zeilenanfang=='	')
				Zeilenanfang++;

			//printf("%s\n", Zeilenanfang);

			if(feof(Datei))
			{
				printf("unerwartetes Dateiende gefunden!\n\n");
				break;
			}

			if(strncmp(Zeilenanfang, "<Team>", 6) == 0)
			{
				if(strncmp(Zeilenanfang+strlen(Zeilenanfang + 6) - 5, "</Team>", 5))
					TeamCounter++;
			}

			if(strncmp(Zeilenanfang, "<Trainer>", 9) == 0)
			{
				Len = strlen(Zeilenanfang + 9) - 10;

				if(strncmp( Zeilenanfang + Len + 9, "</Trainer>", 9) == 0)
				{
					Teams[TeamCounter - 1].Trainer = calloc(Len + 1, sizeof(char));
					strncpy(Teams[TeamCounter - 1].Trainer,Zeilenanfang + 9,Len);
				}
			}

			if(strncmp(Zeilenanfang, "<Goals>", 7) == 0)
			{
				Len = strlen(Zeilenanfang + 7) - 8;

				if(strncmp( Zeilenanfang + Len + 7, "</Goals>", 7) == 0)
				{
					Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Goal = atoi(Zeilenanfang + 7);
				}
			}

         if(strncmp(Zeilenanfang, "<TricotNr>", 10) == 0)
			{
				Len = strlen(Zeilenanfang + 10) - 11;

				if(strncmp( Zeilenanfang + Len + 10, "</TricotNr>", 10) == 0)
				{
					Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Number = atoi(Zeilenanfang + 10);
				}
			}


			if(strncmp(Zeilenanfang, "<Player>", 8) == 0)
			{
				if(strncmp(Zeilenanfang + strlen(Zeilenanfang + 8) - 9, "</Player>", 8) != 0)
				{
					NameFlag = 1;
					Teams[TeamCounter - 1].Playernumber = Teams[TeamCounter - 1].Playernumber + 1;
				}
         }

         if(strncmp(Zeilenanfang, "<Name>", 6) == 0)
			{
				Len = strlen(Zeilenanfang + 6) - 7;

				if(strncmp(Zeilenanfang + Len + 6, "</Name>", 7) == 0)
				{
					if(!NameFlag)//Team-Name
					{
						Teams[TeamCounter - 1].Name = calloc(Len + 1, sizeof(char));
						strncpy(Teams[TeamCounter - 1].Name,Zeilenanfang + 6,Len);
					}

					if(NameFlag)//Player-Name
					{
						Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Name = calloc(Len + 1, sizeof(char));
						strncpy(Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Name,Zeilenanfang + 6,Len);
						NameFlag=0;
					}
				}
			}

			if(strncmp(Zeilenanfang, "<Birthday>", 10) == 0)
			{
				int Year = 0,
				Month    = 0,
				Day      = 0;

				Len = strlen(Zeilenanfang + 10) - 11;

				Day   = atoi(Zeilenanfang + 10);
				Month = atoi(Zeilenanfang + 10 + 3);
				Year  = atoi(Zeilenanfang + 10 + 6);

				Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Bdate.Year  = Year;
				Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Bdate.Month = Month;
				Teams[TeamCounter - 1].Player[Teams[TeamCounter - 1].Playernumber - 1].Bdate.Day   = Day;
			}


		}while(strncmp(Zeilenanfang, "</Data>", 7) != 0 );

		fclose(Datei);
		//разложить на элементы
	}

	//waitForEnter();
	return 0;
}

