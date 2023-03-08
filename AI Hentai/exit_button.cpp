#include "exit_button.h"


extern bool exit_game;


exit_button::exit_button(const Vector2&& coordinate, const std::string& path, scene_function action = scene_function::NOTHING,
	int width = 0, int height = 0, obj_pos position = obj_pos::NOTHING)
	: button(coordinate, path, action, width, height, position)
{}


void exit_button::update()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), this->b_rect))
		exit_game = true;
}


void exit_button::draw()
{
	button::draw();
}
