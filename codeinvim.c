/*Diaconu Tudor-Gabriel 312CA*/

#include <stdio.h>

void sortare_vector(int n, int v[])
{
	int i, j, aux;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
} //functie de sortare descrescatoare a unui vector

int main(void)
{
	int n, x[100], i, c[100], punctajmin, pct = 0;
	int p[100], pctmax = 0, m = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &c[i]);
	scanf("%d", &punctajmin);
	for (i = 0; i < n; i++) {
		p[i] = (10 - x[i]) * c[i];
		pctmax += p[i];
		pct += x[i] * c[i];
	} //calculam cate puncte de credit mai poate obtine prin mariri
	if (pctmax + pct < punctajmin) {
		printf("-1\n");//verificam daca poate atinge punctajul minim
	} else {
		sortare_vector(n, p);
		for (i = 0; i < n; i++) {
			pct += p[i];
			m++;//calculam numarul de materii necesare, initial fiind 0
			if (pct >= punctajmin)
				break;//in momentul atingerii punctajului minim, iesim din for
		}
	}
	printf("%d\n", m);
	return 0;
}
