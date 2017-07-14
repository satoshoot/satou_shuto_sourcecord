#ifndef ISCENE_H_
#define ISCENE_H_

enum class Scene;

class IScene {
public:
	virtual ~IScene() {}

	virtual void Start() = 0;

	virtual void Update(float time) = 0;

	virtual void Draw() const = 0;

	virtual bool isEnd() const = 0;

	virtual Scene Next() const = 0;

	virtual void End() = 0;

};

#endif // !ISCENE_H_
