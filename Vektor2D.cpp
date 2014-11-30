/*
 * Vektor2D.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */

#include <iostream>
#include "Vektor2D.h"
#include "Matrix.h"
using namespace std;

Vektor2D::Vektor2D() :
		Vektor(2) {
}
Vektor2D::Vektor2D(float a, float b) :
		Vektor(2) {
	m_Element[0] = a;
	m_Element[1] = b;
}

Vektor2D Vektor2D::operator *(float x) {
	Vektor2D temp;
	for (int i = 0; i < 2; i++) {
		temp.m_Element[i] = this->m_Element[i] * x;
	}
	return temp;
}

Vektor2D Vektor2D::operator +(const Vektor2D& y) {
	Vektor2D temp;
	for (int i = 0; i < 2; i++) {
		temp.m_Element[i] = this->m_Element[i] + y.m_Element[i];
	}
	return temp;
}

void Vektor2D::addiere(Vektor2D v)const {
	for (int i = 0; i < m_Zeilen * m_Spalten; i++) {
		m_Element[i] += v.m_Element[i];
	}

}

void Vektor2D::kopiereIn(Vektor2D &zielvar) {
	for (int i = 0; i < m_Zeilen * m_Spalten; i++) {
		m_Element[i] = zielvar.m_Element[i];
	}
}

void Vektor2D::ausgabe() const {
	cout << "Vektor2D: ";
	Matrix::ausgabe();
}

void tausche(Vektor2D &a, Vektor2D &b) {
	Vektor2D temp;
	temp.kopiereIn(a);
	a.kopiereIn(b);
	b.kopiereIn(temp);
}

