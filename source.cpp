#include<stdlib.h>
#include<stdio.h>

int menu();

struct Aluno
{
    char nomeAluno[61];
    char emailAluno[61];
    int ruAluno;
};


int main(int argc, char const *argv[])
{
    int opcao = 0;

    while (opcao != 2)
    {
        opcao = menu();
    }
    
    
    return 0;
}

int menu()
{
	int c, opcao;

	// Titulo da aplicação
	printf("\nBuscador de Aluno\n");
	// Opções do menu
	printf("1 - Buscar Aluno\n");
	printf("2 - Sair\n\n");
	
	// Solicita a opção
	printf("Digite o numero da opcao desejada: ");
	scanf("%d", &opcao);
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
	printf("\n");

	return opcao;
}
