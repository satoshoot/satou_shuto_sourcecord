#ifndef _TITLE_ICON_H_
#define _TITLE_ICON_H_
#include "../../ITitleTextureBase/ITitleTextureBase.h"

class TitleIcon :public ITitleTextureBase
{
public:
	TitleIcon(const GSvector2& position, const TextureName& name);

	virtual void StartUpdate(float deltaTime, float& counter)override;
	virtual void EndUpdate(float deltaTime, float& counter)override;

	virtual void Draw()const override;

private:
	bool OpenIcon(float deltaTime, float& counter);
	bool SizeUp(float deltaTime, float& counter);
	bool SizeDown(float deltaTime, float& counter);
	void Alpha();
	void ClampSize(float min, float max);

private:
	GSvector2 m_Size;

	float m_Alpha;
	float m_AlphaPlus;

	GSvector2 m_Position;
	TextureName m_Name;

};
#endif // !_TITLE_ICON_H_