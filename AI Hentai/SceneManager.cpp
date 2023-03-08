#include "SceneManager.h"
#include <iostream>

std::vector<Scene*> SceneManager::scenes;
unsigned SceneManager::activeSceneIndex{ 0 };


void SceneManager::addScene(Scene* scene)
{
    scenes.push_back(scene);
}


void SceneManager::setActiveScene(unsigned index)
{
    if (index < 0 || index >= scenes.size()) {
        std::cout << "Invalid scene index " << index << std::endl;
        return;
    }

    // Deactivate the current scene
    if (activeSceneIndex >= 0 && activeSceneIndex < scenes.size()) {
        scenes[activeSceneIndex]->onDeactivate();
    }

    // Set the new active scene
    activeSceneIndex = index;
    scenes[activeSceneIndex]->onActivate();
}


void SceneManager::update()
{
    scenes[activeSceneIndex]->update();
}


void SceneManager::draw()
{
    scenes[activeSceneIndex]->draw();
}


SceneManager& SceneManager::Get()
{
    static SceneManager instance;
    return instance;
}


SceneManager::~SceneManager()
{
    for (auto& scene : scenes)
        delete scene;
}
