#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>

namespace Food
{
	enum class FoodType;
	class FoodItem;

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		//Rand
		std::default_random_engine random_engine;
		std::random_device random_device;

		float cell_width;
		float cell_height;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		sf::Vector2i getRandomPosition();
		void destroyFood();
		// Food spawn and check
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i getValidSpawnPosition();
		FoodType getRandomFoodType();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}