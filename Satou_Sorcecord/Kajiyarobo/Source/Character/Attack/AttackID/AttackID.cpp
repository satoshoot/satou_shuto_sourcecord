#include "AttackID.h"

AttackID::AttackID()
	: m_ID(1)
{

}
//ID‚Ìæ“¾
int AttackID::GetID()
{
	int getID = m_ID;
	//ID‚ğ‘‚â‚·
	m_ID+=1;
	//‘‚â‚·‘O‚ÌID‚ğ“n‚·
	return getID;
}
