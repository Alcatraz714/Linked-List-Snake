#pragma once
#include <SFML/System/Vector2.hpp>
#include "Player/Direction.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
	using namespace LinkedList;

	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
	private:

		//const vars and handles
		const int initial_snake_length = 10;
		SnakeState current_snake_state;
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;

		//functions
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();

		//Linked List
		LinkedList::SingleLinkedList* single_linked_list;
		void createLinkedList();

	public:

		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		//Spawn
		void spawnSnake();
		void respawnSnake();
		//Getter and Setter
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}