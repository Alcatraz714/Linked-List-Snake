#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include "Food/FoodType.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
	using namespace Food;

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

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
		const int minimum_snake_size = 3;
		int player_score;

		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const LinkedList::Direction default_direction = LinkedList::Direction::RIGHT;

		SnakeState current_snake_state;
		float elapsed_duration;
		float restart_counter;
		LinkedList::Direction current_snake_direction;
		InputState current_input_state;

		LinkedList::SingleLinkedList* single_linked_list;
		// Creation and I/O
		void createLinkedList();
		void processPlayerInput();
		void updateSnakeDirection();
		void delayedUpdate();
		void moveSnake();
		// Collision handling 
		void processSnakeCollision();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();
		void OnFoodCollected(FoodType food_type);
		// Respawn and Restart
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
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		bool isSnakeSizeMinimum();
		//Ops and O(N)
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}