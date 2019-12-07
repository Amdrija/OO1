#include "Mapa.h"

Mapa::Mapa(unsigned int height_, unsigned int width_)
	:height(height_), width(width_){
	initialize_matrix();
}

Mapa::Mapa(const Mapa& map)
{
	copy(map);
}

Mapa::Mapa(Mapa&& map)
{
	move(map);
}

Mapa& Mapa::operator=(const Mapa& map)
{
	if (this != &map) {
		delete_map();
		copy(map);
	}

	return *this;
}

Mapa& Mapa::operator=(Mapa&& map)
{
	if (this != &map) {
		delete_map();
		move(map);
	}

	return *this;
}

Mapa::~Mapa()
{
	delete_map();
}

int Mapa::getWidth() const
{
	return width;
}

int Mapa::getHeight() const
{
	return height;
}

bool Mapa::changeTileWithRoad(int position_y, int position_x, PoljePut::Category category)
{
	if (positionXOutOfBounds(position_x) || positionYOutOfBounds(position_y)) {
		return false;
	}
	Polje* new_road = new PoljePut(category, matrix[position_y][position_x]->getNeprohodnost());
	delete matrix[position_y][position_x];
	matrix[position_y][position_x] = new_road;
	return true;
}

bool Mapa::changeTileWithForest(int position_y, int position_x, unsigned int density)
{
	if (positionXOutOfBounds(position_x) || positionYOutOfBounds(position_y)) {
		return false;
	}
	Polje* new_road = new PoljeSuma(density, matrix[position_y][position_x]->getNeprohodnost());
	delete matrix[position_y][position_x];
	matrix[position_y][position_x] = new_road;
	return true;
}

//ovo moze bolje da se refaktorise
Mapa& Mapa::operator+=(unsigned int difference)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			*matrix[i][j] += difference;
		}
	}
	return *this;
}

Mapa& Mapa::operator-=(unsigned int difference)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			*matrix[i][j] -= difference;
		}
	}
	return *this;
}

void Mapa::copy(const Mapa& map)
{
	width = map.width;
	height = map.height;
	initialize_matrix(&map);
}

void Mapa::move(Mapa& map)
{
	width = map.width;
	height = map.height;
	matrix = map.matrix;
	map.matrix = nullptr;
	//ovo je bitno jer kasnije kada on brise taj priveremeni objekat
	//ne zelimo da idem kroz for petlju, jer je matrix=nullptr, pa ce puci
	map.width = 0;
	map.height = 0;
}

void Mapa::delete_map()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete matrix[i][j];
		}
		delete matrix[i];
	}
	delete matrix;
	matrix = nullptr;
	width = 0;
	height = 0;
}

//inicijalizuje matricu nekom datom mapom
//ili ako nije data mapa( parametar pokazivaca na mapu je nullptr)
//onda inicijalizuje matricu default vrednostima polja
void Mapa::initialize_matrix(const Mapa* map)
{
	matrix = new Polje * *[height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new Polje * [width];
		for (int j = 0; j < width; j++) {
			if (map == nullptr)
				matrix[i][j] = new Polje;
			else
				matrix[i][j] =map->matrix[i][j]->copy();
		}
	}
}

bool Mapa::positionXOutOfBounds(unsigned int position_x) const
{
	return position_x >= width || position_x < 0;
}

bool Mapa::positionYOutOfBounds(unsigned int position_y) const
{
	return position_y >= height || position_y < 0;
}

std::ostream& operator<<(std::ostream& os, const Mapa& map)
{
	for (int i = 0; i < map.getHeight(); i++) {
		for (int j = 0; j < map.getWidth(); j++) {
			os << *map.matrix[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}
