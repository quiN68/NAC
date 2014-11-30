/*
 * Matrix.h
 *
 *  Created on: Oct 7, 2014
 *      Author: philip
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Vektor;
class Matrix {
private:
	static int counter;

protected:
	int m_Spalten, m_Zeilen;
	float *m_Element;


public:
	Matrix(int, int);
	Matrix(const Matrix &obj);
	void operator=(Matrix const &obj);
	float& operator()(const int, const int) const;
	virtual void ausgabe() const;
	int getCounter();
	virtual ~Matrix();
	Matrix operator*(const Matrix& m) const;
	Vektor operator*(const Vektor& v) const;

};

#endif /* MATRIX_H_ */
