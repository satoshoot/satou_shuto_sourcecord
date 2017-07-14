#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "../IScenePtr.h"
#include <unordered_map>

enum class Scene;
class GameManager;

class SceneManager
{
public:
	SceneManager(GameManager* gameManager);
	~SceneManager();

	void Initialize();

	void Update(float time);

	void Draw() const;

	void End();

	void Add(Scene name, const IScenePtr& scene);

	void Change(Scene name);

	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator = (const SceneManager& other) = delete;

private:
	std::unordered_map<Scene, IScenePtr> scenes_;
	IScenePtr currentScene_;
};

#endif // !SCENE_MANAGER_H_
