/*
 * The Pair class encapsulates a pair of coordinates.
 * This could be used for points on a Cartesian plane
 * or other application in which an (x,y) pair is used.
 * For example, in the PosPoly application we can 
 * allow the term in a polynomial, cx^p (e.g., 2x^3)
 * to be represented as (c,p) or (p,c).  The order
 * (i.e., whether c is represented as x and p as y 
 *  or vice versa) doesn't matter. 
 * You just need to be consistent.
 * You'll notice that I added getX() and getY() methods
 * to permit the PosPoly class to access the private
 * x and y variables.  
 * Also, compared to the sample code, I switched the
 * order of public and private sections to place 
 * the public section first, which is the convention.
 */ 
#ifndef PAIR_H
#define PAIR_H

class Pair {
  public:
	Pair( );
	Pair(int xx,int yy);
	void setX(int xx);
	void setY(int yy);
	int getX() const;
	int getY() const;
	void display( ) const;
	bool isEqualTo(const Pair & other) const;
	double distanceTo(const Pair & other) const;

  private:
    int x,y;

};

#endif
