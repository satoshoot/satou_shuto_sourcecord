#include "Light.h"

Light::Light(IWorld* world, const GSvector3 position, GameManager* gameManager)
	:Actor(world, "Light", position, BoundingSphere(), gameManager)
{

}

void Light::OnDraw()const
{
	static const float ambient[] = { 0.2f,0.2f,0.2f,1.0f };//����
	static const float diffuse[] = { 1.0f,1.0f,1.0f,1.0f };//�g�U���ˌ�
	static const float speclar[] = { 1.0f,1.0f,1.0f,1.0f };//���ʔ���
	float position[] = { m_Position.x,m_Position.y,m_Position.z,0.0f };//���C�g�̕���

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, speclar);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

}