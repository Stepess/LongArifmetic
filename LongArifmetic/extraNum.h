/*#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "longNum.h"

class extraNum//129
{
public:
	extraNum();
	extraNum(string s);
	unsigned int* getPointer();
	void longShiftDigitsToHigh(int k);
	void longDivMod(extraNum& A, extraNum& B);
	void set(extraNum& A);
	void set(longNum& A);
	int longCmp(extraNum& A);
	string convertToBin();
	int longSub(extraNum& A, extraNum& B);
	void longShiftBitsToHigh(int k);
	void setBit(int t);
	~extraNum();

private:
	unsigned int* num = new unsigned int[129];
};
*/