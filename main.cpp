#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define N 8


using namespace std;

void imprimir(int t[N][N])
{
   int i, j;
   for (i=0; i<N; i++)
   {
     for (j=0; j<N; j++)
     {
         if( t[i][j]==0 )
            cout<<("__|");
         else
            printf("%2d|", t[i][j]);
    }
     cout<<endl;
   }
   cout<<endl;
}
int esta_amenazada(int f, int c, int t[N][N] ){
    int i;
  //mi
  //t[7][3] = 1;
   for(i=0; i<N; i++){
      if( t[f][i]!=0 || t[i][c]!=0 )
         return 1;
   }
   //di
   for(i=0; f-i>=0 && c-i>=0; i++){
      if( t[f-i][c-i]!=0 )
         return 1;
   }
   //dd
   for(i=0; f-i>=0 && c+i<N; i++){
      if( t[f-i][c+i]!=0 )
         return 1;
   }
   //di
   for(i=0; f+i<N && c-i>=0; i++){
      if( t[f+i][c-i]!=0 )
         return 1;
   }
   //dd
   for(i=0; f+i<N && c+i<N; i++){
      if( t[f+i][c+i]!=0 )
         return 1;
   }
   return 0;
}
int resolver(int t[N][N], int c){
    int f;

    imprimir(t);
    /* Oe si quieres ver paso a paso como se ejecuta el programa descomenta el getchar
    y cuando salga la consola vas apretando enter y va acomodando las reynas de ahi cuando no hay soluciom
    veras como funciona el bactraking*/

    //getchar();
   system("cls");
  //  t[7][3] = 1;
    if( c == N )
        return 1;


    for(f = 0; f<N; f++){
            //f
            //t[7][3]=1;
        if( esta_amenazada(f, c, t)==0 ){
            t[f][c]=c+1;
            if( resolver(t, c+1) == 1 ){
                return 1;
            }
            t[f][c]=0;
        }
    }
    return 0;
}
main(){

   int tablero[N][N];
   int i,j;
   for(i=0; i<N; i++){
      for(j=0; j<N; j++){
         tablero[i][j]=0;
      }
    //  tablero[7][3] = 1;
   }



 clock_t inicio, fin;
    inicio=clock();
   if( resolver(tablero,0) == 1 ){
       cout<<"Encontre la solucion"<<endl;
    }
    else{
        cout<<"No existe la solucion"<<endl;
    }

    fin=clock();
   imprimir(tablero);
   //


   getchar();
   cout<<"tiempo de ejecucion: "<<fin - inicio<<endl;
   return 0;
}

