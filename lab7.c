#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

int pierwotny(int p){
	int n=p-1;
	int dzielnik[100];
	int k=0;
	for(k=0;k<100;k++){
                    dzielnik[k]=100000;
                    }
	int z=0;
	while(n%2==0&&n!=1){
                     n/=2;
                     dzielnik[z]=2;
                     z++;
                     }
	if(n!=1){
		Fermat(n, dzielnik, z);
	}
	
	k=0;
	while(dzielnik[k]!=100000){
                    //printf("%i\t",dzielnik[k]);
                    k++;
                    }
    int tab[k];
    int i=0, warunek, r;
    do{
    	warunek=0;
	    //srand(time(NULL));
		r=(rand()%(p-4))+2;
		//printf("\n%i\n",r);
		for(i=0;i<k;i++){
			tab[i]=potegowanie(r,n/dzielnik[i],p);
				//printf("%i\t",tab[i]);
				if(tab[i]==1){
	                          warunek++;
	                          }
				
			}
	}while(warunek>0);
	return r;
}
void Elgamal(){
	printf("ElGamal:\n");
	int p;
	printf("Podaj liczbe pierwsza:\t");
	scanf("%i",&p);
	int r=pierwotny(p);
	printf("Klucz tajny r:\t%i\n",r);
	//srand(time(NULL));
	int k=(rand()%(p-3))+2;
	printf("Klucz tajny k:\t%i\n",k);
	int a=potegowanie(r,k,p);
	printf("Klucz publiczny(p,r,a):\t(%i,%i,%i)\n",p,r,a);
	int b;
	printf("Podaj wiadomosc b:\t");
	scanf("%i",&b);
	//srand(time(NULL));
	int j=(rand()%(p-4))+2;
	printf("Klucz tajny j:\t%i\n",j);
	long long int c2;
	c2=(b*potegowanie(a,j,p))%p;
	long long int c1;
	c1=potegowanie(r,j,p);
	printf("Wiadomosc zaszyfrowana(C1,C2):\t(%lli,%lli)\n",c1,c2);
	long long int t=potegowanie(c1,p-1-k,p);
	printf("Liczba t:\t%lli\n",t);
	long long int tekst=(c2*t)%p;
	printf("Liczba odszyfrowana:\t%lli\n",tekst);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
	Elgamal();
	printf("\n\n");
	system("pause");
	return 0;
}
