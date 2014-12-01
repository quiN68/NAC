/*
 * Funktion2D.h
 *
 *  Created on: Nov 24, 2014
 *      Author: philip
 */

#ifndef FUNKTION2D_H_
#define FUNKTION2D_H_
#include "Gerade2D.h"




class Funktion2D : public Vektor2D{


public:
Funktion2D();
virtual ~Funktion2D();
virtual float operator()(const Vektor2D&) const;
};

Vektor2D gradient2D(Funktion2D&, Vektor2D&);
Vektor2D minimieren2D(Funktion2D&, Vektor2D&, float, float tol = 0.00001, float ftol = 0.00001);

#endif /* FUNKTION2D_H_ */
