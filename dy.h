#include <stdio.h>
#include <stdlib.h>
#define xljishu 3000
#define ybrl 10
#define xlcishu 10000
#define cengshu 5
#define meiceng 5
int ct1=0;

const double alpha=0.000001;
double alphatj=28.190000;
const double beta=0.900000;

double xlji[xljishu][ybrl];
double bqji[xljishu];//标签

double wji0[meiceng][ybrl];
double wji[cengshu][meiceng][meiceng];
double wjiend[meiceng];

double bji0[meiceng][ybrl];
double bji[cengshu][meiceng][meiceng];
double bjiend[meiceng];

double zji0[meiceng];
double zji[cengshu][meiceng];
double zend;

double xji[cengshu+1][meiceng];
double jieguo;

double jhuanchong;
double j;

/*
double wpyzsyg0[meiceng][ybrl];
double wpyzsyg[cengshu][meiceng][meiceng];
double wpyzsygend[meiceng];
double bpyzsyg0[meiceng][ybrl];
double bpyzsyg[cengshu][meiceng][meiceng];
double bpyzsygend[meiceng];
*/
