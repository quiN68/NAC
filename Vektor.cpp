/*
 * Vektor.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */

#include <iostream>
#include <math.h>
#include "Vektor.h"
#include <limits>

using namespace std;

Vektor::Vektor(int n) :
		Matrix(1, n) {
}

Vektor::~Vektor() {
}
float Vektor::skalarprodukt(Vektor a) const {
	if (m_Zeilen == a.m_Zeilen && m_Spalten == a.m_Spalten) {
		float skalarProdukt = 0;
		for (int i = 0; i < m_Zeilen * m_Spalten; i++) {
			skalarProdukt += m_Element[i] * a.m_Element[i];
		}
		return skalarProdukt;
	} else
		return numeric_limits<float>::quiet_NaN();

}
float Vektor::betrag() const {
	return sqrt(skalarprodukt(*this));
}

float Vektor::winkel(Vektor a) const {
	if (m_Zeilen == a.m_Zeilen && m_Spalten == a.m_Spalten) {
		float winkel = 0;
		winkel = acos((skalarprodukt(a)) / (betrag() * a.betrag()));
		return winkel / M_PI * 180;
	} else
		return numeric_limits<float>::quiet_NaN();

}
void Vektor::subtrahiere(Vektor a) {
	for (int i = 0; i < m_Zeilen * m_Spalten; i++) {
		m_Element[i] -= a.m_Element[i];
	}
}

const float& Vektor::operator()(int zeile) const {
	if (zeile > m_Zeilen * m_Spalten) {
		throw std::numeric_limits<float>::quiet_NaN();
	} else
		return m_Element[zeile - 1];
}

float& Vektor::operator ()(int zeile) {
	if (zeile > m_Zeilen * m_Spalten) {
		throw std::numeric_limits<float>::quiet_NaN();
	} else
		return m_Element[zeile - 1];
}

