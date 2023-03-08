#pragma once
#include <raylib.h>
#include <string>


class Window
{
    Image icon;

public:
    Window(int width, int height, const std::string& title, const std::string& iconPath)
	    : icon(LoadImage(iconPath.c_str()))
    {
		InitWindow(width, height, title.c_str()); // Create the window with the given size and title
        SetWindowIcon(icon); // Set the window icon using the given image path
    }

    ~Window()
    {
        UnloadImage(icon);
        CloseWindow(); // Close the window when the object is destroyed
    }

    void setTitle(const std::string& title)
    {
        SetWindowTitle(title.c_str()); // Set the window title to the given string
    }

    void setIcon(const std::string& iconPath)
    {
        SetWindowIcon(LoadImage(iconPath.c_str())); // Set the window icon using the given image path
    }

    void setWindowSize(int width, int height)
    {
        SetWindowSize(width, height); // Set the window size to the given dimensions
    }

    void setWindowFPS(int fps) const
    {
        SetTargetFPS(fps);
    }

    void Fullscreen() const
    {
        ToggleFullscreen();
    }

    bool shouldClose() const
    {
        return WindowShouldClose(); // Check if the user has attempted to close the window
    }

    void clearBackground(Color color) const
    {
        ClearBackground(color); // Clear the window with the given color
    }

    void beginDrawing() const
    {
        BeginDrawing(); // Begin drawing to the window
    }

    void endDrawing() const
    {
        EndDrawing(); // End drawing to the window
    }
};

