#include <iostream>
#include <cstdlib>
#define TAM 40
using namespace std;
void empilha (int p[], int &t, int v);
void desempilha (int p[], int &t);

int
main ()
{
  int topo = -1, pilha[TAM], num, resto;
  cout << "\nNumero em decimal: ";
  cin >> num;
  num = abs (num);

  while (num > 0)
    {
      resto = num % 2;
      empilha (pilha, topo, resto);
      num /= 2;
    }
  desempilha (pilha, topo);
  cout << "\n\n";
  system ("pause");
}

void
empilha (int p[], int &t, int v)
{
  if (t == TAM - 1)
    cout << "\nAtenC'C#o Pilha Cheia!!\n ";
  else
    {
      t++;			// atualiza topo
      p[t] = v;			// pilha recebe valor
    }
}

void
desempilha (int p[], int &t)
{
  if (t == -1)
    cout << "\nPilha vazia!!\n ";
  else
    {
      while (t != -1)
	{
	  cout << p[t];
	  t--;			// atualiza topo
	}
    }

}