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


int main()
{

	deck main_deck;
	main_deck.create();
	main_deck.quick_shuffle();

	player smart;
	player random;

	random.add_card(main_deck.draw(), 2);
	smart.add_card(main_deck.draw(), 2);

	deck temp_deck;
	card played_card;
	card temp_card;
	


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

		if (played_card.number == 11)
		{
			played_card = smart.drop_card(smart.smart_move(played_card, main_deck));
			played_card = smart.joker_rand(played_card);

			if (smart.get_size() == 0)
			{
				win = 1;
				cout << "PLAYER smart has won the game." << endl;
				break;
			}
		}
		else if (played_card.number == 12)
		{
			played_card = smart.drop_card(smart.smart_move(played_card, main_deck));
			played_card = smart.joker_rand(played_card);

			if (smart.get_size() == 0)
			{
				win = 1;
				cout << "PLAYER smart has won the game." << endl;
				break;
			}
		}
		else 
		{
			played_card = random.drop_card(random.random_move(played_card, main_deck));
			played_card = random.joker_rand(played_card);
		}

		random.print_hand();

		if (random.get_size() == 0)
		{
			win = 1;
			cout << "PLAYER random has won the game." << endl;
			break;
		}

		if (force_draw_bool)
		{
			if (played_card.number == 10)
			{
				cout << "Huzz kettot!" << endl;
				card draw_2;
				draw_2 = main_deck.draw();
				smart.add_card(draw_2, 2);
			}

			if (played_card.number == 14)
			{
				cout << "Huzz negyet!" << endl;
				card draw_4;
				draw_4 = main_deck.draw();
				smart.add_card(draw_4, 2);

			}
			force_draw_bool = false;
		}

		if (played_card.number == 11)
		{
			played_card = random.drop_card(random.random_move(played_card, main_deck));
			played_card = random.joker_rand(played_card);

			if (random.get_size() == 0)
			{
				win = 1;
				cout << "PLAYER random has won the game." << endl;
				break;
			}
		}
		else if (played_card.number == 12)
		{
			played_card = random.drop_card(random.random_move(played_card, main_deck));
			played_card = random.joker_rand(played_card);

			if (random.get_size() == 0)
			{
				win = 1;
				cout << "PLAYER random has won the game." << endl;
				break;
			}
		}
		else
		{
			played_card = smart.drop_card(smart.smart_move(played_card, main_deck));
			played_card = smart.joker_rand(played_card);
		}

		smart.print_hand();

		if (smart.get_size() == 0)
		{
			win = 1;
			cout << "PLAYER smart has won the game." << endl;
			break;
		}

	}
	std::cin.get();

	return 0;
}
