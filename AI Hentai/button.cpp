#include "button.h"
#include "SceneManager.h"
#include <iostream>

extern bool exit_game;

button::button(const Vector2& coordinate, const std::string& path, scene_function action, 
	int width, int height, obj_pos position)
	: b_position(coordinate), action(action)
{
	Image temp = LoadImage(path.c_str());

	if (width && height)
		ImageResize(&temp, width, height);

	b_texture = new Texture2D(LoadTextureFromImage(temp));
	UnloadImage(temp);

	switch (position)
	{
	case obj_pos::NOTHING:
	{
		b_rect = { b_position.x, b_position.y,
			static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::CENTER:
	{
		b_rect = { (GetScreenWidth() / 2) - (b_texture->width / 2) - b_position.x,
		(GetScreenHeight() / 2) - (b_texture->height / 2) - b_position.y,
		static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::CENTERX:
	{
		b_rect = { (GetScreenWidth() / 2) - (b_texture->width / 2) - b_position.x,
		b_position.y,
			static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::CENTERY:
	{
		b_rect = { b_position.x,
		(GetScreenHeight() / 2) - (b_texture->height / 2) - b_position.y,
		static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::TOP:
	{
		b_rect = { b_position.x, 0,
			static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::BOTTOM:
	{
		b_rect = { b_position.x,
			static_cast<float>(GetScreenHeight() - b_texture->height),
		static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::LEFT:
	{
		b_rect = { 0, b_position.y,
		static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	case obj_pos::RIGHT:
	{
		b_rect = { static_cast<float>(GetScreenWidth() - b_texture->width),
			b_position.y,
		static_cast<float>(b_texture->width), static_cast<float>(b_texture->height) };
	}break;

	}	
}


button::~button()
{
	UnloadTexture(*b_texture);
	delete b_texture;
}


void button::draw() 
{
	DrawTextureRec(*b_texture, {0, 0, b_rect.width, b_rect.height}, {b_rect.x, b_rect.y}, WHITE);
}
