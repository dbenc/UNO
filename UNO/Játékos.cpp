/*	A játékosok "kezei" a kezükben lévő lapok.
	Ezek std::vector típusuak és ezekbe rakom a card típusú kártyáimat.
*/

#include "Kártya.h"
#include "Játékos.h"
#include <iostream>
#include <string.h>
#include <vector> 

using namespace std;

// Kártya felhúzás
void player::add_card(card temp_card)
{
	hand.push_back(temp_card);
}

void player::print_hand()
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		cout << i << ": " << hand[i] << endl;
	}
}

// Kiválasztja hogy melyik kártyát teheti le a játékos
int player::move_smart(card table_card)
{
	for (size_t start = 0; start < hand.size(); start++)
	{
		if (table_card.number == hand[start].number)
		{
			return start;
		}
		else if (table_card.color == hand[start].color)
		{
			return start;
		}
		else if (hand[start].color == joker)
		{
			return start;
		}
	}
	return 66;
}


// A különbség az előzőhöz képest hogy ő nem teszi le a színválasztót csak ha színválasztó van lent
int player::move_rand(card table_card)
{
	for (size_t start = 0; start < hand.size(); start++)
	{
		if (table_card.number == hand[start].number)
		{
			return start;
		}
		else if (table_card.color == hand[start].color)
		{
			return start;
		}
	}
	return 66;
}

// Amikor a játékos letett egy kártyát ami miatt a következő kimarad,
// nem nézi a számot nehogy ő is kimardjon (az uno fáljban majd látszik miért)
int player::move_turn(card table_card)
{
	for (size_t start = 0; start < hand.size(); start++)
	{
		if (table_card.color == hand[start].color)
		{
			return start;
		}
		else if (hand[start].color == joker)
		{
			return start;
		}
	}
	return 66;
}

// Leteszi a kártyát vagy létrehoz egy olyat ami nincs a pakliban,
// ami lényegében húzást jelent (ez is majd az uno fájlban látszik)
card player::drop_card(unsigned pos)
{
	card temp_card;


	if (pos <= hand.size())
	{
		temp_card = hand[pos];

		hand.erase(hand.begin() + pos);

		return temp_card;
	}
	else
	{
		card r;
		r.number = 99;
		r.color = piros;
		return r;
	}
}


//Ha színválasztója van, mindig zöldet kér
card player::joker_rand(card temp_card)
{
	card joker_card;

	if (temp_card.color == joker)
	{
		joker_card.color = zöld;
		return joker_card;
	}
	else
	{
		return temp_card;
	}
}


//Színválasztónál azt a színt kéri amiből a legtöbbje van
card player::joker_smart(card temp_card)
{
	card joker_card;

	if (temp_card.color == joker)
	{
		int max_count = 0;
		for (size_t i = 0; i < hand.size(); i++)
		{
			int count = 1;
			for (size_t j = i + 1; j < hand.size(); j++)
			{
				if (hand[i].color == hand[j].color)
					count++;
			}
			if (count > max_count)
			{
				max_count = count;
			}
		}

		for (size_t i = 0; i < hand.size(); i++)
		{
			int count = 1;
			for (size_t j = i + 1; j < hand.size(); j++)
			{
				if (hand[i].color == hand[j].color)
					count++;
			}
			if (count == max_count)
			{
				joker_card.color = hand[i].color;
			}
		}
		return joker_card;
	}
	else
	{
		return temp_card;
	}
}



void player::print_size()
{
	cout << hand.size() << endl;
}

int player::get_size()
{
	int size = static_cast<int>(hand.size());
	return size;
}