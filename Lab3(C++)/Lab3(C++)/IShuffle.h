#pragma once

class IShuffle
{
public:
	virtual void shuffle() = 0;
	virtual void shuffle(size_t left, size_t right) = 0;
};