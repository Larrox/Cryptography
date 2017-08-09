#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sito(int liczba){
     printf("Sito Eratostenesa:\n");
     printf("Podaj liczbe:\t");
     scanf("%i",&liczba);
     int pierwiastek= sqrt(liczba);
     int tab[liczba-1];
     int i,j;
     for(i=2;i<=liczba;i++){
                            tab[i-2]=i;
                            }
     for(j=2;j<=pierwiastek;j++){
                           for(i=0;i<liczba-1;i++){
                                                   if(tab[i]%j==0&&tab[i]!=j){
                                                                              tab[i]=-7;
                                                                              }
                                                                              }
                                                                              }
     for(i=0;i<=liczba-2;i++){
                              //printf("%i\t",tab[i]);
                              }
     int licznik=0;
     int tab2[liczba];
     for(i=0;i<=liczba-2;i++){
                              if(tab[i]!=-7){
                                             tab2[licznik]=tab[i];
                                             licznik++;
                                             }
                                             }
      for(i=0;i<licznik;i++){
                              printf("%i\t",tab2[i]);
                              }
}

void euklides(int a, int b){
     printf("Algorytm Euklidesa:\n");
     printf("Podaj a:\t");
     scanf("%i",&a);
     printf("Podaj b:\t");
     scanf("%i",&b);
     int r1,q1,r2,q2,r3,q3;
     int x_1,x0,x1,y_1,y0,y1;
     r1=a%b;
     q1=a/b;
     r2=b%r1;
     q2=b/r1;
     x_1=1;
     y_1=0;
     x0=0;
     y0=1;
     printf("\n");
     printf("a\tq\tx\ty\n");
     printf("%i\t%i\t%i\t%i\n",a,0,1,0);
     printf("%i\t%i\t%i\t%i\n",b,0,0,1);
     do{
             q3=r1/r2;
             r3=r1%r2;
             x1=x_1-x0*q1;
             y1=y_1-y0*q1;
             x_1=x0;
             x0=x1;
             y_1=y0;
             y0=y1;
             printf("%i\t%i\t%i\t%i\n",r1,q1,x1,y1);
             r1=r2;
             r2=r3;
             q1=q2;
             q2=q3;
             }while(r3!=0);
    x1=x_1-x0*q1;
    y1=y_1-y0*q1;
    printf("%i\t%i\t%i\t%i\n",r1,q1,x1,y1);
	x_1=x0;
    x0=x1;
    y_1=y0;
    y0=y1;
    x1=x_1-x0*q2;
    y1=y_1-y0*q2;
    printf("%i\t%i\t%i\t%i\n",r2,q2,x1,y1);
   	printf("NWD:\t%i",r1);
}
int euklidesnwd(int a, int b){
     int r1,q1,r2,q2,r3,q3;
     int x_1,x0,x1,y_1,y0,y1;
     r1=a%b;
     q1=a/b;
     r2=b%r1;
     q2=b/r1;
     x_1=1;
     y_1=0;
     x0=0;
     y0=1;
     do{
             q3=r1/r2;
             r3=r1%r2;
             x1=x_1-x0*q1;
             y1=y_1-y0*q1;
             x_1=x0;
             x0=x1;
             y_1=y0;
             y0=y1;
             r1=r2;
             r2=r3;
             q1=q2;
             q2=q3;
             }while(r3!=0);
    x1=x_1-x0*q1;
    y1=y_1-y0*q1;
	x_1=x0;
    x0=x1;
    y_1=y0;
    y0=y1;
    x1=x_1-x0*q2;
    y1=y_1-y0*q2;
   	return r1;
}
int euklidesd(int a, int b){
     int r1,q1,r2,q2,r3,q3;
     int x_1,x0,x1,y_1,y0,y1;
     r1=a%b;
     q1=a/b;
     r2=b%r1;
     q2=b/r1;
     x_1=1;
     y_1=0;
     x0=0;
     y0=1;
     do{
             q3=r1/r2;
             r3=r1%r2;
             x1=x_1-x0*q1;
             y1=y_1-y0*q1;
             x_1=x0;
             x0=x1;
             y_1=y0;
             y0=y1;
             r1=r2;
             r2=r3;
             q1=q2;
             q2=q3;
             }while(r3!=0);
    x1=x_1-x0*q1;
    y1=y_1-y0*q1;
    int bufor=x1;
	x_1=x0;
    x0=x1;
    y_1=y0;
    y0=y1;
    x1=x_1-x0*q2;
    y1=y_1-y0*q2;
    return x0;
}
void zamiana(long long int a, int tab[100]){
     int i=0;
     while(a){
              tab[i]=a%2;
              a = a/2;
              i++;
              }            
     }          
int potegowanie(long long int liczba,long long int potega,long long int modulo){
    int binarne[1000];
    int i=0;
    long long int pomoc=0;
    for(i=0;i<1000;i++){
                        binarne[i]=2;
                        }   
    pomoc=1;   
    zamiana(potega, binarne);
    i=0;
    int j=0;
    while(binarne[i]!=2){
                         if(binarne[i]==1){
                                           for(j=0;j<pow(2,i);j++){
                                                                   pomoc *= liczba;
                                                                   pomoc = pomoc%modulo;
                                                                   }
                                                                   }
                         i++;
                         }
                                   
return pomoc;
}
void RSA(int p, int q){
	printf("RSA:\n");
    printf("Podaj P:\t");
    scanf("%i",&p);
    printf("Podaj Q:\t");
    scanf("%i",&q);
    int n=p*q;
    int fi=(p-1)*(q-1);
    int e;
    int nwd;
    int d;
    srand(time(NULL));
       do{
        e=(rand()%fi)+1;
        nwd=euklidesnwd(e,fi);
        }while(nwd!=1);
        d=euklidesd(e,fi);
        if(d<0){
        do{
                          d+=fi;
                          }while(d<=0);
                          }
        printf("\nE=\t%i",e);
        printf("\nD=\t%i",d);
        printf("\nKlucz publiczny\t(%i,%i)",n,e);
        printf("\nKlucz prywatny\t(%i,%i)",n,d);
        long long int c,m;
        printf("\nPodaj tekst:\t");
        scanf("%i",&m);
        c=potegowanie(m,e,n);
        printf("Zaszyfrowany:\t%i",c);
        m=potegowanie(c,d,n);
        printf("\nOdszyfrowany:\t%i",m);
        
       
}
int main(int argc, char *argv[])
{
  int liczba;
  sito(liczba);
  printf("\n\n");
  int a,b;
  euklides(a,b);
  printf("\n\n");
  int p,q;
  RSA(p,q);
  printf("\n\n");
  system("PAUSE");	
  return 0;
}
