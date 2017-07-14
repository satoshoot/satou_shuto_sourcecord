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

	//���b�V���̓ǂݍ���
	void LoadMesh(const MeshName& meshName, const std::string& name);

	//���b�V���ƃ{�[���̓ǂݍ���
	void LoadModel(const MeshName& meshName, const std::string& name, const std::string& sklName);

	//�A�j���[�V�����̓ǂݍ���
	void LoadAnimation(const MeshName& animationName, const std::string& anmName);

	//���b�V���ƃI�N�c���[�̓ǂݍ���
	void LoadOctree(const MeshName& meshName, const std::string& name, const std::string& octName);

	//�QD���\�[�X�̓ǂݍ���
	void LoadTexture(const TextureName& textureName, const std::string& name);

	//���b�V���f�[�^�̍폜
	void DeleteMesh();

	//���b�V���ƃ{�[���f�[�^�̍폜
	void DeleteModel();

	//�A�j���[�V�����f�[�^�̍폜
	void DeleteAnimation();

	//���b�V���ƃI�N�c���[�f�[�^�̍폜
	void DeleteOctree(const MeshName& meshName);

	//�e�N�X�`���f�[�^�̍폜
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
