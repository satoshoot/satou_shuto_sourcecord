#ifndef _IWORLD_H_
#define _IWORLD_H_

#include "../Actor/ActorPtr/ActorPtr.h"
#include "../Field/FieldPtr.h"
#include <string>
#include <gslib.h>

enum class ActorGroup;
enum class EventMessage;
class Camera;

class IWorld
{
public:
	//仮想デストラクタ
	virtual ~IWorld() {}

	//アクターの追加
	virtual void AddActor(ActorGroup group, const ActorPtr& actor) = 0;

	//アクターの検索
	virtual ActorPtr FindActor(const std::string& name) = 0;

	//ターゲットした敵の位置
	virtual std::string GetTargetEnemyName(GSvector3& playerPosition) = 0;

	//フィールドの取得
	virtual FieldPtr GetField()const = 0;

	//カメラの取得
	virtual Camera* GetCamera()const = 0;

	//メッセージの送信
	virtual void sendMessage(EventMessage message, void* param = nullptr) = 0;

};


#endif // !_WORLD_H_