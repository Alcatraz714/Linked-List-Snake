#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>
#include "LinkedList/Node.h"

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
		const float spawn_duration = 4.f;

		float elapsed_duration;

		FoodSpawningStatus current_spawning_status;
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		// To generate random values.
		std::default_random_engine random_engine;

		// To give random seed to generator.
		std::random_device random_device;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();

		sf::Vector2i getValidSpawnPosition();
		sf::Vector2i getRandomPosition();
		FoodType getRandomFoodType();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);

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

		bool processFoodCollision(LinkedList::Node* head_node, FoodType& out_food_type);
		void destroyFood();
	};
}