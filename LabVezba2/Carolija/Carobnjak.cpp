#include "Carobnjak.h"
#include "Igrac.h"
Carobnjak::Carobnjak(const std::string& name, int mana_, int power_)
	:Borac(name, mana_, power_){}


void Carobnjak::useCard(Igrac* controller, Igrac* opponent) const{
	const Karta* fighter_with_min_power = opponent->getActive()->getFighterWithMinPower();
	if (fighter_with_min_power != nullptr) {
		if (fighter_with_min_power->getPower() < power) {
			opponent->sendActiveCardToGraveyard(fighter_with_min_power);
		}
	}
	opponent->changeHP(-power * 2);
}

void Carobnjak::write(std::ostream& os) const
{
	Borac::write(os);
	os << " CAROBNJAK";
}
