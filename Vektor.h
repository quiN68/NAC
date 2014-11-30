/*
 * Vektor.h
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */

#ifndef VEKTOR_H_
#define VEKTOR_H_
#include "Matrix.h"

class Vektor : public Matrix {
public:
	Vektor(int);
	virtual ~Vektor();
	float skalarprodukt(Vektor) const;
	float betrag() const;
	float winkel(Vektor) const;
	void subtrahiere(Vektor);
	const float& operator()(int) const;
	float& operator()(int);
};




#endif /* VEKTOR_H_ */
