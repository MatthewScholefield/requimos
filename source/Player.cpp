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

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

#include "Player.hpp"
#include "Renderer.hpp"
#include "Grid.hpp"

sf::Texture Player::texture;
sf::Sprite Player::sprite;

void Player::init()
{
	if (!texture.loadFromFile("player.png"))
		throw std::runtime_error("Could find player.png");
	sprite.setTexture(texture);
}

Player::Player() : Entity(), dir(Direction::RIGHT)
{
}

const std::pair<sf::Keyboard::Key, Direction> Player::arrows[] = {
	{sf::Keyboard::W, Direction::UP},
	{sf::Keyboard::A, Direction::LEFT},
	{sf::Keyboard::S, Direction::DOWN},
	{sf::Keyboard::D, Direction::RIGHT}
};

void Player::update(Grid &grid)
{
	for (auto &i : arrows)
		if (sf::Keyboard::isKeyPressed(i.first))
			dir = i.second;
}

void Player::advance(Grid& grid)
{
	Position newPos(pos);

	newPos += Position::fromDir(dir);
	newPos.clipBounds();

	if (grid.isFree(newPos))
	{
		grid.moveEntity(pos, newPos);
		pos = newPos;
	}
}

sf::Sprite &Player::getSprite()
{
	return sprite;
}
