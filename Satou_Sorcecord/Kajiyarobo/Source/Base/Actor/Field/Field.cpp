#include"Field.h"
#include"../../../Utility/Enum/MeshName.h"
#include"../Ray.Line/Ray.h"
#include"../Ray.Line/Line.h"
#include"../BoundingSphere/BoundingSphere.h"

Field::Field(GSuint wall, GSuint skybox, GSuint floor)
	: mWall(wall)
	, mSkybox(skybox)
	, mField(floor)
{ }

//Ray‚Æ’n–Ê‚ª“–‚½‚Á‚Ä‚¢‚½‚çintersect‚ð•Ô‚·
bool Field::Collision(
	const Ray& ray,
	GSvector3* intersect,
	GSplane* plane
	)const
{
	return gsOctreeCollisionRay(
		gsGetOctree(mField),
		&ray.mPosition,
		&ray.mDirection,
		intersect,
		plane
		) == GS_TRUE;
}

//Line‚Æ’n–Ê‚ª“–‚½‚Á‚Ä‚¢‚½‚çintersect‚ð•Ô‚·
bool Field::Collision(
	const Line& line,
	GSvector3* intersect,
	GSplane* plane
	)const
{
	return gsOctreeCollisionLine(
		gsGetOctree(mField),
		&line.mStart,
		&line.mEnd,
		intersect,
		plane
		) == GS_TRUE;
}

//‹…‘Ì‚Æ’n–Ê‚ª“–‚½‚Á‚Ä‚¢‚½‚çintersect‚ð•Ô‚·
bool Field::Collision(
	const BoundingSphere& sphere,
	GSvector3* intersect
	)const
{
	return gsOctreeCollisionSphere(
		gsGetOctree(mField),
		&sphere.mCenter,
		sphere.mRadius,
		intersect
		) == GS_TRUE;
}

void Field::Draw()const
{
	gsDrawSkyBox(mSkybox);
	BackGround();
	gsDrawOctree(mField);
}

void Field::BackGround()const
{
	GSmatrix4 projection(GS_MATRIX4_IDENTITY);

	projection.setPosition(GSvector3(0.0f, 40.0f, 0.0f));
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(projection);
	gsDrawMesh(mWall);
	glPopMatrix();

}

