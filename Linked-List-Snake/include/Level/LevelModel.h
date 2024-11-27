#pragma once
#include <SFML/System/Vector2.hpp>
#include "Level/LevelData.h"
#include <vector>

namespace Level
{
    class LevelModel
    {
    private:
        std::vector<LevelData> level_configurations;

        float cell_width;
        float cell_height;

    public:
        static const int number_of_rows = 28;
        static const int number_of_columns = 50;

        LevelModel();
        ~LevelModel();

        void initialize(int width, int height);

        float getCellWidth();
        float getCellHeight();
    };
}