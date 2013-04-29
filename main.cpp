#include <cstdio>
#include <iostream>
#include <cstring>

#include "deque.h"

/* Functie care incrementeaza ziua si sterge intrarile mai vechi decat maxDays
 */
void dayPasses(Deque *d, int maxDays, int *day)
{
	(*day) ++;
	if(*day >= maxDays)
	{
		int x = *day - maxDays;
		while(d->back() <= x)
		{
			d->popBack();
		}
	}
}

/* Functie care sterge intrarile recente
 */
void clearRecentHistory(Deque *d, int noDays, int day)
{
	if(noDays >= day)
	{
		while(!d->isEmpty())
			d->popFront();
		return;
	}
	while(day-d->front() + 1 <= noDays)
	{
		int x = d->front();
		while(x == d->front())
			d->popFront();
	}
}

/* Functie care modifica numarul maxis de zile la valoare noDays si strege
 * intrarile devenite vrea vechi 
 */
void setMaxDays(Deque *d, int *maxDays, int day, int noDays)
{
	(*maxDays) = noDays;
	if(day >= *maxDays)
	{
		int x = day - *maxDays;
		while(d->back() <= x )
		{
			d->popBack();
		}
	}
}

/* Functie care importa intrari in deque dintr-un fisier, pe care la aduga la
 * coada
 */
void recoverHistory(Deque *d, char fileName[], int day, int maxDays )
{
	FILE* f = fopen(fileName, "r");
	if(f == NULL)
	{
		printf("Couldn't open file %s\n", fileName);
		return;
	}
	
	int N;
	fscanf(f, "%d", &N);
	
	for(int i = 0; i < N; i++)
	{
		int zi;
		char *link = new char[40];
		fscanf(f, "%d%s", &zi, link);
		d->pushBack(link, zi);
	}
}

int main()
{
	int N;
	int day = 0;
	int maxDays = 30;
	fscanf(stdin, "%d", &N);
	char word[30];
	
	Deque *d = new Deque(N);
	
	while(fscanf(stdin,"%s", word) == 1)
	{
		if(strcmp(word, "DAY_PASSES") == 0)
		{
			dayPasses(d, maxDays, &day);
		}
		
		else if(strcmp(word, "ACCESS_PAGE") == 0)
		{
			char *URL = new char[40];
			fscanf(stdin, "%s", URL);
			d->pushFront(URL, day); //adauga o intrare in deque
			
		}
		
		else if(strcmp(word, "CLEAR_RECENT_HISTORY") == 0)
		{
			int no_days;
			fscanf(stdin, "%d", &no_days);
			clearRecentHistory(d, no_days, day);
		}
		
		else if(strcmp(word, "SET_MAX_DAYS") == 0)
		{
			int no_days;
			fscanf(stdin, "%d", &no_days);
			setMaxDays(d, &maxDays, day, no_days);
		}
		
		else if(strcmp(word, "SHOW_ENTRY") == 0)
		{
			//afiseaza intrarea de la indexul index
			int index;
			fscanf(stdin, "%d", &index);
			printf("\nENTRY %d:\n%d %s\n",index, d->get(index).day, d->get(index).URL); 
		}
		
		else if(strcmp(word, "DELETE_ENTRY") == 0)
		{
			int index;
			fscanf(stdin, "%d", &index);
			d->erase(index); //sterge intrarea de la indexul index
		}
		
		else if(strcmp(word, "SHOW_HISTORY") == 0)
		{
			if(day >= maxDays)
			{
				int x = day - maxDays;
				while(d->back() <= x)
				{
					d->popBack();
				}
			}
			printf("HISTORY:\nCurrent day: %d\n", day);
			d->print(); //afiseaza toate intrarile din deque
		}
		
		else if(strcmp(word, "RECOVER_HISTORY") == 0)
		{
			char file_name[30];
			fscanf(stdin, "%s", file_name);
			recoverHistory(d, file_name, day, maxDays);
		}
	}
	return 0;
}













