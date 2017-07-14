#ifndef _I_TITLE_TEXTURE_BASE_H_
#define _I_TITLE_TEXTURE_BASE_H_
#include "../../../Utility/Enum/TextureName.h"
#include <gslib.h>

class ITitleTextureBase
{
public:
	virtual void StartUpdate(float deltaTime, float& counter) = 0;

	virtual void EndUpdate(float deltaTime, float& counter) = 0;

	virtual void Draw()const = 0;
};

#endif // !_I_TITLE_TEXTURE_BASE_H_
