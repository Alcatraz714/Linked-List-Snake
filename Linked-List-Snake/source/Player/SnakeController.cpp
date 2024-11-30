#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelService.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;
	using namespace Level;

	void SnakeController::processPlayerInput()
	{

	}

	void SnakeController::updateSnakeDirection()
	{

	}

	void SnakeController::moveSnake()
	{

	}

	void SnakeController::processSnakeCollision()
	{

	}

	void SnakeController::handleRestart()
	{

	}

	void SnakeController::reset()
	{

	}

	void SnakeController::destroy()
	{
		delete(single_linked_list);
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++) 
		{
			single_linked_list->insertNodeAtTail();     // Insert nodes at tail to create the initial snake
		}
	}

	void SnakeController::respawnSnake()
	{

	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}
}