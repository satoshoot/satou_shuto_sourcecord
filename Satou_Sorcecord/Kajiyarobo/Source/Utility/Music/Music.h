#ifndef _MUSIC_H_
#define _MUSIC_H_
#include <vector>
#include <string>

#include "../Enum/SoundName.h"

class Music
{
public:
	Music();

	void LoadBGM(const SoundName& bgm, const std::string& name, bool loop);

	void LoadSE(const SoundName& seName, const std::string& name);

	void DeleteSE();

private:
	using NameVector = std::vector<SoundName>;
	NameVector mSEVector;

};

#endif // !_MUSIC_H_
