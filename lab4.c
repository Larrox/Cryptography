#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void zamiana(int a, int tab[100]){
     int i=0;
     while(a){
              tab[i]=a%2;
              a = a/2;
              i++;
              }            
     }          
int potegid(int liczba){
    int d=0;
     int q=0;
     int bufor;
     bufor=liczba;
     while(liczba%2==0){
                        liczba=liczba/2;
                        d++;}
     q=liczba;
     return d;
     }
int potegiq(int liczba){
    int d=0;
     int q=0;
     int bufor;
     bufor=liczba;
     while(liczba%2==0){
                        liczba=liczba/2;
                        d++;}
     q=liczba;
     return q;
     }
int potegowanie(int liczba, int potega, int modulo){
    int binarne[1000];
    int i=0;
    int pomoc=0;
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
              
int dzialanie(int liczba, int potega, int modulo){
  int tab[100];
  int i=0;
  int b=0;
  for(i=0;i<100;i++){
          tab[i]=7;
          }
 	 zamiana(potega,tab);
 	 i=0;
	while (tab[i]!=7){
          printf("%i\t",tab[i]);
          i++;
          }
	printf("\n");
	int j,licznik=0;
	long long int y[100];
	y[0]= liczba;
	y[0]=y[0]%modulo;
	printf("\nliczba\t%i\n",liczba);
	printf("\nmod\t%i\n",modulo);
	printf("\ny0\t%i\n",y[0]);
	for(j=0;j<i;j++){
	                       licznik++;
	                       y[j+1]= y[j]*y[j];
	                       y[j+1]=y[j+1]%modulo;
	                       printf("%i\t",y[j]);
	                   }
	                       
	long long int a=1;
		for(j=0; j<=i; j++){
			if (tab[j]==1){
				a= a*y[j];
				a=a%modulo;
			}
		}
	b=a;
	return b;
}

int main(int argc, char *argv[]){
	
 int liczba=0, potega=0, modulo=0;
 printf("Podaj liczbe:\t");
 scanf("%i", &liczba);
 printf("Podaj potege:\t");
 scanf("%i", &potega);
 printf("Podaj modulo:\t");
 scanf("%i", &modulo);
 int wynik;
wynik= dzialanie(liczba,potega,modulo);
printf("\nwynik\t%i\n",wynik);
srand(time(NULL));
int liczba2=0;
printf("\nPodaj liczbe:\t");
scanf("%i", &liczba2);
int liczba3=0;
liczba3=liczba2-1;
int q=0, d=0;
d=potegid(liczba3);
q=potegiq(liczba3);
 printf("D=%i",d);
 printf("q=%i",q);
 int x;
x=(rand()%liczba3-1)+1;
printf("\nrand\t%i\n",x);
int pomoc;
pomoc=potegowanie(x,q,liczba2);
printf("\nLiczba2= %i",pomoc);
int k;
for(k=0;k<d;k++){
                 pomoc=pow(pomoc,2);
                 pomoc=pomoc%liczba2;
                 }
if(pomoc==1||pomoc==liczba2-1){
             printf("\nLiczba jest prawdopodobnie pierwsza\n");
             }
else{
     printf("\nLiczba nie jest pierwsza\n");
     }



  system("PAUSE");	
  return 0;
}
