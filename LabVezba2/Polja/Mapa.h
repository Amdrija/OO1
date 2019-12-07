#ifndef MAPA_H
#define MAPA_H

#include "Polje.h"
#include "PoljePut.h"
#include "PoljeSuma.h"
#include <iostream>

class Mapa
{
public:
	Mapa(unsigned int height, unsigned int width);
	Mapa(const Mapa&);
	Mapa(Mapa&&);
	Mapa& operator=(const Mapa&);
	Mapa& operator=(Mapa&&);
	~Mapa();
	int getWidth() const;
	int getHeight() const;
	bool changeTileWithRoad(int position_y, int position_x, PoljePut::Category category);
	bool changeTileWithForest(int position_y, int position_x, unsigned int density);
	Mapa& operator+=(unsigned int difference);
	Mapa& operator-=(unsigned int difference);
	friend std::ostream& operator<< (std::ostream& os, const Mapa& map);
private:
	Polje*** matrix = nullptr;
	int width, height;
	void copy(const Mapa&);
	void move(Mapa&);
	void delete_map();
	void initialize_matrix(const Mapa* map = nullptr);
	bool positionXOutOfBounds(unsigned int position_x) const;
	bool positionYOutOfBounds(unsigned int position_y) const;
};
#endif

