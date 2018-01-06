#include <iostream>
#include <string>


using namespace std;

class HeapSort
{
public:
	//deklarujemy tablic� dynamiczn�
	long size_;
	long *tab_;
	HeapSort::HeapSort()
	{
		size_ = 0;
		tab_ = 0;
	}
	HeapSort::~HeapSort()
	{
		//usuwanie tablicy dynamicznej
		delete[] tab_;
	}
	//tworzenie tablicy o rozmia�e size_
	void Createtable()
	{
		if (tab_)
		{
			delete[] tab_;
		}
			
		tab_ = new long[size_];
	}
	//ustalanie rozmiary tablicy
	void Size(long _size)
	{
		size_ = _size;
		Createtable();
	}
	//wy�wietlanie ca�ej tablicy
	void Print()
	{
		for (long i = 0; i < size_; i++)
		{
			cout << tab_[i] << " ";
		}
		std::cout << std::endl;
	}
	//wy�wietlamy tablic� pomijaj�c posortowane elementy
	void Print(long _i)
	{
		for (long i = 0; i < size_-_i; i++)
		{
			cout << tab_[i] << " ";
		}
		std::cout << std::endl;
	}
	//dodajemy element do tablicy
	void Add(long _nr, long _i)
	{
		tab_[_i] = _nr;
	}
	//kopcowanie
	void Heap(long nr_tab)
	{
		long pom = 0;
		//wykonuje si� dopiero po 1 kopcowaniu gdy mamy ju� jed� uporz�dkowan� liczb�(zamienia miejscami posortwoan� liczb� z ostatnim[nieposortowanym] elementem kopca)
		if (nr_tab != 0)
		{
			pom = tab_[0];
			tab_[0] = tab_[size_ - nr_tab];
			tab_[size_ - nr_tab] = pom;
		}
		//zmienne pomocnicze(dzia�amy urzywaj�c 2 wzor�w na "dzieci" niepa�yste[N=(i-1)/2] i parzyste[N=(i-2)/2] element�w kopca)
		long y = 0;
		long x = 0;
		for (long i = 0; i < size_- nr_tab; i++)
		{
			x = i;
			//p�tla wykonuje si� dopukie nie natrafimy na 0 element kopca
			while (x != 0)
			{
				//je�li indeks parzysty to:
				if (x % 2 == 0)
				{
					y = (x - 2) / 2;
				}
				//je�li indeks nieparzysty to:
				else
				{
					y = (x - 1) / 2;
				}
				//zamiana element�w mniejszego z wi�krzym(wi�krzy ma by� ten z mniejszym indeksem[ten po lewej stronie])
				if (tab_[x] > tab_[y])
				{
					pom= tab_[x];
					tab_[x] = tab_[y];
					tab_[y] = pom;
				}
				//teraz lecimy po "dzieciach" kopca
				x = y;
			}
		}
	}
};


int main()
{
	HeapSort h;
	long pom = 0;
	long  N = 0;
	cin >> N;
	long size_tab = 0;
	long el_tab = 0;
	while (pom < N)
	{
		cin >> size_tab;
		h.Size(size_tab);
		for (long i = 0; i < size_tab; i++)
		{
			cin >> el_tab;
			h.Add(el_tab,i);
		}
		for (long i = 0; i < size_tab; i++)
		{
			h.Heap(i);
			if (i != size_tab - 1)
			{
				h.Print(i);
			}
			else
			{
				h.Print();
			}
			
			
		}
		
		pom++;
	}
	return 0;
}