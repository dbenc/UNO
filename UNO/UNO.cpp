/*	
	A játék két részből áll:
	Az elsőben előkészíti, megcsinálja a paklit, a játékosokat, oszt, kever stb.
	A második maga a meccs ami addig megy amíg az egyik játékosnak el nem fogynak a lapjai
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include "Kártya.h"
#include "Pakli.h"
#include "Játékos.h"

using namespace std;


int main()
{
	// A fő pakli előkészítése
	deck main_deck;
	main_deck.create();
	main_deck.shuffle();

	// Játékosaink
	player random1;
	player random2;
	player smart;


	//Húzás
	for (int i = 0; i < 7; i++)
	{
		card tempcard;
		tempcard = main_deck.draw();
		random1.add_card(tempcard);
	}

	for (int i = 0; i < 7; i++)
	{
		card tempcard;
		tempcard = main_deck.draw();
		random2.add_card(tempcard);
	}

	for (int i = 0; i < 7; i++)
	{
		card tempcard;
		tempcard = main_deck.draw();
		smart.add_card(tempcard);
	}

	// Ezek a letett kártyák 
	deck temp_deck;
	card played_card;
	card temp_card;

	// Induló kártya kihúzása
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

	do
	{
		cout << '\n' << "Huzas vege nyomj gombot...";
	} while (cin.get() != '\n');

	random1.print_hand();
	smart.print_hand();
	random2.print_hand();

	cout << "kezdokartya :" << played_card << endl;

	card chosen_card;

	do
	{
		cout << '\n' << "A meccs kezdesehez nyomj gombot...";
	} while (cin.get() != '\n');

	int win = 0;


	// Maga a meccs 
	while (win == 0)
	{
		cout << " Fo pakli allapota: " << main_deck.get_size() << endl;
		cout << " Lerakott kartyak: " << temp_deck.get_size() << endl;


		do
		{
			cout << '\n' << "A kor kezdesehez nyomj gombot...";
		} while (cin.get() != '\n');


		//Első játékos
		cout << "Random jön" << endl;


		// Ellenőrzik hogy a letett lap nem húzat-e fel vele lapot
		if (played_card.number == 10)
		{
			cout << "Huzz kettot!" << endl;
			
			for (int i = 0; i < 2; i++)
			{
				card draw_2;
				draw_2 = main_deck.draw();
				random1.add_card(draw_2);
			}
		}

		if (played_card.number == 14)
		{
			cout << "Huzz negyet!" << endl;
			for (int i = 0; i < 4; i++)
			{
				card draw_4;
				draw_4 = main_deck.draw();
				random1.add_card(draw_4);
			}

		}

		//  A következő kettő statement azt nézi, hogy nem marad-e ki a játékos
		// ezért kell turn_move mert ezek statementek a számot nézik
		if (played_card.number == 11)
		{
			cout << "Smart jon" << endl;
			

			chosen_card = smart.drop_card(smart.move_turn(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				smart.add_card(main_deck.draw());
			}

			cout << "smart lerakja :" << played_card << endl;
		
			if (smart.get_size() == 0)
			{
				win = 1;
				cout << "PLAYER nyert." << endl;
				break;
			}

			cout << "smnart keze:" << endl;

			smart.print_hand();

			if (smart.get_size() == 1)
			{
				cout << "UNO!";
			}
		
		}

		else if (played_card.number == 12)
		{
			cout << "Smart jon" << endl;
			

			chosen_card = smart.drop_card(smart.move_turn(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				smart.add_card(main_deck.draw());
			}

			cout << "smart lerakja :" << played_card << endl;

			if (smart.get_size() == 0)
			{
				win = 1;
				cout << "smart nyert." << endl;
				break;
			}

			cout << "smart keze:" << endl;
			smart.print_hand();

			if (smart.get_size() == 1)
			{
				cout << "UNO!";
			}
		}
		else
		{
			//Kiválasztja a megjátszandó lapot
			chosen_card = random1.drop_card(random1.move_rand(played_card));

			// A kapott szám alapján húz vagy megjátsza a lapot
			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);
				played_card = chosen_card;
			}
			else
			{
				random1.add_card(main_deck.draw());
			}

			played_card = random1.joker_rand(played_card);

		}

		cout << "random lerakja:" << played_card << endl;

		// Nézi hogy nyert-e
		if (random1.get_size() == 0)
		{
			win = 1;
			cout << "random1 a nyertes." << endl;
			break;
		}

		cout << "random1 keze:" << endl;

		random1.print_hand();

		if (random1.get_size() == 1)
		{
			cout << "UNO!";
		}

		cout << "Smart kovetkezik" << endl;

	
		if (played_card.number == 10)
		{
			cout << "Huzz kettot!" << endl;

			for (int i = 0; i < 2; i++)
			{
				card draw_2;
				draw_2 = main_deck.draw();
				smart.add_card(draw_2);
			}
		}

		if (played_card.number == 14)
		{
			cout << "Huzz negyet!" << endl;
			for (int i = 0; i < 4; i++)
			{
				card draw_4;
				draw_4 = main_deck.draw();
				smart.add_card(draw_4);
			}
			
		}


		if (played_card.number == 11)
		{
			cout << "Random2 jon" << endl;

			chosen_card = random2.drop_card(random2.move_turn(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				smart.add_card(main_deck.draw());
			}

			cout << "random2 lerakja :" << played_card << endl;


			if (random2.get_size() == 0)
			{
				win = 1;
				cout << "random2 nyert." << endl;
				break;
			}

			cout << "random2 keze:" << endl;
			random2.print_hand();

			if (random2.get_size() == 1)
			{
				cout << "UNO!";
			}

		}
		else if (played_card.number == 12)
		{
			cout << "Random2 jon" << endl;

			chosen_card = random2.drop_card(random2.move_turn(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				random2.add_card(main_deck.draw());
			}

			cout << "random2 lerakja :" << played_card << endl;

			if (random2.get_size() == 0)
			{
				win = 1;
				cout << "random2 nyert." << endl;
				break;
			}

			cout << "random2 keze:" << endl;
			random2.print_hand();

			if (random2.get_size() == 1)
			{
				cout << "UNO!";
			}
		}
		else
		{
			chosen_card = smart.drop_card(smart.move_smart(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				smart.add_card(main_deck.draw());
			}

			played_card = smart.joker_rand(played_card);
		}

		cout << "smart lerakja :" << played_card << endl;

		cout << "smart keze:" << endl;

		smart.print_hand();

		if (smart.get_size() == 1)
		{
			cout << "UNO!";
		}

		if (smart.get_size() == 0)
		{
			win = 1;
			cout << "smart nyerte a meccset." << endl;
			break;
		}

		cout << "Random2 kovetkezik" << endl;


		if (played_card.number == 10)
		{
			cout << "Huzz kettot!" << endl;

			for (int i = 0; i < 2; i++)
			{
				card draw_2;
				draw_2 = main_deck.draw();
				random2.add_card(draw_2);
			}
		}

		if (played_card.number == 14)
		{
			cout << "Huzz negyet!" << endl;
			for (int i = 0; i < 4; i++)
			{
				card draw_4;
				draw_4 = main_deck.draw();
				random2.add_card(draw_4);
			}

		}


		if (played_card.number == 11)
		{
			cout << "random1 jatekos kovetkezik"<< endl;


			chosen_card = smart.drop_card(smart.move_turn(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				smart.add_card(main_deck.draw());
			}

			cout << "random1 lerakja :" << played_card << endl;

			if (smart.get_size() == 0)
			{
				win = 1;
				cout << "A meccset random1 nyerte." << endl;
				break;
			}

			cout << "random1 keze:" << endl;
			smart.print_hand();

			if (random1.get_size() == 1)
			{
				cout << "UNO!";
			}

		}
		else if (played_card.number == 12)
		{
			cout << "random1 jatekos kovetkezik" << endl;

			chosen_card = random1.drop_card(random1.move_turn(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);

				played_card = chosen_card;
			}
			else
			{
				random1.add_card(main_deck.draw());
			}

			cout << "random1 lerakja :" << played_card << endl;

			cout << "random1 keze:" << endl;
			random1.print_hand();

			if (random1.get_size() == 0)
			{
				win = 1;
				cout << "A meccset random1 nyerte." << endl;
				break;
			}

			if (random1.get_size() == 1)
			{
				cout << "UNO!";
			}
		}
		else
		{

			chosen_card = random2.drop_card(random2.move_rand(played_card));

			if (chosen_card.number != 99)
			{
				temp_deck.add_card(chosen_card);
				played_card = chosen_card;
			}
			else
			{
				random2.add_card(main_deck.draw());
			}

			played_card = random2.joker_rand(played_card);

		}

		cout << "random2 lerakta:" << played_card << endl;

		if (random2.get_size() == 0)
		{
			win = 1;
			cout << "A meccset random2 nyerte." << endl;
			break;
		}

		cout << "random2 keze:" << endl;

		random2.print_hand();

		if (random2.get_size() == 1)
		{
			cout << "UNO!";
		}


		// Ha fogy a főpakli visszakeveri a letett lapokat
		if (main_deck.get_size() < 10)
		{
			for (int i = 0; i < main_deck.get_size(); i++)
			{
				temp_deck.add_card(main_deck.draw());
			}
			main_deck = temp_deck;
			main_deck.quick_shuffle();
			temp_deck = deck();
		}

		do
		{
			cout << '\n' << "Nyomj egy gombot a kor vegehez...";
		} while (cin.get() != '\n');

	}

	return 0;
}
