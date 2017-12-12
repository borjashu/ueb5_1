#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED
#define MAXPLAYER 23



typedef struct
{
   int Year;
   int Month;
   int Day;
}TDate;

typedef struct
{
   char* Name;
   int Number;
   int Goal;
   TDate Bdate;
}TPlayer;

typedef struct
{
   char* Name;
   char* Trainer;
   int Playernumber;
   TPlayer Player[MAXPLAYER];
}TTeam;

extern int TeamCounter;

extern TTeam Teams[];

#endif // DATASTRUCTURE_H_INCLUDED
