//
// Created by abodi on 07/05/2020.
//
#include "solver.hpp"
#include <iostream>
int main()
{
    solver::ComplexVariable x;
    std::cout<<solve((x^0)==-16);

    return 0;
}
