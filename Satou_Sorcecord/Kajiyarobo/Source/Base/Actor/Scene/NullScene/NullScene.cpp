#include "NullScene.h"
#include "../Scene.h"

void NullScene::Start() {

}

void NullScene::Update(float) {

}

void NullScene::Draw() const {

}

bool NullScene::isEnd() const {
	return false;
}

Scene NullScene::Next() const {
	return Scene::None;
}

void NullScene::End() {

}