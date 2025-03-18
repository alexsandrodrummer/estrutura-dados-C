//bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//constantes
#define tamanho 5 

//estrutura da pilha
struct tpilha {
    int dados[tamanho];
    int ini;
    int fim;
};

//variáveis globais
struct tpilha pilha;
int op;

//prototipação
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

//função principal
int main(){
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    pilha.ini = 0;
    pilha.fim = 0;

    while(op != 0) {
        system ("cls");
        pilha_mostrar();
        menu_mostrar();
        scanf ("%d", &op);
    
        switch (op) {
            case 1:
                pilha_entrar();
                break;
            case 2:
                pilha_sair();
                 break;
        }
    } 
    return (0);
}
//Adicionar um elemento no final da pilha
void pilha_entrar (){
    if (pilha.fim == tamanho) {
        printf ("\nA pilha esta cheia, impossivel empilhar ! \n\n");
        system ("pause");
    }
    else {
        printf ("\nDigite um valor para empilhar: ");
        scanf ("%d", &pilha.dados[pilha.fim]);
        pilha.fim++;
    }
}