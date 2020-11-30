#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define L 30
#define C 30

int TABULEIRO[L][C], TABVERI[L][C];              

void TABVERIV0(){
  for(int l = 0; l < L; l++){
    for (int c = 0; c < C; c++){
      TABVERI[l][c] = 0;
    }
  }
}


int ContadorTab(int y,int x){
  int c = 0;
  for(int i = y-1; i <= y+1; i++){
    for (int j = x-1; j <= x+1; j++){
      if ((i >= 0 && j >= 0) && (i < 30 && j < 30)){
        if (i == y && j == x){}else{
          if (TABULEIRO[i][j] == 1){c ++;}
        }
      }
    }
  }
  return c;
}


void TABparaTAB(){
  for(int l = 0; l < L; l++){
    for (int c = 0; c < C; c++){
      if (TABVERI[l][c] == 1 && TABULEIRO[l][c] == 0){
          TABULEIRO[l][c] = 1;
        }else if (TABVERI[l][c] == 1 && TABULEIRO[l][c] == 1){
          TABULEIRO[l][c] = 0;
        }
    }
  }
}


void regras(){
  TABVERIV0();
  for(int l = 0; l < L; l++){
    for (int c = 0; c < C; c++){
      int Contador = ContadorTab(l,c);
      
      //regras 1, 2 e 3
      if (TABULEIRO[l][c] == 1) {
        if (Contador < 2 || Contador > 3) {TABVERI[l][c] = 1;}
      }
      
      //regra 4
      if (TABULEIRO[l][c] == 0){
        if (Contador == 3){
          TABVERI[l][c] = 1;
        }
      }
    }
  }
  TABparaTAB();
}
