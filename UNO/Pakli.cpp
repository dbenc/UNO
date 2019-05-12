/* Pakli tartalma:
	19 kék kártya: 0-9;
	19 zöld kártya: 0-9;
	19 piros kártya: 0-9;
	19 sárga kártya: 0-9
	„8 Húzz kettőt!” kártya: 2 kék, 2 zöld, 2 piros, 2 sárga
	„8 Fordulj! kártya”: 2 kék, 2 zöld, 2 piros, 2 sárga
	„8 Ugorj!” kártya: 2 kék, 2 zöld, 2 piros, 2 sárga
	„4 Színválasztó” kártya;
	„4 Húzz négyet! Színválasztó” kártya
*/


/*
01234 =  "szín" és a szín
0 = "szín"
1 = piros
2 = zöld
3 = kék
4 = sárga
*/




#define DECK_SIZE 108

#include "Pakli.h"
#include "Kártya.h"
#include <iostream>
#include <cstdlib>
#include  <ctime>
using namespace std;

deck::deck()
{
	ptr_deck = new card[DECK_SIZE];
	size = 0;


}

void deck::create()
{
	int num = 0;


	// 0 kártyák
	for (int col = 1; col <= 4; col++)
	{
		ptr_deck[size].number = num;
		ptr_deck[size].color = static_cast<COLOR>(col);
		size++;
	}

	// kártyák: 1 - 9 , "ugorj!", "húzz kettőt", "fordulj!"
	for (num = 1; num <= 12; num++)
	{
		for (int x = 0; x < 2; x++)
		{
			for (int col = 1; col <= 4; col++)
			{
				ptr_deck[size].number = num;
				ptr_deck[size].color = static_cast<COLOR>(col);
				size++;
			}
		}

	}

	// kártyák: "színválasztó", "szín húzz négyet"
	for (num = 13; num <= 14; num++)
	{
		for (int x = 0; x < 4; x++)
		{
			ptr_deck[size].number = num;
			ptr_deck[size].color = joker;
			size++;
		}
	}


}

deck::deck(const deck & other)
{
	copy(other);
}


const deck & deck::operator= (const deck & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}



deck::~deck()
{
	clear();
}




void deck::shuffle()
{
	/* rand csere vagy marad egy adott kártya  ( több esély a cserére)*/
	/* rand hova cserélje a kártyát (rand 0-tól 107-ig inklúzív)*/

	/* O(n^2) keverés */
	/* átmeneti array létrehozása ami másolja az eredetit */
	/* kiválasztott elem másolása az átmenetiből az arr[0]-be */
	/* ismétlés */


	// átmeneti pakli létrehozása
	card* temp_deck = new card[size];
	for (int i = 0; i < size; i++)
	{
		temp_deck[i] = ptr_deck[i];
	}


	int temp_size = size;
	int temp_pos;
	int pos;
	for (int i = 0; i < size; i++)
	{
		// véletlen pozíció a temp_deck-ben
		srand(time(NULL)); // minden alkalommal más szám
		pos = rand() % temp_size;
		//véletlen elem deck[i]-hez rendelése
		ptr_deck[i] = temp_deck[pos];

		// elem eltávolítása a temp_deck-ből 
		temp_size--;
		for (temp_pos = pos; temp_pos < temp_size; temp_pos++)
		{
			temp_deck[temp_pos] = temp_deck[temp_pos + 1];
		}
	}

	delete[] temp_deck;



}
card deck::draw()
{
	if (size <= 0)
	{ 
		return card();
	}
	card temp_card = ptr_deck[size - 1];
	size--;
	return temp_card;
}


int deck::add_card(card temp_card)
{
	if (size < DECK_SIZE)
	{
		ptr_deck[size] = temp_card;
		size++;
		return 0;
	}
	else
		return -1;
}


void deck::quick_shuffle()
{
	/* O(n) keverés(fisher-yates) algoritmus
		rand() alapján véletlen számot generál O(1)-ben
		az utolsó elemtől kezd
		kicseréli egy véletlen választott elemmel amit az egész array-ből választ beleértve az előzőt is
		vegyük az array-t 0-tól n-2-ig(a méret egyel kisebb )
		ismétlés amíg a első elemhez nem érünk
	*/
	int pos;
	int temp_size = size - 1;
	card temp_card;
	while (temp_size > 0)
	{
		srand(time(NULL));
		pos = rand() % temp_size;
		// elemcsere
		temp_card = ptr_deck[temp_size];
		ptr_deck[temp_size] = ptr_deck[pos];
		ptr_deck[pos] = temp_card;
		// méret kicsinyítése egyel
		temp_size--;
	}

}



void deck::print_deck()
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << ptr_deck[i] << endl;
	}
}

void deck::copy(const deck & other)
{
	size = other.size;
	ptr_deck = new card[size];
	for (int i = 0; i < size; i++)
	{
		ptr_deck[i] = other.ptr_deck[i];
	}
}


void deck::clear()
{
	delete[]ptr_deck;
	ptr_deck = NULL;
	size = 0;
}


int deck::get_size()
{
	return size;
}

