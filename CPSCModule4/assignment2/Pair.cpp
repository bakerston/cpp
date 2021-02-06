
// wdg 2014
// Pair.cpp
#include <iostream>
#include <cmath>
using namespace std;
#include "Pair.h"

  Pair::Pair( ) : x(0), y(0)
  {
  }

  Pair::Pair(int xx,int yy) : x(xx), y(yy)
  {
  }

  void Pair::setX(int xx)
  {
    x=xx;
  }

  void Pair::setY(int yy)
  {
    y=yy;
  }

  void Pair::display( ) const
  {
    cout << "(" << x << ":" << y << ")";
  }

  bool Pair::isEqualTo(const Pair & other) const
  {
    return x==other.x && y==other.y;
  }

  double Pair::distanceTo(const Pair & other) const
  {
    return sqrt( (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) );
  }


