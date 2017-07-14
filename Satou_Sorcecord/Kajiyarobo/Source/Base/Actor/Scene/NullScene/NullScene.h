#ifndef _NULL_SCENE_H_
#define _NULL_SCENE_H_

#include "../IScene.h"

class NullScene : public IScene
{
public:
	virtual void Start() override;

	virtual void Update(float time) override;

	virtual void Draw() const override;

	virtual bool isEnd() const override;

	virtual Scene Next() const override;

	virtual void End() override;
};

#endif
