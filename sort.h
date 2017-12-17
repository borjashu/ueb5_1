#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/*******************************************************
 * void Tausche
 *
 * Funktion: Tauschen von zwei Strings
 * Parameter: 2x TPlayer Pointer
 * Ergebnis:
 * ****************************************************/
void Tausche(TPlayer * A, TPlayer * B);

/*******************************************************
 * int partition
 *
 * Funktion: durchsuchen nach größenunterschieden in
 *           TextArray und vertauschen
 * Parameter: TPlayer pointer, int, int, int Fkt TPlayer pointer
 *            in TPlayer pointer in int r, int
 * Ergebnis: int
 * ****************************************************/
int partition(TPlayer * A, int ui, int oi, int (*Fkt)(TPlayer *, TPlayer *, int r), int r);

/*******************************************************
 * void qSort
 *
 * Funktion: Grenzen setzen, zur Partition schicken
 * Parameter:
 *
 * ****************************************************/
void qSort(TPlayer * A, int ui, int oi, int (*Fkt)(TPlayer *, TPlayer *, int r), int r);

/*******************************************************
 * void QSort
 *
 * Funktion: starten von qSort
 * Parameter:
 *
 * ****************************************************/
void QSort(TPlayer * A, int Anz, int (*Fkt)(TPlayer *, TPlayer *, int r), int r);


#endif // SORT_H_INCLUDED
