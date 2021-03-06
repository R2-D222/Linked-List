#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
#pragma warning(disable:4996)

typedef struct elem {
	int x;
	struct elem * nast;
}el;

typedef el *wel ;
void usunwsk(wel *l);

void druk(wel l) {
	if (l == NULL)
		printf("Lista jest pusta...");
	else
	{
		while (l != NULL) {
			printf("%i ", l->x);
			l = l->nast;
		}
	}
	printf("\n");
}

wel polacz_listy(wel p, wel q, wel sort) {
	wel pointer = NULL; // bedzie wskazywac na poczatek nowej posrtowanej listy
	
	if (!p) return q; // sprawdzaja czy istnieje lista q i p;
	if (!q) return p;
	if (p&&q) {
		if (p->x <= q->x) {
			sort = p;
			p = sort->nast;
		}
		else {
			sort = q;
			q = sort->nast;
		}
	}
	pointer = sort;
	while (p&&q) {
		if (p->x <= q->x) {
			sort->nast = p;
			sort = p;
			p = sort->nast;
		}
		else {
			sort->nast = q;
			sort = q;
			q = sort->nast;
		}
	}
	if (!p) sort->nast = q;
	if (!q) sort->nast = p;
	return pointer;
}

void drukodwrotnie(wel l) {
	if (l != NULL){
		drukodwrotnie(l->nast);
		printf("%i ", l->x);
	}
}

void zad5(wel *l){ // iteracyjnie
	wel p = NULL, q = NULL, m = *l;
	while (m != NULL) {
		q = m->nast;
		m->nast = p;
		p = m;
		m = q;
	}
	*l = p;
}

void zad5r(wel *l){ // rekursywnie	
	wel poczatek, reszta;
	if (l == NULL) { 
		return; 
	}
	poczatek = *l;
	reszta = poczatek->nast;

	//jesli jeden element na liscie 
	if (reszta == NULL) { 
		return; 
	}
	zad5r(&reszta);
	poczatek->nast->nast = poczatek;
	poczatek->nast = NULL;
	
	*l = reszta;
}

wel dodpocz(wel l, int y) {
	wel nowa = (wel)malloc(sizeof(el));

	if (nowa != NULL) {
		nowa->x = y;
		nowa->nast = l;
	}
	return nowa;
}

void zad6wartownik(wel *l, int y) {
	while (*l && (*l)->x < y) {
		l = &((*l)->nast);
	}
	*l = dodpocz(*l, y);
}
void zad6bezwartownik(wel *l, int y)
{
	while ((*l)->x < y) {
		l = &((*l)->nast);
}
	*l = dodpocz(*l, y);

}

wel dodkon(wel l, int y) {
	wel q = (wel)malloc(sizeof(el));
	wel r = l;
	if (q != NULL) {
		q->x = y;
		q->nast = NULL;

		if (l == NULL) return q;
		else {
			while (r->nast != NULL)
			{
				r = r->nast;
			}
			r->nast = q;
		}
	}
	return l;
}

wel znajdz(wel l, int y) {

	while (l != NULL && l->x != y) {
		l = l->nast;
	}
	return l;
}

wel* znajdz1(wel *l, int y) { // done
	while (*l != NULL && (*l)->x != y) {
		l = &(*l)->nast;
	}
	return l;
}

void dodza1(wel *r, int y) { // done
	wel t = (wel)malloc(sizeof(wel));
	t->x = y;
	t->nast = (*r)->nast;
	(*r)->nast = t;
}

void dodprzed1(wel *r, int y) {
	wel t = (wel)malloc(sizeof(wel));
	t->x = y;
	t->nast = *r;
	*r = t;
}

void odwroc(wel p) {
	wel q = NULL, r = NULL;
	while (p != NULL) {
		r = p;
		p = p->nast;
		r->nast = q;
		q = r;
	}
}

void usunwsk(wel *l) { // done
	wel q = *l;
	if (*l != NULL) {
		*l = (*l)->nast;
		free(q);
	}
}

void usunp1(wel *l) { // done
	usunwsk(l);
}

void usunk1(wel *l) { //done
	while ((*l)->nast != NULL) {
		l = &(*l)->nast;
	}
	usunwsk(l);
}

void dodza(wel l, int y) {
	wel t = (wel)malloc(sizeof(wel));
	t->x = y;
	t->nast = l->nast;
	l->nast = t;
}

void dodprzed(wel l, int y) {
	wel t = (wel)malloc(sizeof(wel));
	t->x = l->x;
	t->nast = l->nast;
	l->x = y;
	l->nast = t;
}

wel usunp(wel l) {
	wel q = l;
	if (l != NULL) {
		l = l->nast;
		free(q);
	}
	return l;
}

wel usunk(wel l) {
	wel q = l;
	wel r = (wel)malloc(sizeof(wel));

	if (l != NULL) {
		if (l->nast == NULL) { l = NULL; }
		else {
			while (q->nast != NULL) { r = q; q = q->nast; }
			r->nast = NULL;
		}
		free(q);
		return l;
	}
}
void zad2_a(wel *l, int y) { // bez rekurencji
	wel m = *l, n = NULL;
	while (m != NULL && m->x == y) {
		*l = m->nast;
		free(m);
		m = *l;
	}
	while (m != NULL) {
		while (m != NULL && m->x != y) {
			n = m;
			m = m->nast;
		}
		if (m == NULL) return;
		n->nast = m->nast;
		free(m);
		m = n->nast;
	}
}

void zad2_reku() {
	
}


int main()
{
	int i, j, k, pp;
	wel p = NULL, *q = NULL, x = NULL;
	do {
		printf("Co zrobic? \n \n 1 - dodaj na poczatku \n 2 - dodaj na koncu \n 3 - znajdz \n 4 - dodaj za \n 5 - dodaj przed \n 6 - usun pierwszy el. listy \n 7 - usun ostatni el. listy \n 8 - usun wyszukany el. listy \n 9 - Drukuj liste w odwrotnej kolejnosci \n 10 - Zad 5 - Odwroc liste iteracyjnie \n 11 - Zad 5 - Odwroc liste rekursywnie \n 12 - Zad 6 - Dodaj rosnaco bez wartownika \n 13 - Zad 6 - Dodaj rosnaco z wartownikiem \n 14 - zad 2 - Usun wystapienia bez rekurencji \n 15 - zad 2 - Usun wystapienia rekurencyjnie \n 0 - koniec \n");
		scanf("%i", &k);

		switch (k) {
		case 1:
			printf("Podaj element: ");
			scanf("%i", &j);
			p = dodpocz(p, j);
			druk(p);
			break;
		case 2:
			printf("Podaj element: ");
			scanf("%i", &j);
			p = dodkon(p, j);
			druk(p);
			break;
		case 3:
			printf("Co znalezc ? ");
			scanf("%i", &j);
			q = znajdz1(&p, j);
			if (*q == NULL)
				printf("Nie ma %i na liscie p \n", j);
			break;
		case 4:
			if (*q != NULL)
			{
				printf("Co dodac za znalezionym ? \n");
				scanf("%i", &j);
				dodza1(q, j);
				druk(p);
			}
			else
				printf("Nie wiem gdzie dodac \n");
			break;
		case 5:
			if (*q != NULL)
			{
				printf("Co dodac przed znalezionym ? \n");
				scanf("%i", &j);
				dodprzed1(q, j);
				q = &((*q)->nast);
				druk(p);
			}
			else
				printf("Nie wiem gdzie dodac \n");
			break;
		case 6:
			usunp1(&p);
			druk(p);
			break;
		case 7:
			usunk1(&p);
			druk(p);
			break;
		case 8:
			if (*q != NULL) {
				usunwsk(q);
				druk(p);
			}
			else
				printf("Nie znaleziono elementu listy \n");
			break;
		case 9:
			drukodwrotnie(p);
			printf("\n");
			break;
		case 10:
				printf("Lista przed odwroceniem: ");
				druk(p);
				zad5(&p);
				printf("Lista po odwroceniu: ");
				druk(p);
				break;

		case 11:
			printf("Lista przed odwroceniem: ");
			druk(p);
			zad5(&p);
			printf("Lista po odwroceniu: ");
			druk(p);
			break;

		case 12:
			printf("Podaj element: ");
			scanf("%i", &pp);
			zad6bezwartownik(&p, pp);
			druk(p);
			break;

		case 13:
			printf("Podaj element: ");
			scanf("%i", &pp);
			zad6wartownik(&p, pp);
			druk(p);

		case 14:
			printf("Wystapienia jakiej wartosci usunac z listy? \n");
			scanf("%i", &pp);
			zad2_a(&p, pp);
			printf("Aktualna lista po usunieciu: ");
			druk(p);
			break;
		}

	} while (k != 0);

	system("pause"); 
	return 0;
}

