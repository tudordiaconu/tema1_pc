/*Diaconu Tudor-Gabriel 312CA*/

#include <stdio.h>

int main(void)
{
	int t, n, m, i, dl[100], dc[100], elem[200][200];
	int j, k, ml[100][100], mc[100][100];
	int sc[100] = {0}, sl[100] = {0};
	int scc[100] = {0}, sll[100] = {0};
	int ctdim;
	scanf("%d", &t);
	for (i = 0; i < n; i++)
		dl[i] = 0;
	for (i = 0; i < m; i++)
		dc[i] = 0;
	for (i = 0; i < t; i++) {
		ctdim = 1;
		scanf("%d %d", &n, &m);
		for (j = 0; j < n; j++) {
			scanf("%d", &dl[j]);//citirea numarului de secvente de pe linii
			for (k = 0; k < dl[j]; k++) {
				scanf("%d", &ml[j][k]);
				sl[j] += ml[j][k];
//citirea dimensiunilor secventelor de pe linii si calcularea sumelor
			}
		}
		for (j = 0; j < m; j++) {
			scanf("%d", &dc[j]);//citirea numarului de secvente de pe coloane
			for (k = 0; k < dc[j]; k++) {
				scanf("%d", &mc[j][k]);
				sc[j] += mc[j][k];
//citirea dimensiunilor secventelor de pe coloane si calcularea sumelor
			}
		}
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++)
				scanf("%d", &elem[j][k]);
		} //citirea nomogramei ce trebuie verificata
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++)
				sll[j] += elem[j][k];
		} //calcularea sumelor elementelor de pe fiecare linie din nomograma
		for (k = 0; k < m; k++) {
			for (j = 0; j < n; j++)
				scc[k] += elem[j][k];
		} //calcularea sumelor elementelor de pe fiecare coloana din nomograma
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				if (sll[j] != sl[j] || scc[k] != sc[k])
					ctdim = 0;
			} //verificare daca nomograma este corecta
		}
		if (ctdim == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");
		for (j = 0; j < n; j++) {
			sl[j] = 0;
			sll[j] = 0;
		}
		for (j = 0; j < m; j++) {
			sc[j] = 0;
			scc[j] = 0;
		} //vectorii suma devin 0 pentru a permite verificarea unui nou puzzle
	}
	return 0;
}
