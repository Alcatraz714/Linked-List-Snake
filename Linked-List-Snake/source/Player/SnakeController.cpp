#include "Player/SnakeController.h"

namespace Player
{
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

	}

	SnakeController::SnakeController()
	{

	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{

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

	}

	void SnakeController::spawnSnake()
	{

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