#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void Fermat(unsigned long long liczba, int *tab, int i){
     unsigned long long l,p,y,y2,x;
     x= ceil(sqrt(liczba));
     do
     {
                 y2=x*x-liczba;
                 y= floor(sqrt(y2));
                 if(y2==y*y){
                             l=x-y;
                             p=x+y;
                             if(l==1){
                                      break;
									  }
                             Fermat(l,tab,i);
                             Fermat(p,tab,i);
                             return;
                             }
                 x++;
                 }while(x+y<liczba);
    for (i = 0; i < 100; i++){
		if (tab[i] == 100000){
			tab[i] = liczba;
			break;
		}
	}
                 }

void zamiana(int a, int tab[100]){
     int i=0;
     while(a){
              tab[i]=a%2;
              a = a/2;
              i++;
              }            
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
void lucas(int n, int k, int dzielnik[100]){
	printf("\n\nTest Lucasa:\n");
	int j=0,i=0,s=1;
	for(j=1;j<k;j++){
		for(i=0;i<k-1;i++){
			if(dzielnik[j]==dzielnik[j-1]){
				dzielnik[j]=dzielnik[j+1];
			}
		}
	}
	printf("\nLiczby pierwsze:");
	i=0;
	while(dzielnik[i]!=100000){
	                    printf("\t%i",dzielnik[i]);
	                    i++;
	                    }
	int licznik=n-1;
	srand(time(NULL));
	int b=(rand()%(licznik-2))+2;
	int warunek=0;
	printf("\n\nRand\t%i\n",b);
	long long int wynik=potegowanie(b,licznik,n);
	printf("\nWarunek pierwszy\t%i\n",wynik);
	int tab[k];
	if(wynik==1){
		printf("\nWarunek drugi");
		for(j=0;j<i;j++){
			tab[j]=potegowanie(b,licznik/dzielnik[j],n);
			printf("\t%i",tab[j]);
			if(tab[j]==1){
                          warunek++;
                          }
			
		}
	if (warunek>0)
	{
                   printf("\n\nTest nierozstrzygniety");
                   }
                   else
                   {
                       printf("\n\nLiczba jest pierwsza");
                       }
                       
	}
	else{
		printf("\nLiczba nie jest pierwsza");
	}
}
int main(int argc, char *argv[])
{
  int liczba=0;
  int dzielnik[100];
  int k=0;
	for(k=0;k<10;k++){
                    dzielnik[k]=100000;
                    }
  int z=0;
  printf("Podaj liczbe:\t");
  scanf("%i",&liczba);
  int n=liczba+1;
  printf("\nRozklad Fermata:\t");
  while(liczba%2==0&&liczba!=1){
                     liczba/=2;
                     dzielnik[z]=2;
                     z++;
                     }
if(liczba!=1){
	Fermat(liczba, dzielnik, z);
	}
	
   k=0;
  while(dzielnik[k]!=100000){
                    printf("%i\t",dzielnik[k]);
                    k++;
                    }
int i=0,j=0,bufor=0;
  for(i=2;i<k;i++){
                   for(j=k;j>=i;j--){
                                    if (dzielnik[j-1]>dzielnik[j]){
                                                       bufor=dzielnik[j-1];
                                                       dzielnik[j-1]=dzielnik[j];
                                                       dzielnik[j]=bufor;
                                                       }
                                                       }
                         }
 k=0;
 printf("\nMirek\n");
  while(dzielnik[k]!=100000){
                    printf("%i\t",dzielnik[k]);
                    k++;
                    }
//test lucasa
lucas(n,k,dzielnik);
printf("\n\n");
  system("PAUSE");	
  return 0;
}
