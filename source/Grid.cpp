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

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Grid.hpp"
#include "Position.hpp"
#include "Renderer.hpp"
#include "ComputerPlayer.hpp"

sf::Texture Grid::texture;
sf::Sprite Grid::sprite;

void Grid::init()
{
	if (!texture.loadFromFile("slot.png"))
		throw std::runtime_error("Could find slot.png");
	sprite.setTexture(texture);
}

Grid::Grid() : entities()
{
	spawnPlayer();
}

void Grid::reset()
{
	entities.clear();
}

void Grid::render(Renderer& renderer)
{
	auto box = (sf::Vector2f)renderer.getSize();
	box.x /= (float) sx;
	box.y /= (float) sy;

	float scaleX = box.x / (float) sprite.getTextureRect().width;
	float scaleY = box.y / (float) sprite.getTextureRect().height;

	for (int i = 0; i < sx; ++i)
		for (int j = 0; j < sy; ++j)
		{
			sprite.setScale(scaleX, scaleY);
			sprite.setPosition(i * box.x, j * box.y);
			renderer.draw(sprite);
		}
	
	sf::RectangleShape rect;

	for (Entity::Ptr &i : entities)
	{
		rect.setFillColor(i->color);
		rect.setSize(sf::Vector2f(box.x, box.y));
		rect.setPosition(i->pos.x * box.x, i->pos.y * box.y);
		renderer.draw(rect);
	}
}

void Grid::spawnPlayer()
{
	entities.emplace_back(new ComputerPlayer());
	player = entities.back();
}

void Grid::spawnEnemy()
{
	entities.emplace_back(new Enemy(player));
}

Entity::Ptr &Grid::getPlayer()
{
	return player;
}

Entity::Ptr Grid::findNearest(EntityType type, const Position &pos)
{
	int minDist = std::numeric_limits<int>::max();
	Entity::Ptr nearest;
	for (Entity::Ptr &i : entities)
	{
		int dist = i->pos.dist(pos);
		if (dist < minDist && i->type == type)
		{
			minDist = dist;
			nearest = i;
		}
	}
	return nearest;
}
