// wdg 2014
// Pair.h
#ifndef PAIR_H
#define PAIR_H

class Pair {
  private:
    int x,y;

  public:
    Pair( );
    Pair(int xx,int yy);
    void setX(int xx);
    void setY(int yy);
    void display( ) const;
    bool isEqualTo(const Pair & other) const;
    double distanceTo(const Pair & other) const;

};

#endif
