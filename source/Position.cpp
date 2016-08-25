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

#include "Position.hpp"
#include "Direction.hpp"
#include "Grid.hpp"

Position::Position() : x(0), y(0)
{
}

Position::Position(int x, int y) : x(x), y(y)
{
}

void Position::clipBounds()
{
	if (x >= Grid::sx)
		x -= Grid::sx;
	if (y >= Grid::sy)
		y -= Grid::sy;

	if (x < 0)
		x += Grid::sx;
	if (y < 0)
		y += Grid::sy;
}

Position Position::fromDir(Direction dir)
{
	switch (dir)
	{
	case Direction::UP:
		return Position(0, -1);
	case Direction::DOWN:
		return Position(0, +1);
	case Direction::LEFT:
		return Position(-1, 0);
	case Direction::RIGHT:
		return Position(+1, 0);
	}
}

Position &Position::operator+=(const Position &rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

bool Position::operator==(const Position& rhs)
{
	return rhs.x == x && rhs.y == y;
}

