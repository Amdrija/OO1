#ifndef IGRAC_H
#define IGRAC_H

#include <iostream>
#include <string>
#include "Zbirka.h"

class Igrac
{
public:
	Igrac(const std::string& name,int hp_, int mana_, Zbirka* deck_);
	//nema smisla da igrac moze da se kopira, ali nije na odmet da to postoji
	//za slucaj da se u modifikacijama trazi tako nesto, pa da ne moram tamo
	//na licu mesta da kucam
	Igrac(const Igrac&);
	Igrac(Igrac&&);
	Igrac& operator= (const Igrac&);
	Igrac& operator=(Igrac&&);
	~Igrac();
	bool hasLostGame() const;
	bool canActivate(const Karta*) const;

	//nije konst, jer se aktiviranjem karte menjaju zbirke hand i active
	bool activateCard(const Karta*);
	bool sendActiveCardToGraveyard(const Karta*);
	bool discardCard(const Karta*);
	//ako zelis da smanjis hp ili manu, onda je difference < 0
	//ako zelis da povecas hp ili manu, onda je difference > 0
	int changeHP(int difference);
	int changeMana(int difference);
	std::string getName() const;
	int getHP() const;
	int getMana() const;
	const Zbirka* getDeck() const;
	const Zbirka* getHand() const;
	const Zbirka* getActive() const;
	const Zbirka* getGraveyard() const;
	bool draw();
private:
	std::string player_name;
	int hp;
	int mana;
	Zbirka* deck;
	Zbirka* hand = new Zbirka;
	Zbirka* active = new Zbirka;
	Zbirka* graveyard = new Zbirka;
	void copy(const Igrac&);
	void move(Igrac&);
	void delete_player();
};

#endif

