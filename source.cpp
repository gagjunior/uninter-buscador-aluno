#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int menu();

struct Aluno
{
	char nomeAluno[61];
	char emailAluno[61];
	int ruAluno;

	struct Aluno *direita, *esquerda;
};

int main(int argc, char const *argv[])
{
	int opcao = 0;

	while (opcao != 2)
	{
		opcao = menu();
		switch (opcao)
		{
		case 1:
			printf("Digite o nome do aluno: ");
			gets_s()
			break;
		
		default:
			break;
		}
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

void Inserir(Aluno ** elementoVarredura, int ru) {
	
	if (*elementoVarredura == NULL)
	{
		Aluno *NovoAluno = NULL;
		NovoAluno = (Aluno *)malloc(sizeof(Aluno));
		NovoAluno->esquerda = NULL;
		NovoAluno->direita = NULL;

		NovoAluno->ruAluno = ru;
		*elementoVarredura = NovoAluno;
		return;
	}

	if (ru < (*elementoVarredura)->ruAluno) 
	{
		Inserir(&(*elementoVarredura)->esquerda, ru);
	}
	else 
	{
		if (ru > (*elementoVarredura)->ruAluno)
		{
			Inserir(&(*elementoVarredura)->direita, ru);
		}
	}
}
