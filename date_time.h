#include <stdio.h>
#include "datastructure.h"
   /***************************************************************************
    *  isLeapYear
    *  Ueberprüt ob ein es ein Schaltjahr ist
    *  Parameter: year
    *
    *  Ergebnis : Erg: Gibt ein int wert aus.(Nein = 0 | Ja = 1)
    ***************************************************************************/

int isLeapYear(int year);

   /***************************************************************************
    *  getDateFromString
    *  Ueberprüt ob das angegebene Datum (Parameter Struktur TDate
    *  mit Tag, Monat und Jahr) ein gültiges Datum ist,zerlegt das Datum und speichert es.
    *  Parameter: Input,Date
    *
    *  Ergebnis : Erg: Gibt ein int wert aus.(Nein = 0 | Ja = 1)
    ***************************************************************************/

int getDateFromString(char Input[], TDate *Date);

    /***************************************************************************
    *  getDateFromString
    *  Ueberprüt ob das angegebene Zeit (Parameter Struktur TTime
    *  mit Stunde, Minute und Sekunde) ein gültiges Zeit ist,zerlegt die Zeit und speichert es.
    *  Parameter: Input,Time
    *
    *  Ergebnis : Erg: Gibt ein int wert aus.(Nein = 0 | Ja = 1)
    ***************************************************************************/


int getDate(char *Inputname,int nothing,TDate **adress);

void printDate(int* Number,TDate* Date);
