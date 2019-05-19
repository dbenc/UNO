/*	Két fajta játékosom van: az egyik "random", a másik a "smart".
	Mivel nem igazán találtam jó taktikát arra hogyan lehet nyerni UNO-ban,
	ezért csak néhány helyen van különbség a két fajta játékos között.
*/



#ifndef JÁTÉKOS_H
#define JÁTÉKOS_H

#include "Kártya.h"
#include <vector> 
using namespace std;


class player
{
	public:
		player()
		{}
		~player()
		{}
		void add_card(card temp_card);
		void print_hand();
		int move_rand(card table_card);
		int move_smart(card table_card);
		int move_turn(card table_card);
		card drop_card(unsigned pos);
		card joker_rand(card temp_card);
		card joker_smart(card temp_card);
		void print_size();
		int get_size();

	private:
		std::vector <card> hand;

};


#endif 
