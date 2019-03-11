#pragma once
#include <string>
#include <iostream>

class MovieishEntity
{
protected:
	std::string title;
	bool followed;
public:
	MovieishEntity();
	~MovieishEntity();
	void SetTitle(std::string);
	std::string GetTitle();
	void Follow();
	void Unfollow();
	bool IsFollowed();
	virtual void Display() = 0;
	virtual int GetType() = 0;
};