#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <string.h>

//Estruturas de cada parte
typedef struct endereco
{
    char Rua[50];
    int Numero;
    char Bairro[50];
    char Cidade[50];
    char Estado[50];
} ENDERECO;
typedef struct voo
{
    int Identificador;
    int Aeronave;
    char Empresa[50];
    char Origem[50];
    char Destino[50];
    int DataPartida[3];
    char HorarioPartida[10];
    int QtdPassageiros;
    struct voo *Prox;
} VOO;
typedef struct passageiros
{
    int Identificador;
    char Nome[50];
    long long Identidade;
    ENDERECO Endereco;
    long long Telefone;
    char Sexo;
    struct passageiros *Prox;
} PASSAGEIROS;
typedef struct passagens
{
    int Numero;
    int IdentPass;
    int IdentVoo;
    float Valor;
    int DataVenda[3];
    struct passagens *Prox;
} PASSAGENS;


//Declaração das filas
typedef VOO *FILA_VOO;
typedef PASSAGEIROS *FILA_PASSAGEIROS;
typedef PASSAGENS *FILA_PASSAGENS;

//Iniciando as filas...
void Inic1(FILA_VOO *Fila);
void Inic2(FILA_PASSAGEIROS *Fila);
void Inic3(FILA_PASSAGENS *Fila);

//Procedimentos VOO
void InserirVoo(FILA_VOO *FilaVoo);
void ListarVoo(FILA_VOO FilaVoo);
void ApagarVoo(FILA_VOO *FilaVoo);

//Procedimentos PASSAGEIROS
void InserirPassageiros(FILA_PASSAGEIROS *FilaPassageiros);
void ListarPassageiros(FILA_PASSAGEIROS FilaPassageiros);
void ApagarPassageiros(FILA_PASSAGEIROS *Fila);

//Procedimentos PASSAGENS
void InserirPassagens(FILA_PASSAGENS* FilaPassagens);
void ListarPassagens(FILA_PASSAGENS FilaPassagens);
void ApagarPassagens(FILA_PASSAGENS *FilaPassagens);

//Programa Principal
int main ()
{
    FILA_VOO FVOO; FILA_PASSAGEIROS FPASSAGEIROS; FILA_PASSAGENS FPASSAGENS;
    Inic1(&FVOO); Inic2(&FPASSAGEIROS); Inic3(&FPASSAGENS);
    int opcao1 = 0, opcao2 = 0;

    while(opcao1 != 5 )
    {
        printf("O que deseja fazer?\n");
        printf("1 - Voos\n2 - Passagens\n3 - Passageiros\n4 - Relatorios\n5 - Sair\n");
        scanf("%d", &opcao1);

        switch(opcao1)
        {
        case (1):               //Voos

            printf("Voos - O que deseja fazer?\n");
            printf("1 - Incluir\n2 - Alterar\n3 - Excluir\n4 - Consultar\n");
            scanf("%d", &opcao2);
                switch(opcao2)
                {
                    case (1):
                        InserirVoo(&FVOO);
                        printf("Voo inserido com sucesso!\n\n");
                        break;

                    case(2):
                        break;

                    case(3):
                        ApagarVoo(&FVOO);
                         printf("Voo excluido com sucesso!\n\n");
                        break;

                    case(4):
                        printf("\n\nListando passagens:\n");
                        ListarVoo(FVOO);
                        printf("\n\n");
                        break;

                    default: printf("Opcao Invalida!\n\n");
                }
            break;

        case (2):               //Passagens

            printf("Passagens - O que deseja fazer?\n");
            printf("1 - Incluir\n2 - Alterar\n3 - Excluir\n4 - Consultar\n");
            scanf("%d", &opcao2);
            switch(opcao2)
                {
                    case (1):
                        printf("\n");
                        InserirPassagens(&FPASSAGENS);
                        printf("Passagem inserida com sucesso!\n\n");
                        break;

                    case(2):
                        break;

                    case(3):
                        ApagarPassagens(&FPASSAGENS);
                        printf("Passagem excluida com sucesso!\n\n");
                        break;

                    case(4):
                        printf("\n\nListando Passagens:\n");
                        ListarPassagens(FPASSAGENS);
                        break;

                    default: printf("Opcao Invalida!\n\n");
                }
            break;

        case (3):               //Passageiros

            printf("Passageiros - O que deseja fazer?\n");
            printf("1 - Incluir\n2 - Alterar\n3 - Excluir\n4 - Consultar\n");
            scanf("%d", &opcao2);
            switch(opcao2)
                {
                    case (1):
                        printf("\n");
                        InserirPassageiros(&FPASSAGEIROS);
                        printf("Passageiro inserido com sucesso!\n\n");
                        break;

                    case(2):
                        break;

                    case(3):
                        ApagarPassageiros(&FPASSAGEIROS);
                         printf("Passageiro excluido com sucesso!\n\n");
                        break;

                    case(4):
                        printf("\n\nListando passageiros:\n");
                        ListarPassageiros(FPASSAGEIROS);
                        break;

                    default: printf("Opcao Invalida!\n\n");
                }
            break;

        case (4):               //Relatórios

            printf("Relatorios - O que deseja fazer?\n");
            printf("1 - Ver quantidade de passagens vendidas por voo\n2 - Ver quantidade de voos por empresa\n3 - Ver lista de passageiros por voo\n");
            scanf("%d", &opcao2);
            break;

        case  (5):              //Sair

            break;

        default: printf("Opcao Invalida!\n\n");

        }
    }
return 0;
}


//Iniciando as filas...
void Inic1(FILA_VOO *FilaVoo)
{
    *FilaVoo = NULL;
}
void Inic2(FILA_PASSAGEIROS *FilaPassageiros)
{
    *FilaPassageiros = NULL;
}
void Inic3(FILA_PASSAGENS *FilaPassagens)
{
    *FilaPassagens = NULL;
}

//Procedimentos VOO
void InserirVoo(FILA_VOO *FilaVoo)
{
    int Identificador, Aeronave, DataPartida[3], QtdPassageiros;
    char Empresa[50], Origem[30], Destino[30], HorarioPartida[10];
    if(*FilaVoo==NULL){
        *FilaVoo = (FILA_VOO) malloc(sizeof(VOO));
        if(*FilaVoo == NULL) return;
        //Lendo os valores do usuário
        printf("Insira o Identificador do Voo: "); scanf("%d", &Identificador);
        printf("Insira a Aeronave: "); scanf("%d", &Aeronave);
        printf("Insira a Empresa do Voo: "); scanf(" %[^\n]", &Empresa);
        printf("Insira a Origem do Voo: "); scanf(" %[^\n]", &Origem);
        printf("Insira o Destino do Voo: "); scanf(" %[^\n]", &Destino);
        printf("Insira a Data de Partida(dia): "); scanf("%d", &DataPartida[0]);
        printf("Insira a Data de Partida(mes): "); scanf("%d", &DataPartida[1]);
        printf("Insira a Data de Partida(ano): "); scanf("%d", &DataPartida[2]);
        printf("Insira o Horario de partida: "); scanf(" %[^\n]", HorarioPartida);
        printf("Insira a quantidade de passageiros do voo: "); scanf("%d", &QtdPassageiros);

        //Enviando valores inseridos
        (*FilaVoo)->Aeronave = Aeronave;
        strcpy((*FilaVoo)->Empresa, Empresa);
        strcpy((*FilaVoo)->Origem, Origem);
        strcpy((*FilaVoo)->Destino, Destino);
        memcpy((*FilaVoo)->DataPartida, DataPartida, 3 * sizeof(int));
        strcpy((*FilaVoo)->HorarioPartida, HorarioPartida);
        (*FilaVoo)->QtdPassageiros = QtdPassageiros;

        (**FilaVoo).Prox = NULL;
    }
    else
        InserirVoo(& (**FilaVoo).Prox);
}
void ListarVoo(FILA_VOO FilaVoo)
{
    if (FilaVoo == NULL) return;
    printf("Identificador do Voo: %d\nAeronave: %d\nEmpresa: %s\nOrigem: %s\nDestino: %s\nDataPartida: %d %d %d\nHorarioPartida: %s\nQtdPassageiros: %d\n", FilaVoo->Identificador, FilaVoo->Aeronave, FilaVoo->Empresa, FilaVoo->Origem, FilaVoo->Destino, FilaVoo->DataPartida[0], FilaVoo->DataPartida[1], FilaVoo->DataPartida[2], FilaVoo->HorarioPartida, FilaVoo-> QtdPassageiros);
    ListarVoo(FilaVoo->Prox);
}
void ApagarVoo(FILA_VOO *FilaVoo)
{
    VOO *Tmp = *FilaVoo;
    if (*FilaVoo == NULL) return;
    *FilaVoo = (*FilaVoo)->Prox;
    free(Tmp);
}


//Procedimentos Passageiros
void InserirPassageiros(FILA_PASSAGEIROS *FilaPassageiros)
{
    int Identificador;
    char Nome[50], Sexo;
    long long Identidade, Telefone;
    ENDERECO Endereco;

    if(*FilaPassageiros == NULL){
        *FilaPassageiros = (FILA_PASSAGEIROS) malloc (sizeof(PASSAGEIROS));
        if(*FilaPassageiros == NULL) return;

        //Lendo os valores do usuário
        printf("Insira o Identificador do Passageiro: "); scanf("%d", &Identificador);
        printf("Insira o Nome do Passageiro: "); scanf(" %[^\n]", &Nome);
        printf("Insira a Identidade do Passageiro: "); scanf("%d", &Identidade);
        printf("Insira o Endereço do Passageiro:\n  Rua:"); scanf(" %[^\n]", Endereco.Rua);
        printf("    Numero:"); scanf(" %d", Endereco.Numero);
        printf("    Bairo:"); scanf(" %[^\n]", Endereco.Bairro);
        printf("    Cidade:"); scanf(" %[^\n]", Endereco.Cidade);
        printf("    Estado:"); scanf(" %[^\n]", Endereco.Estado);

        //Enviando valores inseridos
        (*FilaPassageiros)->Identificador = Identificador;
        (*FilaPassageiros)->Identidade = Identidade;
        strcpy((*FilaPassageiros)->Endereco.Rua, Endereco.Rua);
        (*FilaPassageiros)->Endereco.Numero = Endereco.Numero;
        strcpy((*FilaPassageiros)->Endereco.Bairro, Endereco.Bairro);
        strcpy((*FilaPassageiros)->Endereco.Cidade, Endereco.Cidade);
        strcpy((*FilaPassageiros)->Endereco.Estado, Endereco.Estado);
        strcpy((*FilaPassageiros)->Nome, Nome);
        ((*FilaPassageiros)->Telefone) = Telefone;
        ((*FilaPassageiros)->Sexo) = Sexo;

        (**FilaPassageiros).Prox = NULL;
    }
    else
        InserirPassageiros(&(**FilaPassageiros));
}
void ListarPassageiros(FILA_PASSAGEIROS FilaPassageiros)
{
    if (FilaPassageiros == NULL) return;
    printf("Identificador: %d\nNome: %s\nIdentidade: %lld\nEndereco: %s\nTelefone: %lld\nSexo: %c\n", FilaPassageiros->Identificador, FilaPassageiros->Nome, FilaPassageiros->Identidade, FilaPassageiros->Endereco, FilaPassageiros->Telefone, FilaPassageiros->Sexo);
    ListarPassageiros(FilaPassageiros->Prox);
}
void ApagarPassageiros(FILA_PASSAGEIROS *FilaPassageiros)
{
    PASSAGEIROS *Tmp = *FilaPassageiros;
    if (*FilaPassageiros == NULL) return;
    *FilaPassageiros = (*FilaPassageiros)->Prox;
    free(Tmp);
}

//Procedimentos Passagens
void InserirPassagens(FILA_PASSAGENS* FilaPassagens)
{
    int Numero, IdentPass, IdentVoo, DataVenda[3];
    float Valor;
    if(FilaPassagens == NULL){
        *FilaPassagens = (FILA_PASSAGENS) malloc(sizeof(PASSAGENS));
        if(FilaPassagens == NULL) return;

        //Lendo os valores do usuário
        printf("Insira o Numero: "); scanf("%d", &Numero);
        printf("Insira o Identificador do Passageiro: "); scanf("%d", &IdentPass);
        printf("Insira o Identificador do Voo: "); scanf("%d", &IdentVoo);
        printf("Insira a Data da Venda(dia): "); scanf("%d", DataVenda[0]);
        printf("Insira a Data da Venda(mes): "); scanf("%d", DataVenda[1]);
        printf("Insira a Data da Venda(ano): "); scanf("%d", DataVenda[2]);
        printf("Insira o Valor: "); scanf("%f", &Valor);

        //Enviando valores inseridos
        (*FilaPassagens)->Numero = Numero;
        (*FilaPassagens)->IdentPass = IdentPass;
        (*FilaPassagens)->IdentVoo = IdentVoo;
        (*FilaPassagens)->Valor = Valor;
        memcpy((*FilaPassagens)->DataVenda, DataVenda, 3 * sizeof(int));

        (**FilaPassagens).Prox = NULL;
    }
    else
        InserirPassagens(&(**FilaPassagens).Prox);
}
void ListarPassagens(FILA_PASSAGENS FilaPassagens)
{
    if (FilaPassagens == NULL) return;
    printf("Numero:%d\nIdentificador da Passagem:%d\nIdentificador do Voo:%dValor:R$%.2f\nData de Venda:%d %d %d\n", FilaPassagens->Numero, FilaPassagens->IdentPass, FilaPassagens->IdentVoo, FilaPassagens->Valor, FilaPassagens->DataVenda[0], FilaPassagens->DataVenda[1], FilaPassagens->DataVenda[2]);
    ListarPassagens(FilaPassagens->Prox);
}
void ApagarPassagens(FILA_PASSAGENS *FilaPassagens)
{
    PASSAGENS *Tmp = *FilaPassagens;
    if (*FilaPassagens == NULL) return;
    *FilaPassagens = (*FilaPassagens)->Prox;
    free(Tmp);
}



