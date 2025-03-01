#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Lógica do jogo

//declaraçao da struct com as propriedades das cartas
typedef struct carta {
    char codigo[4];
    char estado[25];
    char cidade[25];
    unsigned int populacao;
    float area;
    double pib;
    int qtdePontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

float calcularDensidadePopulacional(unsigned int pop, float area){
    return (float) pop / area;
}

float calcularPibPerCapita(double pib, unsigned int pop){
    return (float) pib / pop;
}

//solicita e armazena os dados
Carta cadastrarCarta(Carta carta){
    printf("\nInforme o código (Formato A01): ");
    scanf(" %[^\n]", carta.codigo); 
    printf("Informe o Estado: ");
    scanf(" %[^\n]", carta.estado); //lê caracteres enquanto nao forem quebra de linha
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta.cidade);
    printf("Informe o número da população: ");
    scanf(" %u", &carta.populacao);
    printf("Informe a área em km²: ");
    scanf(" %f", &carta.area);
    printf("Informe o PIB: ");
    scanf(" %lf", &carta.pib);
    printf("Informe a quantidade de pontos turísticos: ");
    scanf(" %d", &carta.qtdePontosTuristicos);
    carta.densidadePopulacional = calcularDensidadePopulacional(carta.populacao, carta.area);
    carta.pibPerCapita = calcularPibPerCapita(carta.pib, carta.populacao);

    return carta;
}

// Exibição dos Dados das Cartas
void exibirCarta(Carta carta){
    //valida se dado da carta foi preenchido
    if(carta.estado[0] == '\0'){
        printf("\nCarta não cadastrada.\n");
        return;
    }

    printf("\n------------------------------------------------\n");
    printf("Código: %s\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Nome: %s\n", carta.cidade);
    printf("População: %u\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2lf\n", carta.pib);
    printf("Quantidade de pontos turísticos: %d\n", carta.qtdePontosTuristicos);
    printf("Densidade Populacional: %.2f pessoas/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
    printf("------------------------------------------------\n");
}

void exibirCarta1(Carta carta1){
    printf("\nCarta 1: Código: %s", carta1.codigo);
    printf(" - Estado: %s", carta1.estado);
    printf(" - Cidade: %s", carta1.cidade);
}

void exibirCarta2(Carta carta2){
    printf("\nCarta 2: Código: %s", carta2.codigo);
    printf(" - Estado: %s", carta2.estado);
    printf(" - Cidade: %s", carta2.cidade);
}

void exibirResultado(double pop1, double pop2){
    //comparaçao da propriedade selecionada entre as duas cartas
    if(pop1 > pop2){
        printf("\n\n*************  Resultado: Carta 1 venceu!  **************\n");
    }
    if(pop1 < pop2){
        printf("\n\n*************  Resultado: Carta 2 venceu!  **************\n");
    }
    if(pop1 == pop2){
        printf("\n\n*********  Resultado: As duas cartas empataram!  ********\n");
    }
    printf("\n");
}

void compararCartas(Carta carta1, Carta carta2){
    char opcao = '\0';

    //laço para menu de seleçao da propriedade
    do{
        printf("\nSelecione a propriedade que deseja comparar ou digite 0 \npara voltar ao menu anterior: ");
        printf("\na. População\nb. Área\nc. PIB\nd. Número de pontos turísticos\ne. Densidade populacional\nf. PIB per capita");
        printf("\nOpção: ");
        scanf(" %c", &opcao);
    
        //executa conforme opçao de propriedade escolhida
        switch(opcao){
            case 'a':
                printf("\n\nComparando a população das cidades... \n");
                exibirCarta1(carta1);
                printf(" - População: %u", carta1.populacao);
                exibirCarta2(carta2);
                printf(" - População: %u", carta2.populacao);

                //chama metodo que compara as propriedades e exibe o resultado
                exibirResultado(carta1.populacao, carta2.populacao);

                break;
            case 'b':
                printf("\n\nComparando a área das cidades... \n");
                exibirCarta1(carta1);
                printf(" - Área: %.2f", carta1.area);
                printf(" km²");
                exibirCarta2(carta2);
                printf(" - Área: %.2f", carta2.area);
                printf(" km²");

                //chama metodo que compara as propriedades e exibe o resultado
                exibirResultado(carta1.area, carta2.area);

                break;
            case 'c':
                printf("\n\nComparando o PIB das cidades... \n");
                exibirCarta1(carta1);
                printf(" - PIB: R$ %.2lf", carta1.pib);
                exibirCarta2(carta2);
                printf(" - PIB: R$ %.2lf", carta2.pib);

                //chama metodo que compara as propriedades e exibe o resultado
                exibirResultado(carta1.pib, carta2.pib);

                break;  
            case 'd':
                printf("\n\nComparando o número de pontos turísticos das cidades... \n");
                exibirCarta1(carta1);
                printf(" - Número de pontos turísticos: %d", carta1.qtdePontosTuristicos);
                exibirCarta2(carta2);
                printf(" - Número de pontos turísticos: %d", carta2.qtdePontosTuristicos);
            
                //chama metodo que compara as propriedades e exibe o resultado
                exibirResultado(carta1.qtdePontosTuristicos, carta2.qtdePontosTuristicos);

                break;
            case 'e':
                printf("\n\nComparando a densidade populacional das cidades... \n");
                exibirCarta1(carta1);
                printf(" - Densidade populacional: %.2f", carta1.densidadePopulacional);
                printf(" hab/km²");
                exibirCarta2(carta2);
                printf(" - Densidade populacional: %.2f", carta2.densidadePopulacional);
                printf(" hab/km²");

                //chama metodo que compara as propriedades e exibe o resultado
                exibirResultado(carta2.densidadePopulacional, carta1.densidadePopulacional);

                break;
            case 'f':
                printf("\n\nComparando o PIB per capita das cidades... \n");
                exibirCarta1(carta1);
                printf(" - PIB per capita: R$ %.2f", carta1.pibPerCapita);
                exibirCarta2(carta2);
                printf(" - PIB per capita: R$ %.2f", carta2.pibPerCapita);

                //chama metodo que compara as propriedades e exibe o resultado
                exibirResultado(carta1.pibPerCapita, carta2.pibPerCapita);

                break;
            case '0':
                printf("\nVoltando ao menu anterior...\n");

                break;
            default:
                printf("\n\nOpção inválida.\n");
        }
    } while (opcao != '0');
}

int main(void) {
    char opc = '\0';
    Carta carta1 = {0};
    Carta carta2 = {0};

    //cadastra as cartas iniciais
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.estado, "Paraná");
    strcpy(carta1.cidade, "Cascavel");
    carta1.populacao = 320000;
    carta1.area = 140;
    carta1.pib = 1100200300;
    carta1.qtdePontosTuristicos = 12;
    carta1.densidadePopulacional = calcularDensidadePopulacional(320000, 140);
    carta1.pibPerCapita = calcularPibPerCapita(1100200300, 320000);

    strcpy(carta2.codigo, "A02");
    strcpy(carta2.estado, "Paraná");
    strcpy(carta2.cidade, "Toledo");
    carta2.populacao = 150000;
    carta2.area = 120;
    carta2.pib = 1200300400;
    carta2.qtdePontosTuristicos = 10;
    carta2.densidadePopulacional = calcularDensidadePopulacional(150000, 120);
    carta2.pibPerCapita = calcularPibPerCapita(1200300400, 150000);

    printf("\n***********************************************************");
    printf("\n                Bem vindo ao Super Trunfo!                 ");

    //laço para menu principal
    do{
        printf("\n***********************************************************\n");
        printf("\nSelecione uma opção: \n1. Cadastrar cartas\n2. Jogar\n3. Sair");
        printf("\nOpção: ");
        scanf(" %c", &opc);

        switch (opc)
        {
            case '1':
                printf("\n***********************************************************");
                printf("\n                    Cadastro das cartas                    \n");

                //chama o metodo para cadastrar a carta 1
                carta1 = cadastrarCarta(carta1);
                //exibe os dados da carta 1
                printf("\n\nCarta 1: ");
                exibirCarta(carta1);
                        
                //chama o metodo para cadastrar a carta 2
                carta2 = cadastrarCarta(carta2);
                //exibe os dados da carta 2
                printf("\n\nCarta 2: ");
                exibirCarta(carta2);

                printf("\nVoltando ao menu anterior...\n");

                break;

            case '2':
                printf("\n***********************************************************");
                printf("\n                   Vamos iniciar o jogo!                   \n");

                //solicita propriedade, compara as cartas e exibe o resultado
                compararCartas(carta1, carta2);

                break;

            case '3':
                printf("\nEncerrando o jogo...\n\n");

                break;

            default:
                printf("\nOpção inválida.\n");

                break;
        }
    } while(opc != '3');

    return 0;
}
