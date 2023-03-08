#pragma once
#include <vector>

#include "Scene.h"
#include "raylib.h"

class button;

class MainMenuScene final :
    public Scene
{
    Texture2D background_menu;
    std::vector<button*> buttons_menu;

public:
    MainMenuScene();
    ~MainMenuScene();

    void update() override;

    void draw() override;

    void onActivate() override;

    void onDeactivate() override;
};

