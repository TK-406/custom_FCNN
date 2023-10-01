#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
//#include "hs.h"
//#include "dy.h"
#include "fxhs.h"





double jsyg;




int main(int argc, char** argv){
    //初始化开始
    for(int ctcs0 = 0;ctcs0 < xljishu;ctcs0++) {
        for(int ctcs1 = 0;ctcs1 < ybrl;ctcs1++) {
            xlji[ctcs0][ctcs1]=(double)(rand()%11);
        }
    }
    for(int ctcspe0 = 0;ctcspe0 < meiceng;ctcspe0++) {
        for(int ctcspe1 = 0;ctcspe1 < ybrl;ctcspe1++) {
            wji0[ctcspe0][ctcspe1]=(double)-(rand()%2+1);
            bji0[ctcspe0][ctcspe1]=(double)-(rand()%2+1);
        }
    }
    for(int ctcs1 = 0;ctcs1 < cengshu;ctcs1++) {
        for(int ctcs2 = 0;ctcs2 < meiceng;ctcs2++) {
            for(int ctcs3 = 0;ctcs3 < meiceng;ctcs3++) {
                wji[ctcs1][ctcs2][ctcs3]=(double)-(rand()%2+1);
                bji[ctcs1][ctcs2][ctcs3]=(double)-(rand()%2+1);
            }
        }
    }
    for(int ctcs4 = 0;ctcs4 < meiceng;ctcs4++) {
        wjiend[ctcs4]=(double)-(rand()%2+1);
        bjiend[ctcs4]=(double)-(rand()%2+1);
    }
    for(int ctql0 = 0;ctql0 < meiceng;ctql0++) {
        zji0[ctql0]=0.000000;
    }
    for(int ctql0 = 0;ctql0 < cengshu;ctql0++) {
        for(int ctql1 = 0;ctql1 < meiceng;ctql1++) {
            zji[ctql0][ctql1]=0.000000;
        }
    }
    zend=0;
    for(int ctcs5 = 0;ctcs5 < xljishu;ctcs5++) {
        bqji[ctcs5]=0.000000;
        //(double)(rand()%1);
    }
    //初始化结束
    for(int ct0 = 0;ct0 < xlcishu;ct0++) {
        //清零开始
        for(int ctql0 = 0;ctql0 < meiceng;ctql0++) {
            zji0[ctql0]=0.000000;
        }
        for(int ctql0 = 0;ctql0 < cengshu;ctql0++) {
            for(int ctql1 = 0;ctql1 < meiceng;ctql1++) {
                zji[ctql0][ctql1]=0.000000;
            }
        }
        zend=0.000000;
        for(int ctql2 = 0;ctql2 < cengshu+1;ctql2++) {
            for(int ctql3 = 0;ctql3 < meiceng;ctql3++) {
                xji[ctql2][ctql3]=0.000000;
            }
        }
        jieguo=0.000000;
        jhuanchong=0.000000;
        j=0.000000;
        //清零结束
        for(ct1 = 0;ct1 < xljishu;ct1++) {
            for(int ct2 = 0;ct2 < meiceng;ct2++) {
                for(int ct3 = 0;ct3 < ybrl;ct3++) {
                    zji0[ct2]+=xlji[ct1][ct3]*wji0[ct2][ct3]+bji0[ct2][ct3];
                }
                xji[0][ct2]=relu(zji0[ct2]);
            }
            for(int ct4 = 0;ct4 < cengshu;ct4++) {
                for(int ct5 = 0;ct5 < meiceng;ct5++) {
                    for(int ct6 = 0;ct6 < meiceng;ct6++) {
                        zji[ct4][ct5]+=xji[ct4][ct5]*wji[ct4][ct5][ct6]+bji[ct4][ct5][ct6];
                    }
                    xji[ct4+1][ct5]=relu(zji[ct4][ct5]);
                }
            }
            for(int ct7 = 0;ct7 < meiceng;ct7++) {
                zend+=xji[cengshu][meiceng-1]*wjiend[ct7]+bjiend[ct7];
            }
            jieguo=relu(zend);
            jhuanchong+=fabs(bqji[ct1]-jieguo);
            //开始反向传播
            alphapyz=pow(alpha,alphatj);
            //printf("%lf",alphapyz);
            double hcwtc;
            double sunshidao;
            if(bqji[ct1]-jieguo<0.000000)
            {
                sunshidao=1.000000;
            }
            else
            {
                sunshidao=-1.000000;
            }
            ;
            //―――――――――――――――――――――――――――――――――――
            count0=cengshu;
            for(int ctw1 = 0;ctw1 < meiceng;ctw1++) {
                wpianyizhi=sunshidao*reludao(jieguo)*wjiend[ctw1]*reludao(xji[cengshu][ctw1]);
                bpianyizhi=sunshidao*reludao(jieguo)*wjiend[ctw1]*reludao(xji[cengshu][ctw1]);
                fxchuanbo0(ct1);
            }
            //――――――――――――――――――――――――――――――――――
            for(int ctw0 = 0;ctw0 < cengshu;ctw0++) {
                count=cengshu;
                for(int ctw1 = 0;ctw1 < meiceng;ctw1++) {
                    wpianyizhi=sunshidao*reludao(jieguo)*wjiend[ctw1]*reludao(xji[cengshu][ctw1]);
                    bpianyizhi=sunshidao*reludao(jieguo)*wjiend[ctw1]*reludao(xji[cengshu][ctw1]);
                    fxchuanbo1(ctw0);
                }
            }
            //――――――――――――――――――――――――――――――――――――
            for(int ctw1912 = 0;ctw1912 < meiceng;ctw1912++) {
                wpianyizhi=sunshidao*reludao(jieguo)*xji[cengshu][ctw1912];
                bpianyizhi=sunshidao*reludao(jieguo);
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
                wjiend[ctw1912]-=wpianyizhi*alphapyz;
                bjiend[ctw1912]-=bpianyizhi*alphapyz;
            }
            //反向传播结束
        }
        j=jhuanchong/xljishu;
        if(ct0==0)
        {
            jsyg=j;
        };
        if(j>jsyg)
        {
            alphatj+=0.100000;
        };
        jsyg=j;
        
        printf("\n第%d次%lf\0",ct0,j);
        printf("\n%lf",alphatj);
        
        //printf("\npianyi%lf",wpianyizhi);
        if(kbhit()!=0)
        {
            exit(0);
        }
    }
    //int ct1341=mkdir("/storage/emulated/0/aaa",0777);
    int cs1341=mkdir("/storage/emulated/0/download/aaa", 0777);
    printf("%d",cs1341);
    FILE* fpw;
    FILE* fpb;
    fpw=fopen("/storage/emulated/0/download/aaa/wji0.cunchu","wb+");
    fpb=fopen("/storage/emulated/0/download/aaa/bji0.cunchu","wb+");
    for(int ctcspe0 = 0;ctcspe0 < meiceng;ctcspe0++) {
        for(int ctcspe1 = 0;ctcspe1 < ybrl;ctcspe1++) {
            fwrite(&(wji0[ctcspe0][ctcspe1]),sizeof(double),1,fpw);
            fwrite(&(bji0[ctcspe0][ctcspe1]),sizeof(double),1,fpb);
        }
    }
    fclose(fpw);
    fclose(fpb);
    fpw=fopen("/storage/emulated/0/download/aaa/wji.cunchu","wb+");
    fpb=fopen("/storage/emulated/0/download/aaa/bji.cunchu","wb+");
    for(int ctcs1 = 0;ctcs1 < cengshu;ctcs1++) {
        for(int ctcs2 = 0;ctcs2 < meiceng;ctcs2++) {
            for(int ctcs3 = 0;ctcs3 < meiceng;ctcs3++) {
                fwrite(&(wji[ctcs1][ctcs2][ctcs3]),sizeof(double),1,fpw);
                fwrite(&(bji[ctcs1][ctcs2][ctcs3]),sizeof(double),1,fpb);
            }
        }
    }
    fclose(fpw);
    fclose(fpb);
    fpw=fopen("/storage/emulated/0/download/aaa/wjiend.cunchu","wb+");
    fpb=fopen("/storage/emulated/0/download/aaa/bjiend.cunchu","wb+");
    for(int ctcs4 = 0;ctcs4 < meiceng;ctcs4++) {
        fwrite(&(wjiend[ctcs4]),sizeof(double),1,fpw);
        fwrite(&(bjiend[ctcs4]),sizeof(double),1,fpb);
    }
    fclose(fpw);
    fclose(fpb);
    printf("保存完毕");
}
