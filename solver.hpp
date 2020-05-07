#include <stdio.h>
#include <complex>

namespace solver{
class RealVariable{
private:
double re;
mutable double x;
mutable double x2;
public:
RealVariable(double _x2=0,double _x=1,double _re=0):re(_re),x(_x),x2(_x2){}// normal constructor
RealVariable(const RealVariable& rv):x2(rv.x2),x(rv.x),re(rv.re){}// copy constructor
double getx2()const {return this->x2;}
double getx()const {return this->x;}
double getre()const{return this->re;}
RealVariable operator-(double a)
{
    //we better return *this as a reference
    RealVariable rv(this->getx2(),this->getx(),this->getre()-a);
    return rv;
}
    RealVariable& operator=(const RealVariable& a)
            {
        x2=a.x2;
        x=a.x;
        re=a.re;
        return *this;
    }
// we better return a reference since we haven't implemented a copy constructor
// although compilers have their own version of copy constructor for trivial objects
friend RealVariable operator*(double a, const RealVariable& f);
friend RealVariable operator*( const RealVariable& f,double a);
 friend RealVariable operator*( const RealVariable& f, const RealVariable&g);
friend RealVariable operator-(const RealVariable& f,double a);
friend RealVariable operator-(const RealVariable& f,const RealVariable& e);
friend RealVariable operator-(double a, const RealVariable& f);
friend RealVariable operator/(const RealVariable& h,double e);
friend RealVariable operator^( const RealVariable& f,double a);
friend RealVariable operator+(const RealVariable& x,const RealVariable& f);
friend RealVariable operator+(const RealVariable& x,double a);
friend RealVariable operator+(double a,const RealVariable& x);
friend RealVariable operator==(const RealVariable& a,const RealVariable& b);
friend RealVariable operator==(const RealVariable& a,double e);
};
    RealVariable operator*(double a, const RealVariable& f);
     RealVariable operator*( const RealVariable& f,double a);
     RealVariable operator*( const RealVariable& f, const RealVariable& g);
     RealVariable operator-(const RealVariable& f,double a);
     RealVariable operator-(const RealVariable& f,const RealVariable& e);
     RealVariable operator-(double a, const RealVariable& f);
   RealVariable operator/(const RealVariable& h,double e);
    RealVariable operator^( const RealVariable& f,double a);
    RealVariable operator+(const RealVariable& x,const RealVariable& f);
  RealVariable operator+(const RealVariable& x,double a);
    RealVariable operator+(double a,const RealVariable& x);
  RealVariable operator==(const RealVariable& a,const RealVariable& b);
    RealVariable operator==(const RealVariable& a,double e);
//-----------------------------------------------------------------------------------------------------------------------



class ComplexVariable{
public:
RealVariable var;
std::complex<double> imag;
ComplexVariable(const ComplexVariable  &f):var(f.var.getx2(),f.var.getx(),f.var.getre()),imag(f.imag){}
 ComplexVariable(double x2=0,double x=1,double re=0,std::complex<double> a=(0,0)):var(x2,x,re),imag(a){}
 ComplexVariable(RealVariable& f):var(f),imag((0,0)){}
    ComplexVariable& operator =(const ComplexVariable& a)
    {
        this->var=a.var;
        this->imag=a.imag;
        return *this;
    }
    friend ComplexVariable operator*(double a, const ComplexVariable& f);
    friend ComplexVariable operator*( const ComplexVariable& f,double a);
    friend ComplexVariable operator*( const ComplexVariable& f, const ComplexVariable&g);
    friend ComplexVariable operator-(const ComplexVariable& f,double a);
    friend ComplexVariable operator-(const ComplexVariable& f,const ComplexVariable& e);
    friend ComplexVariable operator-(double a, const ComplexVariable& f);
    friend ComplexVariable operator/(const ComplexVariable& h,double e);
    friend ComplexVariable operator^( const ComplexVariable& f,double a);
    friend ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable& f);
    friend ComplexVariable operator+(const ComplexVariable& x,double a);
    friend ComplexVariable operator+(double a,const ComplexVariable& x);
    friend ComplexVariable operator==(const ComplexVariable& a,const ComplexVariable& b);
    friend ComplexVariable operator==(const ComplexVariable& a,double e);
    friend ComplexVariable operator+(const ComplexVariable& a,std::complex<double> comp);
    friend ComplexVariable operator+(std::complex<double> comp,const ComplexVariable& a);
};
     ComplexVariable operator*(double a, const ComplexVariable& f);
    ComplexVariable operator*( const ComplexVariable& f,double a);
     ComplexVariable operator*( const ComplexVariable& f, const ComplexVariable&g);
     ComplexVariable operator-(const ComplexVariable& f,double a);
     ComplexVariable operator-(const ComplexVariable& f,const ComplexVariable& e);
     ComplexVariable operator-(double a, const ComplexVariable& f);
     ComplexVariable operator/(const ComplexVariable& h,double e);
     ComplexVariable operator^( const ComplexVariable& f,double a);
     ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable& f);
     ComplexVariable operator+(const ComplexVariable& x,double a);
     ComplexVariable operator+(double a,const ComplexVariable& x);
     ComplexVariable operator==(const ComplexVariable& a,const ComplexVariable& b);
     ComplexVariable operator==(const ComplexVariable& a,double e);

    double solve( RealVariable a);

std::complex<double> solve( ComplexVariable b);
//     std::complex <double> operator"" i(long double d )
//    {
//        return std::complex <double> { 0.0 , static_cast <double> ( d ) };
//    }
}
