#include <stdlib.h>
#include <stdio.h>

// Define a estrutura de dado Aluno
struct Aluno
{
	char *nomeAluno;
	char *emailAluno;
	int ruAluno;

	struct Aluno *direita, *esquerda;
};

// Declaração das funções
int menu();
void consultaOrdenada(Aluno *ElementoVarredura);
void inserir(Aluno **elementoVarredura, char nomeAluno[61], char emailAluno[61], int ru);
Aluno *buscar(Aluno **ElementoVarredura, int ru);

int main(int argc, char const *argv[])
{
	int opcao = 0, ru, c; // variaveis auxiliares

	// Declara e armazena memoria para a lista de alunos (Arvore Binária)
	Aluno *root;
	root = (Aluno *)malloc(sizeof(Aluno));
	root = NULL;

	// Declara e armazena memoria para o aluno procurado
	Aluno *alunoProcurado;
	alunoProcurado = (Aluno *)malloc(sizeof(Aluno));

	// Faz a inserção diretamente no código dos alunos
	inserir(&root, "Gilberto Junior", "gagjunior@hotmail.com", 143586);
	inserir(&root, "Pamela Vieira", "pamela@hotmail.com", 123456);
	inserir(&root, "Andre Luis", "andre@hotmail.com", 987850);
	inserir(&root, "Paulo Andrade", "paulo@hotmail.com", 784567);
	inserir(&root, "Carlos Augusto", "carlos@hotmail.com", 125437);
	inserir(&root, "Gilmar Santos", "gilmar@hotmail.com", 5678);
	inserir(&root, "Tiago Casturino", "tiago@hotmail.com", 3472);
	inserir(&root, "Murilo Gomes", "murilo@hotmail.com", 223344);
	inserir(&root, "Guilherme Junior", "guilherme@hotmail.com", 338765);
	inserir(&root, "Jeferson Jorge", "jeferson@hotmail.com", 980675);
	inserir(&root, "Elquias Jorge", "elquias@hotmail.com", 101010);

	// Loop para ficar exibindo o menu
	// Só é encerrado caso a opção seja igual a 3 - Sair
	while (opcao != 3)
	{
		opcao = menu(); // executa a função menu e passa o valor para variavel auxiliar
		switch (opcao)
		{
		case 1: // buscar aluno
			printf("Digite o numero do RU para buscar: ");
			scanf_s("%d", &ru);
			while ((c = getchar()) != '\n' && c != EOF)
			{
			}
			alunoProcurado = buscar(&root, ru);
			if (alunoProcurado != NULL)
			{
				printf_s("\nAluno encontrado! - Nome: %s, E-mail: %s, RU: %d\n",
						 alunoProcurado->nomeAluno, alunoProcurado->emailAluno, alunoProcurado->ruAluno);
			}
			else
			{
				printf_s("\nRU nao localizado. Aluno nao cadastrado ou RU digitado incorretamente...\n");
			}

			break;
		case 2: //listar os alunos cadastrados
			consultaOrdenada(root);
		default:
			break;
		}
	}

	return 0;
}

//Função para exibição do menu
int menu()
{
	int c, opcao;

	// Titulo da aplicação
	printf("\nBuscador de Aluno\n");
	// Opções do menu
	printf("1 - Buscar Aluno\n");
	printf("2 - Listar\n");
	printf("3 - Sair\n\n");

	// Solicita a opção
	printf("Digite o numero da opcao desejada: ");
	scanf("%d", &opcao);
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
	printf("\n");

	return opcao;
}

//Função para inserir o aluno
void inserir(Aluno **elementoVarredura, char nomeAluno[61], char emailAluno[61], int ru)
{
	//Verifica se a lista de alunos (Arvore Binária) está vazia
	//Se sim salva os dados do aluno
	if (*elementoVarredura == NULL)
	{
		Aluno *NovoAluno = NULL;
		NovoAluno = (Aluno *)malloc(sizeof(Aluno));
		NovoAluno->esquerda = NULL;
		NovoAluno->direita = NULL;

		NovoAluno->nomeAluno = nomeAluno;
		NovoAluno->emailAluno = emailAluno;
		NovoAluno->ruAluno = ru;

		*elementoVarredura = NovoAluno;
		return;
	}

	//Se não está vazia inicia as verificações para saber qual lado inserir o aluno
	//Se RU menor insere na esquerda
	if (ru < (*elementoVarredura)->ruAluno)
	{
		inserir(&(*elementoVarredura)->esquerda, nomeAluno, emailAluno, ru);
	}
	else
	{
		//Se RU maior insere na direita
		if (ru > (*elementoVarredura)->ruAluno)
		{
			inserir(&(*elementoVarredura)->direita, nomeAluno, emailAluno, ru);
		}
	}
}

//Função para listar os alunos
//Não solicitado no exercicio porem implementado para uma melhor visualização
//Função recursiva que lista todos os alunos da esquerda para direita
void consultaOrdenada(Aluno *ElementoVarredura)
{
	if (ElementoVarredura)
	{
		consultaOrdenada(ElementoVarredura->esquerda);
		printf("Nome: %s, E-mail: %s, RU: %d\n",
			   ElementoVarredura->nomeAluno, ElementoVarredura->emailAluno, ElementoVarredura->ruAluno);
		consultaOrdenada(ElementoVarredura->direita);
	}
}

//Função para buscar aluno
Aluno *buscar(Aluno **ElementoVarredura, int ru)
{
	//Verifica se a lista (Arvore) está vazia e retorna nulo
	if (*ElementoVarredura == NULL)
		return NULL;

	//Verifica se o RU procurado é menor
	//Inicia a busca pela esquerda
	if (ru < (*ElementoVarredura)->ruAluno)
	{
		buscar(&((*ElementoVarredura)->esquerda), ru);
	}
	else
	{
		//Se RU maior busca pela direita e retorna o aluno
		if (ru > (*ElementoVarredura)->ruAluno)
		{
			buscar(&((*ElementoVarredura)->direita), ru);
		}
		else
		{
			if (ru == (*ElementoVarredura)->ruAluno)
				return *ElementoVarredura;
		}
	}
}
