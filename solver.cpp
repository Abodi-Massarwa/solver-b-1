//
// Created by abodi on 04/05/2020.
//
#include "solver.hpp"
#include <iostream>
#include <math.h>
using namespace solver;
RealVariable& solver::operator*(double a, RealVariable& f)
{
 f.re*=a;
 f.x*=a;
 f.x2*=a;
 return f;
}
RealVariable& operator*( RealVariable& f,double a)
{
    return solver::operator*(a,f);
}
RealVariable& solver::operator*( RealVariable& f, RealVariable& g)
{
    f.re*g;
    f.x*g;
    f.x2*g;
    return g;
}
RealVariable& solver::operator+(double a, const RealVariable& f)
{
    RealVariable rv(f.x2,f.x,f.re+a);
    return rv;
}
RealVariable& solver::operator+( const RealVariable& f,double a)
{
    return  solver::operator+(a,f);
}
RealVariable& solver::operator+(const RealVariable& f,const RealVariable& g)
{
   RealVariable temp(f.x2+g.x2,f.x+g.x,f.re+g.re);
   return temp;
}
RealVariable& solver::operator-(const RealVariable& f,const RealVariable& g)
{
    RealVariable temp(f.x2-g.x2,f.x-g.x,f.re-g.re);
    return temp;
}
RealVariable& solver::operator-(double a, const RealVariable& f)
{
    return solver::operator+(-a,f);
}
RealVariable& solver::operator-( const RealVariable& f,double a)
{
    return  solver::operator+(f,-a);
}
double power(double,int);
RealVariable& solver::operator^( const RealVariable& f,double a)
{
    //a^2+2ab+b^2
    //if f^a -> pow >2 throw exception
    std::string str="sorry we cant deal with power >2";
    if(f.x2!=0)
    {
        //indicates that it cant be even risen with any a
        //except for 0 and 1
        if(a!=0&&a!=1)
        {
            try {
                throw str;
            }
            catch(std::string& str)
            {
                std::abort();
            }

        }
    }
    else if(f.x!=0)
    {
        if(a>2)
        {
            try {
                throw str;
            }
            catch(std::string& str)
            {
                std::abort();
            }

        }
    }
    /// now assume we're clear to go .
    RealVariable xx(pow(f.x2,a),2*f.x*f.re,power(f.re,a));
    return xx;

}
double power(double x, int a)
{
    if(a==0) return 1;
    return x*power(x,a-1);
}
RealVariable& solver::operator/(const RealVariable& h,double e)// more likely wont be fx/gx
{
    RealVariable rv(h.x2/e,h.x/e,h.re/e);
    return rv;
}
RealVariable& solver::operator==(const RealVariable& a,const RealVariable& b)
{
    RealVariable rv(a.x2-b.x2,a.x-b.x,a.re-b.re);
    return rv;
}
RealVariable& solver::operator==(const RealVariable& a,double b)
{
    RealVariable rv(a.x2,a.x,a.re-b);
    return rv;
}
double solver::solve( RealVariable& a)
{
    //depends, in case we have a polynomial of rank 1 its solvable in o(1)
    //but in case we have a polynomial of rank 2 , it must be recursive (divide and conquer algorithm)
   if(a.getx2()==0) /* indicates a level 1 polynomial*/
   {
       /* no need to care for any kind of complex solution since
        * complex solution appear when root of -1 comes */
       return (-1*(a.getre()))/a.getx();

   }
   double coff=(-1*a.getx());
    double root=sqrt((a.getx()*a.getx()-4*a.getx2()*a.getre()))/(2*a.getx2());
    double ans_1=coff+root;
    double ans_2=coff-root;
    return ans_2;

}