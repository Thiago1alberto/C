#include <stdio.h>
#include <locale.h>

struct Operands {
    double num1;
    double num2;
};

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    setlocale(LC_ALL,"");
    if (b == 0) {
        printf("Erro: divisão por zero não é permitida.\n");
        return 0;
    } else {
        return a / b;
    }
}

int main() {
    setlocale(LC_ALL,"");
    int option;
    struct Operands ops;

    while (1) {
        printf("\nCALCULADORA\n");
        printf("Escolha a operação:\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");

        scanf("%d", &option);

        if (option == 5) {
            printf("Encerrando a calculadora.\n");
            break;
        }

        printf("Digite o primeiro número: ");
        scanf("%lf", &ops.num1);

        printf("Digite o segundo número: ");
        scanf("%lf", &ops.num2);

        double result = 0;
        switch (option) {
            case 1:
                result = addition(ops.num1, ops.num2);
                break;
            case 2:
                result = subtraction(ops.num1, ops.num2);
                break;
            case 3:
                result = multiplication(ops.num1, ops.num2);
                break;
            case 4:
                result = division(ops.num1, ops.num2);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                continue;
        }

        printf("Resultado: %.2lf\n", result);
    }

    return 0;
}
