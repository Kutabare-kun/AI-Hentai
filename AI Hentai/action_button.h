#pragma once
#include "button.h"
class action_button :
    public button
{
public:
	action_button(const Vector2&&, const std::string&, scene_function, int, int, obj_pos);
	~action_button() = default;

	void update() override;

	void draw() override;

};

