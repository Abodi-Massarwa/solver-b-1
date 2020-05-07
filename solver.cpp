//
// Created by abodi on 04/05/2020.
//
#include "solver.hpp"
#include <iostream>
#include <math.h>
using namespace solver;
RealVariable solver::operator*(double a, const RealVariable& f)
{
    RealVariable rv(f.getx2()*a,f.getx()*a,f.getre()*a);
 return rv;
}
RealVariable solver::operator*( const RealVariable& f,double a)
{
    return solver::operator*(a,f);
}
RealVariable solver::operator*( const RealVariable& f, const RealVariable& g)
{
    //RealVariable rvx2=f.getx2()*g;
    RealVariable rvx=f.getx()*(g);
    RealVariable rvreal= f.getre() *(g);
    RealVariable rv(rvx.getx2() + rvreal.getx2(), rvx.getx() + rvreal.getx(), rvx.getre() + rvreal.getre());
    return rv;
}
RealVariable solver::operator+(double a, const RealVariable& f)
{
    RealVariable rv(f.x2,f.x,f.re+a);
    return rv;
}
RealVariable solver::operator+( const RealVariable& f,double a)
{
    return  solver::operator+(a,f);
}
RealVariable solver::operator+(const RealVariable& f,const RealVariable& g)
{
   RealVariable temp(f.x2+g.x2,f.x+g.x,f.re+g.re);
   return temp;
}
RealVariable solver::operator-(const RealVariable& f,const RealVariable& g)
{
    RealVariable temp(f.x2-g.x2,f.x-g.x,f.re-g.re);
    return temp;
}
RealVariable solver::operator-(double a, const RealVariable& f)
{
    return solver::operator+(-a,f);
}
RealVariable solver::operator-( const RealVariable& f,double a)
{
    return  solver::operator+(f,-a);
}
double power(double,int);
//RealVariable& solver::operator^( const RealVariable& f,double a)
//{
//    //a^2+2ab+b^2
//    //if f^a -> pow >2 throw exception
//    std::string str="sorry we cant deal with power >2";
//    if(f.x2!=0)
//    {
//        //indicates that it cant be even risen with any a
//        //except for 0 and 1
//        if(a!=0&&a!=1)
//        {
//            try {
//                throw str;
//            }
//            catch(std::string& str)
//            {
//                std::abort();
//            }
//
//        }
//    }
//    else if(f.x!=0)
//    {
//        if(a>2)
//        {
//            try {
//                throw str;
//            }
//            catch(std::string& str)
//            {
//                std::abort();
//            }
//
//        }
//    }
//    /// now assume we're clear to go .
//    RealVariable xx(pow(f.x2,a),2*f.x*f.re,power(f.re,a));
//    return xx;
//
//}
double power(double x, int a)
{
    if(a==0) return 1;
    return x*power(x,a-1);
}
RealVariable solver::operator/(const RealVariable& h,double e)// more likely wont be fx/gx
{
    RealVariable rv(h.x2/e,h.x/e,h.re/e);
    return rv;
}
RealVariable solver::operator==(const RealVariable& a,const RealVariable& b)
{
    RealVariable rv(a.x2-b.x2,a.x-b.x,a.re-b.re);
    return rv;
}
RealVariable solver::operator==(const RealVariable& a,double b)
{
    RealVariable rv(a.x2,a.x,a.re-b);
    return rv;
}
double solver::solve( RealVariable a)
{
    if(a.getx2()==0 && a.getx()==0) throw std::invalid_argument("false!");
    //depends, in case we have a polynomial of rank 1 its solvable in o(1)
    //but in case we have a polynomial of rank 2 , it must be recursive (divide and conquer algorithm)
   if(a.getx2()==0) /* indicates a level 1 polynomial*/
   {
       /* no need to care for any kind of complex solution since
        * complex solution appear when root of -1 comes */
       return (-1*(a.getre()))/a.getx();

   }
   double coff=(-1*a.getx());
    double root=sqrt((a.getx()*a.getx()-4*a.getx2()*a.getre()));
    double ans_1=(coff+root)/(2*a.getx2());
    double ans_2=(coff-root)/(2*a.getx2());
    if(ans_1==ans_1) return ans_1;
    throw  std::invalid_argument( "received complex value" );

}
RealVariable solver::operator^(  const RealVariable& f,double a) //done
{
    /* in case we have normal variable we must deal with it normally but if we suppose have (ax^2+bx+c)^n then we must deal with it differently */
    if(a>2||a<0)
    {
        throw "can't deal with functions more than level 2 or negative power";
    }
    /// assume power is legal !
    if(f.getx2()!=0)
    {
        throw "bro we don't deal with polynomials raised to power>2";
    }
    //assume a is legal and power is also legal
    // it might be x^a or (x+c)^a such that a ==0,1,or 2
    // no case for x^2 raised to another power we only need to check for re and x
    //forgot about power 1 or 0
    if(f.getre()==0)
    {
        if(a==2)
        return RealVariable (pow(f.getx(),a),0,0);
        else if(a==1) return RealVariable(f);
        else //a==0
        return RealVariable(0,0,1);


    }
    RealVariable rv;
    //else +c
    if(a==1) return RealVariable(f);
    if(a==2)
    RealVariable rv(pow(f.getx(),2),2*f.getx()*f.getre(),pow(f.getre(),2)); //a^2 +2ab+b^2
   else if(a==0) RealVariable rv(0,0,1);

    return rv;
}
std::complex<double> solver::solve( const ComplexVariable b)
{
    if(b.var.getx2()==0&&b.var.getx()==0) throw std::invalid_argument("false!");
    if(b.imag.imag()!=0)
    {
        //indicted rank 1 with complex number
        std::complex<double> answer(b.var.getre()+b.imag.real(),b.imag.imag());
        return -answer;
    }
    double real_ans=0;
    bool isreal=true;
    try {
        real_ans=solver::solve(b.var);
    }
    catch (std::invalid_argument& e)
    {
    isreal= false;
    }
   if(isreal) return std::complex<double>(real_ans,0);
    //else its complex
//    if(b.imag.imag()!=0)
//    {
//        //indicted rank 1 with complex number
//        return -b.imag;
//    }
    double part1=((-b.var.getx())/2*b.var.getx2());
    double part2=(sqrt(-(pow(b.var.getx(),2)-4*b.var.getx2()*b.var.getre()))/(2*b.var.getx2()));
    return std::complex<double>(part1,part2);
}
ComplexVariable solver::operator*(double a,  const solver::ComplexVariable& f)
{
    RealVariable rv=a*f.var;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator*( const ComplexVariable& f,double a)
{
    RealVariable rv=f.var*a;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator*( const ComplexVariable& f, const ComplexVariable& g)
{
    RealVariable rv=f.var*g.var;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator-(const ComplexVariable& f,double a)
{
    RealVariable rv=f.var-a;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator-(const ComplexVariable& f,const ComplexVariable& e)
{
    RealVariable rv=f.var-e.var;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator-(double a, const ComplexVariable& f)
{
    RealVariable rv=a-f.var;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator/(const ComplexVariable& h,double e)
{
    RealVariable rv=h.var/e;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator^( const ComplexVariable& f,double a)
{
    RealVariable rv=(f.var^a);
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator+(const ComplexVariable& x,const ComplexVariable& f)
{
    RealVariable rv=x.var+f.var;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator+(const ComplexVariable& x,double a)
{
    RealVariable rv=x.var+a;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator+(double a,const ComplexVariable& x)
{
    RealVariable rv=a+x.var;
    ComplexVariable cv(rv);
    return cv;
}
ComplexVariable solver::operator==(const ComplexVariable& a,const ComplexVariable& b)
{
    RealVariable rv=a.var==b.var;
    ComplexVariable cv(rv);
    std::complex<double> free_num=a.imag-b.imag;
    cv.imag=free_num;
    return cv;
}
ComplexVariable solver::operator==(const ComplexVariable& a,double e)
{
    RealVariable rv=a.var==e;
    ComplexVariable cv(rv);
    return cv;
}

ComplexVariable solver::operator+(const ComplexVariable &a, std::complex<double> comp) {
    ComplexVariable cv(a);
    cv.imag+=comp; ///must be implemented in std::complex
    return cv;
}

ComplexVariable solver::operator+(std::complex<double> comp, const ComplexVariable &a) {
    return a+comp;
}
