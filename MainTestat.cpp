/*
 * Main2.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: philip
 */
#include <iostream>
#include "Funktion2D.h"

using namespace std;
int main() {
//	Vektor2D neu(5, 5);
//	neu = neu * 3.0;
//	neu.ausgabe();
//	cout << endl;
//
//	Vektor2D neuAddieren(5, 5);
//	neu + neuAddieren;
//	neu.ausgabe();
//	cout << endl;

	Vektor2D startwert(4, 0);
	startwert.ausgabe();
	cout << endl;
	Funktion2D func;
	Vektor2D min;
	min = minimieren2D(func, startwert, 0.07);
	cout << "Test 1 mit Vektor(4,0)" << endl;
	min.ausgabe();
	cout << endl;
	cout << func(min) << endl;


	startwert = Vektor2D(4, 1);
	min = minimieren2D(func, startwert, 0.07);
	cout << "Test 2 mit Vektor(4,1)" << endl;
	min.ausgabe();
	cout << endl;
	cout << func(min) << endl;

	startwert = Vektor2D(3, 1);
	min = minimieren2D(func, startwert, 0.05);
	cout << "Test 3 mit Vektor(3.0,1.0)" << endl;
	min.ausgabe();
	cout << endl;
	cout << func(min) << endl;

}
