/*Diaconu Tudor-Gabriel 312CA*/

#include <stdio.h>

int main(void)
{
	int n, x0, x1, x2, i, nr = 0, xmax_impar, xmin_par;
	int minn = 1000000, maxx = 0, okmin, okmax;
	double m_a;
	long s = 0;
	i = 1;
	scanf("%d\n", &n);
	if (n == 1) {
		scanf("%d", &x0);
		s = 0;
		m_a = 0.0000000;
		xmin_par = 0;
		xmax_impar = 0;
	}
	//exceptie pentru cazul in care este citit un singur copac
	if (n == 2) {
		scanf("%d %d", &x0, &x1);
		s = 0;
		m_a = 0.0000000;
		xmin_par = 0;
		xmax_impar = 0;
	}
	//exceptie pentru cazul in care sunt cititi doar 2 copaci
	if (n > 2) {
		okmin = 0;
		okmax = 0;
		scanf("%d %d", &x0, &x1);
		while (i < n - 1) {
			scanf("%d", &x2);
			if (x1 > x0 && x1 > x2) {  //verificare daca e copac special
				s += x1;  //construirea sumei copacilor speciali
				nr++;   //numararea copacilor speciali pentru media aritmetica
				if (i % 2 == 1) {
					if (x1 > maxx) {
						xmax_impar = x1;
						maxx = x1;
						okmax = 1;
					}
				} else {
					if (x1 < minn) {
						xmin_par = x1;
						minn = x1;
						okmin = 1;
					}
					//stabilirea existentei unui maxim pe pozitie impara
					//stabilirea existentei unui minim pe pozitie para
				}
			}
			i++;
			x0 = x1;
			x1 = x2;
		}
	}
	if (n > 2)
		m_a = (double)s / nr;
	if (okmin == 0 && n > 2)
		xmin_par = -1;
	if (okmax == 0 && n > 2)
		xmax_impar = -1;
		// exceptiile, in cazul in care nu exista maxim impar sau minim par
	printf("%ld\n", s);
	printf("%0.7lf\n", m_a);
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);
	return 0;
}
