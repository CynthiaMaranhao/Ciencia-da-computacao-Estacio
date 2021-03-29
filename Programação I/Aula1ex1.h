#include <iostream> 
// biblioteca input e output

using namespace std;
// reconhecer automática a concatenação de >> ou << do C++

//
int main () 
{
	//Declaração das variáveis
	int n1, n2,s;
	//Entradas
	cout << ("Número..:");
	cin >> n1;
	cout << ("Número..:");
	cin >> n2;
	//Processamento
	s = n1 + n2;
	//Saída
	cout << ("Soma....:");
	cout << s;
	return 0;
}
