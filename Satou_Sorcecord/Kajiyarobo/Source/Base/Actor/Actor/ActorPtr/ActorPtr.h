#ifndef _ACTOR_PTR_H_
#define _ACTOR_PTR_H_
#include <memory>

class Actor;

using ActorPtr = std::shared_ptr<Actor>;

//make_shared‚ğ‘‚©‚È‚­‚Ä‚à—Ç‚­‚È‚é
template<class T,class... Args>
inline ActorPtr new_Actor(Args&&... args)
{
	return std::make_shared<T>(args...);
}


#endif // !_ACTOR_PTR_H_
