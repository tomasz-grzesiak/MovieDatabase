#include "MovieishEntity.h"

MovieishEntity::MovieishEntity()
{
}

MovieishEntity::~MovieishEntity()
{
}

void MovieishEntity::SetTitle(std::string a)
{
	title = a;
}

std::string MovieishEntity::GetTitle()
{
	return title;
}

void MovieishEntity::Follow()
{
	followed = true;
}

void MovieishEntity::Unfollow()
{
	followed = false;
}

bool MovieishEntity::IsFollowed()
{
	return followed;
}