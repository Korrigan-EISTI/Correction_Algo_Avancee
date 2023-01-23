#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int len = 0;

/* EXERCICE 1 */

int min(int Tab[]){
    int min = Tab[0];
    for (int i = 0; i<len; i++){
        if (Tab[i]<min){
            min = Tab[i];
        }
    }
    return min;
}

int max(int Tab[]){
    int max = Tab[0];
    for (int i = 0; i<len; i++){
        if (Tab[i]>max){
            max = Tab[i];
        }
    }
    return max;
}

void MinMax (){
    puts ("Entrer la taille du tableau");
    scanf ("%d", &len);
    srand(time(NULL));
    int Tab[len];
    for (int i = 0; i<len; i++){
        Tab[i] = rand()%100;
        printf("%d\n", Tab[i]);
    }
    printf ("Le minimum du tableau est %d et le maximum est %d", min(Tab), max(Tab));
}

/* EXERCICE 2 */

void Devinette (){
    srand(time(NULL));
    int nombre = rand()%101;
    int compt = 0;
    int guess;
    do{
        puts("Essayez de deviner le nombre");
        scanf("%d", &guess);
        compt++;
    }while (guess!=nombre);
    printf("Bravo, vous avez reussi en %d coups", compt);
}

/* EXERCICE 3 */

void chaine (char* path, char* mot){
    FILE* fp = fopen(path, "r");
    char c;
    char str[500];
    int compt = 0;
    if (fp == NULL){
        puts("ERREUR OUVERTURE FICHIER");
        exit(0);
    }
    while(fread(&c, sizeof(char), 1, fp) != NULL){
        if (c != ' '){
            switch (c){
            case ',':
                break;
            case '.':
                break;
            case ';':
                break;
            case '!':
                break;
            case ':':
                break;
            case '?':
                break;
            default:
                strncat (str, &c, 1);
                break;
            }
        }else{
            if (strcmp(str, mot) == 0){
                compt++;
                printf("Occurence du mot en position : %d \n", compt);
            }
            strcpy(str, "");
        }
    }
}

/* EXERCICE 4 */

int puissance (int a, int b){
    int p = 1;
    for (int i = 0; i<b; i++){
        p = p*a;
    }
    return p;
}


void polynome (int point){
    int n;
    puts ("Entrer le degre du polynome");
    scanf ("%d", &n);
    int coeff;
    int res = 0;
    for (int i = 0; i<=n; i++){
        printf ("Entrer le coefficient pour x^%d ", i);
        scanf("%d", &coeff);
        res = res + (coeff*puissance(point, i));
    }
    printf("La valeur en %d du polynome est %d", point, res);
}

/* EXERCICE 5 */

/* Fonction qui calcule une factorielle */

void factorielle (){
    int nb = 0;
    int prod = 1;
    puts ("Entrer un nombre : ");
    scanf ("%d", &nb);
    for (int i = 1; i <= nb; i++){ // On boucle pour calculer la factorielle
        prod = prod * i;
    }
    printf ("La factorielle de %d est %d", nb, prod); // On affiche la factorielle
}

/* Fonction qui donne le PGCD de deux nombres */

void pgcd (){
    int nbr1, nbr2, pgcd, i;
  
    printf("Entrez deux entiers: ");
    scanf("%d", &nbr1);
    scanf("%d", &nbr2);
  
    for(i=1; i <= nbr1 && i <= nbr2; i++) // On s'arrête quand un des deux nombres est atteint
    {
        if(nbr1%i==0 && nbr2%i==0) // Si les deux nombres sont divisibles par i
            pgcd = i; // i devient le nouveau PGCD
    }
  
    printf("PGCD de %d et %d = %d", nbr1, nbr2, pgcd); // On affiche le PGCD
}

/* Fonction qui calcule le determinant d'une équation du second degré */

int delt (int a, int b, int c){
    return ((b*b) - (4*a*c));
}

/* Fonction qui résoud une équation du second degré */

void second_deg (){
    int a, b, c;
    // On entre les coefficients a pour X^2, b pour X et c tout seul
    puts ("Entrer les coefficient a, b et c");
    scanf ("%d %d %d", &a, &b, &c);
    int delta = delt(a, b, c); // On calcule le determinant
    if (delta > 0){ // Si le déterminant est positif on a deux solutions réelles
        puts ("Deux solutions relles");
        printf ("x1 = %f et x2=%f", (-b + sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a)); // On affiche les deux solutions réelles
    }else{
        if (delta == 0){ // Si le déterminant est égal à zéro alors on a qu'une solution
            puts ("Une soltion relles");
            printf ("x= %f", -b/(2*a)); // On affiche cette solution
        }else{
            if (delta < 0){ // Si le déterminant est négatif alors on a deux solutions complexes
                puts("Pas de solutions reelles mais deux solutions complexes");
                printf("x1 = %f - i%f et x2 = %f +i%f", -b/(2*a), sqrt(abs(delta))/(2*a), -b/(2*a), sqrt(abs(delta))/(2*a)); // On affiche les deux solutions complexes
            }
        }
    }
}

/* Fonction de menu maths */

void menu_maths (){
    printf("\e[1;1H\e[2J"); // Clear le terminal
    int choix = 0;
    if (choix != 0){ // Si la fonction c'est mal loadée, on sort du programme
        exit(0);
    }else{ // Sinon on laisse l'utilisateur choisir
        printf("Entrer votre choix \n 1: factorielle \n 2: PGCD \n 3: Equation du second degre \n");
        scanf("%d", &choix);
        switch (choix){ // Selon le choix de l'utilisateur
        case 1: // Cas 1 on calcule la factorielle
            factorielle();
            break;
        case 2: // Cas 2 on calcule le PGCD de deux nombres
            pgcd();
            break;
        case 3: // Cas 3 on résouds une équation du second degré
            second_deg();
            break;
        default: // Cas par défaut on sort
            break;
        }
    }
}

void menu(int argc, char** argv){
    int choix;
    int point;
    char* mot = (char*)malloc(500*sizeof(char));
    puts ("Entrer votre choix \n 1: Min/Max \n 2: Devinette \n 3: Occurences dans un texte \n 4: Calculer la valeur d'un polynome \n 5: Menu maths");
    scanf ("%d", &choix);
    switch (choix)
    {
    case 1:
        MinMax();
        break;
    case 2:
        Devinette();
        break;
    case 3:
        puts("Entrer un mot à rechercher");
        scanf("%s", mot);
        chaine(argv[1], mot);
        break;
    case 4:
        puts("Entrer un point");
        scanf("%d", &point);
        polynome(point);
        break;
    case 5:
        menu_maths();
    case 6:

    default:
        break;
    }
}

int main (int argc, char** argv){
    menu(argc, argv);
    return 0;
}