#include <stdio.h>
#include <string.h>


typedef struct ruch
{
	struct ruch *next;
	int pierwotna_pozycja;
	int nastepna_pozycja;
	int wartosc_czarne;
	int wartosc_biale;
}move;


move* start(double lwl, double lwb, double lwp, char *lszachownica[6][6])
{
	for (int li = 0; li < 6; li++)
	{
		if (li%2 == 1)
		{
			lszachownica[li][1] = 'c';
			lszachownica[li][5] = 'b';
		}
		else
		{
			lszachownica[li][0] = 'c';
			lszachownica[li][4] = 'b';
		}
	}
	move *lruch = malloc(sizeof(move));
	lruch->wartosc_czarne = 0;
	lruch->wartosc_biale = 0;
	lruch->pierwotna_pozycja = 0;
	lruch->nastepna_pozycja = 0;

}

main()
{
	char szachownica[6][6] = { "" };
	double wl = 0;
	double wb = 0;
	double wp = 0;
	int i;
	char przelacznik[10] = { "" };

	//chujnia ze sprawdzaniem specyfikatorów
	while (wl*wb*wp == 0)
	{
		scanf("%s", przelacznik);
		if (strcmp(przelacznik, "-wl") == 0)
		{
			scanf("%lf", &wl);
		}
		else
		{
			if (strcmp(przelacznik, "-wb") == 0)
			{
				scanf("%lf", &wb);
			}
			else
			{
				if (strcmp(przelacznik, "-wp") == 0)
				{
					scanf("%lf", &wp);
				}
				else
				{
					scanf("%s", przelacznik);
					printf("Zly przelacznik. Prosze podac poprawny.\n");
				}
			}
		}
	}

}