#include "RankChar.h"
#include "RankA/RankA.h"
#include "RankS/RankS.h"
#include "RankB/RankB.h"
#include "RankC/RankC.h"

RankChar::RankChar()
	: nRankChar(nullptr)
{

}

RankChar::~RankChar()
{
	delete nRankChar;
}

void RankChar::ClearTime(float& time)
{
	if (time <= 60 * 300)
	{
		nRankChar = new RankS();
		return;
	}
	if (time <= 60 * 450)
	{
		nRankChar = new RankA();
		return;
	}
	if (time <= 60 * 600)
	{
		nRankChar = new RankB();
		return;
	}
	nRankChar = new RankC();
}

void RankChar::Update(float deltaTime,const float& count)
{
	if (count <= 60 * 4)
		nRankChar->Update(deltaTime);
}

void RankChar::Draw()const
{
	nRankChar->Draw();
}