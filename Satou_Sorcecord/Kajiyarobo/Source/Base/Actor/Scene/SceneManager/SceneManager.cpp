#include "SceneManager.h"
#include "../NullScene/NullScene.h"

SceneManager::SceneManager(GameManager* gameManager)
	:currentScene_(std::make_shared<NullScene>())
{

}
SceneManager::~SceneManager()
{ }

void SceneManager::Initialize() {
	End();
	scenes_.clear();
}

void SceneManager::Update(float time) {
	currentScene_->Update(time);
	if (currentScene_->isEnd()) {
		Change(currentScene_->Next());
	}
}

void SceneManager::Draw()const {
	currentScene_->Draw();
}

void SceneManager::End() {
	currentScene_->End();
	currentScene_ = std::make_shared<NullScene>();
}

void SceneManager::Add(Scene name, const IScenePtr& scene) {
	scenes_[name] = scene;
}

void SceneManager::Change(Scene name) {
	End();
	currentScene_ = scenes_[name];
	currentScene_->Start();
}