#pragma once

namespace Player
{
	class SnakeController
	{
	private:

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();
	};
}