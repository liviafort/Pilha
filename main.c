#include <stdio.h>
#include <stdlib.h>


typedef struct{
  char links[30];
}Site;

typedef struct no{
  Site endereco;
  struct no *seguinte;
}No;

Site nomesite(){
  Site site;
  scanf("%s", site.links);
  return site;
}

No* push(No *topo){
  No *novosite = calloc(1, sizeof(No));
  novosite -> endereco = nomesite();
  novosite -> seguinte = topo;
  return novosite;
}

No* pop(No **topo){
  if (topo==NULL){
    printf("**Você ainda não inseriu nenhum site. Tente novamente.**\n");
    return 0;
  }
  else{
    No *desempilha = *topo;
    *topo = desempilha->seguinte;
    printf("****Removido com sucesso.****\n");
    free(desempilha);
    return desempilha;
  }
}

void imprimirsite(Site site){
  printf("%s\n", site.links);
}

void historicopilha(No *topo){
  if (topo!=NULL){
  while(topo!=NULL){
    imprimirsite(topo->endereco);
    topo = topo->seguinte;
  }
  }
  else{
  printf("**Você ainda não inseriu nenhum site. Tente novamente.**\n");
  }
}
int main(){
  No *topo = 0;
  No *tirar;
  int opcao, i;
  for (i=0;i<100;i++){
    printf("\n\t\tMENU\n\t1-Inserir\n\t2-Remover\n\t3-Histórico\n\t4-Sair\n\n\n");
    scanf("%d", &opcao);
    if (opcao==4)
      break;
    while(opcao>0){
      if (opcao==1){
        topo = push(topo);
        break;
      }
      else if (opcao==2){
        tirar = pop(&topo);
        break;
      }
      else if (opcao==3){
        historicopilha(topo);
        break;
      }
      else{
        printf("**ALERTA! Esse comando não existe.**\n");
        break;
      }
  }
  }
  return 0;
}