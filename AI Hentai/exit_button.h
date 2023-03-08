#pragma once
#include <raylib.h>
#include <string>

#include "button.h"


class exit_button :
    public button
{
public:
	exit_button(const Vector2&&, const std::string&, scene_function, int, int, obj_pos);
	~exit_button() = default;

	void update() override;

	void draw() override;
};

