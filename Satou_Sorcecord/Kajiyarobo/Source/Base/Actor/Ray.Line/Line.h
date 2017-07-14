#ifndef _LINE_H_
#define _LINE_H
#include <gslib.h>

class Line
{
public:
	//�f�t�H���g�R���X�g���N�^
	Line() = default;

	//�R���X�g���N�^
	/*1,�n�_ 2,�I�_*/
	Line(const GSvector3& start, const GSvector3& end)
		:mStart{ start }, mEnd{ end } {}

public:
	GSvector3 mStart{ 0.0f,0.0f,0.0f };
	GSvector3 mEnd{ 0.0f,0.0f,0.0f };
};


#endif // !_LINE_H_
