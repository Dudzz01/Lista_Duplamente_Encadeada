#include <stdio.h>

void inserirInicio(int dado);
void busca(int lista, int dado);
void inverter(int lista);

typedef struct No{
    int dado;
    No *proximo;
    No *anterior;
}No;

No *inicio1 = nullptr; No *inicio2 = nullptr;

void inserirInicio(int dado){
    No *novo = new No();
    novo->dado = dado;
    novo->proximo = inicio1;
    novo->anterior = NULL; // se ainda a lista nao existir, ou seja, caso so exista 1 estrutura na qual ainda nao foi referida a lista e consequentemente nenhuma outra estrutura anterior a esta, entao o ponteiro que indica para alguma estrutura anterior a essa é nulo
    if(inicio1!=nullptr){
        inicio1->anterior = novo;
    }
    inicio1 = novo;
}

void busca(int lista, int dado)
{
    if(lista == 1)
    {
        No *aux;
        if (inicio1 != nullptr)
        {
            for (aux = inicio1; aux != nullptr; aux = aux->proximo)
            {
                if (dado == aux->dado)
                {
                    printf("Dado %d encontrado no endereco %p| na lista %d", aux->dado, aux, lista);
                    return;
                }
            }
              printf("Dado nao encontrado");
            return;
        }
        else{
            printf("Lista nao existe");
        }
    }
}

void imprimir(int lista){

    if(lista == 1){
        No *aux;


        if(inicio1!= nullptr) {
            for (aux = inicio1; aux != nullptr; aux = aux->proximo) {
                printf("Num end: %p  ||  Dado: %d \n", aux, aux->dado);
            }
        }
        else{
            printf("Lista nao existe");
        }
    }
}

void inverter(int lista){
    if(lista == 1){
        No *aux;
        No *aux2;
        No *ultimo_elemento;
        for(aux = inicio1; aux!=nullptr; aux = aux->proximo){
                if(aux->proximo == nullptr){
                   // printf("%d", aux->dado);
                    ultimo_elemento = aux;
                }
        }
        inicio1 = ultimo_elemento;
        aux = inicio1;
        printf("Endereco inicial da lista: %p \n", aux);
        printf("Lista Invertida\n");
        printf("\n");
        do{
            aux2 = aux->proximo;
            aux->proximo = aux->anterior;
            aux->anterior = aux2;
            aux = aux->proximo;
        } while (aux!= nullptr);



    }
}





int main() {

int vetor[10] = {1,2,3,4,5,6,7,8,9,10};

for(int i = 9; i>=0; i--){
    inserirInicio(vetor[i]);
}

    imprimir(1);
    inverter(1);
   imprimir(1);


    return 0;
}
