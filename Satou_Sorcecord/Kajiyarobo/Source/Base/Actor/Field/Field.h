#ifndef _FIELD_H_
#define _FIELD_H_
//#include"../Ray.Line/Ray.h"
//#include"../Ray.Line/Line.h"
//#include"../BoundingSphere/BoundingSphere.h"
#include <gslib.h>

class Ray;
class Line;
class BoundingSphere;


class Field
{
public:
	Field(GSuint wall, GSuint skybox, GSuint floor);

	bool Collision(
		const Ray& ray,
		GSvector3* intersect = nullptr,
		GSplane* plane = nullptr)const;

	bool Collision(
		const Line& line,
		GSvector3* intersect = nullptr,
		GSplane* plane = nullptr)const;

	bool Collision(
		const BoundingSphere& sphere,
		GSvector3* intersect = nullptr)const;

	void Draw()const;

	Field(const Field& other) = delete;
	Field operator =(const Field& other) = delete;

private:
	void BackGround()const;

private:
	GSuint mWall;
	GSuint mSkybox;
	GSuint mField;
};

#endif // !_FIELD_H_
