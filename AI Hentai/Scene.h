#pragma once

class Scene
{
public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void onActivate() = 0;
    virtual void onDeactivate() = 0;
};

