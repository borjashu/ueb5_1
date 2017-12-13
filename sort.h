#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/*******************************************************
 * void Tausche
 *
 * Funktion: Tauschen von zwei Strings
 * Parameter: 2x TTeam Pointer
 * Ergebnis:
 * ****************************************************/
//void Tausche(TTeam * A, TTeam * B);

/*******************************************************
 * int partition
 *
 * Funktion: durchsuchen nach größenunterschieden in
 *           TextArray und vertauschen
 * Parameter: TTeam pointer, int, int, int Fkt TTeam pointer
 *            in TTeam pointer in int r, int
 * Ergebnis: int
 * ****************************************************/
//int partition(TTeam * A, int ui, int oi, int (*Fkt)(TTeam *, TTeam *, int r), int r);

/*******************************************************
 * void qSort
 *
 * Funktion: Grenzen setzen, zur Partition schicken
 * Parameter:
 *
 * ****************************************************/
//void qSort(TTeam * A, int ui, int oi, int (*Fkt)(TTeam *, TTeam *, int r), int r);

/*******************************************************
 * void QSort
 *
 * Funktion: starten von qSort
 * Parameter:
 *
 * ****************************************************/
void QSort(TTeam * A, int Anz, int (*Fkt)(TTeam *, TTeam *, int r), int r);


#endif // SORT_H_INCLUDED
