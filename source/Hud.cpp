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

#include <stdexcept>
#include <bits/basic_string.h>
#include "Hud.hpp"
#include "Renderer.hpp"

Hud::Hud()
{
	if (!font.loadFromFile("PoiretOne-Regular.ttf"))
		throw std::runtime_error("Could not load PoiretOne-Regular.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(30, 30, 30));
	text.setCharacterSize(SIZE);
	text.setOrigin(0, 0);
	setScore(0);
}

void Hud::setScore(int score)
{
	text.setString(std::to_string(score));
}

void Hud::render(Renderer& renderer)
{
	renderer.draw(text);
}

