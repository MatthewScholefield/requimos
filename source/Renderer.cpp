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
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <iostream>

#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow &renderWindow) : renderWindow(renderWindow), view(renderWindow.getDefaultView())
{
	renderWindow.setView(view);
}

void Renderer::draw(const sf::Drawable& drawable)
{
	renderWindow.draw(drawable);
}

void Renderer::resize(unsigned int width, unsigned int height)
{
	view.setSize(sf::Vector2f(width, height));
	view.setCenter((sf::Vector2f)renderWindow.getSize() / 2.f);
	renderWindow.setView(view);
}

sf::Vector2u Renderer::getSize()
{
	return (sf::Vector2u)view.getSize();
}

