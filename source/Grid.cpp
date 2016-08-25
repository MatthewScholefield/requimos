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

#include "Grid.hpp"
#include "Position.hpp"
#include "Renderer.hpp"

sf::Texture Grid::texture;
sf::Sprite Grid::sprite;

void Grid::init()
{
	if (!texture.loadFromFile("slot.png"))
		throw std::runtime_error("Could find slot.png");
	sprite.setTexture(texture);
}

Grid::Grid(const EntityComponent &component) : entities(component.entities), grid{}
{
}

void Grid::update()
{
	for (auto &column : grid)
		for (State &slot : column)
			slot = State::EMPTY;

	for (const Entity::Ptr &i : entities)
		grid[i->pos.x][i->pos.y] = State::ENTITY;
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
}

bool Grid::isFree(int x, int y)
{
	return grid[x][y] == State::EMPTY;
}

bool Grid::isFree(const Position &pos)
{
	return grid[pos.x][pos.y] == State::EMPTY;
}

void Grid::moveEntity(const Position &begin, const Position &end)
{
	if (grid[end.x][end.y] != State::EMPTY)
		grid[begin.x][begin.y] = grid[end.x][end.y] = State::EMPTY;
	else
	{
		grid[end.x][end.y] = grid[begin.x][begin.y];
		grid[begin.x][begin.y] = State::EMPTY;
	}
}
