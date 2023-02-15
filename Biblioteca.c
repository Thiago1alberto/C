#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 10000

struct book {
    char titulo[100];
    char autor[100];
    int ano;
    int available;
};

struct book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("A biblioteca já está cheia.\n");
        return;
    }

    struct book new_book;

    printf("Digite o título do livro: ");
    scanf("%s", new_book.titulo);

    printf("Digite o autor do livro: ");
    scanf("%s", new_book.autor);

    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &new_book.ano);

    new_book.available = 1;

    library[num_books] = new_book;
    num_books++;

    printf("O livro foi adicionado à biblioteca.\n");
}

void search_book() {
    char titulo[100];
    printf("Digite o título do livro que você está procurando: ");
    scanf("%s", titulo);

    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].titulo, titulo) == 0) {
            printf("O livro %s foi encontrado.\n", titulo);
            printf("Autor: %s\n", library[i].autor);
            printf("Ano: %d\n", library[i].ano);
            if (library[i].available) {
                printf("Este livro está disponível para empréstimo.\n");
            } else {
                printf("Este livro não está disponível para empréstimo.\n");
            }
            return;
        }
    }

    printf("O livro %s não foi encontrado.\n", titulo);
}

void show_all_books() {
    if (num_books == 0) {
        printf("A biblioteca está vazia.\n");
        return;
    }

    printf("Lista de livros na biblioteca:\n");

    int i;
    for (i = 0; i < num_books; i++) {
        printf("%d. %s, por %s (%d)\n", i+1, library[i].titulo, library[i].autor, library[i].ano);
        if (library[i].available) {
            printf("   Disponível para empréstimo\n");
        } else {
            printf("   Não disponível para empréstimo\n");
        }
    }
}

int main() {
    int option;

    do {
        printf("\n");
        printf("Bem-vindo ao sistema de biblioteca.\n");
        printf("1. Adicionar livro\n");
        printf("2. Pesquisar livro\n");
        printf("3. Exibir todos os livros\n");
        printf("0. Sair\n");

        scanf("%d", &option);

        switch (option) {
            case 0:
                printf("Obrigado por usar o sistema de biblioteca.\n");
                break;
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                show_all_books();
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 0);

    return 0;
}
