#include <iostream>
#define T 3
using namespace std;

struct vendas { 
int codProduto; /* Codigo do Produto */ 
int qtd; /* Quantidade */ 
double preco; /* Preco do produto */ 
double desconto; /* Percentual de desconto */ 
double total; /*Total da Venda - calculado automaticamente */ 
};

double valorPrestacao(int qtd, double preco, int n);
int main(){
    vendas liquidacao[T];
    int n;
    int i;
    for(int i=0; i<T; i++){
        cout<<"\nEntre com o codigo do Produto:";
        cin>>liquidacao[i].codProduto;
        cout<<"Entre com a quantidade do Produto:";
        cin>>liquidacao[i].qtd;
        cout<<"Entre com o pre�o do Produto:";
        cin>>liquidacao[i].preco;
        liquidacao[i].total = liquidacao[i].qtd * liquidacao[i].preco;
        cout<<"Entre com desconto do Produto:";
        cin>>liquidacao[i].desconto;
        cout<< "Informe a quantidade de presta��es: ";
        cin>>n;
    }
	
	double soma=0, somap=0, prestacao;
    cout<<"________________________________________________________"<<endl;
    cout<<" Dados de Vendas "<<endl;
    cout<<"________________________________________________________"<<endl;
    for(int i=0; i<T; i++){
    cout<<"Codigo do Produto: "<<liquidacao[i].codProduto <<endl;
    cout<<"\nQuantidade do Produto: "<<liquidacao[i].qtd <<endl;
    cout<<"\nPre�o do Produto: "<<liquidacao[i].preco<<endl;
    cout<<"\nDesconto do Produto: "<<liquidacao[i].desconto <<endl;
    cout<<"\nValor Total do Produto: "<<liquidacao[i].total<<endl;
    cout<<"\nn: "<<n<<endl;
    if (n<=6) {
            if (n==1) {
                liquidacao[i].total = liquidacao[i].preco*(liquidacao[i].desconto/100);
                cout << "\nO valor com Desconto �: " <<  liquidacao[i].total;}
            else {
                cout << "\nO valor da presta��o �: " << valorPrestacao(liquidacao[i].qtd, liquidacao[i].preco, n) << endl;
            }
        }
        else {
            cout << "N�mero de presta��es inv�lidas.";
    		prestacao = 0;
        }
    cout<<"-----------------------------------"<<endl;
    soma = soma + liquidacao[i].total;
    somap = somap + valorPrestacao(liquidacao[i].qtd, liquidacao[i].preco, n);
    }
    cout<<"________________________________________________________"<<endl;
    cout<< "A M�dia de Vendas �: " << (soma/T);
    cout<< "A M�dia das Presta��es �: "<< (somap/n)<<endl;
    

	return 0;
	}


double valorPrestacao(int qtd, double preco, int n){
	double prestacao;
	prestacao = (qtd*preco)/n;
	return prestacao;
}
	
