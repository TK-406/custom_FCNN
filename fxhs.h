#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "dy.h"
#include "hs.h"
int count;
int count0;


double wpianyizhi;
double bpianyizhi;

double alphapyz;
//――――――――――――――――――――――――――――――――
int fxchuanbo1(int shuruceng)
{
    count--;
    for(int ctin2 = 0;ctin2 < meiceng;ctin2++) {
        for(int ctin3 = 0;ctin3 < meiceng;ctin3++) {
            wpianyizhi*=wji[count][ctin2][ctin3]*reludao(xji[count][ctin2]);
            bpianyizhi*=wji[count][ctin2][ctin3]*reludao(xji[count][ctin2]);
            if(count<shuruceng+2)
            {
                for(int ctin0 = 0;ctin0 < meiceng;ctin0++) {
                    for(int ctin1 = 0;ctin1 < meiceng;ctin1++) {
                        wpianyizhi*=xlji[shuruceng][ctin0];
                        /*if(ct1==0)
                        {
                            wpyzsyg=wpianyizhi;
                            bpyzsyg=bpianyizhi;
                        }
                        else
                        {
                            wpianyizhi=beta*wpianyizhi+(1.000000-beta)*wpyzsyg;
                            bpianyizhi=beta*bpianyizhi+(1.000000-beta)*bpyzsyg;
                        }
                        ;*/
                        wji[shuruceng][ctin0][ctin1]-=wpianyizhi*alphapyz;
                        bji[shuruceng][ctin0][ctin1]-=bpianyizhi*alphapyz;
                    }
                }
                //printf("%lf\n",wpianyizhi);
                return 0;
            }
            else
            {
                fxchuanbo1(shuruceng);
            }
            ;
        }
    }
}
//―――――――――――――――――――――――――――――――――――――――
int fxchuanbo0(int shurushu)
{
    count0--;
    for(int ctin2 = 0;ctin2 < meiceng;ctin2++) {
        for(int ctin3 = 0;ctin3 < meiceng;ctin3++) {
            wpianyizhi*=wji[count0][ctin2][ctin3]*reludao(xji[count0][ctin2]);
            bpianyizhi*=wji[count0][ctin2][ctin3]*reludao(xji[count0][ctin2]);
            if(count0<2)
            {
                for(int ctin0 = 0;ctin0 < meiceng;ctin0++) {
                    for(int ctin1 = 0;ctin1 < ybrl;ctin1++) {
                        wpianyizhi*=xlji[shurushu][ctin1];
                        /*if(ct1==0)
                        {
                            wpyzsyg=wpianyizhi;
                            bpyzsyg=bpianyizhi;
                        }
                        else
                        {
                            wpianyizhi=beta*wpianyizhi+(1.000000-beta)*wpyzsyg;
                            bpianyizhi=beta*bpianyizhi+(1.000000-beta)*bpyzsyg;
                        }
                        ;*/
                        wji0[ctin0][ctin1]-=wpianyizhi*alphapyz;
                        bji0[ctin0][ctin1]-=bpianyizhi*alphapyz;
                    }
                }
                //printf("%lf\n",wpianyizhi);
                return 0;
            }
            else
            {
                fxchuanbo0(shurushu);
            }
            ;
        }
    }
}
