#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double relu(double shurushu)
{
    double shuru=shurushu;
    if(shurushu>0.000000)
    {
        return shuru;
    }
    else
    {
        return (shuru*0.010000);
    }
    ;
}
double reludao(double shurushu)
{
    if(shurushu>0.000000)
    {
        return 1.000000;
    }
    else
    {
        return 0.010000;
    }
    ;
}
