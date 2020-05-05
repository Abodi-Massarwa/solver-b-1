#include <stdio.h>
#include <complex>

namespace solver{
class RealVariable{
private:
double re;
mutable double x;
mutable double x2;
public:
RealVariable(double _x2=1,double _x=1,double _re=1):re(_re),x(_x),x2(_x2){}// normal constructor
RealVariable(const RealVariable& rv):x2(rv.x2),x(rv.x),re(rv.re){}// copy constructor
double getx2(){return this->x2;}
double getx(){return this->x;}
double getre(){return this->re;}
RealVariable& operator-(double a)
{
    //we better return *this as a reference
    this->re-=a;
    return *this;
}
    RealVariable& operator=(const RealVariable& a)
            {
        RealVariable count(a.x2,a.x,a.re);
        return count;
    }
// we better return a reference since we haven't implemented a copy constructor
// although compilers have their own version of copy constructor for trivial objects
friend RealVariable& operator*(double a, RealVariable& f);
friend RealVariable& operator*( RealVariable& f,double a);
friend RealVariable& operator*( RealVariable& f, RealVariable& g);
friend RealVariable& operator-(const RealVariable& f,double a);
friend RealVariable& operator-(const RealVariable& f,const RealVariable& e);
friend RealVariable& operator-(double a, const RealVariable& f);
friend RealVariable& operator/(const RealVariable& h,double e);
friend RealVariable& operator^(const RealVariable& f,double a);
friend RealVariable& operator+(const RealVariable& x,const RealVariable& f);
friend RealVariable& operator+(const RealVariable& x,double a);
friend RealVariable& operator+(double a,const RealVariable& x);
friend RealVariable& operator==(const RealVariable& a,const RealVariable& b);
friend RealVariable& operator==(const RealVariable& a,double e);
};

//-----------------------------------------------------------------------------------------------------------------------



class ComplexVariable{
public:
double re;
double img;
ComplexVariable()=default;
ComplexVariable(double _re,double _img){
re=_re;
img=_img;

}
ComplexVariable operator-(double e)
{
ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator==(const ComplexVariable& e){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator==(std::complex<double> yvalue){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator==(double e){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator^(double e){

ComplexVariable temp(0,0);
return temp;
}
ComplexVariable operator+(const ComplexVariable& e){

ComplexVariable temp(re+e.re,img+e.img);
return temp;
}
ComplexVariable operator+(double e){

ComplexVariable temp(re+e,img);
return temp;
}
ComplexVariable operator/(double e){
ComplexVariable temp(0,0);
return temp;
}
friend ComplexVariable operator+( const ComplexVariable& e,std::complex<double> yvalue){

ComplexVariable temp(0,0);
return temp;

}
friend ComplexVariable operator+(double e,const ComplexVariable& f);
friend ComplexVariable operator+(double ef,std::complex<double> e);
friend ComplexVariable operator-(const ComplexVariable& e,const ComplexVariable& f);
friend ComplexVariable operator*(double e,const ComplexVariable& f);

};


double solve( RealVariable& a);

std::complex<double> solve( const ComplexVariable b);

};
