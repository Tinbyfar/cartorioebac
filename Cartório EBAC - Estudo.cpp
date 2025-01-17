#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); 
	// inicio da criação de variáveis/string
	char arquivo[11];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	// final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado\n\n"); // coletando as informações do usuário
	scanf("%s", cpf); // %s refere-se a string

	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, e o W significa escrever (wright)
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecho o arquivo

	file = fopen(arquivo, "a"); // incluir informações
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
		printf("\nNão localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar() // opção 3, deletar usuários
{
	char cpf[40]; // criar a string CPF
	
	printf("Digite o CPF do usuário a ser deletado\n\n");
	scanf("%s",cpf); // scanear a string, vai salvar na string
	
	FILE *file = fopen(cpf, "r"); // Abrir o arquivo para leitura
	
	if (file == NULL) {
		printf("Usuário não encontrado no sistem!\n\n");
		system("pause");
		return 0; // Retorna ao inicio
	}
	
	fclose(file); // Fechar o arquivo depois de verificar a existência
	
	printf("Deseja realmente deletar este aluno?"); // Confirmar deleção
	printf("CPF: %s\n", cpf);
	printf("\nDigite (s) para sim e (n) para não! \n\n"); 
	
	char opcao; // criando variavel opção
	getchar(); // resposta deixada pelo scanf anterior
	opcao = getchar(); // obter resposta do usuário
	
 if (opcao == 's' || opcao == 'S') // Se a opção for 's' ou 'S'
    {
        // Tenta remover o arquivo
        if (remove(cpf) == 0) {
            printf("Aluno deletado com sucesso!\n");
        } else {
            printf("Erro ao tentar deletar o arquivo.\n");
        }
    }
    else if (opcao == 'n' || opcao == 'N') {
        printf("Operação cancelada. Retorne ao menu principal!\n");
    }
    else {
        printf("Opção inválida!\n");
    }

    system("pause");
    return 0; // Retorna 0 no final da função
}

int main() // seleção
{
	int opcao=0; //definindo as variáveis
	int	laco=1;

	for(laco=1; laco=1;) 
	{
		
		system("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

		printf("### Estudo Cartório ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do Menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Opção:  "); //final do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário

		system("cls"); // responsável por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta(); // chamada de funções
			break;
			
			case 3:
			deletar(); // chamada de funções
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;  

	} //fim da seleção
}
}
