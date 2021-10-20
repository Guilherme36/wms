/*
   Leia uma sequ�ncia de n n�meros e armazene-os em um array.
   Ap�s, leia o valor de uma posi��o do vetor e realize uma remo��o.
   No final imprima o vetor.
   */

#include <stdio.h>

#define MAX 100

int main(){
  int v[MAX], i, n = 0;
  int posicao;

  puts("**Remove um elemento de um vetor, pelo indice**");

  puts("Digite o tamanho do vetor");
  scanf("%d", &n);

  puts("Digite os elementos do vetor");
  for(i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  printf("Digite o indice (posicao) do elemento que deseja remover - entre 0 e %d\n", n - 1);
  scanf("%d", &posicao); //se o usuario digita um indice maior que n - 1, remove ultimo elemento

  for(i = posicao; i < n - 1; i++){
    v[i] = v[i + 1];
  }
  n--; //mesmo que n = n - 1;

  puts("Imprimindo vetor apos o elemento ser removido");
  for(i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  puts("");

  /*
  for(int i = 0; i < 5; i++){
  printf("\nimprimindo o apagado: %d\n", v[i]);
  }
  */
  printf("\nimprimindo o apagado: %d\n", v[3]);

  return 0;
}
