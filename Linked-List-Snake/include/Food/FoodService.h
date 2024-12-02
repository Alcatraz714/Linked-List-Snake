#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>

namespace Food
{
	enum class FoodType;
	class FoodItem;

	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};

	class FoodService
	{
	private:
		FoodSpawningStatus current_spawning_status;
		FoodItem* current_food_item;
		const float spawn_duration = 4.f;
		float elapsed_duration;

		float cell_width;
		float cell_height;

		//Rand
		std::default_random_engine random_engine;
		std::random_device random_device;

		// Food spawn and check
		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		void destroyFood();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i getValidSpawnPosition();
		sf::Vector2i getRandomPosition();
		FoodType getRandomFoodType();

		void updateElapsedDuration();
		void handleFoodSpawning();
		void reset();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void stopFoodSpawning();
	};
}