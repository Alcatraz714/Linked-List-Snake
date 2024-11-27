#pragma once
namespace Level
{
    class LevelController
    {
    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();
    };
}