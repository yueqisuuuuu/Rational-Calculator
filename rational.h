#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational{
private:
    int num;
    int den;
public:
    int get_num();
    int get_den();
    Rational();
    Rational(int n, int d);
    //Pre: d!=0
    //Post: set num=n, den=d
    void reduce();
    //Pre: den!=0
    //Post: return rational in the most reduce form
    void reciprocal();
    //Pre: den!=0 && num!=0
    //Post: return the reciprocal of this rational
};

Rational operator +(Rational a, Rational b);
//Pre: a.get_den()!=0 && b.get_den()!=0
//Post: Returns a new Rational that is the sum of the two Rationals passed in, in its reduced form
Rational operator *(Rational a, Rational b);
//Pre: a.get_den()!=0 && b.get_den()!=0
//Post: Returns a new Rational that is the product of the two Rations passed in, in its reduced form
bool operator <(Rational a, Rational b);
//Pre: a.get_den()!=0 && b.get_den()!=0
//Post: Returns true if a<b and false if not
bool operator >(Rational a, Rational b);
//Pre: a.get_den()!=0 && b.get_den()!=0
//Post: Returns true if a>b and false if not
bool operator ==(Rational a, Rational b);
//Pre: a.get_den()!=0 && b.get_den()!=0
//Post: Returns true if a==b and false if not
std::ostream& operator <<(std::ostream& out, Rational a);
//Pre: a.get_den()!=0 && b.get_den()!=0
//Post: Prints out the Rational a

#endif // RATIONAL_H
