#pragma once
#include <raylib.h>
#include <string>

#include "Enums.h"


class button
{
protected:
	Vector2 b_position;
	scene_function action;

	Texture2D* b_texture;
	Rectangle b_rect;

public:
	button(const Vector2&, const std::string&, scene_function, int, int, obj_pos);
	virtual ~button();

	virtual void update() = 0;

	virtual void draw() = 0;
};
