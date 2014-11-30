#include "Gerade2D.h"


Gerade2D::Gerade2D(Vektor2D normale, Vektor2D *aufpunkt) :
		m_Normale(normale), m_Aufpunkt(*aufpunkt) {
}

Gerade2D::~Gerade2D(void) {
}

float Gerade2D::gerichteterAbstand(Vektor2D x) const {
	Vektor2D diff(x);
	diff.subtrahiere(m_Aufpunkt);
	return m_Normale.skalarprodukt(diff) / m_Normale.betrag();
}

bool Gerade2D::aufGerade(Vektor2D x) const {
	if (fabs(this->gerichteterAbstand(x)) == 0) {
		return true;
	}
	return false;
}

void Gerade2D::normale(Vektor2D normale) {
	m_Normale = normale;
}
void Gerade2D::aufpunkt(Vektor2D aufpunkt) {
	m_Aufpunkt = aufpunkt;
}
const Vektor2D Gerade2D::normale() const {
	return m_Normale;
}
const Vektor2D Gerade2D::aufpunkt() const{
	return m_Aufpunkt;
}
