#include "stdafx.h"

/*
#include "stdafx.h"
#include <iostream>
#include <string>
#include "longNum.h"
#include "extraNum.h"

const unsigned int base = 4294967296;



extraNum::extraNum()
{
	for (int i = 0; i < 129; i++)
		num[i] = 0;
}

extraNum::extraNum(string s)
{
	int index = 0, k = 0, x = 0;
	for (int i = 0; i < 129; i++) {
		num[i] = 0;
	}
	for (int i = s.length() - 1; i > -1; i--) {
		int f = 0;
		char symb;
		switch (s[i])
		{
		case 'A':
			symb = '0';
			f = 1;
			break;
		case 'B':
			symb = '1';
			f = 1;
			break;
		case 'C':
			symb = '2';
			f = 1;
			break;
		case 'D':
			symb = '3';
			f = 1;
			break;
		case 'E':
			symb = '4';
			f = 1;
			break;
		case 'F':
			symb = '5';
			f = 1;
			break;
		default:
			f = 0;
			break;
		}
		if (f == 1) { x = symb - '0' + 10; }
		else { x = s[i] - '0'; }
		num[index] = num[index] + (x << (4 * k));
		k = (k + 1) % 8;
		if (k == 0)
			index++;
	}
}

unsigned int* extraNum::getPointer()
{
	return num;
}

void extraNum::longShiftDigitsToHigh(int k)
{
	unsigned int* shiftedNum = new unsigned int[129];
	for (int i = 0; i < 129; i++)
		shiftedNum[i] = 0;
	for (int i = 0; i < 129 - k; i++) {
		shiftedNum[i + k] = num[i];
	}
	for (int i = 0; i < 129; i++)
		num[i] = 0;
	for (int i = 0; i < 129; i++)
		num[i] = shiftedNum[i];
	delete[] shiftedNum;
}

void extraNum::set(extraNum& A)
{
	for (int i = 0; i < 129; i++)
		this->num[i] = A.num[i];
}
*/
/*void extraNum::set(longNum& A)
{
unsigned int* buff = new unsigned int[64];
buff = A.getPointer();
for (int i = 63; i < 129; i++)
this->num[i] = 0;
for (int i = 0; i < 64; i++)
this->num[i] = buff[i];
delete[] buff;
}*/
/*
int extraNum::longCmp(extraNum& A)
{
	int result = 0, i = 128;
	while ((num[i] == A.num[i]) && (i>-1))
		i--;
	if (i == -1)
		return result;
	else {
		if (num[i] > A.num[i])
			result = 1;
		else
			result = -1;
	}
	return result;
}

string extraNum::convertToBin()
{
	int i = 128;
	while ((num[i] == 0) && (i > -1))
		i--;
	if (i == -1)
		return "0";
	string out = "";
	char x;
	for (; i > -1; i--) {
		for (int j = 1; j <= 32; j++) {
			switch ((num[i] >> (32 - j)) & 0x1)
			{
			case 0:
				x = '0';
				break;
			case 1:
				x = '1';
				break;
			defaut:
				break;
			}
			out = out + x;
		}
	}
	while (out[0] == '0')
		out.erase(0, 1);
	return out;
}

int extraNum::longSub(extraNum& A, extraNum& B)
{
	extraNum C;
	__int64 buff = 0;
	int borrow = 0;
	for (int i = 0; i < 129; i++) {
		buff = (__int64)A.num[i] - B.num[i] - borrow;
		if (buff >= 0) {
			C.num[i] = buff;
			borrow = 0;
		}
		else {
			C.num[i] = base + buff;
			borrow = 1;
		}
	}
	if (borrow == 1) {
		cout << "Error! Negative result." << endl;
		for (int i = 0; i < 129; i++)
			C.num[i] = 0;
		this->set(C);
		return 0;
	}
	else
	{
		this->set(C);
		return borrow;
	}
}

void extraNum::longShiftBitsToHigh(int k)
{
	for (int j = 0; j < k; j++) {
		for (int i = 128; i > 0; i--)
			num[i] = (num[i] << 1) + (num[i - 1] >> 31);
		num[0] = num[0] << 1;
	}
}

void extraNum::setBit(int t)
{
	int wp = t / 32;
	num[wp] = num[wp] | (1 << (t % 32));
}

void extraNum::longDivMod(extraNum& A, extraNum& B)
{
	int k = 0, t = 0;
	k = bitLength(B.convertToBin());
	if (k == 0) {
		cout << "Error! Dividing on 0." << endl;
		return;
	}
	extraNum R;
	R.set(A);
	extraNum Q, C;
	while ((R.longCmp(B) == 1) || (R.longCmp(B) == 0)) {
		t = bitLength(R.convertToBin());
		C.set(B);
		C.longShiftBitsToHigh(t - k);
		if (R.longCmp(C) == -1)
		{
			t--;
			C.set(B);
			C.longShiftBitsToHigh(t - k);
		}
		R.longSub(R, C);
		Q.setBit(t - k);
	}
	this->set(Q);
}

extraNum::~extraNum()
{
	delete[] num;
}*/
