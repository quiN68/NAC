/*
 * Funktion2D.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: philip
 */

#include "Funktion2D.h"
#include <math.h>
#include <iostream>
using namespace std;

Funktion2D::Funktion2D() {

}

float Funktion2D::operator ()(const Vektor2D& v) const {
	Vektor2D temp(1, 0);
	float zaehler = 0;
	Vektor2D help = temp + v;
	zaehler = help.betrag();
	return (sin(zaehler)/zaehler)*(-1);
}

Vektor2D gradient2D(Funktion2D& func, Vektor2D& vek) {
	const float h = 0.0001;
	// Ableitung nach x
	Vektor2D vekXPlusH(vek(1) + h, vek(2));
	Vektor2D vekXMinusH(vek(1) - h, vek(2));
	float x1 = func(vekXPlusH);
	float x2 = func(vekXMinusH);
	float ergebnis1 = (x1 - x2) / (2 * h);
	// Ableitung nach y
	Vektor2D vekYPlusH(vek(1), vek(2) + h);
	Vektor2D vekYMinusH(vek(1), vek(2) - h);
	float y1 = func(vekYPlusH);
	float y2 = func(vekYMinusH);
	float ergebnis2 = ((y1 - y2) / (2 * h));

	return Vektor2D(ergebnis1, ergebnis2);
}

Vektor2D minimieren2D(Funktion2D& func, Vektor2D startstelle,
		float schrittweite, float tol, float ftol) {
	Vektor2D alterStart(0, 0);
	float funcWertAlt = 0,funcWertNeu = 0;
	// mindestens einmal ausführen
	do {
		funcWertAlt = func(startstelle);
		alterStart = startstelle;
		startstelle = startstelle + gradient2D(func, startstelle) * (-schrittweite);
		funcWertNeu = func(startstelle);
//		cout << funcWertAlt << " " << funcWertNeu << endl;
//		startstelle.ausgabe();
//		cout << endl;
	} while (ftol < fabs(funcWertNeu-funcWertAlt)
			&& tol < fabs(alterStart.betrag() - startstelle.betrag()));

	return startstelle;
}

Funktion2D::~Funktion2D() {

}
