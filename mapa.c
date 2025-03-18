1 //Bibliotecas
2 #include <stdio.h>
3 #include <stdlib.h>
4 #include <locale.h>
5
6 //Constantes
7 #define tamanho 20
8
9 //Estrutura da Senha
10 typedef struct tsenha {
11    int numero;
12    char tipo;
13 } tsenha;
14 
15 //Estrutura da Fila
16 struct tfilabanco {
17    tsenha dados[tamanho];
18    int ini;
19    int fim;
20 };
21
22 //Variáveis globais
23 struct tfilabanco fila;
24 int op, proximo;
25
26 //Protipação
27 void fila_entrar();
28 void fila_sair();
29 void fila_mostrar();
30 void menu_mostrar();
31
32 //Função principal
33 int main(){
34    setlocale(LC_ALL, "Portuguese");
35    op = 1;
36    proximo = 1;
37    fila.ini = 0;
38    fila.fim = 0;
39    while (op != 0) {
40        system("cls");
41        fila_mostrar();
42        menu_mostrar();
43        scanf("%d", &op);
44        switch (op) {
45            case 1:
46                fila_entrar();
47                break;
48            case 2:
49                fila_sair();
50                break;
51        }
52    }
53    return 0;
54 }
55
56 //Adicionar um elemento no final da Fila
57 void fila_entrar(){
58    if (fila.fim == tamanho) {
59        printf("\nA fila está cheia, volte outro dia!\n\n");
60        system("pause");
61        return;
62    }
63
64    char tipo;
65    printf("\nEscolha o tipo do atendimento:");
66    printf("\nC - Comum");
67    printf("\nP - Prioridade");
68    printf("\nR - Rápido: ");
69    scanf(" %c", &tipo);
70    if (tipo != 'C' && tipo != 'P' && tipo != 'R') {
71        printf("\nTipo de atendimento inválido!\n\n");
72        return;
73    }
74    fila.dados[fila.fim].tipo = tipo;
75    fila.dados[fila.fim].numero = proximo;
76    proximo++;
77    fila.fim++;
78 }
79
80 //Retirar o primeiro elemento da Fila de acordo com o caixa
81 void fila_sair() {
82    if (fila.ini == fila.fim) {
83        printf("\nFila vazia, mas logo aparece alguém!\n\n");
84        system("pause");
85    } else {
86        int caixa;
87        char tipoatendimento;
88        printf("\nQual caixa vai atender (1 a 4)?: ");
89        scanf("%d", &caixa);
90        switch (caixa) {
91            case 1:
92                tipoatendimento = 'P';
93                break;
94            case 2:
95            case 3:
96                tipoatendimento = 'C';
97                break;
98            case 4:
99                tipoatendimento = 'R';
100                break;
101            default:
102                printf("\nValor inválido!");
103                return;
104        }
105        // Define a posição do elemento aser removido como 0
106        int posicao = 0;
107
108        // Procura elemento do tipo correspondente
109        for (int i = 0; i < tamanho; i++) {
110            if (fila.dados[i].tipo == tipoatendimento) {
111                posicao = i;
112                break;
113            }
114        }
115
116        printf("\n\n###### ATENDIMENTO #########\n");
117        printf("Senha: %c-%d\n", fila.dados[posicao].tipo, fila.dados[posicao].numero);
118        printf("Caixa: %d\n", caixa);
119        printf("###### ATENDIMENTO #########\n\n");
120
121        // Retira elemento da posição e move os demais
122        for (int i = posicao; i < tamanho; i++) {
123            fila.dados[i].numero = fila.dados[i+1].numero;
124            fila.dados[i].tipo = fila.dados[i+1].tipo;
125        }
126        fila.dados[fila.fim].numero = 0;
127        fila.dados[fila.fim].tipo = ' ';
128        fila.fim--;
129    }
130 }
131
132 //Mostrar o conteúdo da Fila
133 void fila_mostrar() {
134    int i;
135    printf("[ ");
136    for (i = 0; i < tamanho; i++) {
137        printf("%c-%d ", fila.dados[i].tipo, fila.dados[i].numero);
138    }
139    printf("]\n\n");
140 }
141
142 //Mostrar o menu de opções
143 void menu_mostrar() {
144    printf("\nEscolha uma opção:\n");
145    printf("1 - Nova senha\n");
146    printf("2 - Atender\n");
147    printf("0 - Sair\n\n");
148 }