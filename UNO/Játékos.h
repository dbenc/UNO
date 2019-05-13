#ifndef JÁTÉKOS_H
#define JÁTÉKOS_H

#include "Kártya.h"
class player
{
	public:
			player();
			void add_card(card temp_card, int i);
			void print_hand();
			int random_move(card table_card, deck deck);
			int smart_move(card table_card, deck deck);
			card drop_card(int pos);
			card joker_rand(card temp_card);
			card joker_smart(card temp_card);
			int get_size() const;

	private:
		card* hand;
		int size;

};

#endif 
