#include "Igrac.h"

Igrac::Igrac(const std::string& name, int hp_, int mana_, Zbirka* deck_)
	:player_name(name),hp(hp_), mana(mana_), deck(deck_){}

Igrac::Igrac(const Igrac& player)
{
	copy(player);
}

Igrac::Igrac(Igrac&& player)
{
	move(player);
}

Igrac& Igrac::operator=(const Igrac& player)
{
	if (this != &player) {
		delete_player();
		copy(player);
	}
	return *this;
}

Igrac& Igrac::operator=(Igrac&& player)
{
	if (this != &player) {
		delete_player();
		move(player);
	}
	return *this;
}

Igrac::~Igrac()
{
	delete_player();
}

bool Igrac::hasLostGame() const
{
	return hp <= 0;
}

bool Igrac::canActivate(const Karta* card) const
{
	return mana >= card->getMana();
}


//TODO implementacija za activateCard()
bool Igrac::activateCard(const Karta* card)
{
	int mana_cost = card->getMana();
	if (hand->transfer_card(active, card))
	{
		mana -= mana_cost;
		return true;
	}
	return false;
}

bool Igrac::sendActiveCardToGraveyard(const Karta* card)
{
	return active->transfer_card(graveyard, card);
}

bool Igrac::discardCard(const Karta* card)
{
	return hand->transfer_card(graveyard, card);
}

int Igrac::changeHP(int difference)
{
	return hp += difference;
}

int Igrac::changeMana(int difference)
{
	return mana += difference;
}

std::string Igrac::getName() const
{
	return player_name;
}

int Igrac::getHP() const
{
	return hp;
}

int Igrac::getMana() const
{
	return mana;
}

const Zbirka* Igrac::getDeck() const
{
	return deck;
}

const Zbirka* Igrac::getHand() const
{
	return hand;
}

const Zbirka* Igrac::getActive() const
{
	return active;
}

const Zbirka* Igrac::getGraveyard() const
{
	return graveyard;
}

bool Igrac::draw()
{
	return deck->transfer_card(hand, (*deck)[(int)0]);
}

void Igrac::copy(const Igrac& player)
{
	player_name = player.player_name;
	hp = player.hp;
	mana = player.mana;
	deck = new Zbirka(*player.deck);
	hand = new Zbirka(*player.hand);
	active = new Zbirka(*player.active);
	graveyard = new Zbirka(*player.graveyard);
}

void Igrac::move(Igrac& player)
{
	player_name = player.player_name;
	player_name = player.player_name;
	hp = player.hp;
	mana = player.mana;
	deck = player.deck;
	hand = player.hand;
	active = player.active;
	graveyard = player.graveyard;
	player.deck = nullptr;
	player.hand = nullptr;
	player.active = nullptr;
	player.graveyard = nullptr;
}

void Igrac::delete_player()
{
	delete deck;
	delete hand;
	delete active;
	delete graveyard;
	deck = nullptr;
	hand = nullptr;
	active = nullptr;
	graveyard = nullptr;
	hp = 0;
	mana = 0;
	player_name = "";
}
