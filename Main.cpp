/*
 * Main.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */
#include <iostream>
#include "Gerade2D.h"

using namespace std;

static void falsch() {
	std::cout << "falsch" << std::endl;
}

#define TEST(bedingung)                   \
  if(bedingung)                           \
    std::cout << "richtig" << std::endl;  \
  else                                    \
    falsch();

void matrixTest() {

	Matrix m1(3, 3);
	m1(1, 1) = 1;
	m1(1, 2) = 2;
	m1(1, 3) = 3;
	m1(2, 1) = 4;
	m1(2, 2) = 5;
	m1(2, 3) = 6;
	m1(3, 1) = 7;
	m1(3, 2) = 8;
	m1(3, 3) = 9;
	Vektor v(3);
	v(1) = 2;
	v(2) = 3;
	v(3) = 1;

	Vektor r(3);
	r = m1 * v;
	r.ausgabe();
	cout << endl;
	const Vektor cv(r);
	cv.ausgabe();
	cout << endl;
	Vektor vexpected(3);
	vexpected(1) = 11;
	vexpected(2) = 29;
	vexpected(3) = 47;

	r.subtrahiere(vexpected);
	TEST(r.betrag() < 0.0001);

	TEST(fabs(cv(1) - vexpected(1)) < 0.0001);

	const Matrix cm(m1);
	TEST(fabs(m1(1, 1) - cm(1, 1)) < 0.0001);

	Matrix m2(2, 3);
	m2(1, 1) = 1;
	m2(1, 2) = 2;
	m2(2, 1) = 4;
	m2(2, 2) = 5;
	m2(3, 1) = 7;
	m2(3, 2) = 8;

	Matrix mr(m1 * m2);

	Matrix mexpected(3, 2);
	mexpected(1, 1) = 30;
	mexpected(1, 2) = 36;
	mexpected(2, 1) = 66;
	mexpected(2, 2) = 81;
	mexpected(3, 1) = 102;
	mexpected(3, 2) = 126;

	int i, j;
	for (i = 1; i < 3; ++i)
		for (j = 1; j < 2; ++j) {
			TEST(fabs(mr(i, j) - mexpected(i, j)) < 0.0001);
		}
	cout << "hallo" << endl;
	try {
		mr(3, 3);
		falsch();
	} catch (float nan) {
		if (nan == nan) {
			falsch();
		}
	}

	try {
		cv(2);
		falsch();
	} catch (float nan) {
		if (nan == nan) {
			falsch();

		}
	}

	TEST(fabs(v.skalarprodukt(vexpected) - 156) < 0.0001);
}

void geradenTest(const Gerade2D& g) {
	Vektor2D v(6, 0);
	TEST(g.aufGerade(v) == true);

	TEST(fabs(g.gerichteterAbstand(Vektor2D(9, 4)) - (-5)) < 0.0001);

	TEST(fabs(g.normale().winkel(Vektor2D(1, -7)) - 45) < 0.0001);

	Gerade2D g2(Vektor2D(7, 7));
	g2.normale(g.normale());
	TEST(fabs(g2.normale().betrag() - 5) < 0.0001);

	TEST(g2.aufGerade(g.aufpunkt()) == false);
}

int main2() {
	{
		Vektor2D a(3, 1);
		Vektor2D b(1, 2);
		Vektor2D c;

		Vektor2D *z = new Vektor2D(-3, 1);
		Vektor2D *w = new Vektor2D;
		Vektor2D u(1, 2);

		c.addiere(a);
		b.addiere(c);

		cout << "Betrag von b nach Addition von c: " << b.betrag() << endl;

		a.addiere(*z);
		cout << endl;

		cout << "Vektor a nach Addition von z: " << endl;
		a.ausgabe();
		cout << endl;
		cout << endl;

		w->addiere(*z);
		w->addiere(b);

		cout << "Vektor w nach 2 Additionen: " << endl;
		w->ausgabe();
		cout << endl;
		cout << endl;

		w->kopiereIn(u);
		a.kopiereIn(u);

		cout << "Vektor w nach kopieren von u: " << endl;
		w->ausgabe();
		cout << endl;
		cout << endl;

		cout << "Vektor a nach kopieren von u: " << endl;
		a.ausgabe();
		tausche(a, *z);
		cout << endl;
		cout << endl;

		cout << "Vektor a nach tauschen mit z: " << endl;
		a.ausgabe();
		cout << endl;
		cout << endl;

		cout << "Vektor z nach tauschen mit a: " << endl;
		z->ausgabe();
		cout << endl;
		cout << endl;

		cout << "Betrag von a: " << a.betrag() << endl;
		cout << "Betrag von b: " << b.betrag() << endl;
		cout << "Betrag von c: " << c.betrag() << endl;
		cout << "Betrag von u: " << u.betrag() << endl;
		cout << "Betrag von z: " << z->betrag() << endl;
		cout << "Betrag von w: " << w->betrag() << endl;
		cout << endl;

		delete z;
		delete w;

		Vektor2D h(2, 2);
		Vektor2D j(2, 2);
		cout << "Vektor h: " << endl;
		h.ausgabe();
		cout << endl;
		cout << "Vektor j: " << endl;
		j.ausgabe();
		cout << endl;
		cout << "Skalarprodukt: " << h.skalarprodukt(j) << endl;
		cout << endl;
		cout << "HEEEherh" << endl;
		Vektor2D vek1(1, 1);
		Vektor2D vek2(-5, 0);
		cout << "H23424rh" << endl;
		cout << "Winkel: " << vek1.winkel(vek2) << "°" << endl;
		cout << endl;

//Blatt 5
		//	Vektor2D* vektor2DArraGerade2D g2(Vektor2D(7, 7));y[3];

		Vektor2D* varr[] = { new Vektor2D(2, 3), new Vektor2D(-2, 1) };

		varr[0]->addiere(*varr[1]);
		varr[0]->ausgabe();
		cout << endl;
		for (int i = 0; i < 2; i++)
			delete varr[i];

		Gerade2D g(Vektor2D(-3, -4), new Vektor2D(2, 3));
		geradenTest(g);

		cout << g.gerichteterAbstand(Vektor2D(4, 3)) << endl;
		Vektor2D tempVek(4, -3);

		cout << g.aufGerade(tempVek) << endl;
		g.aufpunkt().ausgabe();
		cout << endl;
		g.aufpunkt(tempVek);
		g.aufpunkt().ausgabe();
		cout << endl;

		g.normale().ausgabe();
		cout << endl;
		g.normale(tempVek);
		g.normale().ausgabe();
		cout << endl;

		Vektor2D neu(5, 5);
		neu = neu * 3.0;
		neu.ausgabe();
		cout << endl;

		Vektor2D neuAddieren(5, 5);
		neu + neuAddieren;
		neu.ausgabe();
		cout << endl;

		matrixTest();
	}

	Matrix M(1, 2);
	cout << "Counter: " << M.getCounter();
	cout << endl;

}

