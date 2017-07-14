#ifndef _FIELDPTR_H_
#define _FIELDPTR_H_
#include <memory>

class Field;

using FieldPtr = std::shared_ptr<Field>;

template <class T,class... Args>
inline FieldPtr new_Field(Args&&... args)
{
	return std::make_shared<T>(args...);
}


#endif // !_FIELDPTR_H_
