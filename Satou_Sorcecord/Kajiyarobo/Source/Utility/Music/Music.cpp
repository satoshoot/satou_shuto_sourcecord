#include "Music.h"
#include <gslib.h>
#include <GSmusic.h>

Music::Music()
{ }

void Music::LoadBGM(const SoundName & bgm, const std::string & name, bool loop)
{
	gsLoadMusic((GSuint)bgm, name.c_str(), loop);
}

void Music::LoadSE(const SoundName& seName, const std::string& resource)
{
	gsLoadSE((GSuint)seName, resource.c_str(), 60, GMIDI_DEFAULT);
	mSEVector.push_back(seName);
}


void Music::DeleteSE()
{
	for (NameVector::iterator i = mSEVector.begin(); i != mSEVector.end(); i++)
	{
		gsDeleteSE((GSuint)*i);
	}
	mSEVector.clear();
}