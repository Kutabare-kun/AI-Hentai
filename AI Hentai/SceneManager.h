#pragma once
#include <vector>
#include "Scene.h"


class SceneManager
{
private:
    static std::vector<Scene*> scenes;
    static unsigned activeSceneIndex;

    SceneManager() {}
public:
    SceneManager(const SceneManager&) = delete;
    void operator=(const SceneManager&) = delete;

    static SceneManager& Get();

    static void addScene(Scene* scene);

    static void setActiveScene(unsigned index);

    static void update();

    static void draw();

    ~SceneManager();
};
