#include "AttackID.h"

AttackID::AttackID()
	: m_ID(1)
{

}
//ID�̎擾
int AttackID::GetID()
{
	int getID = m_ID;
	//ID�𑝂₷
	m_ID+=1;
	//���₷�O��ID��n��
	return getID;
}
