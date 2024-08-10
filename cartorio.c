#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro(){ //Fun��o respons�vel por cadastrar os usu�rios no sistema
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("digite o CPF a ser cadastrado: \n"); //cole��o de informa��es de usu�rios
	scanf("%s", cpf); //refere-se � strings
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
}

int consulta(){
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("N�o foi poss�vel localizar o arquivo consultado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	printf("Pressione qualquer tecla para continuar...\n");
    getchar(); // Espera por um caractere extra ap�s scanf
    getchar(); // Espera por uma tecla para sair

    return 0;
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sustema. \n");
		system("pause");
	}
}


int main(){
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;){
		
		system("cls"); //respons�vel por limpar a tela 
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("###Cart�rio da EBAC###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do menu
	
		system("cls");
		
		switch(opcao){
			case 1:
			registro(); //chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
	
		
	}
}
