/*Diaconu Tudor-Gabriel 312CA*/

#include <stdio.h>

int n_desc(int n)
{
	int v[10], i, copn, x = 0, j;
	copn = n;
	for (i = 0; i < 10; i++)
		v[i] = 0;
	while (copn > 0) {
		v[copn % 10]++;
		copn /= 10;
	}
	for (i = 9; i >= 0; i--) {
		if (v[i] > 0) {
			for (j = 0; j < v[i]; j++)
				x = x * 10 + i;
		}
	}
	return x;
} //functie pentru ordonarea descrescatoare a cifrelor unui numar

int n_cresc(int n)
{
	int v[10], i, copn, x = 0, j;
	copn = n;
	for (i = 0; i < 10; i++)
		v[i] = 0;
	while (copn > 0) {
		v[copn % 10]++;
		copn /= 10;
	}
	for (i = 1; i < 10; i++) {
		if (v[i] > 0) {
			for (j = 0; j < v[i]; j++)
				x = x * 10 + i;
		}
	}
	return x;
} //functie pentru ordinea crescatoare a cifrelor unui numar

int main(void)
{
	int n, nr[100], i, j, m, k, contor = 0;
	scanf("%d", &n);
	for (i = 0; i < 100; i++) {
		nr[i] = n_desc(n) - n_cresc(n);
		n = nr[i];
	} //construirea unui vector cu diferentele respective
	for (i = 0; i < 100; i++) {
		for (j = i + 1; j < 100; j++) {
			if (nr[i] == nr[j]) {
				contor = 1;
				m = j - i;
				k = i;
				break;
			} //verificarea daca exista 2 diferente egale
		}
		if (contor == 1)
			break;
	}
	printf("%d\n", k);//afisarea numarului de pasi
	for (i = k; i < k + m; i++)
		printf("%d ", nr[i]);//afisarea numerelor din secventa
	printf("\n");
	return 0;
}

