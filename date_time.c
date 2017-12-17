#include <stdio.h>
#include "date_time.h"


int getDate(char *Inputname,int nothing,TDate **adress)
{
   TDate Date;


   char Input[20];
   int ok = 0;
   do
   {
      printf("Geben Sie bitte ein Geburtsdatum ein: ");
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
         if (getDateFromString(Input, &Date))
         {
           //printf("Das Datum %02i.%02i.%04i ist gueltig!\n", Date.Day, Date.Month, Date.Year);

            ok = 1;
         }

         else
            printf("Das eingegebene Datum %s ist ungueltig!\n", Input);

      else
         break;
   } while (!ok);


}




/**************************************************
 *  Checkin if the year is a leap year or not
**************************************************/
int isLeapYear(int year)
{
   if(year % 4 == 0)
   {
      if(year % 400 == 0) return 1;
      if(year % 100 == 0) return 0;
   }

   else return 0;
}

/**************************************************
 *  liest aus einer Zeichenkette die Tag, Monat
 *  und Jahr und speichert diese – sofern sie eine
 *  gültige Datum bilden – in der Datestruktur.
**************************************************/

int getDateFromString(char Input[], TDate *Date)
{
   int k,i,dotc = 0;
   int j = 0;
   char buff[20];
   *buff = '\0';
   TDate temp;

   for (i = 0; i < 19; i++)
   {
      if(Input[i]!='.'&&Input[i]!='\0')
      {
         buff[j] = Input[i];
         j++;
      }

      if(Input[i] == '.')
      {
         if(dotc == 0)
         {
            temp.Day=atoi(buff);
         }

         if(dotc == 1)
         {
            temp.Month = atoi(buff);
         }

         for(k=0;k<=20;k++)
         {
            buff[k] = '\0';
         }

         dotc++;
         j=0;
      }

      if(Input[i] == '\0')
      {

         if(dotc == 2)
         {
            temp.Year = atoi(buff);
            dotc = 0;

            for(k=0;k<=20;k++)
            {
               buff[k] = '\0';
            }

         }
      else  break;
      }


   }

   if(isDateValid(temp))
   {
      Teams[TeamCounter].Player[Teams[TeamCounter].Playernumber].Bdate = temp;
      return 1;
   }

   return 0;
}

/**************************************************
 *  Ueberprüt ob das angegebene Datum
 *  (Parameter Struktur TDate mit Tag,
 *  Monat und Jahr) ein gültiges Datum ist
**************************************************/

int isDateValid(TDate temp )
{
   int month[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

   if(temp.Month <= 12 && temp.Day <= month[temp.Month] && temp.Month != 2 && temp.Day != 0)
   {
       return 1;
   }

   if(temp.Month == 2 && temp.Day<29)
   {
      return 1;
   }

   if(temp.Month == 2 && temp.Day == 29)
   {
      return isLeapYear(temp.Year);
   }

   else return 0;
}


void printDate(int* Number,TDate* Date)
{
   if(Date->Day == 0)
   {
      printf("%i)",*Number);
   }
   else
   {
      printf("%i; *%02i.%02i.%04i)",*Number, Date->Day, Date->Month, Date->Year);
   }

}












































