#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
 

struct data_ {
int dia, mes, ano;
} cadastro; 
 

struct paciente
{
  char nome[30]; 
  string senhaCod;
  int senha, sexo, idade, pSis, pDis, prioridade; 
  data_ cadastro;
  double temp, peso, altura; 
  struct paciente *prox;
};


void registro(paciente *ptr);
paciente* triagem(paciente *ptr);
paciente *atende(paciente *ptr);
void exibep(paciente *ptr);
void exiben(paciente *ptr);
void libera(paciente *ptr);


int main()
{   int op; 
    paciente *lista=NULL; 
 do
 { system("cls"); 
   cout<<"\n\n< < <     ATENDIMENTO    < < <"; 
    cout<<"\n<                             <"; 
    cout<<"\n< 1- TRIAGEM - CADASTRO       <";                                   
    cout<<"\n< 2- ATENDIMENTO              <"; 
    cout<<"\n< 3- LISTA PRIORIDADE ALTA    <";  
    cout<<"\n< 4- LISTA PRIORIDADE BAIXA   <";     
    cout<<"\n< 5- LISTA - ATEDIMENTO       <";     
    cout<<"\n< 6-                          <";
    cout<<"\n< 7- LIBERA LISTA             <"; 
    cout<<"\n< 8- SAIR                     <";                 
    cout<<"\n< Opcao:                      <";
    cout<<"\n< < < < < < < < < < < < < < < <\n"; 
    cin>>op;
    
   system("cls");
    switch(op)
    {   
      case 1:cout<<"\nTRIAGEM - CADASTRO: ";
             triagem(lista);
             break;
             
      case 2:cout<<"\nATENDIMENTO: "<<endl;
             lista= atende(lista);
             break;
                   
     case 3:if(!lista) // ponteiro não inicializado
              cout << "\nNada a remover. Lista vazia\n";
			  else
			  {
			  cout<<"\nLISTAR - FILA ALTA PRIORIDADE"<< endl;
			  exibep(lista);
             }
             break;                         
      case 4:if(!lista)
              cout << "\n\nNada a remover. Lista vazia\n";
             else 
             {
              cout<<"\n\nLISTAR - FILA BAIXA PRIORIDADE\n"<< endl;
			  exiben(lista); 
             }
             break;              
             
     case 5:cout<<"\nLISTAR - AGUARDANDO ATENDIMENTO"<< endl;
	 		if(lista!=NULL){
				exibep(lista);
				exiben(lista);
				
			}
			else cout<<"Fila Vazia - Sem Pacientes."<<endl;
			break;         
    case 6:
           break; 
    case 7:if(lista)
              cout<<"\nTem elementos na Lista\n";
             else
             { 
               libera(lista);
               cout<<"\nLiberando Memoria";
             }  
             break; 
     
           
    case 8: cout<<"Fechando Lista Encadeada\n";           
            break;   
			
	
      default:cout<<"\nOpcao Invalida\n";
  }
  cout<<"\n\n"; 
  system("pause");
 } while(op != 8);
 return 0;
} 


// Cadastro Paciente 
void registro(paciente *ptr)
{
   // Ler os dados
	cout << "\n-----------------------------";
	cout << "\nEntre com os dados:";
	cout << "\n-----------------------------" << endl;
	cout << "Nome Paciente..........:" ;
	cin >> ptr->nome;
	/*cout << "Sexo (1-M / 2-F).......:" ;
	cin>> ptr->sexo;
	cout << "Data Cadastro" ;
	cout << "\nDia...................:" ;
	cin>> ptr->cadastro.dia;
	cout << "Mes...................:" ;
	cin>> ptr->cadastro.mes;
	cout << "Ano...................:" ;
	cin>> ptr->cadastro.ano;
	cout << "Temperatura...........:" ;
	cin>> ptr->temp;
	cout << "Peso..................:" ;
	cin>> ptr->peso;
	cout << "Altura................:" ;
	cin>> ptr->altura; */
	cout << "Pressao Sistolica.....:" ;
	cin>> ptr->pSis;
	cout << "Pressao Diastolica....:" ;
	cin>> ptr->pDis;
}


// 1- Triagem
paciente* triagem(paciente *ptr) // Fila
{
   	paciente *novo, *aux;
   	novo = new paciente;
  	registro(novo);
	novo->senha=1000;
	novo->prox = NULL;
   /*if(!novo)
   {
     cout<<"\nNao foi possivel fazer Alocacao\n";
     system("pause");   exit (1);
    }*/
    
    if(novo->pSis>=180 || novo->pDis>120){
		novo->prioridade = 1;
		novo->senhaCod = "P";}
   	else{
	
		novo->prioridade = 0;
		novo->senhaCod = "N";}
		if(ptr=NULL){   // ponteiro não inicializado
			aux=ptr;
			while(aux->prox){
				aux=aux->prox;
				novo->senha++;
			}
			aux->prox = novo;
		}
		else{
			ptr = novo;
		}
	 return ptr;
}


// 2- Atendimento  - Paciente
paciente *atende(paciente *ptr){ // fila
  paciente *aux = new paciente;
	if (ptr!=NULL){
	
		if (ptr->prioridade=1)  {
  			cout<<"Paciente "<<ptr->senhaCod<<"-"<<ptr->senha<<" Atendido."<<endl;
	  		aux = ptr;
	  		ptr = ptr->prox;
	  		aux=0;
	  		delete aux; // libera o paciente
	  		return ptr;
		}
		if (ptr->prioridade=0){
 		
			cout<<"Paciente "<<ptr->senhaCod<<ptr->senha<<" Atendido."<<endl;
			aux = ptr;
			ptr = ptr->prox;
			aux=0;
			delete aux;  // libera	o paciente
			return ptr;
		}
	}
  	else
   		cout<<"Nao ha pacientes para ser atendidos."<<endl;
	
}



// 3 a 5 - Apresentar Fila

void exibep(paciente *ptr){  
  if (ptr->prioridade=1)
  	while(ptr)
  	{
    	cout<< ptr->senhaCod <<"-" <<ptr->senha <<" - "  << ptr->nome << endl; 
    	ptr=ptr->prox;
  	}	

}

void exiben(paciente *ptr){  
  if (ptr->prioridade=0)
   while(ptr)
  {
    
	 cout<< ptr->senhaCod <<"-" <<ptr->senha <<" - "  << ptr->nome << endl; 
    ptr=ptr->prox;
  }
  

}


void libera(paciente *ptr)
{
    delete ptr;   ptr=0;    
} 
 
