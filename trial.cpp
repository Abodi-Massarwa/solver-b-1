//
// Created by abodi on 04/05/2020.
//
#include "solver.hpp"
#include <iostream>
using namespace solver;
int main()
{
///RealVariable x(1,2,-15);
RealVariable y;
std::cout<<solve(((1*y)^2)+2*y-15);
///no problem with rank 1 polynomials !
// but rank 2 wtf !
    return 0;
}
