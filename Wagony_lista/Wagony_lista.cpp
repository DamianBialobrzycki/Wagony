#include "stdafx.h"

#include <iostream>

struct lista
{
	lista * nastepny;
	int numer;

};

struct stos
{
	lista * S; // lista przechowująca stos

	stos(); // konstruktor
	~stos(); // destruktor
	bool pusty(void);
	lista * top(void);
	void push(int v);
	void pop(void);
	void pokaz(void);
	bool posortowane();
	void odwroc(lista * & head);
};

stos::stos()
{
	S = NULL;

}

stos::~stos()
{
	while (S) pop();

}

bool stos::pusty(void)
{
	return !S;
}

lista * stos::top(void)
{
	return S;
}

void stos::push(int v)
{
	lista * e = new lista;
	e->numer = v;
	e->nastepny = S;
	S = e;

	//delete e;
}

void stos::pop(void)
{
	if (S)
	{
		lista * e = S;
		S = S->nastepny;
		//delete e;
	}

}

void stos::pokaz()
{
	lista * tmp;
	tmp = top();
	if (tmp == NULL)
	{
		std::cout << "PUSTE";
		return;
	}

	while (tmp != NULL)
	{
		
		if (tmp->nastepny != NULL)
			printf("%d ", tmp->numer);
		else
		{
			printf("%d", tmp->numer);
			break;
		}
		tmp = tmp->nastepny;
	}
	//delete tmp;
}

void stos::odwroc(lista * & head)
{
	lista * p, *pc;
	if (head)
	{
		pc = head;
		while (pc->nastepny)
		{
			p = pc->nastepny;
			pc->nastepny = p->nastepny;
			p->nastepny = head;
			head = p;
		}
	}
}

bool stos::posortowane()
{
	lista * tmp;
	tmp = top();
	while (tmp != NULL)
	{
		if (tmp->nastepny == NULL)
			break;
		else
		{
			if (tmp->nastepny->numer > tmp->numer)
				return false;
		}
		tmp = tmp->nastepny;
	}
	return true;
}


int main()
{
	int iloscWagonow = 0;
	int numerWagonu = 0;
	bool posortowane = false;


	stos * torBoczny = new stos();
	stos * bocznica = new stos();
	stos * torGlowny = new stos();

	std::cin >> iloscWagonow;

	for (int i = 0; i < iloscWagonow; i++)
	{
		std::cin >> numerWagonu;
		torBoczny->push(numerWagonu);
	}

	torBoczny->odwroc(torBoczny->S);


	int licznik = 0;

	while (true)
	{	
		licznik++;
		//std::cout << "krok: " << licznik << std::endl;
		if (torBoczny->S != NULL)
		{
			if (torBoczny->S->nastepny != NULL)
			{
				//std::cout << "jestem tu1" << std::endl;
				if (torBoczny->S->numer < torBoczny->S->nastepny->numer)
				{
					//std::cout << "z bocznego na glowny jezeli jest nastepnik" << std::endl;
					//std::cout << torBoczny->S->numer << std::endl;
					torGlowny->push(torBoczny->S->numer);
					torBoczny->pop();
					//continue;
				}
				else
				{
					if (bocznica->S != NULL)
					{
						if (torBoczny->S->numer > bocznica->S->numer)
						{
							//std::cout << "z bocznicy an glowny jest cos na bocznicy" << std::endl;
							torGlowny->push(bocznica->S->numer);
							bocznica->pop();
						}
						else
						{
							//std::cout << "z bocznego na bocznice" << std::endl;
							bocznica->push(torBoczny->S->numer);
							torBoczny->pop();
						}
					}
					else
					{
						//std::cout << "z bocznego na bocznice" << std::endl;
						bocznica->push(torBoczny->S->numer);
						torBoczny->pop();
					}

					
					
					//continue;

				}
			}
			else
			{
				if (bocznica->S != NULL)
				{
					if (torBoczny->S->numer > bocznica->S->numer)
					{
						//std::cout << "z bocznicy an glowny jest cos na bocznicy" << std::endl;
						torGlowny->push(bocznica->S->numer);
						bocznica->pop();
					}
					else
					{
						//std::cout << "z bocznego na bocznice" << std::endl;
						bocznica->push(torBoczny->S->numer);
						torBoczny->pop();
					}
				}
				else
				{
					//std::cout << "z bocznego na bocznice" << std::endl;
					bocznica->push(torBoczny->S->numer);
					torBoczny->pop();
				}

				/*std::cout << "z bocznego an glowny2" << std::endl;
				torGlowny->push(torBoczny->S->numer);
				torBoczny->pop();*/
				//continue;
			}
		}
		

		if (torBoczny->S == NULL && bocznica->S != NULL)
		{
			//std::cout << "z bocznicy an glowny kocnowy" << std::endl;
				torGlowny->push(bocznica->S->numer);
				bocznica->pop();
				//continue;
		}

		/*std::cout << "===============\n";
		std::cout << "TG: ";
		torGlowny->pokaz();
		std::cout << std::endl;
		std::cout << "B: ";
		bocznica->pokaz();
		std::cout << std::endl;
		std::cout << "TB: ";
		torBoczny->pokaz();
		std::cout << "\n===============\n";
		std::cout << std::endl;*/

		if (torBoczny->S == NULL && bocznica->S == NULL)
			break;
	}

	//torGlowny->odwroc(torGlowny->S);

	if (torGlowny->posortowane())
		std::cout << "TAK";
	else
		std::cout << "NIE";

	
	/*std::cout << "TG: "; 
	torGlowny->pokaz();
	std::cout << std::endl;
	std::cout << "B: ";
	bocznica->pokaz();
	std::cout << std::endl;
	std::cout << "TB: ";
	torBoczny->pokaz();
	std::cout << std::endl;*/
	
	delete torBoczny;
	delete torGlowny;
	delete bocznica;

    return 0;
}

