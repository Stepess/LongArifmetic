// LongArifmetic.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "longNum.h"
#include <ctime>
#include "extraNum.h"

using namespace std;

int main()
{
	longNum num("27557968C88CA1EBBA23FDB04EBB6A302D10568C75591D89E88C413BF1A016D3");//
	longNum num1("1332F20EED9DD43B93D4A042232AE8D583DA4874037FBCA3E06E7EBCA4A12188");//
	longNum num2("E04A866BA60CD73D50562D50F2BAB9F0562D318CB42C14002F5923D2D2487717");//
	longNum num3;
	

	
	//num3.barrettPrediction(num);
	//num3.barrettReduction(num, num1);
	num3.longModPowerBarrett(num, num1, num2);
	cout << num3.display() << endl;
	
	/*cout << "A: " << endl;
	cout << "long = ";
	num.show();
	cout << endl;
	cout << "hex = (" << num.display() << ")" << endl;
	cout << "B: " << endl;
	cout << "long = ";
	num1.show();
	cout << endl;
	cout << "hex = (" << num1.display() << ")" << endl;
	cout << "================================================" << endl;
	int carry = num2.longAdd(num, num1);
	cout << "ADD" << endl;
	cout << "A + B = " << num.display() << " + " << num1.display() << " = " << num2.display() << endl;
	cout << "carry = " << carry << endl;
	cout << "================================================" << endl;
	int borrow = num2.longSub(num, num1);
	cout << "SUBTRACTION" << endl;
	cout << "A - B = " << num.display() << " - " << num1.display() << " = " << num2.display() << endl;
	cout << "borrow = " << borrow << endl;
	cout << "================================================" << endl;
	cout << "COMPARING" << endl;
	cout << "result of comparing = " << num.longCmp(num1) << endl;
	cout << "================================================" << endl;
	cout << "MULTIPLICATION" << endl;
	num2.longMulOneDigit(num, 0);
	num2.longMul(num, num1);
	cout << "A * B = " << num.display() << " * " << num1.display() << " = " << num2.display() << endl;
	cout << "================================================" << endl;
	cout << "DIVISION" << endl;
	num2.longDivMod(num, num1);
	cout << "A \\ B (the whole part) = " << num.display() << " \\ " << num1.display() << " = " << num2.display() << endl;
	cout << "================================================" << endl;
	cout << "EXPONENTIATION (variant I)" << endl;
	unsigned int start_time = clock();
	num2.longPower1(num, num1);
	unsigned int end_time = clock(); 
	unsigned int search_time = end_time - start_time; 
	cout << "A ^ B = " << num.display() << " ^ " << num1.display() << " = " << num2.display() << endl;
	cout << "working time = " << search_time << endl;
	cout << "================================================" << endl;
	cout << "EXPONENTIATION (variant II)" << endl;
	start_time = clock();
	num2.longPower2(num, num1);
	end_time = clock();
	search_time = end_time - start_time;
	cout << "A ^ B = " << num.display() << " ^ " << num1.display() << " = " << num2.display() << endl;
	cout << "working time = " << search_time << endl;
	cout << "================================================" << endl;
	int t = 8;
	cout << "EXPONENTIATION (window, t = " << t << ")" << endl;
	end_time = clock();
	search_time = end_time - start_time;
	num2.longPowerWindow(num, num1, t);
	end_time = clock();
	search_time = end_time - start_time;
	cout << "A ^ B = " << num.display() << " ^ " << num1.display() << " = " << num2.display() << endl;
	cout << "working time = " << search_time << endl;
	cout << "================================================" << endl;
	cout << "TESTING CORRECT" << endl;
	longNum num3, num4;
	cout << "(A+B)*C = C*(A+B) = A*C + B*C" << endl;
	num3.longAdd(num, num1);
	num3.longMul(num3, num2);
	cout << num3.display() << endl;
	num3.longAdd(num, num1);
	num3.longMul(num2, num3);
	cout << num3.display() << endl;
	num3.longMul(num, num2);
	num4.longMul(num1, num2);
	num3.longAdd(num3, num4);
	cout << num3.display() << endl;
	cout << "n*A = A + A + ... + A" << endl;
	longNum n("64");
	num3.longMul(n, num);
	num4.longMulOneDigit(num4, 0);
	for (int i = 0; i < 100; i++)
		num4.longAdd(num4, num);
	cout << num3.display() << "  =   " << num4.display() << endl;*/

	system("pause");
    return 0;
}

