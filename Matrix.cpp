/*
 * Matrix.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */

#include <iostream>
#include "Matrix.h"
#include <limits>

using namespace std;
int Matrix::counter = 0;

Matrix::Matrix(int m, int n) :
		m_Spalten(m), m_Zeilen(n) {
	m_Element = new float[m_Zeilen * m_Spalten];
	m_Element = new float[m_Zeilen * m_Spalten]();
	counter++;
	//cout << "Standardkonstruktor von Matrix wurde aufgerufen" << endl;
}

float& Matrix::operator()(const int spalte, const int zeile) const {
	if (zeile-1 > m_Zeilen || spalte-1 > m_Spalten) {
		throw numeric_limits<float>::quiet_NaN();
	} else {
		return m_Element[((zeile - 1) * m_Spalten + (spalte - 1))];
	}
}

void Matrix::operator=(Matrix const &obj) {

	if (this != &obj) {
		for (int i = 0; i < m_Spalten * m_Zeilen; i++) {
			m_Element[i] = obj.m_Element[i];
		}
	}
}

Matrix::Matrix(const Matrix &obj) :
		m_Spalten(obj.m_Spalten), m_Zeilen(obj.m_Zeilen) {
	m_Element = new float[m_Spalten * m_Zeilen];
	for (int i = 0; i < m_Spalten * m_Zeilen; i++) {
		m_Element[i] = obj.m_Element[i];
	}
	counter++;
}

void Matrix::ausgabe() const {
	for (int i = 0; i < m_Zeilen * m_Spalten; i++) {
		cout << m_Element[i] << " ";
	}
}

int Matrix::getCounter() {
	return counter;
}

Matrix::~Matrix() {
	// cout << "Matrix ( ";
	// ausgabe();
	// cout << ") wird zerstört" << endl;
	counter--;
//	delete[] m_Element;
}

