#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>


void gotoligcol(int lig, int col)
{
    COORD mycoord;
    mycoord.X=col;
    mycoord.Y=lig;
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),mycoord);
}

void initgrillejeu(char grillejeu[20][20])
{
    int i,j;
    for(i=0;i<20;i++)
    {
        gotoligcol (i+3,3);
        printf("|");
        for(j=0;j<20;j++)
        {
            gotoligcol(i+3,j*2+5);
            printf("%c",grillejeu[i][j]='*');
        }
        printf("|");
        printf("\n");

    }
}

void initgrillepiece(char grillepiece[12][19])
{
    int i,j;
    for(i=0;i<12;i++)
    {
        for(j=0;j<19;j++)
        {
           grillepiece[i][j]='*';
        }
    }
}

void initgrillerotation(char grillerotation[5][5])
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            grillerotation[i][j]='*';
        }

    }
}

typedef struct piece
{
    int lig,col,deplig,depcol,vit;
}t_piece;

/*void initpiece(piece *pt)
{
    pt->lig=4;
    pt->col=5;
    pt->deplig=0;
    pt->depcol=0;
    pt->vit=1;
}
*/
int main()
{


    int a,b,c,d,e,f,g,h,i,j,k,l,x,y,z;
    char A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T;

    char grillejeu[20][20];
    char grillepiece[12][19];
    char grillerotation[5][5];
    char key='q';

    char lettrepiece;
    int numerorotation;

    initgrillejeu(grillejeu);
    initgrillepiece(grillepiece);
    initgrillerotation(grillerotation);

    printf("          Ceci est la matrice de jeu\n\n");

//creation des pieces
    grillepiece[0][0]='A';

    grillepiece[0][2]='B';
    grillepiece[0][3]='B';

    for(z=5;z<8;z++)
    {
        grillepiece[0][z]='C';
    }

    for(z=9;z<11;z++)
    {
        grillepiece[0][z]='D';
        grillepiece[1][9]='D';
    }
    for(z=12;z<16;z++)
    {
        grillepiece[0][z]='E';
    }
    for(z=0;z<5;z++)
    {
        grillepiece[z][18]='F';
    }
    for(z=2;z<5;z++)
    {
        grillepiece[z][0]='G';
        grillepiece[4][1]='G';
    }
    for(z=2;z<5;z++)
    {
        grillepiece[z][3]='H';
        grillepiece[3][4]='H';
    }
    for(z=6;z<8;z++)
    {
        grillepiece[2][z]='I';
        grillepiece[3][6]='I';
        grillepiece[3][7]='I';
    }
    for(z=0;z<4;z++)
    {
        grillepiece[6][z]='L';
        grillepiece[7][3]='L';
    }
    for(z=8;z<12;z++)
    {
        grillepiece[z][0]='Q';
        grillepiece[9][1]='Q';
    }
    for(z=2;z<5;z++)
    {
        grillepiece[11][z]='R';
        grillepiece[10][3]='R';
        grillepiece[9][3]='R';
    }
    for(z=7;z<10;z++)
    {
        grillepiece[11][z]='S';
        grillepiece[10][7]='S';
        grillepiece[9][7]='S';
    }
    for(z=5;z<8;z++)
    {
        grillepiece[z][6]='M';
        grillepiece[7][5]='M';
        grillepiece[8][5]='M';
    }
    for(z=5;z<8;z++)
    {
        grillepiece[z][9]='N';
        grillepiece[6][8]='N';
        grillepiece[7][8]='N';
    }
    for(z=14;z<17;z++)
    {
        grillepiece[3][z]='K';
        grillepiece[2][14]='K';
        grillepiece[4][15]='K';
    }
    for(z=10;z<12;z++)
    {
        grillepiece[3][z]='J';
        grillepiece[4][11]='J';
        grillepiece[4][12]='J';
    }
    for(z=15;z<18;z++)
    {
        grillepiece[10][z]='U';
        grillepiece[11][16]='U';
        grillepiece[9][16]='U';
    }
    for(z=16;z<19;z++)
    {
        grillepiece[7][z]='P';
        grillepiece[6][16]='P';
        grillepiece[8][18]='P';
    }
    for(z=6;z<9;z++)
    {
        grillepiece[z][14]='O';
        grillepiece[6][13]='O';
        grillepiece[8][13]='O';
    }
    for(z=10;z<12;z++)
    {
        grillepiece[9][z]='T';
        grillepiece[10][11]='T';
        grillepiece[10][12]='T';
        grillepiece[11][12]='T';
    }
    for(i=0;i<12;i++)
    {
        for(j=0;j<19;j++)
        {
            printf("%c",grillepiece[i][j]);
        }
        printf("\n");
    }
    printf("Ceci est la matrice des pieces\n\n");

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%c",grillerotation[i][j]);
        }
        printf("\n");
    }
    printf("Ceci est la matrice de rotation\n\n");





    //selection des pieces
    printf("Entrer le nom de la piece voulue: ");
    scanf("%c",&lettrepiece);
    if(lettrepiece=='A')
        {
           grillerotation[2][2]='A';
           for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                printf("%c",grillerotation[i][j]);

            }
            printf("\n");
           }

        }



    if(lettrepiece=='B')
        {
           grillerotation[2][2]='B';
           grillerotation[2][3]='B';
           for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                printf("%c",grillerotation[i][j]);
            }
            printf("\n");
           }

        }


    if (lettrepiece=='C')
        {
            grillerotation[2][1]='C';
            grillerotation[2][3]='C';
            grillerotation[2][2]='C';
            for (i=0;i<5;i++){
            for (j=0;j<5;j++){
                  printf ("%c", grillerotation[i][j]);
            }
            printf("\n");
            }
        }



    if (lettrepiece == 'D')
    {
        grillerotation[2][2] = 'D';
        grillerotation[3][2] = 'D';
        grillerotation[2][3] = 'D';
        for (i=0;i<5;i++){
            for (j=0;j<5;j++){
                printf ("%c", grillerotation[i][j]);

            }
            printf("\n");
        }
}




if (lettrepiece == 'E')
{
    grillerotation[2][0] = 'E';
    grillerotation[2][1] = 'E';
    grillerotation[2][2] = 'E';
    grillerotation[2][3] = 'E';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'F')
{
    grillerotation[0][2] = 'F';
    grillerotation[1][2] = 'F';
    grillerotation[2][2] = 'F';
    grillerotation[3][2] = 'F';
    grillerotation[4][2] = 'F';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}



if (lettrepiece == 'G')
{
    grillerotation[1][1] = 'G';
    grillerotation[2][1] = 'G';
    grillerotation[2][2] = 'G';
    grillerotation[2][3] = 'G';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}



if (lettrepiece == 'H')
{
    grillerotation[1][1] = 'H';
    grillerotation[2][1] = 'H';
    grillerotation[3][1] = 'H';
    grillerotation[2][2] = 'H';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece =='I')
{
    grillerotation[1][1] = 'I';
    grillerotation[1][2] = 'I';
    grillerotation[2][2] = 'I';
    grillerotation[2][1] = 'I';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'J')
{
    grillerotation[1][1] = 'J';
    grillerotation[1][2] = 'J';
    grillerotation[2][2] = 'J';
    grillerotation[2][3] = 'J';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'K')
{
    grillerotation[1][1] = 'K';
    grillerotation[1][2] = 'K';
    grillerotation[1][3] = 'K';
    grillerotation[0][1]='K';
    grillerotation[2][2]='K';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}

if (lettrepiece == 'L')
{
    grillerotation[2][0] = 'L';
    grillerotation[2][1] = 'L';
    grillerotation[2][2] = 'L';
    grillerotation[2][3] = 'L';
    grillerotation[3][3] = 'L';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}
printf("\n");


if (lettrepiece == 'M')
{
    grillerotation[3][1] = 'M';
    grillerotation[4][1] = 'M';
    grillerotation[3][2] = 'M';
    grillerotation[2][2] = 'M';
    grillerotation[1][2] = 'M';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'N')
{
    grillerotation[1][2] = 'N';
    grillerotation[2][1] = 'N';
    grillerotation[2][2] = 'N';
    grillerotation[3][1] = 'N';
    grillerotation[3][2] = 'N';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'O')
{
    grillerotation[1][1] = 'O';
    grillerotation[1][2] = 'O';
    grillerotation[2][2] = 'O';
    grillerotation[3][1] = 'O';
    grillerotation[3][2] = 'O';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}



if (lettrepiece == 'P')
{
    grillerotation[1][1] = 'P';
    grillerotation[2][1] = 'P';
    grillerotation[2][2] = 'P';
    grillerotation[2][3] = 'P';
    grillerotation[3][3] = 'P';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}



if (lettrepiece == 'Q')
{
    grillerotation[1][1] = 'Q';
    grillerotation[2][1] = 'Q';
    grillerotation[3][1] = 'Q';
    grillerotation[4][1] = 'Q';
    grillerotation[2][2] = 'Q';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'R')
{
    grillerotation[1][2] = 'R';
    grillerotation[2][2] = 'R';
    grillerotation[3][1] = 'R';
    grillerotation[3][2] = 'R';
    grillerotation[3][3] = 'R';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece ==  'S')
{
    grillerotation[1][1] = 'S';
    grillerotation[2][1] = 'S';
    grillerotation[3][1] = 'S';
    grillerotation[3][2] = 'S';
    grillerotation[3][3] = 'S';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'T')
{
    grillerotation[1][1] = 'T';
    grillerotation[1][2] = 'T';
    grillerotation[2][2] = 'T';
    grillerotation[2][3] = 'T';
    grillerotation[3][3] = 'T';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}


if (lettrepiece == 'U')
{
    grillerotation[1][2] = 'U';
    grillerotation[2][1] = 'U';
    grillerotation[2][2] = 'U';
    grillerotation[2][3] = 'U';
    grillerotation[3][2] = 'U';
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf ("%c", grillerotation[i][j]);

        }
        printf("\n");
    }
}



    //rotations
     printf("\nEntrer 6 pour la rotation vers la droite, ou 0 pour selectionner la piece sans rotation");
     scanf("%d",&numerorotation);

     if(numerorotation==6)
     {
         for(i=0;i<5;i++)
         {
             for(j=0;j<5;j++)
             {
                 printf("%c",grillerotation[j][-i+4]);
             }
             printf("\n");
         }

     }


     if(numerorotation==0)
     {
         for(i=0;i<5;i++)
         {
             for(j=0;j<5;j++)
             {
                 grillerotation[i][j]=grillerotation[i][j];
             }
         }
         for(i=0;i<5;i++)
         {
             for(j=0;j<5;j++)
             {
                 printf("%c",grillerotation[i][j]);
             }
             printf("\n");
         }
     }

// copie de la piece dans la matrice de jeu:

//



    return 0;
}



