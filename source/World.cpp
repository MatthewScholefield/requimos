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

#include "World.hpp"
#include "Enemy.hpp"
#include "ComputerPlayer.hpp"

World::World() : score(0), hud(), entityComponent(), grid(entityComponent), player()
{
	entityComponent.addEntity(new ComputerPlayer());
	player = entityComponent.getLast();
}

void World::update()
{
	if (!player->isAlive && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		reset();
	entityComponent.update(grid);
	grid.update();
}

void World::advance()
{
	int oldScore = score;
	if (rand() % 10 == 1)
		entityComponent.addEntity(new Enemy(player));
	entityComponent.advance(grid, player->isAlive ? score : oldScore);
	if (oldScore != score)
		hud.setScore(score);
}

void World::reset()
{
	entityComponent.entities.clear();
	entityComponent.addEntity(new ComputerPlayer());
	player = entityComponent.getLast();
	score = 0;
	hud.setScore(score);
}

void World::render(Renderer &renderer)
{
	grid.render(renderer);
	entityComponent.render(renderer);
	hud.render(renderer);
}
