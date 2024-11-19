#include <stdio.h>
#include <stdlib.h>
#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||
#define then
typedef enum { false, true } bool;

// Question 1

float UnSurFactorielle(int n){
    float fact = 1;
    float res = 1;
    for (int i = 1; i <= n; i++){ 
        fact = fact * i;
        res = res + (1/fact);
    }
    return res;
  
}

// Question 2

void SuiteDeE(int n){
    double res = 0;
    res = UnSurFactorielle(0) - 1;
    printf("n = 0, terme = %f\n", res);
   
    for (int i = 1; i <=n ; i++){
        res = i*UnSurFactorielle(i-1) - 1;
        printf("n = %d, terme = %f\n", i, res);
    }
    
            
}
    
// Question 3 

// Version 1 RECURSIVE SIMPLE
int power1(int x, int n){
    if (n==0){
        return 1;
    } else {
        return power1(x, n-1) * x;
    }
}

// Version 1a RECURSIVE SIMPLE AVEC N NEGATIFS
double power1a(double x, int n){ 
   if (n==0){
        return 1;
    } else if (n>0){
        return power1a(x,n-1) * x;
    } else if (x==0){
        printf("Erreur : 0^(-n) impossible\n");
    } else {
        return 1/(power1a(x,(-n-1)) * x);
    }
}

// Version 2 ITERARTIVE SIMPLE 
int power2(int x, int n){
    int res = 1;
    while (n > 0){
        res = res * x;
        n--;
    }
    return res;
}

// Version 2a ITERATIVE SIMPLE AVEC N NEGATIFS (CA COMPILE MAIS ELLE NE DONNE PAS LE BON RESULTAT A L'EXECUTION)
float power2a(int x, int n){ 
    float r = 1;
    if (n==0) {
        return r;
    } else if (n > 0){
        while (n > 0){
        r = r * x;
        n--;
        }
        return r;
    }

    if (x==0 && n < 0){
        printf("Erreur : 0^(-n) impossible\n");
    } else {
        while(n < 0){
            r = 2;
            n = -n - 1;
        }
        return r;
    }
      
}

// Version 3 RECURSIVE TERMINALE AVEC SOUS-PROCEDURE
void power3_aux(int x, int n, int * r){
    if (!(n==0)) {
        * r =  * r * x;
        power3_aux( x, n-1, r); 
    } 
}

int power3(int x, int n){ 
    int r = 1;
    power3_aux(x, n, &r);
    return r;
}

// Version 4 RECURSIVE TERMINALE AVEC SOUS-FONCTION
int power4_aux(int x, int n, int r){
    if (n==0){
        return r;
    } else {
        return power4_aux(x, n-1, r*x);
    }
}

int power4(int x, int n){ 
    return power4_aux(x, n, 1);
}

// Version 5 RECURSIF SIMPLE PAR N/2 BOURDE
int power5(int x, int n){
    if(n==0){
        return 1;
    } else {
        if (n%2==0){
            return power5(x, n/2) * power5(x, n/2);
        } else {
            return power5(x, n/2) * power5(x, n/2) * x;
        }
    }
}

// Version 6 RECURSIF SIMPLE PAR N/2
int power6(int x, int n){
    int y;
    if (n==0){
        return 1;
    } else {
        y = power6(x, n/2);
        if (n%2==0){
            return y * y;
        } else {
            return y * y * x;
        }
    }
}

// Version 7 RECURSIF SIMPLE PAR N/2 VARIANTE
int power7(int x, int n){
    if (n==0){
        return 1;
    } else {
        if (n%2==0){
            return power7(x*x,n/2);
        } else {
            return power7(x*x,n/2) * x;
        }
    }
}

// Version 8 RECURSIF SIMPLE PAR N/2, AVEC SOUS-FONCTION
int pow_aux8(int x, int n, int r){
    if (n==0){
        return r;
    } else {
        if (n%2==0){
            return pow_aux8(x*x, n/2, r);
        } else {
            return pow_aux8(x*x, n/2, r*x);
        }
    }
}

int power8(int x, int n){
    return pow_aux8(x, n, 1);
}

// Version 9 RECURSIF SIMPLE, PAR N/2, AVEC SOUS-PROCEDURE
int pow_aux9(int x, int n, int * r){
    if (n==0){

    } else {
        if (NOT(n%2==0)) {
            * r =  * r * x;
            pow_aux9(x*x, n/2, r);
        }
    }
}

int power9(int x, int n){
    int r = 1;
    pow_aux9(x, n, &r);
    return r;
}

// Version 10 ITERATIF, PAR N/2
int power10(int x, int n){
    int r = 1;
    while (n ISNOT 0){
        if (NOT(n%2==0)){
            r = r * x;
            n = n/2;
            x = x * x;
        }
    }
    return r;
    
}

// VERSION DES POWER EN TYPE DOUBLE POUR LES PUISSANCE DE 10
double power1_d(double x, int n){
    if (n==0){
        return 1;
    } else {
        return power1_d(x, n-1) * x;
    }
}

double power2_d(double x, int n){
    double res = 1.0;
    while (n > 0){
        res = res * x;
        n--;
    }
    return res;
}

double power3_aux_d(double x, int n, double * r){
    if (!(n==0)) {
        * r =  * r * x;
        power3_aux_d( x, n-1, r); 
    } 
}

double power3_d(double x, int n){ 
    double r = 1;
    power3_aux_d(x, n, &r);
    return r;
}

double power4_aux_d(double x, int n, double r){
    if (n==0){
        return r;
    } else {
        return power4_aux_d(x, n-1, r*x);
    }
}

double power4_d(double x, int n){ 
    return power4_aux_d(x, n, 1);
}

double power5_d(double x, int n){
    if(n==0){
        return 1;
    } else {
        if (n%2==0){
            return power5_d(x, n/2) * power5_d(x, n/2);
        } else {
            return power5_d(x, n/2) * power5_d(x, n/2) * x;
        }
    }
}

double power6_d(double x, int n){
    double y;
    if (n==0){
        return 1;
    } else {
        y = power6_d(x, n/2);
        if (n%2==0){
            return y * y;
        } else {
            return y * y * x;
        }
    }
}

double power7_d(double x, int n){
    if (n==0){
        return 1;
    } else {
        if (n%2==0){
            return power7_d(x*x,n/2);
        } else {
            return power7_d(x*x,n/2) * x;
        }
    }
}

double pow_aux8_d(double x, int n, double r){
    if (n==0){
        return r;
    } else {
        if (n%2==0){
            return pow_aux8_d(x*x, n/2, r);
        } else {
            return pow_aux8_d(x*x, n/2, r*x);
        }
    }
}

double power8_d(double x, int n){
    return pow_aux8_d(x, n, 1);
}

double pow_aux9_d(double x, int n, double * r){
    if (n==0){

    } else {
        if (NOT(n%2==0)) {
            * r =  * r * x;
            pow_aux9_d(x*x, n/2, r);
        }
    }
}

double power9_d(double x, int n){
    double r = 1;
    pow_aux9_d(x, n, &r);
    return r;
}

double power10_d(double x, int n){
    double r = 1;
    while (n ISNOT 0){
        if (NOT(n%2==0)){
            r = r * x;
            n = n/2;
            x = x * x;
        }
    }
    return r;
    
}

// Fonction (1+(1/N))^N qui utilisent les differentes versions de power pour les puissances de 10 
double PuissancesDe10_1(int n){
    return power1_d((1+(1/(power1_d(10,n)))),power1_d(10,n));
}

double PuissancesDe10_2(int n){
    return power2_d((1+(1/(power2_d(10,n)))),power2_d(10,n));
}

double PuissancesDe10_3(int n){
    return power3_d((1+(1/(power3_d(10,n)))),power3_d(10,n));
}

double PuissancesDe10_4(int n){
    return power4_d((1+(1/(power4_d(10,n)))),power4_d(10,n));
}

double PuissancesDe10_5(int n){
    return power5_d((1+(1/(power5_d(10,n)))),power5_d(10,n));
}

double PuissancesDe10_6(int n){
    return power6_d((1+(1/(power6_d(10,n)))),power6_d(10,n));
}

double PuissancesDe10_7(int n){
    return power7_d((1+(1/(power7_d(10,n)))),power7_d(10,n));
}

double PuissancesDe10_8(int n){
    return power8_d((1+(1/(power8_d(10,n)))),power8_d(10,n));
}

double PuissancesDe10_9(int n){
    return power9_d((1+(1/(power9_d(10,n)))),power9_d(10,n));
}

double PuissancesDe10_10(int n){
    return power10_d((1+(1/(power10_d(10,n)))),power10_d(10,n));
}

// Question 4 : Fonction d'Ackerman
// Version recursive
int Ackerman(int m, int n){
    if (m==0){
        return n + 1;
    } else {
        if (n==0){
        return Ackerman(m-1,1);
    } else {
        return Ackerman(m-1, Ackerman(m, n-1));
    }
    }
}

// Version recurso-iterative
int Ackerman2(int m, int n) {
    if (m==0){
        return n + 1;
    } else {
        int r = 1;
        for(int i = 1; i <= (n+1); i++){
            r = Ackerman2(m-1,r);
            }
        return r;
    }
}

// Question 5
// Version Iterative
float X1(int n){
    float res = 1;
    //printf("n = 0, terme = %f\n", res);
    for (int i = 1; i <= n; i++){
        res = res + (2/res);
        //printf("n = %d, terme = %f\n", i, res);
    }
    return res;
}

// Version recursive 
float X2(int n){
    if (n==0){
        return 1;
    } else {
        return X2(n-1) + (2/X2(n-1));
    }
}

// Version recursive avec sous-fonction
float X3_aux(int n, float res){
    if (n==0){
        return res;
    } else {
        return X3_aux(n-1, res) + (2/(X3_aux(n-1, res))); 
    }
}

float X3(int n){
    return X3_aux(n, 1.0);
}

// Version recursive avec sous-procedure 
float X4_aux(int n, float * res){
    if (n==0){
        /*rien*/
    } else {
        * res = * res + (2/ * res);
        X4_aux(n-1,res);
    }
    
}

float X4(int n){
    float res = 1;
    X4_aux(n, &res);
    return res;
}

int main(int argc, char const *argv[])
{   

    // Test Question 1
    printf("UnSurFactorielle pour n = 9 : %lf\n", UnSurFactorielle(9)); // Je m'arretes a n = 9 car au-dela le resultat ne change pas

    // Test Question 2
    printf("Affichage des 50 premiers termes :\n");
    SuiteDeE(50);

    // Test Question 3
    
    printf("power1 pour 2^3 : %d\n", power1(2,3));
    printf("power2 pour 2^3 : %d\n", power2(2,3));
    //printf("power1a pour 2^3 : %d\n", power1a(2,(-1)));  // Ne fonctionne pas
    //printf("power2a pour 2^3 : %d\n", power2a(0,(-1)));  // Ne fonctionne pas
    printf("power3 pour 2^3 : %d\n", power3(2,3)); 
    printf("power4 pour 2^3 : %d\n", power4(2,3));
    printf("power5 pour 2^3 : %d\n", power5(2,3));
    printf("power6 pour 2^3 : %d\n", power6(2,3));
    printf("power7 pour 2^3 : %d\n", power7(2,3));
    printf("power8 pour 2^3 : %d\n", power8(2,3));
    printf("power9 pour 2^3 : %d\n", power9(2,3));
    printf("power10 pour 2^3 : %d\n", power10(2,3));
    

   // Test des Fonctions power avec des puissance de 10
    
    printf("Puissance de 10 avec power1 : N = %d, resultat = %lf\n", 4, PuissancesDe10_1(4)); // A partir de N = 10^5, la fonction stope et ne renvoie rien
    printf("Puissance de 10 avec power2 : N = %d, resultat = %lf\n", 4, PuissancesDe10_2(4));
    printf("Puissance de 10 avec power3 : N = %d, resultat = %lf\n", 4, PuissancesDe10_3(4)); // A partir de N = 10^5, la fonction stope et ne renvoie rien
    printf("Puissance de 10 avec power4 : N = %d, resultat = %lf\n", 4, PuissancesDe10_4(4)); // A partir de N = 10^5, la fonction stope et ne renvoie rien
    printf("Puissance de 10 avec power5 : N = %d, resultat = %lf\n", 4, PuissancesDe10_5(4)); // A partir de N = 10^10, la fonction rame et renvoie un resultat bizarre
    printf("Puissance de 10 avec power6 : N = %d, resultat = %lf\n", 4, PuissancesDe10_6(4)); // A partir de N = 10^10, la fonction rame et renvoie un resultat bizarre
    printf("Puissance de 10 avec power7 : N = %d, resultat = %lf\n", 4, PuissancesDe10_7(4)); // A partir de N = 10^10, la fonction rame et renvoie un resultat bizarre
    printf("Puissance de 10 avec power8 : N = %d, resultat = %lf\n", 4, PuissancesDe10_8(4)); // A partir de N = 10^10, la fonction rame et renvoie un resultat bizarre
    printf("Puissance de 10 avec power9 : N = %d, resultat = %lf\n", 4, PuissancesDe10_9(4));
    //printf("Puissance de 10 : n = %d, resultat = %lf\n", 4, PuissancesDe10_10(4)); // Tourne a l'infini pour n'importe quelle valeur

     // Test avec Ackerman1
     
    printf("Ackerman1 pour A(%d,%d) =    %d\n", 0, 0, Ackerman(0,0));
    printf("Ackerman1 pour A(%d,%d) =    %d\n", 1, 0, Ackerman(1,0));
    printf("Ackerman1 pour A(%d,%d) =    %d\n", 2, 0, Ackerman(2,0));
    printf("Ackerman1 pour A(%d,%d) =    %d\n", 3, 0, Ackerman(3,0));
    printf("Ackerman1 pour A(%d,%d) =    %d\n", 4, 0, Ackerman(4,0)); 
    //printf("Ackerman1 pour A(%d,%d) =    %d\n", 5, 0, Ackerman(5,0)); // Elle rame sur ma machine
    //printf("Ackerman1 pour A(%d,%d) =    %d\n", 6, 0, Ackerman(6,0)); // Pour A(6,0), la fonction tourne sans donner de resultat
    

     // Test avec Ackerman2
     
    printf("Ackerman2 pour A(%d,%d) = %d\n", 0, 0, Ackerman2(0,0));
    printf("Ackerman2 pour A(%d,%d) = %d\n", 1, 0, Ackerman2(1,0));
    printf("Ackerman2 pour A(%d,%d) = %d\n", 2, 0, Ackerman2(2,0));
    printf("Ackerman2 pour A(%d,%d) = %d\n", 3, 0, Ackerman2(3,0));
    printf("Ackerman2 pour A(%d,%d) = %d\n", 4, 0, Ackerman2(4,0));
    printf("Ackerman2 pour A(%d,%d) = %d\n", 5, 0, Ackerman2(5,0));
    //printf("Ackerman2 pour A(%d,%d) = %d\n", 6, 0, Ackerman2(6,0)); // Pour A(6,0), la fonction tourne sans donner de resultat
    

   // Test Question 5 
   printf("X1 pour n = %d, terme = %f\n", 100, X1(100)); // Elle calcule bien X(100)
   printf("X2 pour n = %d, terme = %f\n", 30, X2(30)); // A partir de X(35), la fonction rame 
   printf("X3 pour n = %d, terme = %lf\n", 30, X3(30)); // A partir de X(35), la fonction rame 
   printf("X4 pour n = %d, terme = %lf\n", 100, X4(100)); // Elle calcule bien X(100)
    return 0;
}
