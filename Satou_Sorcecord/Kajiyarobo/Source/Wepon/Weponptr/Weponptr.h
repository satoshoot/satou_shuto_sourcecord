#ifndef _WEPON_PTR_H_
#define	_WEPON_PTR_H_
#include <memory>

class Wepon;


using WeponPtr = std::shared_ptr<Wepon>;

#endif // !_WEPON_PTR_H_
