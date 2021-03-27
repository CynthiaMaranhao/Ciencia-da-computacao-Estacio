#include <iostream>
using namespace std;
void empilhar (float p[], float vp, int&t);
void desempilhar (float p[], int&t);
#define TAM 5 // declarando a constante
int main() {
  int op, topo=-1;
  float peso, pacote[TAM];
  
  cout<< "\nValor de topo...:" << topo;
  do{
    cout << "\n-------------------- Exemplo de Pilha -------------------- ";
    cout << "\n1 - Empilhar um pacote";
    cout << "\n2 - Desempilhar um pacote";
    // declarar outras funções
    cout << "\n5 - Sair"; 
    cout << "\nO que deseja fazer...:" ;
    cin >> op;
  
  switch(op)
    {
      case 1: cout<< "\nValor do peso do pacote a ser empilado...: ";
              cin >> peso;
              empilhar(pacote,peso,topo);
              cout << "\nValor de topo...:" << topo;
              break;    
      case 2: cout<< "\nDesempilhando... ";
              desempilhar(pacote,topo);
              cout << "\nValor de topo após desempilhar o pacote...:" << topo;
              break;
      case 5: cout<< "\nExemplo básico de pilha...: ";
              break;
      default: cout<< "\nOpção Inválida...: ";
              break;          

    }
  }while (op !=5);


void empilhar (float p[], float vp, int&t)
{
  // verificar se a pilha está cheia
    if(t==TAM - 1)
      {cout << "Pilha está cheia"<< endl;} 
      else
        { 
          t++;
          p[t] = vp;
        }
}

void desempilhar (float p[], int&t)
{
  // verificar se a pilha está vazia
    if(t == - 1)
      {cout << "Pilha está vazia"<< endl;} 
      else
        { 
          cout << "\nPeso do pacote que está sendo desempilhado...:" << p[t];
          t--;
        }

}
