#pragma once
#include "LevelNumber.h"

namespace Level
{
    class LevelController;

    class LevelService
    {
    private:
        LevelController* level_controller;
        LevelNumber current_level;

        void createLevelController();
        void spawnPlayer();
        void spawnLevelElements(LevelNumber level_to_load);
        void destroy();

    public:
        LevelService();
        ~LevelService();

        void initialize();
        void update();
        void render();

        void createLevel(LevelNumber level_to_load);
        float getCellWidth();
        float getCellHeight();
    };
}