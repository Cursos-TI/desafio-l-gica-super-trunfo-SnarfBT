#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTADO 50
#define MAX_CODIGO 10
#define MAX_NOME   100

typedef struct {
    char estado[MAX_ESTADO];
    char codigo[MAX_CODIGO];
    char nomeCidade[MAX_NOME];
    unsigned long populacao;
    double area;
    double pib;       // em bilhões
    int pontosTuristicos;
    double densidade;
    double pibPerCapita;
} Carta;

enum Atributo { ATR_POPULACAO = 1, ATR_AREA, ATR_PIB, ATR_DENSIDADE, ATR_PIB_PER_CAPITA };

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(const char *prompt, char *buffer, size_t tamanho) {
    printf("%s", prompt);
    if (fgets(buffer, (int)tamanho, stdin)) {
        size_t ln = strlen(buffer) - 1;
        if (buffer[ln] == '\n') buffer[ln] = '\0';
    }
}

void lerCarta(Carta *c) {
    lerString("Digite o estado: ", c->estado, sizeof(c->estado));
    lerString("Digite o codigo da carta: ", c->codigo, sizeof(c->codigo));
    lerString("Digite o nome da cidade: ", c->nomeCidade, sizeof(c->nomeCidade));

    printf("Digite a populacao da cidade: ");
    while (scanf("%lu", &c->populacao) != 1) {
        printf("Entrada invalida. Digite um numero inteiro: ");
        limpar_buffer();
    }
    printf("Digite a area da cidade (km2): ");
    while (scanf("%lf", &c->area) != 1 || c->area <= 0) {
        printf("Entrada invalida. Digite um valor real positivo: ");
        limpar_buffer();
    }
    printf("Digite o PIB da cidade (bilhoes): ");
    while (scanf("%lf", &c->pib) != 1 || c->pib < 0) {
        printf("Entrada invalida. Digite um valor real não negativo: ");
        limpar_buffer();
    }
    // limpeza antes de ultimos scanf
    limpar_buffer();
}

void calcularAtributos(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1e9) / c->populacao;
}

void compararCartas(const Carta *a, const Carta *b, int attr) {
    double val1 = 0.0, val2 = 0.0;
    const char *nomeAttr;

    // Seleciona valores e nome do atributo
    switch (attr) {
        case ATR_POPULACAO:
            val1 = (double)a->populacao;
            val2 = (double)b->populacao;
            nomeAttr = "População";
            break;
        case ATR_AREA:
            val1 = a->area;
            val2 = b->area;
            nomeAttr = "Área";
            break;
        case ATR_PIB:
            val1 = a->pib;
            val2 = b->pib;
            nomeAttr = "PIB";
            break;
        case ATR_DENSIDADE:
            val1 = a->densidade;
            val2 = b->densidade;
            nomeAttr = "Densidade Populacional";
            break;
        case ATR_PIB_PER_CAPITA:
            val1 = a->pibPerCapita;
            val2 = b->pibPerCapita;
            nomeAttr = "PIB per Capita";
            break;
        default:
            printf("Atributo inválido.\n");
            return;
    }

    // Exibe comparação
    printf("\nComparação de cartas (Atributo: %s):\n", nomeAttr);
    if (attr == ATR_POPULACAO) {
        printf("Carta 1 - %s (%s): %lu\n", a->nomeCidade, a->codigo, a->populacao);
        printf("Carta 2 - %s (%s): %lu\n", b->nomeCidade, b->codigo, b->populacao);
    } else if (attr == ATR_AREA) {
        printf("Carta 1 - %s (%s): %.2f km2\n", a->nomeCidade, a->codigo, a->area);
        printf("Carta 2 - %s (%s): %.2f km2\n", b->nomeCidade, b->codigo, b->area);
    } else if (attr == ATR_PIB) {
        printf("Carta 1 - %s (%s): %.2f bilhoes\n", a->nomeCidade, a->codigo, a->pib);
        printf("Carta 2 - %s (%s): %.2f bilhoes\n", b->nomeCidade, b->codigo, b->pib);
    } else if (attr == ATR_DENSIDADE) {
        printf("Carta 1 - %s (%s): %.2f hab/km2\n", a->nomeCidade, a->codigo, a->densidade);
        printf("Carta 2 - %s (%s): %.2f hab/km2\n", b->nomeCidade, b->codigo, b->densidade);
    } else if (attr == ATR_PIB_PER_CAPITA) {
        printf("Carta 1 - %s (%s): R$ %.2f\n", a->nomeCidade, a->codigo, a->pibPerCapita);
        printf("Carta 2 - %s (%s): R$ %.2f\n", b->nomeCidade, b->codigo, b->pibPerCapita);
    }

    // Determina vencedor
    int vencedor;
    if (attr == ATR_DENSIDADE) {
        vencedor = (val1 < val2) ? 1 : 2;
    } else {
        vencedor = (val1 > val2) ? 1 : 2;
    }

    printf("\nResultado: Carta %d (%s) venceu!\n", vencedor,
           (vencedor == 1 ? a->nomeCidade : b->nomeCidade));
}

int main() {
    Carta carta1, carta2;

    printf("--- Cadastro da Carta 1 ---\n");
    lerCarta(&carta1);
    calcularAtributos(&carta1);

    printf("--- Cadastro da Carta 2 ---\n");
    lerCarta(&carta2);
    calcularAtributos(&carta2);

    // Defina aqui o atributo a ser comparado:
    // 1=População, 2=Área, 3=PIB, 4=Densidade Populacional, 5=PIB per Capita
    int ATRIBUTO_COMPARADO = ATR_POPULACAO;

    compararCartas(&carta1, &carta2, ATRIBUTO_COMPARADO);

    return EXIT_SUCCESS;
}
