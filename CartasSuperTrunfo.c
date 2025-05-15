#include <stdio.h>
#include <windows.h>

struct Carta {
    char estado[30];
    char nome_cidade[50];
    char codigo[10];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
};

void println() {
    printf("\n\n");
}

void printSeparator1() {
    printf("\n ─────────────────────────────────── \n");
}
void printSeparator2() {
    printf("\n ─────────────────────────────────────────── \n");
}

int main() {
    // Configura o console para UTF-8 para exibir caracteres especiais
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    struct Carta carta1, carta2;

    printSeparator1();
    printf("       📄 Cadastro da Carta 1");
    printSeparator1();
    printf(" Estado: ");
    scanf(" %[^\n]", carta1.estado);
    printf(" Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nome_cidade);
    printf(" Código (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf(" População: ");
    scanf("%lu", &carta1.populacao);
    printf(" Área (km²): ");
    scanf("%f", &carta1.area);
    printf(" PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf(" Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;

    printSeparator1();
    printf("       📄 Cadastro da Carta 2");
    printSeparator1();
    printf(" Estado: ");
    scanf(" %[^\n]", carta2.estado);
    printf(" Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nome_cidade);
    printf(" Código (ex: A02): ");
    scanf("%s", carta2.codigo);
    printf(" População: ");
    scanf("%lu", &carta2.populacao);
    printf(" Área (km²): ");
    scanf("%f", &carta2.area);
    printf(" PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf(" Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    println();
    printf("       ⚔️ COMPARAÇÃO DE CARTAS (Atributo: PIB per capita)\n");
    printSeparator2();
    printf(" Carta 1 - %s (%s): %.6f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
    printf(" Carta 2 - %s (%s): %.6f\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);

    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("\n Resultado: Carta 1 (%s - %s) venceu!\n", carta1.nome_cidade, carta1.estado);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("\n Resultado: Carta 2 (%s - %s) venceu!\n", carta2.nome_cidade, carta2.estado);
    } else {
        printf("\n Resultado: Empate entre as cartas!\n");
    }

    println();

    // Restaura a codificação padrão do console
    SetConsoleOutputCP(CPAGE_DEFAULT);

    return 0;

    // CADASTRO DE CARTA 1
    // Código (ex: A01): BR01
    // População: 211000000
    // Área (km²): 8515767
    // PIB (em bilhões): 1868
    // Número de pontos turísticos: 25

    // CADASTRO DE CARTA 2
    // Código (ex: A01): BR02
    // População: 125800000
    // Área (km²): 377975
    // PIB (em bilhões): 4937
    // Número de pontos turísticos: 40

}
