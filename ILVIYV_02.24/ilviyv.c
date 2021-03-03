#include <stdio.h>
#include <stdlib.h>
#define N 7
double Fahr();
void beker(double *also,double *felso);

int main()
{

    double homerseklet[N]={10.1, 13.2, 11.0, 12.3, 14.0, 13.5, 13.3};
    double homersekletF[N];

    for(int i=0;i<N;i++){
        homersekletF[i]=Fahr(&homerseklet[i]);
    }}}
    double alsom,felsom;
    beker(&alsom,&felsom);
    for(int i=0;i<N;i++){
        if(homerseklet[i]<=felsom && homerseklet[i]>=alsom ) printf("%.2lf\n",homersekletF[i]);
    }
    FILE *fp;
    fp=fopen("kercsi.txt","wt");
    for(int i=0;i<N;i++){
        if(homerseklet[i]<=felsom && homerseklet[i]>=alsom ) fprintf(fp,"%lf�F;",homersekletF[i]);
    }
    fclose(fp);

    double min=homerseklet[0],max=homerseklet[0];
    for(int i=0;i<N;i++){

        if (homerseklet[i]<min) min=homerseklet[i];
        if (homerseklet[i]>max) max=homerseklet[i];

    }
    double hoingas=max-min;
    printf("\nA min: %.2lf, a max: %.2lf, a max hoingas: %.2lf\n",min,max,hoingas);


    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(homerseklet[j]>homerseklet[j+1]) {
                int temp=homerseklet[j];
                homerseklet[j+1]=homerseklet[j];
                homerseklet[j]=temp;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(homerseklet[i]<=felsom && homerseklet[i]>=alsom ) printf("%.2lf\n",homerseklet[i]);
    }

    return 0;
}
double Fahr(double *c){

    double fok;

    fok=(*c)*1.8+32;
    return fok;

}
void beker(double *alsom,double *felsom){


    char ch;

    do{
    printf("Kerek egy intervallumot a kovetkezo formaban: (x,y)");
    if(scanf("(%lf,%lf)",alsom,felsom)!=2 || *alsom>=*felsom) while((ch=getchar())!='\n');
    else break;
    }while(1);

}
