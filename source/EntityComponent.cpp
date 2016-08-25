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

#include "EntityComponent.hpp"
#include "Renderer.hpp"
#include "Entity.hpp"
#include "Position.hpp"
#include "Grid.hpp"

EntityComponent::EntityComponent() : entities()
{
}

void EntityComponent::update(Grid &grid)
{
	for (Entity::Ptr &i : entities)
		i->update(grid);
}

void EntityComponent::advance(Grid& grid, int &score)
{
	for (Entity::Ptr &i : entities)
		i->advance(grid);

	for (int i = 0; i < entities.size(); ++i)
		for (int j = 0; j < i; ++j)
			if (entities[i]->pos == entities[j]->pos)
				entities[i]->isAlive = entities[j]->isAlive = false;

	for (auto it = entities.begin(); it != entities.end();)
		if (!(*it)->isAlive)
		{
			++score;
			it = entities.erase(it);
		}
		else
			++it;
}

void EntityComponent::render(Renderer &renderer)
{
	auto box = (sf::Vector2f) renderer.getSize();
	box.x /= (float) Grid::sx;
	box.y /= (float) Grid::sy;

	for (Entity::Ptr &i : entities)
	{
		sf::Sprite &sprite = i->getSprite();
		float scaleX = box.x / (float) sprite.getTextureRect().width;
		float scaleY = box.y / (float) sprite.getTextureRect().height;
		sprite.setScale(scaleX, scaleY);
		sprite.setPosition(i->pos.x * box.x, i->pos.y * box.y);
		renderer.draw(sprite);
	}
}

void EntityComponent::addEntity(Entity* entity)
{
	entities.push_back(Entity::Ptr(entity));
}

Entity::Ptr EntityComponent::getLast()
{
	return entities.back();
}

