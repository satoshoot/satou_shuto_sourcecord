#ifndef _TITLE_TEXTURE_MANAGER_H_
#define _TITLE_TEXTURE_MANAGER_H_
#include <list>

class ITitleTextureBase;

class TitleTextureManager
{
public:
	TitleTextureManager();
	~TitleTextureManager();

	void Initialize();

	void StartUpdate(float deltaTime, float& counter);
	void EndUpdate(float deltaTime, float& counter);

	void Draw()const;

	void End();

private:
	void Add();

private:
	using TextureList = std::list<ITitleTextureBase*>;
	TextureList m_TextureList;

};

#endif // !_TITLE_TEXTURE_MANAGER_H_
