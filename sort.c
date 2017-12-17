#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "sort.h"
#include "teams.h"
int i;


void qSort(TPlayer * A, int ui, int oi, int (*Fkt)(TPlayer *, TPlayer *, int r), int r)
{
	int idx;

	if(ui >= oi)					// prueft ob untere grenze groesser oder gleich der oberen grenze
        return ;					// beendet die funktion gegebenfalls
	idx = partition(A, ui ,oi, Fkt, r);		// laesst zwischen der oberen und der unteren grenze sortieren
	qSort(A, ui, idx - 1, Fkt, r);			// ruft sich selbst auf
	qSort(A, idx + 1, oi, Fkt, r);			// ruft sich selbst auf
}

void QSort(TPlayer * A, int Anz, int (*Fkt)(TPlayer *, TPlayer *, int r), int r)
{
       qSort(A, 0, Anz - 1, Fkt, r);
}


int partition(TPlayer * A, int ui, int oi, int (*Fkt)(TPlayer *, TPlayer *, int r), int r)
{
	int i = ui,
       j = oi,
       comp = ui;


	while(i <= j) 		// prueft ob die untere grenze kleiner oder gleich der oberen grenze ist
	{
		while((i <= j) && (Fkt( A+i, A+comp, r) <= 0))
			i++;
		while((j >= i) && (Fkt( A+j, A+comp, r) >= 0))
			j--;
		if(i < j) // prueft ob untere grenze kleiner der oberen grenze
		{
			Tausche(A + i, A + j);
			i++;
			j--;
		}
	}
	i--;
	Tausche(A + i, A + comp);

	return i; // gibt den zaehler i zurueck
}


void Tausche(TPlayer * A, TPlayer * B)
{
	TPlayer temp;

	memcpy(&temp, A, sizeof(TPlayer)); 	    	// speichert den ersten string in einem temporeren string
	memcpy(A, B, sizeof(TPlayer));		// speichert den zweiten string im ersten string
	memcpy(B, &temp, sizeof(TPlayer));		// speichert den temporären string im zweiten string
}
