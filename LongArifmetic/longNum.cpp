#include "stdafx.h"
#include <iostream>
#include <string>
#include "longNum.h"

using namespace std;

const unsigned int base = 4294967296;

longNum::longNum()
{
	for (int i = 0; i < 64; i++)
		num[i] = 0;
}

longNum::longNum(string s)
{
	int index = 0, k = 0, x = 0;
	for (int i = 0; i < 64; i++) {
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

string longNum::display()
{
	int i = 63;
	char x;
	while ((num[i] == 0) && (i > -1))
		i--;
	string out = "";
	if (i == -1)
		return ("0");
	for (; i > -1; i--) {
		for (int j = 1; j <= 8; j++) {
			switch ((num[i] >> (32 - 4 * j)) & 0xF)
			{
			case 0:
				x = '0';
				break;
			case 1:
				x = '1';
				break;
			case 2:
				x = '2';
				break;
			case 3:
				x = '3';
				break;
			case 4:
				x = '4';
				break;
			case 5:
				x = '5';
				break;
			case 6:
				x = '6';
				break;
			case 7:
				x = '7';
				break;
			case 8:
				x = '8';
				break;
			case 9:
				x = '9';
				break;
			case 10:
				x = 'A';
				break;
			case 11:
				x = 'B';
				break;
			case 12:
				x = 'C';
				break;
			case 13:
				x = 'D';
				break;
			case 14:
				x = 'E';
				break;
			case 15:
				x = 'F';
				break;
			default:
				break;
			}
			out = out + x;
		}
	}
	while (out[0] == '0')
		out.erase(0, 1);
	return out;
}

unsigned int* longNum::getPointer()
{
	return num;
}

void longNum::show()
{
	int i = 63;
	while (num[i] == 0)
		i--;
	if (i == -1) {
		cout << "0" << endl;
		return;
	}
	for (int j = i; j > -1; j--)
		cout << num[j] << "   ";
}

void longNum::set(longNum& A)
{
	for (int i = 0; i < 64; i++)
		this->num[i] = A.num[i];
}
/*
void longNum::set(extraNum& A)
{
	unsigned int* buff = new unsigned int[129];
	buff = A.getPointer();
	for (int i = 0; i < 64; i++)
		this->num[i] = buff[i];
}
*/
int longNum::longAdd(longNum& A, longNum& B)
{
	longNum C;
	unsigned __int64 buff = 0;
	int carry = 0;
	for (int i = 0; i < 64; i++) {
		buff =(unsigned __int64) A.num[i] + B.num[i] + carry;
		C.num[i] = buff & 0xFFFFFFFF;
		carry = buff >> 32;
	}
	this->set(C);
	return carry;
}

int longNum::longSub(longNum& A, longNum& B)
{
	longNum C;
	__int64 buff = 0;
	int borrow = 0;
	for (int i = 0; i < 64; i++) {
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
		for (int i = 0; i < 64; i++)
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

int longNum::longCmp(longNum& A)
{
	int result = 0, i = 63;
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

void longNum::longMulOneDigit(longNum& A, unsigned int b)
{
	unsigned int carry = 0,k=0;
	unsigned __int64 buff = 0;
	for (int i = 0; i < 64; i++) {
		buff = (unsigned __int64)A.num[i] * b + carry;
		num[i] = buff & 0xFFFFFFFF;
		carry = buff >> 32;
	}
}

void longNum::longShiftDigitsToHigh(int k)
{
	unsigned int* shiftedNum = new unsigned int[64];
	for (int i = 0; i < 64; i++)
		shiftedNum[i] = 0;
	for (int i = 0; i < 64 - k; i++) {
		shiftedNum[i + k] = num[i];
	}
	for (int i = 0; i < 64; i++)
		num[i] = 0;
	for (int i = 0; i < 64; i++)
		num[i] = shiftedNum[i];
	delete[] shiftedNum;
}

void longNum::longMul(longNum& A, longNum& B)
{
	longNum buff,C;
	for (int i = 0; i < 64; i++) {
		buff.longMulOneDigit(A, B.num[i]);
		buff.longShiftDigitsToHigh(i);
		C.longAdd(C, buff);
	}
	this->set(C);
}

string longNum::convertToBin()
{
	int i = 63;
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

int bitLength(string binary)
{
	if (binary == "0")
		return 0;
	else
		return binary.size();
}

void longNum::longShiftBitsToHigh(int k)
{
	for (int j = 0; j < k; j++) {
		for (int i = 63; i > 0; i--)
			num[i] = (num[i] << 1) + (num[i-1] >> 31);
		num[0] = num[0] << 1;
	}
}

void longNum::setBit(int t)
{
	int wp = t / 32;
	num[wp] = num[wp] | (1 << (t % 32));
}

void longNum::longDivMod(longNum& A, longNum& B)
{
	int k = 0,t = 0;
	k = bitLength(B.convertToBin());
	if (k == 0) {
		cout << "Error! Dividing on 0." << endl;
		return;
	}
	longNum R;
	R.set(A);
	longNum Q,C;
	while ((R.longCmp(B) == 1) || (R.longCmp(B) == 0)) {

		

		t = bitLength(R.convertToBin());
		C.set(B);
		C.longShiftBitsToHigh(t - k);
		if (R.longCmp(C) == -1)
		{
			t--;
			C.set(B);
			C.longShiftBitsToHigh(t-k);
		}
		R.longSub(R, C);
		
		Q.setBit(t - k);
		
	}
	//cout << "A = " << B.display() << " * " << Q.display() << " + " << R.display() << endl;
	this->set(Q);
}

void longNum::longPower1(longNum& A,longNum& B)
{
	longNum C("1");
	longNum a;
	a.set(A);
	string binB = B.convertToBin();
	for (int i = binB.size() - 1; i > -1; i--) {
		if (binB[i] == '1') {
			C.longMul(C, a);
		}
		a.longMul(a, a);
	}
	this->set(C);
}

void longNum::longPower2(longNum&A, longNum& B)
{
	longNum C("1");
	string binB = B.convertToBin();
	for (int i = 0; i < binB.size(); i++) {
		if (binB[i] == '1') {
			C.longMul(C, A);
		}
		if (i != binB.size()-1) {
			C.longMul(C, C);
		}
	}
	this->set(C);
}

unsigned int* longNum::convertTo2t(int t)
{
	//t=1,2,4,8
	int c = 0;
	int k = 0;
	c = pow(2, t) - 1;
	unsigned int* converted = new unsigned int[2048 / t];
	for (int i = 0; i < 2048 / t; i++)
		converted[i] = 0;
	for (int i=0; i < 63; i++) {
		for (int j = 32 / t; j >= 1; j--) {
			converted[k] = ((num[i] >> (32 - t*j)) & c);
			k++;
		}
	}
	return converted;
}

void longNum::longPowerWindow(longNum& A, longNum& B, int t)
{
	longNum C("1");
	longNum* D = new longNum[pow(2, t)];
	D[0].num[0] = 1;
	D[1].set(A);
	for (int i = 2; i < pow(2, t); i++)
		D[i].longMul(D[i - 1], A);
	unsigned int* b = new unsigned int[2048 / t];
	b = B.convertTo2t(t);
	for (int i = (2048 / t) - 1; i >= 1; i--) {
		C.longMul(C, D[b[i]]);
		for (int k = 0; k < t; k++)
			C.longMul(C, C);
	}
	C.longMul(C, D[b[0]]);
	this->set(C);
	delete[] b;
	delete[] D;
}

//2lab

int longNum::even()
{
	int lastBit;
	lastBit = num[0] & 1;
	if (lastBit == 1) return 0;
	else return 1;
}

void longNum::longShiftBitsToLow(int k)
{
	for (int j = 0; j < k; j++) {
		for (int i = 0; i < 63; i++)
			num[i] = (num[i] >> 1) + (num[i + 1] << 31);
		num[63] = num[63] >> 1;
	}
}

void longNum::gcd(longNum& A, longNum& B)
{
	longNum D("1");
	longNum C("0");
	longNum buff;
	if (A.longCmp(B) == 0) {
		this->set(A);
		return;
	}
	while (A.even() & B.even()) {
		A.longShiftBitsToLow(1);
		B.longShiftBitsToLow(1);
		D.longMulOneDigit(D,2);
	}
	while (A.even())
		A.longShiftBitsToLow(1);
	//while (B.longCmp(C) != 0) {
	while (B.longCmp(C)){
		while (B.even())
			B.longShiftBitsToLow(1);
		if (A.longCmp(B) == 1) {
			buff.longSub(A, B);
			A.set(B);
			B.set(buff);
		}
		else
			B.longSub(B, A);
	}
	D.longMul(D, A);
	this->set(D);
}

int longNum::length()
{
	int k = 63;
	while (num[k] == 0)
		k--;
	k++;
	return k;
}

void arrEqual(unsigned int* A, unsigned int* B) {
	for (int i = 0; i < 129; i++) 
		A[i] = B[i];
}

int arrCmp(unsigned int* A, unsigned int* B) {
	int result = 0, i = 63;
	while ((A[i] == B[i]) && (i>-1))
		i--;
	if (i == -1)
		return result;
	else {
		if (A[i] > B[i])
			result = 1;
		else
			result = -1;
	}
	return result;
}

string arrToBin(unsigned int* A)
{
	int i = 128;
	while ((A[i] == 0) && (i > -1))
		i--;
	if (i == -1)
		return "0";
	string out = "";
	char x;
	for (; i > -1; i--) {
		for (int j = 1; j <= 32; j++) {
			switch ((A[i] >> (32 - j)) & 0x1)
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

void arrBitsToHigh(unsigned int* A, int k)
{
	for (int j = 0; j < k; j++) {
		for (int i = 128; i > 0; i--)
			A[i] = (A[i] << 1) + (A[i - 1] >> 31);
		A[0] = A[0] << 1;
	}
}

void arrSub(unsigned int* A, unsigned int* B)
{
	unsigned int* C = new unsigned int[129];
	for (int i = 0; i < 129; i++)
		C[i] = 0;
	__int64 buff = 0;
	int borrow = 0;
	for (int i = 0; i < 129; i++) {
		buff = (__int64)A[i] - B[i] - borrow;
		if (buff >= 0) {
			C[i] = buff;
			borrow = 0;
		}
		else {
			C[i] = base + buff;
			borrow = 1;
		}
	}
	if (borrow == 1) {
		cout << "Error! Negative result." << endl;
		for (int i = 0; i < 129; i++)
			C[i] = 0;
		arrEqual(A, C);
		return;
	}
	else
	{
		arrEqual(A, C);
		return;
	}
}

void longNum::arrDiv(unsigned int* A, longNum& res)
{
	int k = 0, t = 0;
	k = bitLength(this->convertToBin());
	if (k == 0) {
		cout << "Error! Dividing on 0." << endl;
		return;
	}
	unsigned int* R = new unsigned int[129];
	unsigned int* Q = new unsigned int[129];
	unsigned int* C = new unsigned int[129];
	unsigned int* B = new unsigned int[129];
	for (int i = 0; i < 129; i++) {
		R[i] = 0;
		Q[i] = 0;
		C[i] = 0;
		B[i] = 0;
	}
	
	arrEqual(R, A);
	
	for (int i = 0; i < 64; i++)
		B[i] = this->num[i];
	
	while ((arrCmp(R,B) == 1) || (arrCmp(R,B) == 0)) {
		
		t = bitLength(arrToBin(R));
		arrEqual(C, B);
		arrBitsToHigh(C, t - k);
		if (arrCmp(R,C) == -1)
		{
			t--;
			arrEqual(C, B);
			arrBitsToHigh(C, t - k);
		}
		arrSub(R,C);//there
		int s = t - k;
		int wp = s / 32;//set bit
		Q[wp] = Q[wp] | (1 << (s % 32));
		
	}
	
	for (int i = 0; i < 64; i++)
		res.num[i] = Q[i];
}

void longNum::barrettPrediction(longNum& N)
{/*
	longNum B("100000000");
	longNum C("1");
	int k = N.length();
	for (int i = 0; i < 2 * k; i++)
		C.longMul(C, B);*/
	/*
	extraNum B("1");
	extraNum C, res;
	C.set(N);
	int k = N.length();
	B.longShiftDigitsToHigh(2 * k);
	res.longDivMod(B, C);

	this->set(res);
	*/
	
	/*longNum B("1");
	int k = N.length();
	B.longShiftDigitsToHigh(2 * k);
	this->longDivMod(B, N);*/
	longNum some;
	unsigned int* predict = new unsigned int[129];
	for (int i = 0; i < 129; i++)
		predict[i] = 0;
	predict[0] = 1;
	int k = N.length();
	unsigned int* shiftedNum = new unsigned int[129];
	for (int i = 0; i < 129; i++)
		shiftedNum[i] = 0;
	for (int i = 0; i < 129 - (2*k); i++) {
		shiftedNum[i + (2*k)] = predict[i];
	}
	predict[0] = 0;
	for (int i = 0; i < 129; i++)
		predict[i] = shiftedNum[i];
	delete[] shiftedNum;
	
	N.arrDiv(predict,some);
	this->set(some);
	delete[] predict;
}

void longNum::killLastDigits(longNum& A, int k)
{
	unsigned int* shiftedNum = new unsigned int[64];
	for (int i = 0; i < 64; i++)
		shiftedNum[i] = 0;
	for (int i = 0; i < 64 - k; i++) {
		shiftedNum[i] = A.num[i + k];
	}
	for (int i = 0; i < 64; i++)
		this->num[i] = 0;
	for (int i = 0; i < 64; i++)
		this->num[i] = shiftedNum[i];
	delete[] shiftedNum;
}

void longNum::barrettReduction(longNum& X, longNum& N)
{
	longNum buff, pred, res, some;

	int k = N.length();
	buff.killLastDigits(X,k - 1);
	pred.barrettPrediction(N);
	
	buff.longMul(buff, pred);
	buff.killLastDigits(buff, k + 1);
	
	buff.longMul(buff, N);
	
	res.longSub(X, buff);
	while ((res.longCmp(N) == 1) || (res.longCmp(N) == 0))
		res.longSub(res, N);
	this->set(res);
}

void longNum::longModPowerBarrett(longNum& A, longNum& B, longNum& N)
{
	string binB = B.convertToBin();
	longNum res("1");
	for (int i = binB.size()-1; i > -1; i--) {
		if (binB[i] == '1') {
			res.longMul(res, A);
			res.barrettReduction(res, N);
		}
		A.longMul(A, A);
		A.barrettReduction(A, N);
	}
	this->set(res);
}

void longNum::longModWindowPowerBarrett(longNum& A, longNum& B, longNum& N, int t)
{
	longNum C("1");
	longNum* D = new longNum[pow(2, t)];
	D[0].num[0] = 1;
	D[1].set(A);
	for (int i = 2; i < pow(2, t); i++)
	{
		D[i].longMul(D[i - 1], A);
	}
	unsigned int* b = new unsigned int[2048 / t];
	b = B.convertTo2t(t);
	for (int i = (2048 / t) - 1; i >= 1; i--) {
		C.longMul(C, D[b[i]]);
		C.barrettReduction(C, N);
		for (int k = 0; k < t; k++)
		{
			C.longMul(C, C);
			C.barrettReduction(C, N);
		}
			
	}
	C.longMul(C, D[b[0]]);
	C.barrettReduction(C, N);
	this->set(C);
	delete[] b;
	delete[] D;
}



longNum::~longNum()
{
	delete[] num;
}








