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
    scanf("%lu", &populacao1);

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
    scanf("%lu", &populacao2);

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

    // Exibição das cartas
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

    // Menu interativo simples
    int escolha;

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1 a 5): ");
    scanf("%d", &escolha);

    printf("\nResultado da Comparação:\n");

    switch (escolha) {
        case 1:
            printf("População:\n%s: %lu\n%s: %lu\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
            printf("%s venceu!\n", (populacao1 > populacao2) ? "Carta 1" : (populacao2 > populacao1) ? "Carta 2" : "Empate");
            break;
        case 2:
            printf("Área:\n%s: %.3f km²\n%s: %.3f km²\n", nomeCidade1, area1, nomeCidade2, area2);
            printf("%s venceu!\n", (area1 > area2) ? "Carta 1" : (area2 > area1) ? "Carta 2" : "Empate");
            break;
        case 3:
            printf("PIB:\n%s: %.2f\n%s: %.2f\n", nomeCidade1, pib1, nomeCidade2, pib2);
            printf("%s venceu!\n", (pib1 > pib2) ? "Carta 1" : (pib2 > pib1) ? "Carta 2" : "Empate");
            break;
        case 4:
            printf("Pontos Turísticos:\n%s: %d\n%s: %d\n", nomeCidade1, pontosTuristicos1, nomeCidade2, pontosTuristicos2);
            printf("%s venceu!\n", (pontosTuristicos1 > pontosTuristicos2) ? "Carta 1" : (pontosTuristicos2 > pontosTuristicos1) ? "Carta 2" : "Empate");
            break;
        case 5:
            printf("Densidade Demográfica:\n%s: %.2f\n%s: %.2f\n", nomeCidade1, densidadePopulacional1, nomeCidade2, densidadePopulacional2);
            printf("%s venceu!\n", (densidadePopulacional1 < densidadePopulacional2) ? "Carta 1" : (densidadePopulacional2 < densidadePopulacional1) ? "Carta 2" : "Empate");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    // --- DESAFIO FINAL ---
    int atributo1 = 0, atributo2 = 0;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    printf("\n--- Desafio Final: Comparação com Dois Atributos ---\n");
    printf("Escolha o PRIMEIRO atributo:\n1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\nEscolha: ");
    scanf("%d", &atributo1);

    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == atributo1) continue;
        switch(i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Escolha: ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5) {
        printf("Atributos inválidos ou repetidos.\n");
        return 1;
    }

    // Função auxiliar simulada
    float extrairValor(int atr, int carta) {
        switch(atr) {
            case 1: return carta == 1 ? populacao1 : populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? pontosTuristicos1 : pontosTuristicos2;
            case 5: return carta == 1 ? densidadePopulacional1 : densidadePopulacional2;
            default: return 0;
        }
    }

    valor1_carta1 = extrairValor(atributo1, 1);
    valor1_carta2 = extrairValor(atributo1, 2);
    valor2_carta1 = extrairValor(atributo2, 1);
    valor2_carta2 = extrairValor(atributo2, 2);

    char *nomes[6] = {"", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"};

    printf("\nComparação:\n%s:\n%s: %.2f | %s: %.2f\n", nomes[atributo1], nomeCidade1, valor1_carta1, nomeCidade2, valor1_carta2);
    printf("%s:\n%s: %.2f | %s: %.2f\n", nomes[atributo2], nomeCidade1, valor2_carta1, nomeCidade2, valor2_carta2);

    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    // Lógica de vitória por atributo
    int vitorias1 = 0, vitorias2 = 0;

    if (atributo1 == 5)
        valor1_carta1 < valor1_carta2 ? vitorias1++ : (valor1_carta2 < valor1_carta1 ? vitorias2++ : 0);
    else
        valor1_carta1 > valor1_carta2 ? vitorias1++ : (valor1_carta2 > valor1_carta1 ? vitorias2++ : 0);

    if (atributo2 == 5)
        valor2_carta1 < valor2_carta2 ? vitorias1++ : (valor2_carta2 < valor2_carta1 ? vitorias2++ : 0);
    else
        valor2_carta1 > valor2_carta2 ? vitorias1++ : (valor2_carta2 > valor2_carta1 ? vitorias2++ : 0);

    printf("\nSoma dos atributos:\n%s: %.2f\n%s: %.2f\n", nomeCidade1, soma1, nomeCidade2, soma2);

    printf("\nResultado Final:\n");
    (soma1 > soma2) ? printf("Carta 1 venceu!\n") :
    (soma2 > soma1) ? printf("Carta 2 venceu!\n") :
                      printf("Empate!\n");

    return 0;
}
