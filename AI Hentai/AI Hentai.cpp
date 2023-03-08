#include "window.h"
#include "SceneManager.h"
#include "MainMenuScene.h"

#include <iostream>
#include <filesystem>
#include <conio.h>

using namespace std;

extern const string current_path{ filesystem::current_path().string().erase(filesystem::current_path().string().find_last_of('\\')) };
extern bool exit_game{ false };

int main(void)
{
    Window window{
        GetMonitorWidth(GetCurrentMonitor()),
        GetMonitorHeight(GetCurrentMonitor()),
        "AI Hentai",
        current_path + R"(\Source\Photo\Window\Icon.png)"
    };

    SceneManager::addScene(new MainMenuScene());

    //window.Fullscreen();
    window.setWindowFPS(60);
    while (!window.shouldClose() and !exit_game)
    {
        // Logic Scene
        SceneManager::update();

        // Drawing Scene
        window.beginDrawing();
        window.clearBackground(RAYWHITE);

        SceneManager::draw();

        DrawFPS(10, 30);
        window.endDrawing();
    }

    return EXIT_SUCCESS;
}
