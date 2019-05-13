<<<<<<< HEAD
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

void player::add_card(card temp_card, int l)
{
	for (int i = 0; i < l; i++)
	{
		hand[size] = temp_card;
		size++;
	}
	
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
			{
				return start;
			}
			else if (count++ <= 3)
			{
				return start;
			}
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

card player::joker_rand(card temp_card)
{
	if (temp_card.color == joker)
	{
		temp_card.color == zöld;
		return temp_card;
	}
	else
	{
		temp_card.color == temp_card.color;
		return temp_card;
	}
}

card player::joker_smart(card temp_card)
{
	if (temp_card.color == joker)
	{
		int max_count = 0;
		for (int i = 0; i < size; i++)
		{
			int count = 1;
			for (int j = i + 1; j < size; j++)
				if (hand[i] == hand[j])
					count++;
			if (count > max_count)
				max_count = count;
		}

		for (int i = 0; i < size; i++)
		{
			int count = 1;
			for (int j = i + 1; j < size; j++)
				if (hand[i] == hand[j])
					count++;
			if (count == max_count)
				temp_card.color == hand[i].color;
		}
		return temp_card;
	}
	else
	{
		temp_card.color == temp_card.color;
		return temp_card;
	}
}



int player::get_size() const
{
	return size;
=======
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

void player::add_card(card temp_card, int l)
{
	for (int i = 0; i < l; i++)
	{
		hand[size] = temp_card;
		size++;
	}
	
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
			{
				return start;
			}
			else if (count++ <= 3)
			{
				return start;
			}
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
>>>>>>> 96a167121ae05b2c679c8c13053c0ae5cfe43afa
}