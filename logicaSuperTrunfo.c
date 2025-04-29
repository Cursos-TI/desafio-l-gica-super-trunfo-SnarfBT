#include <stdio.h>

// Desafio Super Trunfo - Cidades
// Cadastro, cálculo e comparação das cartas

int main() {
    // Carta 1
    char estado1[10];
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // Carta 2
    char estado2[10];
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // Entrada dos dados da Carta 1
    printf("Cadastro da Carta 1\n");

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado1);

    printf("Digite o código da carta: ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a população da cidade: ");
    scanf("%d", &populacao1);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade em bilhões de reais: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da carta 1
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // Entrada dos dados da Carta 2
    printf("\nCadastro da Carta 2\n");

    printf("Digite o estado: ");
    scanf(" %[^\n]", estado2);

    printf("Digite o código da carta: ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a população da cidade: ");
    scanf("%d", &populacao2);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade em bilhões de reais: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da carta 2
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    // Exibição dos dados da carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.3f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional1);
    printf("PIB per Capita: R$ %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    // Exibição dos dados da carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.3f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional2);
    printf("PIB per Capita: R$ %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparação de Cartas
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidadePopulacional1 < densidadePopulacional2); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    // Menu interativo para comparação de atributos
    int escolha;

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1 a 5): ");
    scanf("%d", &escolha);

    printf("\nResultado da Comparação:\n");

    switch (escolha) {
        case 1: // População
            printf("População:\n");
            printf("%s: %lu\n", nomeCidade1, populacao1);
            printf("%s: %lu\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Carta 1 venceu!\n");
            else if (populacao2 > populacao1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Área:\n");
            printf("%s: %.3f km²\n", nomeCidade1, area1);
            printf("%s: %.3f km²\n", nomeCidade2, area2);
            if (area1 > area2)
                printf("Carta 1 venceu!\n");
            else if (area2 > area1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("PIB:\n");
            printf("%s: %.2f bilhões de reais\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões de reais\n", nomeCidade2, pib2);
            if (pib1 > pib2)
                printf("Carta 1 venceu!\n");
            else if (pib2 > pib1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("Número de Pontos Turísticos:\n");
            printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Carta 1 venceu!\n");
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade Demográfica (regra invertida: menor vence)
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            if (densidadePopulacional1 < densidadePopulacional2)
                printf("Carta 1 venceu!\n");
            else if (densidadePopulacional2 < densidadePopulacional1)
                printf("Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente com um número de 1 a 5.\n");
            break;
    }

    return 0;
}
