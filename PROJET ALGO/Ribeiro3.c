#include <stdio.h>
#include <stdlib.h>
#define ISNOT !=
#define NOT !
#define AND &&
#define OR ||
#define then
typedef enum { false, true } bool;
typedef struct bloc_image
{ bool toutnoir ;
struct bloc_image * fils[4] ;
} bloc_image ;
typedef bloc_image *image ;

// Question 1.1
image Construit_Blanc(){
    image i;
    i = NULL;
    return i;
}

// Question 1.2
image Construit_Noir(){
    image in = (image) malloc(sizeof(bloc_image));
    in->toutnoir = true;
    in->fils[0] = NULL;
    in->fils[1] = NULL;
    in->fils[2] = NULL;
    in->fils[3] = NULL;
    return in;
}

// Question 1.3
image Construit_Composee(image i0, image i1, image i2, image i3){
    image ic = (image) malloc(sizeof(bloc_image));
    ic->toutnoir = false;
    ic->fils[0] = i0;
    ic->fils[1] = i1;
    ic->fils[2] = i2;
    ic->fils[3] = i3;
    return ic;
}

// Question 2.1
void Affiche_Normal(image i){
    if(i == NULL){
        printf("B");
    } else if(i->toutnoir){
        printf("N");
    } else if(NOT (i->toutnoir)){
        printf("(");
        Affiche_Normal(i->fils[0]);
        Affiche_Normal(i->fils[1]);
        Affiche_Normal(i->fils[2]);
        Affiche_Normal(i->fils[3]);
        printf(")");
    }
   
}

// Question 2.2
void Affiche_Profondeur(image i, int p){
    if(i == NULL){
        printf("B%d", p);
    } else if(i->toutnoir){
        printf("N%d", p);
    } else if(NOT (i->toutnoir)){
        printf("(");
        Affiche_Profondeur(i->fils[0], p+1);
        Affiche_Profondeur(i->fils[1], p+1);
        Affiche_Profondeur(i->fils[2], p+1);
        Affiche_Profondeur(i->fils[3], p+1);
        printf(")");
    }
}    
// Question 4.1
bool EstBlanche(image i){
    if(i == NULL){
        return true;
    } else if(i->toutnoir == true){
        return false;
    } else {
        return EstBlanche(i->fils[0]) && EstBlanche(i->fils[1]) && EstBlanche(i->fils[2]) && EstBlanche(i->fils[3]);
    }
}

// Question 4.2
bool EstNoir(image i){
    if(i == NULL){
        return false;
    } else if(i->toutnoir == true){
        return true;
    } else {
        return EstNoir(i->fils[0]) && EstNoir(i->fils[1]) && EstNoir(i->fils[2]) && EstNoir(i->fils[3]);
    }
}

// Question 5
image Diagonale(int p){
    image i = (image) malloc(sizeof(bloc_image));
    if(p ==  0){
        i = Construit_Noir();
    } else if(p == 1){
           i = Construit_Composee(Construit_Noir(), Construit_Blanc(), Construit_Blanc(), Construit_Noir()); 
    } else {
           i = Construit_Composee(Diagonale(p - 1), Construit_Blanc(), Construit_Blanc(), Diagonale(p - 1));    
    }
    return i;
}

// Question 6
image QuartDeTour(image i){
    if(i == NULL || i->toutnoir){
        return i;
    } else {
        image a = i->fils[0];
        image b = i->fils[1];
        image c = i->fils[2];
        image d = i->fils[3];

        i->fils[0] = c;
        i->fils[1] = a;
        i->fils[2] = d;
        i->fils[3] = b;

        QuartDeTour(i->fils[0]);
        QuartDeTour(i->fils[1]);
        QuartDeTour(i->fils[2]);
        QuartDeTour(i->fils[3]);
    }
    return i;
}

// Question 7  NE MARCHE PAS
image Negatif(image i){
    if(i == NULL){
        i->toutnoir = true;
        i->fils[0] = NULL;
        i->fils[1] = NULL;
        i->fils[2] = NULL;
        i->fils[3] = NULL;
    } else if(i->toutnoir){
        i = NULL;
    } else {
        Negatif(i->fils[0]);
        Negatif(i->fils[1]);
        Negatif(i->fils[2]);
        Negatif(i->fils[3]);
    }
}

// Question 8   PAS FINI
image SimplifieProfP(image i, int p){
    if(p >= 0){
        if(i == NULL || i->toutnoir){
            /* ne rien faire */
        } else if(i == Construit_Composee(Construit_Blanc(), Construit_Blanc(), Construit_Blanc(), Construit_Blanc())){
            i = NULL;
        } else if(i == Construit_Composee(Construit_Noir(), Construit_Noir(), Construit_Noir(), Construit_Noir())){
            i->toutnoir = true;
            i->fils[0] = NULL;
            i->fils[1] = NULL;
            i->fils[2] = NULL;
            i->fils[3] = NULL;
        } else {
            SimplifieProfP(i->fils[0], p - 1);
            SimplifieProfP(i->fils[1], p - 1);
            SimplifieProfP(i->fils[2], p - 1);
            SimplifieProfP(i->fils[3], p - 1);
        }
    }
}
int main(int argc, char const *argv[])
{
    image B = Construit_Blanc();
    printf("Affichage Normale d'une image blanche : ");
    Affiche_Normal(B);
    printf("\n");
    printf("Affichage Profondeur d'une image blanche : ");
    Affiche_Profondeur(B,0);
    printf("\n");

    image N = Construit_Noir();
    printf("Affichage Normale d'une image noire : ");
    Affiche_Normal(N);
    printf("\n");
    printf("Affichage Profondeur d'une image noire : ");
    Affiche_Profondeur(N,0);
    printf("\n");

    image c1 = Construit_Composee(B,N,N,B);
    printf("Affichage Normale d'une image composee mixte : ");
    Affiche_Normal(c1);
    printf("\n");
    printf("Affichage Profondeur d'une image composee mixte : ");
    Affiche_Profondeur(c1,0);
    printf("\n");

    image c2 = Construit_Composee(B,B,B,B);
    printf("Affichage Normale d'une image composee blanche : ");
    Affiche_Normal(c2);
    printf("\n");
    printf("Affichage Profondeur d'une image composee blanche : ");
    Affiche_Profondeur(c2,0);
    printf("\n");

    image c3 = Construit_Composee(N,N,N,N);
    printf("Affichage Normale d'une image composee noire : ");
    Affiche_Normal(c3);
    printf("\n");
    printf("Affichage Profondeur d'une image composee noire : ");
    Affiche_Profondeur(c3,0);
    printf("\n");

    printf("EstBlanche avec image composee mixte : %d \n",EstBlanche(c1));
    printf("EstNoir avec image composee mixte : %d \n",EstNoir(c1));
    printf("EstBlanche avec image composee blanche : %d \n",EstBlanche(c2));
    printf("EstNoir avec image composee blanche : %d \n",EstNoir(c2));
    printf("EstBlanche avec image composee noir : %d \n",EstBlanche(c3));
    printf("EstNoir avec image composee noir : %d \n",EstNoir(c3));

    printf("Diagonale avec p = 3 : ");
    Affiche_Normal(Diagonale(3));
    printf("\n");

    image c4 = Construit_Composee(Construit_Composee(B,N,N,N), B, Construit_Composee(N,N,B,B), N);
    printf("QuartDeTour : ");
    Affiche_Normal(QuartDeTour(c4));
    printf("\n");

    //Negatif(B);
    //Affiche_Normal(B);
    //SimplifieProfP(c2, 1);
    //Affiche_Normal(c2);
    return 0;
}
