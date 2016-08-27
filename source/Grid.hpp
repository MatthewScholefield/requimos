/*
 * Copyright (C) 2016 Matthew D. Scholefield
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "Entity.hpp"
#include "GridRunner.hpp"
#include "Enemy.hpp"
#include "EntityType.hpp"

class Position;
class Renderer;

class Grid {
	friend class GridRunner;
public:
	static const int sx = 160, sy = 90;

	static void init();
	Grid();
	void reset();
	void render(Renderer &renderer);
	void spawnPlayer();
	void spawnEnemy();
	Entity::Ptr &getPlayer();
	Entity::Ptr findNearest(EntityType type, const Position &pos);

private:
	std::vector<Entity::Ptr> entities;
	Entity::Ptr player;

	static sf::Texture texture;
	static sf::Sprite sprite;
};
