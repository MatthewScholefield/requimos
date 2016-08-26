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

#include "ComputerPlayer.hpp"
#include "Renderer.hpp"
#include "Grid.hpp"

sf::Texture ComputerPlayer::texture;
sf::Sprite ComputerPlayer::sprite;

void ComputerPlayer::init()
{
	if (!texture.loadFromFile("computer.png"))
		throw std::runtime_error("Could find computer.png");
	sprite.setTexture(texture);
}

ComputerPlayer::ComputerPlayer() : Entity()
{
}

int ComputerPlayer::findFree(const Position& unit, const int max)
{
	Position current(pos);
	return 1;
}

void ComputerPlayer::update(Grid& grid)
{
}

void ComputerPlayer::advance(Grid& grid)
{
	if (grid.isFree(pos + Position(1, 0)))
		pos += Position(1, 0);
	else
		pos += Position(0, 1);
}

sf::Sprite& ComputerPlayer::getSprite()
{
	return sprite;
}
