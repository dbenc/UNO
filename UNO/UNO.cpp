#include <iostream>
#include <cstdio>
#include "Kártya.h"
#include "Kártya.cpp "
#include "Pakli.h"
#include "Pakli.cpp"
#include "Játékos.cpp"
#include "Játékos.h"
#include <fstream>
using namespace std;

#define TEST -1


COLOR FromString(const string& str)
{
	if (str == "piros")
		return piros;
	else if (str == "zold")
		return zöld;
	else if (str == "kek")
		return kék;
	else if (str == "sarga")
		return sárga;
	else
		return joker;
}


int main()
{

	deck main_deck;
	main_deck.create();
	main_deck.quick_shuffle();

	player smart;
	player random;


	deck temp_deck;
	card played_card;
	card temp_card;
	
	cout << main_deck.get_size();


	int card_flag = 0;
	while (card_flag == 0)
	{
		temp_card = main_deck.draw();
		if (temp_card.color != joker)
		{
			card_flag = 1;
			played_card = temp_card;
		}
		else
		{
			temp_deck.add_card(temp_card);
		}
	}


	
	bool force_draw_bool = false;
	int win = 0;

	while (win == 0)
	{
		if (force_draw_bool)
		{
			if (played_card.number == 10)
			{
				cout << "Huzz kettot!" << endl;
				card draw_2;
				draw_2 = main_deck.draw();
				random.add_card(draw_2, 2);
			}

			if (played_card.number == 14)
			{
				cout << "Huzz negyet!" << endl;
				card draw_4;
				draw_4 = main_deck.draw();
				random.add_card(draw_4, 2);

			}
			force_draw_bool = false;
		}


		random.drop_card(random.random_move(played_card, main_deck));





	}
	
	

	std::cin.get();

	return 0;
}
