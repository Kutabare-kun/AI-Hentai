#include "MainMenuScene.h"
#include "exit_button.h"
#include "action_button.h"
#include <iostream>

extern const std::string current_path;

MainMenuScene::~MainMenuScene()
{
	UnloadTexture(background_menu);

	for (auto& object : buttons_menu)
		delete object;
}


MainMenuScene::MainMenuScene()
{
	// Load resources and initialize objects
	Image background = LoadImage((current_path + R"(\Source\Photo\Menu\Menu.png)").c_str());
	ImageResize(&background, GetMonitorWidth(GetCurrentMonitor()), GetMonitorWidth(GetCurrentMonitor()));

	this->background_menu = LoadTextureFromImage(background);
	UnloadImage(background);

	buttons_menu.push_back(new action_button{{0, 6},
		(current_path + R"(\Source\Photo\Menu\Button-Start.png)"), 
		scene_function::MENU, 0, 0, obj_pos::CENTER});

	buttons_menu.push_back(new action_button{ {0, -50},
		(current_path + R"(\Source\Photo\Menu\Button-Settings.png)"),
		scene_function::SETTING, 0, 0, obj_pos::CENTER });

	buttons_menu.push_back(new exit_button{ {0, -106},
		(current_path + R"(\Source\Photo\Menu\Button-Exit.png)"), 
		scene_function::NOTHING, 0, 0, obj_pos::CENTER });
}


void MainMenuScene::update()
{
	// Update game logic
	for (const auto & button : buttons_menu)
		button->update();
}


void MainMenuScene::draw()
{
	// Draw scene
	DrawTextureRec(background_menu, 
		{ 0.f, 0.f, static_cast<float>(background_menu.width), static_cast<float>(background_menu.height) }, 
		{0.f, 0.f}, WHITE);

	for (const auto & button : buttons_menu)
		button->draw();
}


void MainMenuScene::onActivate()
{
	// Called when the scene becomes active
}


void MainMenuScene::onDeactivate()
{
	// Called when the scene is deactivated
}
