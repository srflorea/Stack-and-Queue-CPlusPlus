#pragma once

#include <iostream>

#include "linked_list.h"

using namespace std;

struct sites
{
	char *URL;
	int day;
};

struct Node{
	sites *array;
	int nrElem;
};

class Deque
{
	private:
		LinkedList<struct Node> LL;
		int size;
		
	public:
		Deque(int N)
		{
			size = N;
		}
		
		void pushFront(char *x, int day)
		{
			if(isEmpty())
			{
				struct Node n;
				n.array = new sites[size];
				n.nrElem = 0;
				LL.addFirst(n);
				LL.pfirst->info.array[0].URL = x;
				LL.pfirst->info.array[0].day = day;
				LL.pfirst->info.nrElem ++;
				return;
			}
			
			else if(LL.pfirst->info.nrElem == size)
			{
				struct Node n;
				n.array = new sites[size];
				n.nrElem = 0;
				LL.addFirst(n);
				LL.pfirst->info.array[0].URL = x;
				LL.pfirst->info.array[0].day = day;
				LL.pfirst->info.nrElem ++;
				return;
			}
			
			else
			{
				for(int i = LL.pfirst->info.nrElem - 1; i >= 0 ; i--)
					LL.pfirst->info.array[i + 1] = LL.pfirst->info.array[i];
					
				LL.pfirst->info.array[0].URL = x;
				LL.pfirst->info.array[0].day = day;
				LL.pfirst->info.nrElem ++;
				return;
			}
		}
	
		void pushBack(char *x, int day)
		{
			if(isEmpty())
			{
				struct Node n;
				n.array = new sites[size];
				n.nrElem = 0;
				LL.addLast(n);
				LL.plast->info.array[0].URL = x;
				LL.plast->info.array[0].day = day;
				LL.plast->info.nrElem ++;
				return;
			}
			
			else if(LL.plast->info.nrElem == size)
			{
				struct Node n;
				n.array = new sites[size];
				n.nrElem = 0;
				LL.addLast(n);
				LL.plast->info.array[0].URL = x;
				LL.plast->info.array[0].day = day;
				LL.plast->info.nrElem ++;
				return;
			}
			
			else
			{
				LL.plast->info.array[LL.plast->info.nrElem].URL = x;
				LL.plast->info.array[LL.plast->info.nrElem].day = day;
				LL.plast->info.nrElem ++;
				return;
			}
		}
		
		int back()
		{
			return LL.plast->info.array[LL.plast->info.nrElem - 1].day;
		}
		
		int front()
		{
			return LL.pfirst->info.array[0].day;
		}
		
		void popBack()
		{
			if(LL.isEmpty())
				return;
				
			else if(LL.plast->info.nrElem == 1)
			{
				delete[] LL.plast->info.array;
				LL.removeLast();
				return;
			}
				
			else
			{
				LL.plast->info.nrElem --;
				return;
			}
		}
		
		void popFront()
		{
			if(LL.isEmpty())
				return;
				
			else if(LL.pfirst->info.nrElem == 1)
			{
				delete[] LL.pfirst->info.array;
				LL.removeFirst();
				return;
			}
			
			else
			{
				for(int i = 0; i < LL.pfirst->info.nrElem - 1; i++)
					LL.pfirst->info.array[i] = LL.pfirst->info.array[i + 1];
					
				LL.pfirst->info.nrElem --;
				return;
			}
		}
		
		void erase(int i)
		{
			
			struct list_elem<Node> *paux;
			paux = LL.pfirst;
			
			while(paux)
			{
				if(i < paux->info.nrElem)
					break;
				
				else
				{
					i -= paux->info.nrElem;
					paux = paux->next;
				}
			}
			
			if(paux)
			{
				if(paux->info.nrElem == 1)
				{
					delete[] paux->info.array;
					LL.removeNode(paux);
					return;
				}
				
				else
				{
					for(int j = i; j < paux->info.nrElem - 1; j++)
						paux->info.array[j] = paux->info.array[j + 1];
					
					paux->info.nrElem --;
					return;
				}
			}
			delete paux;
		}
		
		sites get(int i)
		{	
			struct list_elem<Node> *paux = new struct list_elem<Node>;
			paux = LL.pfirst;
			
			while(paux)
			{
				if(i < paux->info.nrElem)
					break;
				
				else
				{
					i -= paux->info.nrElem;
					paux = paux->next;
				}
			}
			
			if(paux)
				return paux->info.array[i];
				
			else
			{
				cout << "out of range\n";
				delete paux;
			}
			
			delete paux;
			sites x;
			return x;
		}
		
		bool isEmpty()
		{
			return LL.isEmpty();
		}
		
		void print()
		{
			struct list_elem<Node> *p;
			p = LL.pfirst;
			while(p != NULL)
			{
				for(int i = 0; i < p->info.nrElem; i++)
				{
					cout << p->info.array[i].day << " ";
					cout << p->info.array[i].URL << "\n";
				}
				p = p->next;
			}
		}
		

		
		
				
};

















