#include "Element/ElementService.h"
#include "Level/LevelModel.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelController.h"
#include "Element/Obstacle.h"
#include "Level/LevelModel.h"
#include <LinkedList/Node.h>

namespace Element
{
	ElementService::ElementService() = default;

	ElementService::~ElementService() = default;

	void ElementService::initialize() { }

	void ElementService::update()
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			obstacle_list[i]->update();
		}
	}

	void ElementService::render()
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			obstacle_list[i]->render();
		}
	}

	const void ElementService::spawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height)
	{
		for (int i = 0; i < element_data_list.size(); i++)
		{
			switch (element_data_list[i].element_type)
			{
			case::Element::ElementType::OBSTACLE:
				spawnObstacle(element_data_list[i].position, cell_width, cell_height);
				break;
			}
		}
	}

	std::vector<sf::Vector2i> ElementService::getElementsPositionList()
	{
		std::vector<sf::Vector2i> elements_position_list;

		for (int i = 0; i < obstacle_list.size(); i++)
		{
			elements_position_list.push_back(obstacle_list[i]->getObstaclePosition());
		}

		return elements_position_list;
	}

	bool ElementService::processElementsCollision(LinkedList::Node* head_node)
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			if (obstacle_list[i]->getObstaclePosition() == head_node->body_part.getNextPosition() ||
				obstacle_list[i]->getObstaclePosition() == head_node->body_part.getPosition())
			{
				return true;
			}
		}

		return false;
	}

	void ElementService::spawnObstacle(sf::Vector2i position, float cell_width, float cell_height)
	{
		Obstacle* obstacle = new Obstacle();

		obstacle->initialize(position, cell_width, cell_height);
		obstacle_list.push_back(obstacle);
	}
}