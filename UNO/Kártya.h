#ifndef _CARD_H_
#define _CARD_H_

#include <ostream>


enum COLOR { wild, red, green, blue, yellow };


class card
{
public:
	int number; // 0-9 a számok, +2, kirekesztő, retúr, színválasztás, +4 (színválasztás) 
	COLOR color; // 5 szín: síma, zöld, kék, sárga, piros 

	//Egyenlőség operátor
	// Ekkor lerakható a kártya a körben
	bool operator==(card const& other) const;

	// Egyenlőtlenség operátor
	bool operator!=(card const& other) const;


	card();

	card(int num, COLOR col);
};


std::ostream& operator<<(std::ostream& out, card const& temp_card);


#endif // _CARD_H_
