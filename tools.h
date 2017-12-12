#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

    /***************************************************************************
    *  clearBuffer
    *  Löscht den Tastaturpuffer!
    *  Parameter: keine
    *
    *  Ergebnis : nichts
    ***************************************************************************/
    void clearBuffer();

     /***************************************************************************
    *  askAgain
    *  Fragt den Anwender ob das Programm wiederholt werden soll.
    *  Parameter: keine
    *
    *  Ergebnis : Erg: Gibt ein int wert aus.(Nein = 0 | Ja = 1)
    ***************************************************************************/
    int askYesOrNo();

    /***************************************************************************
    *  clearScreen
    *  Löscht die ausgabe
    *  Parameter: keine
    *
    *
    ***************************************************************************/
    void clearScreen();

    /***************************************************************************
    *  printLine
    *  zeichnet eine Linie aus Symbole
    *  Parameter: zeichen,zahl
    *
    *
    ***************************************************************************/

   void printLine(char zeichen, int zahl);



   /***************************************************************************
    *  waitForEnter
    *  Auf Eingabetaste warten
    *  Parameter: --
    *
    *
    ***************************************************************************/



    void waitForEnter();


   /***************************************************************************
*  getText
*  text fuer struckt einlesen, Speicher reservieren
*  Parameter: Ausgabenmodificator, maximale eingabelaenge, leere eingabe switch, adresse des Elementes
***************************************************************************/
int getText (char *Inputname,int maxlen,int nothing, char **adress);


   /***************************************************************************
*  getNumber
*  text fuer struckt einlesen, Speicher reservieren
*  Parameter: Ausgabenmodificator, adresse des Elementes, min. Wert, Max. Wert
***************************************************************************/
int getNumber (char *Inputname,char **adress,int von, int bis);

void freeStruct();


   #endif // TOOLS_H_INCLUDED
