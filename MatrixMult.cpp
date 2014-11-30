#include "Matrix.h"
#include "Vektor.h"
#include <limits>

Matrix Matrix::operator*(const Matrix & m) const
{
  if(m_Spalten != m.m_Zeilen)
    throw std::numeric_limits<float>::quiet_NaN();

  Matrix result(m_Zeilen, m.m_Spalten);
  int i,j,k;
  for(i=1;i<=result.m_Zeilen;++i)
  {
    for(j=1;j<=result.m_Spalten;++j)
    {
      float z=0;
      for(k=1;k<=m_Spalten;++k)
      {
        z += (*this)(i,k)*m(k,j);
      }
      result(i,j)=z;
    }
  }
  return result;
}

Vektor Matrix::operator*(const Vektor& v) const
{
  if(m_Spalten != v.m_Zeilen)
    throw std::numeric_limits<float>::quiet_NaN();

  Vektor result(m_Zeilen);
  int i,k;
  for(i=1;i<=result.m_Zeilen;++i)
  {
    float z=0;
    for(k=1;k<=m_Spalten;++k)
    {
      z += (*this)(i,k)*v(k);
    }
    result(i)=z;
  }
  return result;
}

