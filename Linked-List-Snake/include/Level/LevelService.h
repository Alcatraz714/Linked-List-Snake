#pragma once

#include "Level/LevelConfig.h"

namespace Level
{
    class LevelController;

    class LevelService
    {
        LevelController* level_controller;
        LevelNumber current_level;
        LevelType current_level_type;

        void createLevelController();
        void spawnPlayer();
        void spawnLevelElements(LevelNumber level_to_load);
        void spawnFood();
        void destroy();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();

        void createLevel(LevelType level_type);
        void setCurrentLevel(LevelNumber level_to_load);

        float getCellWidth();
        float getCellHeight();
        LevelNumber getCurrentLevel();
        LevelType getCurrentLevelType();
    };
}