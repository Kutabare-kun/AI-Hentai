#pragma once


enum class scene_function
{
	MENU,
	SETTING,
	START,
	STEAM_URL,
	NOTHING,
};


enum class position_on_screen
{
	NOTHING,
	CENTER,
	CENTERX,
	CENTERY,
	BOTTOM,
	TOP,
	LEFT,
	RIGHT,
};

typedef position_on_screen obj_pos;
