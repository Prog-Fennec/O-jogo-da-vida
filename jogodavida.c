#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define L 30
#define C 30

int TABULEIRO[L][C], TABVERI[L][C];              

void VisuTab()
{
  for(int l = 0; l < L; l++)
  {
    for (int c = 0; c < C; c++)
    {
      if(TABULEIRO[l][c] == 0)
      {
        printf("  ");
      }
      else
      {
        printf("O ");}
      }
    printf("\n");
  }
}


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


void TabAlea()
{
  srand(time(NULL));
  
  for (int l = 0; l < L; l++)
  {
    for (int c = 0; c < C; c++)
    {
      TABULEIRO[l][c] = rand()%2;
    }
  }
  VisuTab();
}


void TabPreDef()
{
  int c, l;

  for(;;)
  {
    printf("Indique a posicao da célula viva(-1 -1 = fim):\n");
    scanf("%d %d", &l, &c);
    if(l == -1 && c == -1)
    {
      break;
    }
    TABULEIRO[l][c] = 1;
    VisuTab();
    system("cls");
  }
}

void Geracoes(int G){

  system("cls");
  printf("Geração 1:\n");
  VisuTab();
  sleep(1);
  for (int i = 2; i <= G; i++){
    regras();
    system("cls");
    printf("Geração %d:\n", i);
    VisuTab();
    sleep(1);
  }
}

int main(){

  printf("Digite:\n[1]Aleatório\n[2]Definir\n");
  int a;
  scanf("%d", &a);
  if (a == 2){TabPreDef();}else if(a == 1){
    TabAlea();
  }
  printf("Quantas gerações são:\n");
  int geracoes;
  scanf("%d", &geracoes);

  Geracoes(geracoes);

  return 0;
}
