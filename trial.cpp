//
// Created by abodi on 04/05/2020.
//
#include "solver.hpp"
#include <iostream>
using namespace solver;
int main()
{
solver::ComplexVariable n(1,0,1);
//n+2;
std::cout<<solver::solve(n);
    return 0;
}
