#ifndef __Gerade2D_h__
#define __Gerade2D_h__

#include "Vektor2D.h"
#include <math.h>

class Gerade2D {
	Vektor2D m_Normale;
	Vektor2D m_Aufpunkt;
public:
	Gerade2D(Vektor2D normale, Vektor2D *aufpunkt = new Vektor2D(0,0));
	virtual ~Gerade2D(void);
	float gerichteterAbstand(Vektor2D v) const;
	bool aufGerade(Vektor2D) const;
	void normale(Vektor2D normale);
	void aufpunkt(Vektor2D aufpunkt);
	const Vektor2D normale() const;
	const Vektor2D aufpunkt() const;
};

#endif // __Gerade2D_h__
