/*
 * Vektor2D.h
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */

#ifndef VEKTOR2D_H_
#define VEKTOR2D_H_


#include "Vektor.h"



class Vektor2D : public Vektor{
public:
Vektor2D();
Vektor2D(float a, float b);
void addiere(Vektor2D) const;
void kopiereIn(Vektor2D&);
void ausgabe() const;
Vektor2D operator*(float x);
Vektor2D operator+(const Vektor2D& y);

};

void tausche(Vektor2D&, Vektor2D&);


#endif /* VEKTOR2D_H_ */
