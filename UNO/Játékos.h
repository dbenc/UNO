/*	K�t fajta j�t�kosom van: az egyik "random", a m�sik a "smart".
	Mivel nem igaz�n tal�ltam j� taktik�t arra hogyan lehet nyerni UNO-ban,
	ez�rt csak n�h�ny helyen van k�l�nbs�g a k�t fajta j�t�kos k�z�tt.
*/



#ifndef J�T�KOS_H
#define J�T�KOS_H

#include "K�rtya.h"
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
