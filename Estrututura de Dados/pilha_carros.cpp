#include <iostream>
#include <cstdlib>
#define TAM 8 // declarando a constante
using namespace std;

struct vagas{ 
  int carro[TAM];
  int top;  
}; 

void estacionar(vagas &pil);
void sair(vagas &pil);
void exibir(vagas &pil);
void listar(vagas &pil);
void reiniciar(vagas &pil);

int main(){
	int op;
	vagas pilha;      
	pilha.top = -1; 
	cout<< "\nVagas na pilha:";
	do{
    	cout << "\n---------------------------------------- ";
    	cout << "\n1 - Estacionar carro";
    	cout << "\n2 - Sair da vila";
		cout << "\n3 - Exibir as vagas";
    	cout << "\n4 - Listar de carros para sair";
    	cout << "\n5 - Reiniciar a pilha";
    	cout << "\n6 - Sair";
    	cout << "\nO que deseja fazer...:" ;
    	cin >> op;
		switch(op){
    		case 1:
				estacionar(pilha);
            	break;    
    		case 2:
				sair(pilha);
            	break;
    		case 3:
				exibir(pilha);
            	break;
			case 4:
				listar(pilha);
            	break;
            case 5:
            	reiniciar(pilha);
            	break;
            case 6:
            	cout<<"Encerrando..."<<endl;
            	break;
			default:
				cout<< "\nOpção Inválida.";
            	break;          
		}
	}while (op !=6);
}

void estacionar(vagas &pil){
	int car; 
	if (pil.top == TAM - 1) cout<<"\n Pilha Cheia\n";
	else{
		cout<<"\nEntre com o carro (casa): ";
    	cin >> car;
    	pil.top++;
    	pil.carro[pil.top] = car; 
    	cout << "\n---------------------------------------- ";
    	cout << "\nVagas ocupadas:" << (pil.top+1);
    	cout << "\nVagas restantes:" <<((TAM-1) - pil.top);
	}
}

void sair(vagas &pil){
	if (pil.top<0) cout<<"\nATENCAO. Pilha Vazia\n";
	else{
    	cout<<"\nCarro para sair: "<<pil.carro[pil.top];
    	pil.top--;
	}    
}

void exibir(vagas &pil){
	cout<<"\nQuantidade de vagas livres: "<<((TAM-1) - pil.top);
	cout<<"\nQuantidade de carros para sair: "<<(pil.top+1);
}

void listar(vagas &pil){
	if(pil.top<0) cout<<"\nATENCAO. Fila Vazia\n";
	else{
    	int x=1;
    	cout<<"\nLista de carros para sair:\n";
    	for(int i=pil.top; i>=0;  i--){
       		cout<<"\n\n"<<x<<"° carro a sair";
       		cout<<"\n Carro (casa): "<< pil.carro[i];
       		x++;
    	}
	}
}

void reiniciar(vagas &pil){
	if(pil.top<0){
		cout<<"A pilha ja esta vazia."<<endl;
	}
	else{
		pil.top = -1;
		cout<<"\nVagas ocupadas:" << (pil.top+1);
    	cout<<"\nVagas restantes:" <<((TAM-1) - pil.top);
	}
}





