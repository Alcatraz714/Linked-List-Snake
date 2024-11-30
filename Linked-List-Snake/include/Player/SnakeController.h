#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include "LinkedList/SingleLinkedList.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 3.f;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const LinkedList::Direction default_direction = LinkedList::Direction::RIGHT;

		SnakeState current_snake_state;
		float elapsed_duration;
		float restart_counter;
		LinkedList::Direction current_snake_direction;
		InputState current_input_state;

		LinkedList::SingleLinkedList* single_linked_list;

		void createLinkedList();
		void processPlayerInput();
		void updateSnakeDirection();
		void delayedUpdate();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}