#include "World.h"
#include "../Field/Field.h"
#include "../Camera/Camera.h"
#include <GSeffect.h>

World::World()
	: mListener([](EventMessage, void*) {})
{

}
void World::Update(float deltaTime)
{
	
	mActors.Update(deltaTime);
	/*エフェクトの更新*/
	gsUpdateEffect(deltaTime);

	mCamera->Update(deltaTime);
	mLight->Update(deltaTime);
}

void World::Draw()const
{
	mCamera->Draw();
	mLight->Draw();
	mField->Draw();
	mActors.Draw();

	/*エフェクトの描画*/
	gsSetEffectCamera();
	gsDrawEffect();

}

void World::HandleMessage(EventMessage message, void* param)
{
	//ワールドのメッセ―ジ処理
	mListener(message, param);

	//アクターのメッセージ処理
	mActors.HandleMessage(message, param);
	mCamera->HandleMessage(message, param);
	mLight->HandleMessage(message, param);
}

void World::AddField(const FieldPtr& field)
{
	mField = field;
}

void World::AddCamera(const ActorPtr& camera)
{
	mCamera = camera;
}

void World::AddLight(const ActorPtr& light)
{
	mLight = light;
}

FieldPtr World::GetField()const
{
	return mField;
}

Camera* World::GetCamera()const
{
	return dynamic_cast<Camera*>(mCamera.get());
}

void World::AddActor(ActorGroup group, const ActorPtr& actor)
{
	mActors.AddActor(group, actor);
}

ActorPtr World::FindActor(const std::string& name)
{
	return mActors.FindActor(name);
}

std::string World::GetTargetEnemyName(GSvector3& playerPosition)
{
	return mActors.GetNearEnemyName(playerPosition);
}

void World::sendMessage(EventMessage message, void* param)
{
	HandleMessage(message, param);
}

void World::AddEventMessageListener(EventMessageListener listener)
{
	mListener = listener;
}

