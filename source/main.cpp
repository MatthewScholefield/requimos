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

#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>

#include "Player.hpp"
#include "World.hpp"
#include "Renderer.hpp"
#include "Enemy.hpp"
#include "ComputerPlayer.hpp"

int main()
{
	ComputerPlayer::init();
	Player::init();
	Grid::init();
	Enemy::init();

	World world;

	bool running = true;
	sf::RenderWindow window(sf::VideoMode(650, 650), "Requimos");
	Renderer renderer(window);

	sf::Clock clock;
	clock.getElapsedTime();

	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::Resized:
				renderer.resize(event.size.width, event.size.height);
				break;
			default:
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			running = false;

		world.update();
		if (clock.getElapsedTime().asMilliseconds() > 50)
		{
			clock.restart();
			world.advance();
		}

		window.clear(sf::Color(130, 130, 130));
		world.render(renderer);
		window.display();
	}
	return 0;
}

