#include "Kártya.h"
#include "Játékos.h"
#include <iostream>
#include <string.h>
using namespace std;

player::player() 
{
	hand = new card[size];
	size = 0;
}

void player::add_card(card temp_card, int i)
{
	hand[i] = temp_card;
	size++;
}

void player::print_hand()
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << hand[i];
	}
}

int player::random_move(card table_card, deck deck)
{
	for (int start = 0; start < size + 1; start++)
	{
		if (table_card.number == hand[start].number)
		{
			return start;
		}
		else if (table_card.color == hand[start].color)
		{
			return start;
		}
		else if (start == size)
		{
			hand[start] = deck.draw();
			size++;
			return 66;
		}
	}
}

int player::smart_move(card table_card, deck deck)
{
	int count = 0;
	for (int start = 0; start < size + 1; start++)
	{
		if (table_card.number == hand[start].number)
		{
			for (int j = start + 1; j < size; j++)
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
			for (int i = 1; i < size; ++i)
			{
				if (hand[start].number < hand[i].number)
				{
					hand[start].number = hand[i].number;
				}
			}
			return start;
		}
		else if (start == size)
		{
			hand[start] = deck.draw();
			size++;
			return 66;
		}
	}
}


card player::drop_card(int pos)
{
	card temp_card;
	if (pos >= size)
	{

	}
	else if (pos == size)
	{
		temp_card = hand[pos];
		size--;
		return temp_card;
	}
	else
	{
		temp_card = hand[pos];
		memmove(hand + pos, hand + (pos+1), (size - pos - 1) * sizeof(int));
		size--;
		return temp_card;
	}
}



int player::get_size() const
{
	return size;
}