/*
 * Pair.cpp
 * etk 2021
 * Pair.cpp implements the Pair class and 
 * can be used by the PosPoly implemenation.
 * See that getX() and getY() methods have been added.
 * Notice the isEqualTo method that is useful when
 * implementing PosPoly.
 * Notice that the Pair constructor uses member-initializer 
 * syntax to set the values of x and y. This supports the
 * the creation of const Pair objects.
 * Finally, notice that all non-constructor methods that do not need 
 * to alter the private variables x and y have been declared const.
 */

#include <iostream>
#include <cmath>
using namespace std;
#include "Pair.h"

  Pair::Pair( ) : x(0), y(0) { }

  Pair::Pair(int xx,int yy) : x(xx), y(yy) { }

  void Pair::setX(int xx){
	 x=xx; 
  }

  void Pair::setY(int yy) { 
	y=yy;
  }

  int Pair::getX() const {
	return x;
  }

  int Pair::getY() const {
	return y;
  }

  void Pair::display( ) const {
    cout << "(" << x << ":" << y << ")";
  }

  bool Pair::isEqualTo(const Pair & other) const {
    return x==other.x && y==other.y;
  }

  double Pair::distanceTo(const Pair & other) const {
    return sqrt( (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) );
  }


