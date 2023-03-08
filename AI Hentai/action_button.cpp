#include "action_button.h"
#include "SceneManager.h"

action_button::action_button(const Vector2&& coordinate, const std::string& path, scene_function action = scene_function::NOTHING,
	int width = 0, int height = 0, obj_pos position = obj_pos::NOTHING)
	: button(coordinate, path, action, width, height, position)
{}


void action_button::update()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), this->b_rect) && action != scene_function::NOTHING)
		SceneManager::setActiveScene(static_cast<unsigned>(action));
}


void action_button::draw()
{
	button::draw();
}