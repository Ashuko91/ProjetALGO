#include <stdio.h>
#include <stdlib.h>
//#include "piles.c"
#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
#define then

typedef enum { FALSE, TRUE} bool;

typedef struct Bloc
{
    int nombre;
    struct Bloc *suivant;
} Bloc;

typedef Bloc *Liste ;

void initVide( Liste *L)
{
    *L = NULL ;
}

bool estVide(Liste l)
{
    return l == NULL ;
}

int premier(Liste l)
{
    return l->nombre ; 
}

Liste ajoute(int x, Liste l)
{
    Liste tmp = (Liste) malloc(sizeof(Bloc)) ;
    tmp->nombre = x ;
    tmp->suivant = l ;
    return tmp ;
}

void empile(int x, Liste *L)
{
      *L = ajoute(x,*L) ; 
}

Liste suite(Liste l)
{
    return l->suivant ;
}


void depile(Liste *L)
{
    Liste tmp = *L ;
    *L = suite(*L) ;
    free(tmp) ;
}

void affiche_rec(Liste l)
{
    if(estVide(l))
        printf("\n");
    else
    {
        printf("%d ", premier(l));
        affiche_rec(suite(l));
    }
}


void affiche_iter(Liste l)
{
    Liste L2 = l;
    while(!estVide(L2))
    {
        printf("%d ", premier(L2));
        L2 = suite(L2);
    }
    printf("\n");
}

int longueur_rec (Liste l)
{
    if (l == NULL)
         return 0 ;
    else return (1 + longueur_rec(l->suivant)) ;
}


int longueur_iter (Liste l)
{
    Liste P = l;
    int cpt = 0 ;
    while (P ISNOT NULL)
    {   P = P->suivant ;
        cpt++ ;
    }
    return cpt ;
}

void VD (Liste *L)
          // *L non NULL ie liste non vide
{
     if ( ((**L).suivant) == NULL )
            depile(L) ;   // moralement : depile(& (*L)) ;
     else VD (& ( (**L).suivant )) ;
}

void VireDernier_rec (Liste *L)
{
     if ( (*L) ISNOT NULL )
          VD(L);        // moralement : VD(& (*L)) ;
}

void VireDernier_iter (Liste *L)
{
    if ( (*L) ISNOT NULL)
    {
        while ( ((**L).suivant) ISNOT NULL )
                 L = & ( (**L).suivant ) ;
        free(*L) ;
        *L = NULL ;
     }
}

void VideListe(Liste *L)
{
    if(NOT(estVide(*L)))
    {
        depile(L);
        VideListe(L);
    }
      
}
// Question 1
bool ZeroEnPositionUnOuDeuxOuTrois(Liste l){
    int i = 0;
    if (estVide(l)){
        return FALSE;
    } else {
        while (i < 3) {
            if (premier(l)==0){
                return TRUE;
            }
            l = suite(l);
            if (estVide(l)){
                return FALSE;
            }
            i++;
        } 
        return FALSE; 
    } 
}

// Question 2
bool Pluscourte(Liste l1, Liste l2){
    while (longueur_iter(l1) >= 0) {
        if (estVide(l1) && l1 ISNOT l2){
            return TRUE;
        } else if (estVide(l2)){
            return FALSE;
        }
        l1 = suite(l1);
        l2 = suite(l2);
        
    } 
}

// Question 3
// Version Iterative
int NombreDeZeroAvantPositionK_1(Liste l, int k){
    int res = 0;
    int i = 1;
    if (estVide(l)){
        return res;
    } else {
        while (i <= k) {
            if (premier(l)==0){
                res++;
            }
            l = suite(l);
            i++;
        }
    }
    return res;
}

// Version Recursive
int NombreDeZeroAvantPositionK_2(Liste l, int k){
    if (estVide(l)){
        return 0;
    } else { 
        if (k > 0){
        if (premier(l)==0){
            return 1 + NombreDeZeroAvantPositionK_2(suite(l),k-1); 
        } else {
            return NombreDeZeroAvantPositionK_2(suite(l),k-1);
        }
        }
    }
}

// Version avec sous fonction recursive terminale : ELLE NE DONNE PAS LE BON RESULTAT
int NZAPK_aux_1(Liste l, int k, int res){
    if (estVide(l)){
        return res;
    } else if(k > 0){
        if (premier(l)==0) {
            return NZAPK_aux_1(suite(l), k-1, res + 1);
        } else {
            return NZAPK_aux_1(suite(l), k-1, res);
            } 
        }
    
}

int NombreDeZeroAvantPositionK_3(Liste l, int k){
    return NZAPK_aux_1(l, k, 0);
}

// Version avec sous procedure recursive terminale
int NZAPK_aux_2(Liste l, int k, int *res){
    if (estVide(l)){
        /*ne fais rien*/
    } else {
        if(k > 0){
            if (premier(l)==0){
               *res = *res + 1;
               NZAPK_aux_2(suite(l), k-1, res); 
            } else {
                NZAPK_aux_2(suite(l), k-1, res);
            }
        }
    }
}

int NombreDeZeroAvantPositionK_4(Liste l, int k){
    int res = 0;
    NZAPK_aux_2(l,k,&res);
    return res;
}

// Question 4 : NE MARCHE PAS
int NZARPK_aux(Liste l, int k, int *res){
    if (estVide(l)){
        return *res;
    } else {
        if (k > 0){
        NZARPK_aux(suite(l), k-1, res);
        if (premier(l)==0){
            *res = *res + 1;
        }
        }
    }
}

int NombreDeZeroApresRetroPositionK(Liste l, int k){
    int res = 0;
    NZARPK_aux(l, k, &res);
    return res;
}

// Question 5 : NE RENVOIE PAS LA LISTE DEMANDEE PAR L'ENONCEE
Liste FctBegaye(Liste l){
    Liste a;
    if (estVide(l)){
        return a;
    } else {
        if(premier(l) > 0){
            a = ajoute(premier(l), a);
            a = ajoute(premier(l), a);
            return FctBegaye(suite(l));
        } else {
            return FctBegaye(suite(l));
        }
    }
    
}


int main(int argc, char const *argv[]){
    Liste l1 ;
    initVide (&l1) ;
    empile(1, &l1) ;
    empile(5, &l1) ;
    empile(0, &l1) ;
    empile(2, &l1) ;
    empile(0, &l1) ;
    empile(0, &l1) ;
    printf("Liste l1 : ");
    affiche_iter(l1);
    Liste l2;
    initVide (&l2) ;
    empile(1, &l2) ;
    empile(7, &l2) ;
    empile(5, &l2) ;
    empile(9, &l2) ;
    empile(8, &l2) ;
    empile(6, &l2) ;
    empile(7, &l2) ;
    printf("Liste l2 : ");
    affiche_iter(l2);
    printf("ZPUDT : %d\n", ZeroEnPositionUnOuDeuxOuTrois(l1));
    printf("Pluscourte : %d\n", Pluscourte(l1,l2));
    printf("NZAPK 1 : %d\n", NombreDeZeroAvantPositionK_1(l1,3));
    printf("NZAPK 2 : %d\n", NombreDeZeroAvantPositionK_2(l1,3));
    printf("NZAPK 3 : %d\n", NombreDeZeroAvantPositionK_3(l1,3)); // Cette version ne donne pas le bon resultat        
    printf("NZAPK 4 : %d\n", NombreDeZeroAvantPositionK_4(l1,3));        
    printf("NZARPK : %d\n", NombreDeZeroApresRetroPositionK(l1,2)); // Cette fonction ne marche pas
    
    affiche_rec(FctBegaye(l1)); // Cette fonction renvoie une liste avec chaque element doubler mais la liste est inversee   
    return 0;
}
