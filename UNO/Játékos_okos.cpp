#include "Kártya.h"
#include "Játékos_okos.h"
#include <iostream>
#include <string.h>
using namespace std;

player::player()
{
	hand = new card[s_size];
	s_size = 0;
}

void player::add_card(card temp_card, int i)
{
	hand[i] = temp_card;
	s_size++;
}

void player::print_hand()
{
	for (int i = 0; i < s_size; i++)
	{
		cout << i << ": " << hand[i];
	}
}

int player::smart_move(card table_card, deck deck)
{
	int count = 0;
	for (int start = 0; start < s_size + 1; start++)
	{
		if (table_card.number == hand[start].number)
		{
			for (int j = start + 1; j < s_size; j++)
			{
				if (hand[start].color == hand[j].color)
				{
					count++;
					break;
				}
			}
			if (count++ >= 3)

			return start;
		}
		else if (table_card.color == hand[start].color)
		{
			for (int i = 1; i < s_size; ++i)
			{
				if (hand[start].number < hand[i].number)
					{
						hand[start].number = hand[i].number;
					}
			}
			return start;
		}
		else if (start == s_size)
		{
			hand[start] = deck.draw();
			s_size++;
			return 66;
		}
	}
}

card player::drop_card(int pos)
{
	card temp_card;
	if (pos >= s_size)
	{

	}
	else if (pos == s_size)
	{
		temp_card = hand[pos];
		s_size--;
		return temp_card;
	}
	else
	{
		temp_card = hand[pos];
		memmove(hand + pos, hand + (pos + 1), (s_size - pos - 1) * sizeof(int));
		s_size--;
		return temp_card;
	}
}



int player::get_size() const
{
	return s_size;
}