#include "Level/LevelService.h"
#include "Level/LevelController.h"
#include "Global/ServiceLocator.h"
#include "Element/ElementService.h"
#include "Level/LevelModel.h"

namespace Level
{
	using namespace Global;
	using namespace Element;

	LevelService::LevelService()
	{
		level_controller = nullptr;

		createLevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::createLevelController()
	{
		level_controller = new LevelController();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
		spawnLevelElements(level_to_load);
		spawnPlayer();
		spawnFood();
	}

	float LevelService::getCellWidth()
	{
		return level_controller->getCellWidth();
	}

	float LevelService::getCellHeight()
	{
		return level_controller->getCellHeight();
	}

	void LevelService::spawnPlayer()
	{
		ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
	}

	void LevelService::spawnLevelElements(LevelNumber level_to_load)
	{
		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

		std::vector<ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
		ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);
	}

	void LevelService::spawnFood()
	{
		ServiceLocator::getInstance()->getFoodService()->startFoodSpawning();
	}

	void LevelService::destroy()
	{
		delete level_controller;
	}
}