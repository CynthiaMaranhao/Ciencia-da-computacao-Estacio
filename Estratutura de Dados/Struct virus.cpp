#include <iostream>
using namespace std;

struct data
{
    int dia, mes, ano;
};

struct pesquisa
{
    //char nome[30], char sexo [1];
    data dtrealizacao;
    data nascimento;
    int telefone, sintomas, dias, exames, resultexame, recuperou;
};

int main()
{
	int i=0, qtd=0, soma=0, idade=0, recup=0, op;
	pesquisa virus [2];
	
	do{
		cout << "\n-------------------- MENU -------------------- ";
		cout << "\n1 - Cadastro";
		cout << "\n2 - Exibir Cadastro";
		cout << "\n2 - Quantidade de Pessoas que tiveram vírus";
		cout << "\n3 - Média de idade das Pessoas que tiveram vírus";
		cout << "\n4 - Quantidade de Pessoas que tiveram vírus";
		cout << "\n5 - Listar data nascimento do paciente com sintomas, mas exames negativos";
		cout << "\n6 - Percentual de pessoas que tiveram o vírus";
		cout << "\n7 - Percentual de pessoas que recuperaram do vírus";
		cout << "\n8 - Listar data nascimento do(s) paciente(s) que se recuperaram do vírus";
		cout << "\n9 - Sair"<< endl; 
		cout << "Escolha a sua opção:..."; 
		cin >> op;
  
	switch(op)
    {
      case 1: cout<< "\nCadastro...: ";
				for (i = 0; i < 2; i++){
					cout<< "----------------------------------------REALIZAÇÃO DA PESQUISA---------------------------------------- "<< endl;    
					cout<< "Dados do dia da Pesquisa" << endl;
					cout<< "Dia...: ";
					cin>> virus[i].dtrealizacao.dia;
					cout<< "Mês...: "; 
					cin>> virus[i].dtrealizacao.mes;
					cout<< "Ano...: "; 
					cin>> virus[i].dtrealizacao.ano;
					cout<< "-------------Dados da Pessoa-------------" << endl;
					cout<< "Dia de Nascimento...: "; 
					cin>> virus[i].nascimento.dia;
					cout<< "Mês de Nascimento...: "; 
					cin>> virus[i]. nascimento.mes;
					cout<< "Ano de Nascimento...: "; 
					cin>> virus[i]. nascimento.ano;
					cout<< "Telefone...: "; 
					cin>> virus[i]. telefone;
					cout<< "Teve Sintomas: 1- Sim 2-Não...: "; 
					cin>> virus[i].sintomas;
						if (virus[i].sintomas ==1){
							cout<< "Por quantos dias teve os sintomas...: "; 
							cin>> virus[i].dias;
							qtd ++;
						}
					cout<< "Fez Exames: 1- Sim 2-Não...: "; 
					cin>> virus[i].exames;
						if (virus[i].exames ==1){
							cout<< "Resultado do(s) Exame(s): 1- Positivo 2-Negativo...: "; 
							cin>> virus[i].resultexame;
						}
					cout<< "Se recuperou do vírus: 1- Sim 2-Não...: "; 
					cin>> virus[i].recuperou;
						if (virus[i].recuperou == 1){
							recup++;
						}
				}
              break;    
      case 2: cout<< "\nExibir Cadastro... ";
              cout<< "----------------------------------------RESULTADO DA PESQUISA---------------------------------------- "<< endl;    
			  for (i = 0; i < 2; i++){
				cout<< "------------------------------------Entrevistado..: " << i + 1 <<"-----------------------------------" << endl;
				cout<< "Data da Pesquisa...: " << virus[i].dtrealizacao.dia << "/" << virus[i].dtrealizacao.mes << "/"<< virus[i].dtrealizacao.ano << endl;
				cout<< "-------Dados da Pessoa-------"<< endl;
				cout<< "Data de Nascimento...: "<< virus[i].nascimento.dia  << "/" << virus[i].nascimento.mes << "/" << virus[i].nascimento.ano << endl;
				cout<< "Idade...: " << virus[i].telefone << endl;
				cout<< "Telefone...: " << idade << endl;
					if (virus[i].sintomas ==1){
						
						cout<< "Apresentou sintomas, por " << virus[i].dias << " dia(s)." << endl;
						}
					else {
						cout<< "Não apresentou sintomas." << endl;;
						}
					
					if (virus[i].exames ==1){
						cout<< "Média idade das pessoas que tiveram vírus foi: "; 
						
						if (virus[i].resultexame ==1){
							cout<< "positivo." << endl;
							}
						else {
							cout<< "negativo."<< endl;
							}
					}
					else {
						cout<< "Não realizou exames."<< endl;     
						}   
			  }        
              break;
      case 3: cout<< "\nQuantidade de Pessoas que tiveram vírus...: ";
              cout<<  qtd << endl;
			  break;
	  case 4: cout<< "\nMédia idade das pessoas que tiveram vírus...: "; 
	  
            for (i = 0; i < 2; i++){
                if (virus[i].sintomas ==1){
                    idade = virus[i].dtrealizacao.ano - virus[i].nascimento.ano;
                    soma = soma + idade;
                    }
            }
			  cout<< soma/qtd << endl;
			  break;
	  case 5: cout<< "\nListar data nascimento do paciente com sintomas, mas exames negativos...: ";
            for (i = 0; i < 2; i++){
                if (virus[i].sintomas ==1 && virus[i].resultexame ==0){
                cout<< virus[i].nascimento.dia  << "/" << virus[i].nascimento.mes << "/" << virus[i].nascimento.ano << endl;
                }
            }
	  		break;
	  case 6: 	cout<< "\nPercentual de pessoas que tiveram o vírus...: "; 
				cout<< (qtd*100)/i << endl;
				break;
	  case 7: 	cout<< "\nPercentual de pessoas se recuperaram do vírus...: "; 
				cout<< (recup*100)/i << endl; 
				break;	  
	  case 8:  cout<< "\nListar data nascimento do(s) paciente(s) que se recuperaram do vírus...: ";    
				for (i = 0; i < 2; i++){
					if (virus[i].sintomas ==1 && virus[i].recuperou ==1){
					cout<< virus[i].nascimento.dia  << "/" << virus[i].nascimento.mes << "/" << virus[i].nascimento.ano << endl;
					}
				}
				break;
	  case 9:  cout<< "\nSair";
				break;
	  default: cout<< "\nOpção Inválida...: ";
              break;          
    }
  }while (op !=9);          
}
