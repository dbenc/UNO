/* Pakli tartalma:
	19 kék kártya: 0-9;
	19 zöld kártya: 0-9;
	19 piros kártya: 0-9;
	19 sárga kártya: 0-9
	„8 Húzz kettőt!” kártya: 2 kék, 2 zöld, 2 piros, 2 sárga
	„8 Fordulj! kártya”: 2 kék, 2 zöld, 2 piros, 2 sárga
	„8 Ugorj!” kártya: 2 kék, 2 zöld, 2 piros, 2 sárga
	„4 Színválasztó” kártya;
	„4 Húzz négyet! Színválasztó” kártya
*/


#ifndef PAKLI_H
#define PAKLI_H

#include "Kártya.h"

class deck : public card {
public:
	deck();
	deck(const deck& other);
	const deck& operator= (const deck& other);
	~deck();
	void shuffle();
	card draw();
	void create();
	int add_card(card temp_card);
	void quick_shuffle();
	void print_deck();
	int get_size();

private:
	card* ptr_deck;
	int size;
	void clear();
	void copy(const deck& other);
};


std::ostream & operator<<(std::ostream & out, deck const & temp_deck);
#endif 
