#pragma once

namespace Player
{
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

		//functions
		void processPlayerInput();
		void updateSnakeDirection();
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

		//Spawn
		void spawnSnake();
		void respawnSnake();
		//Getter and Setter
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}