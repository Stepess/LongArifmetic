#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "extraNum.h"

using namespace std;

class longNum
{
public:
	longNum();
	longNum(string s);
	string display();
	unsigned int* getPointer();
	void show();
	void set(longNum& A);
	//void set(extraNum& A);
	//void setExtra(extraNum& A);
	int longAdd(longNum& A, longNum& B);
	int longSub(longNum& A, longNum& B);
	int longCmp(longNum& A);
	void longMulOneDigit(longNum& A, unsigned int b);
	void longShiftDigitsToHigh(int k);
	void longMul(longNum& A, longNum& B);
	string convertToBin();
	void longShiftBitsToHigh(int k);
	void setBit(int t);
	void longDivMod(longNum& A, longNum& B);
	void longPower1(longNum&A, longNum& B);
	void longPower2(longNum&A, longNum& B);
	unsigned int* convertTo2t(int t);
	void longPowerWindow(longNum&A, longNum&B, int t);//t=1,2,4,8
	//2lab
	int even();
	void longShiftBitsToLow(int k);
	void gcd(longNum& A, longNum& B);
	int length();
	void arrDiv(unsigned int* p, longNum& res);
	void barrettPrediction(longNum& N);
	void killLastDigits(longNum& A, int k);
	void barrettReduction(longNum& A, longNum& B);
	void longModPowerBarrett(longNum&A, longNum& B, longNum& C);
	void longModWindowPowerBarrett(longNum&A, longNum& B, longNum& N, int k);
	~longNum();

private:
	unsigned int* num = new unsigned int[64];
};


int bitLength(string binary);
int arrCmp(unsigned int* A, unsigned int* B);
string arrToBin(unsigned int* A);
void arrEqual(unsigned int* A, unsigned int* B);
void arrBitsToHigh(unsigned int* A, int k);
void arrSub(unsigned int* A, unsigned int* B);
