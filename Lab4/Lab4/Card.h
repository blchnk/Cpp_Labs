#pragma once
#include <fstream>

using namespace std;

class Card
{
private:

	char suit_;
	char name_;

public:

	Card(char name, char siut);
	~Card();

	void setSuit(char siut);
	char getSuit()const;

	void setName(char name);
	char getName()const;
	int  getScore();
	friend ostream& operator << (ostream&, Card&);
};

