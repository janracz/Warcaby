#include <stdio.h>
#include <string.h>


typedef struct pozycja
{
	int x;
	int y;
}miejsce;

typedef struct ruch
{
	struct ruch *next;
	miejsce pierwotna_pozycja;
	miejsce nastepna_pozycja;
	miejsce zbita_pozycja;
	int wartosc_czarne;
	int wartosc_biale;
}move;


move* start(double lwl, double lwb, double lwp, char lszachownica[][6])
{
	for (int li = 0; li < 6; li++)
	{
		if (li%2 != 1)
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
	lruch->pierwotna_pozycja.x = 0;
	lruch->pierwotna_pozycja.y = 0;
	lruch->nastepna_pozycja.x = 0;
	lruch->nastepna_pozycja.y = 0;
	lruch->next = utworz_liste_ruchow(lszachownica, 0);			//stwórz t¹ funkcjê XD
	return lruch;
}


move* utworz_liste_ruchow(char llszachownica[][6], int lkolor)
{
	//char bufor_tablica[6][6] = llszachownica;
	char pionek;
	char damka;
	long long unsigned int wspolrzedne;

	if (lkolor == 0)
	{
		pionek = 'c';
		damka = 'C';
	}
	else
	{
		pionek = 'b';
		damka = "B";
	}

	for (int lx = 0; lx < 6; lx++)
	{
		for (int ly = 0; ly < 6; ly++)
		{
			if (llszachownica[lx][ly] == pionek)
			{

			}
			else
			{
				if (llszachownica[lx][ly] == damka)
				{

				}
			}
		}
	}
}

main()
{
	char szachownica[6][6] = { "" };
	double wl = 3;
	double wb = 3;
	double wp = 3;
	int i;
	char przelacznik[10] = { "" };
	move *ruch;

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
	ruch = start(wl, wb, wp, szachownica);
}