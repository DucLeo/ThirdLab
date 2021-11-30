#pragma once
#include<iostream>

using namespace std;

class Iterator {
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};
