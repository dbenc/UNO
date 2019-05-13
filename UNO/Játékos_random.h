#ifndef JÁTÉKOS_RANDOM_H
#define JÁTÉKOS_RANDOM_H

#include "Kártya.h"
class rplayer
{
	public:
			rplayer();
			void rand_add_card(card temp_card, int i);
			void rand_print_hand();
			int random_move(card table_card, deck deck);
			card rand_drop_card(int pos);
			int rand_get_size() const;

	private:
		card* r_hand;
		int size;

};

#endif 
