//TIK TAK TOE SABIR Yassine
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void afficher(char *t){
    int i;
    for (i=0;i<4;i++){
        printf("+---+---+---+---+\n| %c | %c | %c | %c |\n",*(t+4*i),*(t+4*i+1),*(t+4*i+2),*(t+4*i+3));
    }
    printf("+---+---+---+---+\n");
}
int isvide(char *t){
    int vide=0,i,j;
    for (i=1;i<4;i++){
        if (vide==1){break;}
        else{
            for (j=1;j<4;j++){
                if (*(t+i*4+j)==' '){
                    vide=1;
                    break;
                };
            };
        };
    };
    return vide;
}
int listevide(char *t){
    int i,r=0;
    for (i=0;i<3;i++){
        if (*(t+i)==' '){
            r=1;
            break;
        };
    };
    return r;
}
int lstid(char *t){
    int x=*t;
    if (listevide(t)==1){return 0;}
    else{
        if (x==*(t+1) && x==*(t+2)){return 1;}
        else{return 0;};
    };
}
int win(char *t){
    char l1[3]={*(t+5),*(t+6),*(t+7)},l2[3]={*(t+9),*(t+10),*(t+11)},l3[3]={*(t+13),*(t+14),*(t+15)};
    char c1[3]={*(t+5),*(t+9),*(t+13)},c2[3]={*(t+6),*(t+10),*(t+14)},c3[3]={*(t+7),*(t+11),*(t+15)};
    char d1[3]={*(t+5),*(t+10),*(t+15)},d2[3]={*(t+7),*(t+10),*(t+13)};
    int i1=lstid(&l1[0]),i2=lstid(&l2[0]),i3=lstid(&l3[0]),j1=lstid(&c1[0]),j2=lstid(&c2[0]),j3=lstid(&c3[0]),k1=lstid(&d1[0]),k2=lstid(&d2[0]);
    if (i1==1||i2==1||i3==1||j1==1||j2==1||j3==1||k1==1||k2==1){return 1;}
    else{return 0;};
}
int main(){
    char T[4][4];
    int i,j;
    printf("~~ TIK TAK TOE ~~\n\n");
    //initialisation de la matrice
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if (i==0){
                if (j!=0){itoa(j,&T[i][j],10);}
                else{T[i][j]=' ';};
            }
            else{
                if (j==0){itoa(i,&T[i][j],10);}
                else{T[i][j]=' ';};
            };

        };
    };
    //nom des joueurs
    char P1[20],P2[20];
    printf("donner le nom du premier joueur X : ");
    scanf("%s",P1);
    printf("donner le nom du deuxieme joueur O: ");
    scanf("%s",P2);
    //le jeu
    int c=1;
    while (win(&T[0][0])==0 && isvide(&T[0][0])==1){
        afficher(&T[0][0]);
        if (c%2==1){
            printf("c'est le tour du joueur %s --> X \n",P1);
            printf("choisir un emplacement vide : ");
            scanf("%d%d",&i,&j);
            if (i>0 && i<4 && j>0 && j<4 && T[i][j]==' '){
                T[i][j]='X';
            }
            else{
                printf("Vous devriez jouer\n");
                c--;
            };
        }
        else{
            printf("c'est le tour du joueur %s --> O \n",P2);
            printf("choisir un emplacement vide : ");
            scanf("%d%d",&i,&j);
            if (i>0 && i<4 && j>0 && j<4 && T[i][j]==' '){
                T[i][j]='O';
            }
            else{
                printf("Vous devriez jouer\n");
                c--;
            };
        };
        c++;
    };
    afficher(&T[0][0]);
    if (win(&T[0][0])==1){
        if (c%2==1){printf("le joueur gagnant est : %s",P2);}
        else{printf("le joueur gagnant est : %s",P1);};
    }
    else{printf("Égalité");};
    Sleep(5000);
    return 0;
}
