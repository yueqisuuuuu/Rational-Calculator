#include "rational.h"
#include <cmath>
#include <cassert>

int Rational::get_num(){
    return num;
}
int Rational::get_den(){
    return den;
}
Rational::Rational(){
    num=0;
    den=0;
}
Rational::Rational(int n, int d){
    assert(d!=0);
    num=n;
    den=d;
}
void Rational::reduce(){
    assert(den!=0);
    if (num>1){
        for(int i=2; i<=num && i<=den; i++){
            if(((num%i)==0) && ((den%i)==0)){
                num=num/i;
                den=den/i;
                i--;}}}
    else if (num<-1){
        for(int i=2; i<=(-num) && i<=den; i++){
            if((((-num)%i)==0) && ((den%i)==0)){
                num=num/i;
                den=den/i;
                i--;}}}
    }
void Rational::reciprocal(){
    assert(den!=0 && num !=0);
    int a=num;
    num=den;
    den=a;
}

Rational operator +(Rational a, Rational b){
    assert(a.get_den()!=0 && b.get_den()!=0);
    int cn, cd;
    if (a.get_den()==b.get_den()){
        cd=a.get_den();
        cn=a.get_num()+b.get_num();
    }
    else{
        cd=a.get_den()*b.get_den();
        cn=(a.get_num()*b.get_den())+(b.get_num()*a.get_den());
    }
    Rational c(cn,cd);
    c.reduce();
    return c;
}
Rational operator *(Rational a, Rational b){
    assert(a.get_den()!=0 && b.get_den()!=0);
    int cn, cd;
    cd=a.get_den()*b.get_den();
    cn=a.get_num()*b.get_num();
    Rational c(cn,cd);
    c.reduce();
    return c;
}
bool operator <(Rational a, Rational b){
    assert(a.get_den()!=0 && b.get_den()!=0);
    double da=a.get_num()/a.get_den();
    double db=b.get_num()/b.get_den();
    return da<db;
}
bool operator >(Rational a, Rational b){
    assert(a.get_den()!=0 && b.get_den()!=0);
    double da=a.get_num()/a.get_den();
    double db=b.get_num()/b.get_den();
    return da>db;
}
bool operator ==(Rational a, Rational b){
    assert(a.get_den()!=0 && b.get_den()!=0);
    double da=a.get_num()/a.get_den();
    double db=b.get_num()/b.get_den();
    return da==db;
}
std::ostream& operator <<(std::ostream& out, Rational a){
    out<<a.get_num()<<"/"<<a.get_den()<<std::endl<<std::endl;
    return out;
}
