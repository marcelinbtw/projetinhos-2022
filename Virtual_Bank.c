#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

// Valor inicial do saldo da conta.
float saldo = 1000.0;
int OP;


int login() {
    printf("\n\t\t\t === Bem-Vindo ao Virtual Bank ===");
    printf("\n\t\t\t  1. Acessar conta");
    printf("\n\t\t\t  2. Criar conta");
    printf("\n\t\t\t  3. Alterar senha");
    printf("\n\t\t\t  4. Sair");
    printf("\n\t\t\t  Informe a opcao desejada: ");
    scanf("%d", &OP);
    return OP;
}

int telaBanco() {
    printf("\n\t\t\t === Virtual Bank ===");
    printf("\n\t\t\t  1. Depositar");
    printf("\n\t\t\t  2. Sacar");
    printf("\n\t\t\t  3. Extrato da conta");
    printf("\n\t\t\t  4. Informacoes da conta");
    printf("\n\t\t\t  5. Sair");
    printf("\n\t\t\t  Informe a opcao desejada: ");
    scanf("%d", &OP);
    return OP;
}

//Gerador de codigo de 6 caracteres para criar uma referência para cada transação e extrato.
int geracod() {
    {
        int tamanho;
        tamanho = 6;
        char *geracod = malloc(tamanho + 1);

        char *digits = "0123456789";
        int digits_length = strlen(digits);
        srand(time(NULL) * getpid());

        for (int i = 0; i < tamanho; i++)
            geracod[i] = digits[rand() % digits_length];

        printf("Codigo de Transacao: %s\n", geracod);
        free(geracod);
    }
    return telaBanco();
}

double sacarDinheiro(){
    double Sacar;
    printf("Informe um valor para sacar!! \n");
    scanf("%lf",&Sacar);
    if(Sacar > saldo){
        printf("Saldo Insuficiente");
    }
    else{
        printf("Sacando o Valor de %.2f da conta fulano \n", Sacar);
        printf("Sacando...\n");
        saldo -= Sacar;
        printf(geracod());
    }
}

int infosConta() {
    int resInfo;
    //printf("\t\tOlá, %c." % usuarioRes);
    //printf("\t Senha: %d" % senhaRes);
    //printf("\t Códio de Segurança: %d\n" % codigoSegRes);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n\t\t\t O que você deseja?");
    printf("\n\t\t\t  1. Alterar a senha");
    printf("\n\t\t\t  2. Retornar ao menu principal");
    printf("\n\t\t\t  3. Sair");
    scanf("%d", &resInfo);

    if (resInfo == 1) {
        //scanf("%d", &senhaRes);
    }
    else if (resInfo == 2) {
        return telaBanco;
    }
    else if (resInfo == 3) {
        return 0;
    }
    else {
        return infosConta;
    }
}


//
int main() {

    while(1){
        switch (telaBanco())
        {
            case 1:
                break;

            case 2:
                sacarDinheiro();
                break;

            case 3:
                break;

            case 4:
                infosConta();
                break;

            default:
                break;
        }
    }
}