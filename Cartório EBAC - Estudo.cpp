#include <stdio.h> // biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); 
	// inicio da cria��o de vari�veis/string
	char arquivo[11];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	// final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado\n\n"); // coletando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a string

	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, e o W significa escrever (wright)
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecho o arquivo

	file = fopen(arquivo, "a"); // incluir informa��es
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); // mais uma string
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	file = fopen(arquivo,"a");
	
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[11];
	char conteudo[150];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)	
	{
		printf("\nN�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar() // op��o 3, deletar usu�rios
{
	char cpf[40]; // criar a string CPF
	
	printf("Digite o CPF do usu�rio a ser deletado\n\n");
	scanf("%s",cpf); // scanear a string, vai salvar na string
	
	FILE *file = fopen(cpf, "r"); // Abrir o arquivo para leitura
	
	if (file == NULL) {
		printf("Usu�rio n�o encontrado no sistem!\n\n");
		system("pause");
		return 0; // Retorna ao inicio
	}
	
	fclose(file); // Fechar o arquivo depois de verificar a exist�ncia
	
	printf("Deseja realmente deletar este aluno?"); // Confirmar dele��o
	printf("CPF: %s\n", cpf);
	printf("\nDigite (s) para sim e (n) para n�o! \n\n"); 
	
	char opcao; // criando variavel op��o
	getchar(); // resposta deixada pelo scanf anterior
	opcao = getchar(); // obter resposta do usu�rio
	
 if (opcao == 's' || opcao == 'S') // Se a op��o for 's' ou 'S'
    {
        // Tenta remover o arquivo
        if (remove(cpf) == 0) {
            printf("Aluno deletado com sucesso!\n");
        } else {
            printf("Erro ao tentar deletar o arquivo.\n");
        }
    }
    else if (opcao == 'n' || opcao == 'N') {
        printf("Opera��o cancelada. Retorne ao menu principal!\n");
    }
    else {
        printf("Op��o inv�lida!\n");
    }

    system("pause");
    return 0; // Retorna 0 no final da fun��o
}

int main() // sele��o
{
	int opcao=0; //definindo as vari�veis
	int	laco=1;

	for(laco=1; laco=1;) 
	{
		
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

		printf("### Estudo Cart�rio ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Op��o:  "); //final do menu

		scanf("%d", &opcao); //armazenando a escolha do usu�rio

		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			consulta(); // chamada de fun��es
			break;
			
			case 3:
			deletar(); // chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;  

	} //fim da sele��o
}
}
