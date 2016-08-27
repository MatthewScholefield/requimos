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

#include "GridRunner.hpp"
#include "Renderer.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "Grid.hpp"

GridRunner::GridRunner()
{
}

void GridRunner::update(Grid &grid)
{
	for (Entity::Ptr &i : grid.entities)
		i->update(grid);
}

void GridRunner::advance(Grid& grid, int &score)
{
	for (Entity::Ptr &i : grid.entities)
	{
		Position before = i->pos;
		i->advance(grid);
		if (i->pos != before)
			for (Entity::Ptr &j : grid.entities)
				if (i->pos == j->pos && i->id != j->id)
					i->isAlive = j->isAlive = false;
	}

	for (auto it = grid.entities.begin(); it != grid.entities.end();)
		if (!(*it)->isAlive)
		{
			++score;
			it = grid.entities.erase(it);
		}
		else
			++it;
}
