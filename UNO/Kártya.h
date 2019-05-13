#ifndef _KÁRTYA_H_
#define _KÁRTYA_H_

#include <ostream>


enum COLOR { joker, piros, zöld, kék, sárga };


class card
{
public:
	int number; // 0-9 a számok, "húzz kettőt", "ugorj", "fordulj!", "színválasztó", "színválasztás húzz négyet"
	COLOR color; // 5 szín: színtelen, zöld, kék, sárga, piros 

	//Egyenlőség operátor
	// Ekkor lerakható a kártya a körben
	bool operator==(card const& other) const;

	// Egyenlőtlenség operátor
	bool operator!=(card const& other) const;


	card();

	card(int num, COLOR col);
};

std::ostream & operator<<(std::ostream & out, card const & temp_card);


#endif // _KÁRTYA_H_
