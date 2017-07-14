#ifndef _LINE_H_
#define _LINE_H
#include <gslib.h>

class Line
{
public:
	//デフォルトコンストラクタ
	Line() = default;

	//コンストラクタ
	/*1,始点 2,終点*/
	Line(const GSvector3& start, const GSvector3& end)
		:mStart{ start }, mEnd{ end } {}

public:
	GSvector3 mStart{ 0.0f,0.0f,0.0f };
	GSvector3 mEnd{ 0.0f,0.0f,0.0f };
};


#endif // !_LINE_H_
