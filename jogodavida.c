#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){

  int nGer;
  printf("Insira o numero de geracoes:\n");
  scanf("%d", &nGer);

  srand(time(NULL));

  int GRID[30][30];

  //Setando todo o tabuleiro como 0
  for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
          GRID[i][j] = 0;
        }
  }

  //Gerando números
  for (int i = 0; i < 30; i++){
    for (int j = 0; j < 30; j++) {
      GRID[i][j] = rand()%2;
    }
  }

  for (int i = 0; i < nGer; i++){
    printf("Geracao %d:\n", i+1);
    for(int linha = 0 ; linha < 30 ; linha++){
          for(int coluna = 0 ; coluna < 30 ; coluna++){
              if(GRID[linha][coluna] == 0){
                  printf("  ");
              }
              if(GRID[linha][coluna] == 1){
                  printf("O ");
              }
          }
          putchar('\n');
      }
    sleep(4);
    system("cls");
  }

  //Contando vizinhos


  return 0;
}
