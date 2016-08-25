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

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace sf {
	class Sprite;
	class RenderWindow;
	class Drawable;
}

class Renderer {
public:
	Renderer(sf::RenderWindow &window);
	void draw(const sf::Drawable& drawable);
	void resize(unsigned int width, unsigned int height);
	sf::Vector2u getSize();

private:
	sf::RenderWindow &renderWindow;
	sf::View view;
};
