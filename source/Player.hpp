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

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <utility>

#include "Direction.hpp"
#include "Position.hpp"
#include "Entity.hpp"

class Grid;

class Player : public Entity {
public:
	static void init();

	Player();
	void update(Grid &grid) override;
	void advance(Grid &grid) override;
	sf::Sprite &getSprite() override;

private:
	Direction dir;

	static const std::pair<sf::Keyboard::Key, Direction> arrows[];
	static sf::Texture texture;
	static sf::Sprite sprite;
};
