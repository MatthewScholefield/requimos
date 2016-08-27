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

#include "Enemy.hpp"
#include "Grid.hpp"

Enemy::Enemy(const Entity::Ptr &player) :
Entity(EntityType::ENEMY, sf::Color(200,100,0)), player(player)
{
}

void Enemy::update(Grid& grid)
{
}

void Enemy::advance(Grid& grid)
{
	int dX = player->pos.x - pos.x;
	int dY = player->pos.y - pos.y;

	// TODO: Add alternate bot navigation
	// const int slopeRes = 10000;
	// slopeRes < (slopeRes * abs(dY)) / (abs(dY) + abs(dX))
	if (dX == 0 || (dY != 0 && rand() % 2 == 1))
	{
		if ((dY > 0 && dY < Grid::sy / 2) || (dY < 0 && dY < -Grid::sy / 2))
			++pos.y;
		else
			--pos.y;
	}
	else if ((dX > 0 && dX < Grid::sx / 2) || (dX < 0 && dX < -Grid::sx / 2))
		++pos.x;
	else
		--pos.x;
	pos.clipBounds();
}
