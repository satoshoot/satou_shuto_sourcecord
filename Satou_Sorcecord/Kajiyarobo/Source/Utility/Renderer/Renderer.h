#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <gslib.h>
#include <string>
#include <list>

enum class MeshName;
enum class TextureName;

class Renderer
{
public:
	Renderer();
	~Renderer();

	//メッシュの読み込み
	void LoadMesh(const MeshName& meshName, const std::string& name);

	//メッシュとボーンの読み込み
	void LoadModel(const MeshName& meshName, const std::string& name, const std::string& sklName);

	//アニメーションの読み込み
	void LoadAnimation(const MeshName& animationName, const std::string& anmName);

	//メッシュとオクツリーの読み込み
	void LoadOctree(const MeshName& meshName, const std::string& name, const std::string& octName);

	//２Dリソースの読み込み
	void LoadTexture(const TextureName& textureName, const std::string& name);

	//メッシュデータの削除
	void DeleteMesh();

	//メッシュとボーンデータの削除
	void DeleteModel();

	//アニメーションデータの削除
	void DeleteAnimation();

	//メッシュとオクツリーデータの削除
	void DeleteOctree(const MeshName& meshName);

	//テクスチャデータの削除
	void DeleteTexture();


private:
	using NameList = std::list<MeshName>;
	NameList m_MeshList;
	NameList m_ModelList;
	NameList m_AnimationList;

	using TextureList = std::list<TextureName>;
	TextureList m_TextureList;


};

#endif // !_RENDERER_H_
