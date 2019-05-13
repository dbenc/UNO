#include "Kártya.h"

card::card() : number(0), color(joker)
{

}

card::card(int num, COLOR col) : number(num), color(col)
{

}

bool card::operator==(card const& other) const
{
	return number == other.number || color == other.color || color == joker || other.color == joker;

}


bool card::operator!=(card const& other) const
{
	return !(*this == other);
}


std::ostream & operator<<(std::ostream & out, card const & temp_card)
{
	out << "Szam:  ";
	switch (temp_card.number)
	{
	case 10: out << "HUZZ KETTOT"; break;
	case 11: out << "UGORJ!"; break;
	case 12: out << "FORDULJ!"; break;
	case 13: out << "SZINALASZTO"; break;
	case 14: out << "SZIN HUZZ NEGYET"; break;
	default: out << (int)temp_card.number; break;
	}

	out << "  Szin:";
	switch (temp_card.color)
	{
	case joker: out << " joker";  break;
	case piros: out << " piros";  break;
	case zöld: out << " zold";  break;
	case kék: out << " kek";  break;
	case sárga: out << " sarga";  break;
	default: out << "N/A"; break;
	}
	return out;
}
