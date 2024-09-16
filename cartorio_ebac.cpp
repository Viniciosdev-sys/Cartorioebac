#include <stdio.h> //Responsavel pela comunica��o com o usuario
#include <stdlib.h>//Responsavel pela aloca��o de espa�o em memoria
#include <locale.h>//Responsavel pela aloca��o de texto por regi�o
#include <string.h>//Responsavel pelo cuidado das string
int registrar()//Fun��o responsavel por cadrastrar os usuarios no sistema
{
//inicio cria��o de variaveis/string		
char arquivo[40];
char cpf[40];
char nome[40];
char sobrenome[40];
char cargo[30];
//final da cria��o das variaveis/string

printf("Digite o CPF que deseja cadrastrar: ");//coletando informa��o do usuario
scanf("%s", cpf);//%s refere-se a string

strcpy(arquivo, cpf); //Responsavel por copia r valores das String

FILE *file; //cria o arquivo
file = fopen(arquivo, "w"); //criar o arquivo e o w significa escrever
fprintf(file, cpf); //salva o valor da variavel
fclose(file);//fecha o arquivo

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);

printf("Digite o nome a ser cadastrado: ");
scanf("%s" ,nome);

file = fopen(arquivo, "a");
fprintf(file,nome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);

printf("Digite o sobrenome a ser cadrastrado: ");
scanf("%s",sobrenome);

file = fopen(arquivo, "a");
fprintf(file,sobrenome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);

printf("Digite o cargo a ser cadastrado:");
scanf("%s",cargo);

file = fopen(arquivo, "a");
fprintf(file,cargo);
fclose(file);

system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[60];
	char conteudo[400];
	
	printf("Digite o CPF a ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	if(file == NULL)
{
	printf("N�o foi encontrado o CPF solicitado tente novamente!. \n");
}
	
	 while(fgets(conteudo, 400, file) !=NULL)
{
	printf("\n Informa��es da consulta: ");
	printf("%s ", conteudo);
	printf("\n\n");
}

system("pause");
}

int deletar()
{
     char cpf[60];
     
     printf("Digite o CPF do usu�rio a ser deletado: ");
     scanf("%s",cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file ==NULL)
     {
     	printf("O usu�rio n�o encontrado no banco de dados!\n");
     	system("pause");
	 }

}
int main()

{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	 
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //responsavel pelo uso de assentos do PTBR
	    printf("<<<<<>>>>>>  Cart�rio da EBAC  <<<<<>>>>>\n\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do Menu: \n\n");
   	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n\n");
	    printf("\t4 - Deseja sair do Sistema?\n\n");
    	printf("Op��o:"); //fim do menu
	
	    scanf("%d", &opcao); //armazenamento a escolha do usuario 
	
	    system("cls");//responsavel por limpar a tela
	    
	    switch(opcao)
	    {
	   	case 1:
	    	registrar();//chamada de fun��o
	    	break;
	    		
	    case 2:
	    	
	    	consulta();
	    	break;
	    	
	    case 3:
	    	
	    	deletar();
	    	break;
	    	
	    	case 4:
	    		printf("Obrigado e volte sempre!");
	    		return 0;
	    		break;
	    	
	   	default:
	    	printf("Esta fun��o n�o est� disponivel\n");
            system("pause");
	    	break;
		}
	
	    }//fim da sele��o
	
	}
