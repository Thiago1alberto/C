#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"");
    int length, i;
    char password[20];

    // define a semente do gerador de números aleatórios
    srand(time(NULL)); //inicializa a sequência de números aleatórios

    printf("Digite o comprimento da senha (no máximo 20 caracteres): ");
    scanf("%d", &length);

    for (i = 0; i < length; i++) {
        int type = rand() % 3;
        if (type == 0) {
            password[i] = 'a' + rand() % 26;
        } else if (type == 1) {

            password[i] = 'A' + rand() % 26;
        } else {
            password[i] = '0' + rand() % 10;
        }
    }
    password[length] = '\0';
    printf("A senha gerada é: %s\n", password);
    return 0;
}
