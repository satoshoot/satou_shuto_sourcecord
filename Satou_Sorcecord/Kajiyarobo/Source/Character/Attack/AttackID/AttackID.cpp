#include "AttackID.h"

AttackID::AttackID()
	: m_ID(1)
{

}
//IDの取得
int AttackID::GetID()
{
	int getID = m_ID;
	//IDを増やす
	m_ID+=1;
	//増やす前のIDを渡す
	return getID;
}
