#pragma once

#include "Tile.h"

class TileMap
{
private:
	std::vector<std::vector<Tile*>> tiles;

public:
	TileMap();
	~TileMap();
};

