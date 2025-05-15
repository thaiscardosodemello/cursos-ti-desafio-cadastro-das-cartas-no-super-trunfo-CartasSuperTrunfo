#include <stdio.h>
#include <windows.h>

// Estrutura que representa uma carta do jogo
struct Carta {
    char nome_pais[50];
    char codigo[10];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

// Funções auxiliares
void printSeparator() {
    printf("\n ─────────────────────────────────────────── \n");
}

void println() {
    printf("\n\n");
}

int main() {
    // Configura o console para exibir corretamente os caracteres especiais
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    struct Carta carta1 = {
        "Brasil", "BR01", 211000000, 8515767.0f, 1868.0f, 25
    };

    struct Carta carta2 = {
        "Japão", "JP01", 125800000, 377975.0f, 4937.0f, 40
    };

    // Calcula densidade demográfica
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int opcao;

    // Exibe menu interativo
    do {
        printSeparator();
        printf(" 🌍 SUPER TRUNFO - COMPARAÇÃO ENTRE PAÍSES");
        printSeparator();
        printf(" Escolha o atributo para comparar:");
        println();
        printf("   (1) População\n");
        printf("   (2) Área\n");
        printf("   (3) PIB\n");
        printf("   (4) Pontos Turísticos\n");
        printf("   (5) Densidade Demográfica\n");
        printf("   (0) Sair\n");
        println();
        printf(" Opção: ");
        scanf("%d", &opcao);
        println();
   

        // Avalia a opção escolhida
        switch (opcao) {
            case 1:
                println();
                printf("🔢 Comparação: População");
                printSeparator();                
                println();
                printf("%s: %lu habitantes\n", carta1.nome_pais, carta1.populacao);
                printf("%s: %lu habitantes\n", carta2.nome_pais, carta2.populacao);
                println();

                if (carta1.populacao > carta2.populacao) {
                    printf("✔️  %s venceu!\n", carta1.nome_pais);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("✔️  %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("⚖️  Empate!\n");
                }
                break;

            case 2:
                println();
                printf("📏 Comparação: Área");
                printSeparator();                
                println();
                printf("%s: %.2f km²\n", carta1.nome_pais, carta1.area);
                printf("%s: %.2f km²\n", carta2.nome_pais, carta2.area);
                println();

                if (carta1.area > carta2.area) {
                    printf("✔️  %s venceu!\n", carta1.nome_pais);
                } else if (carta2.area > carta1.area) {
                    printf("✔️  %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("⚖️  Empate!\n");
                }
                break;

            case 3:
                println();
                printf("💰 Comparação: PIB (em bilhões)");
                printSeparator();                
                println();
                printf("%s: %.2f bilhões\n", carta1.nome_pais, carta1.pib);
                printf("%s: %.2f bilhões\n", carta2.nome_pais, carta2.pib);
                println();

                if (carta1.pib > carta2.pib) {
                    printf("✔️  %s venceu!\n", carta1.nome_pais);
                } else if (carta2.pib > carta1.pib) {
                    printf("✔️  %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("⚖️  Empate!\n");
                }
                break;

            case 4:
                println();
                printf("📸 Comparação: Pontos Turísticos");
                printSeparator();                
                println();
                printf("%s: %d pontos\n", carta1.nome_pais, carta1.pontos_turisticos);
                printf("%s: %d pontos\n", carta2.nome_pais, carta2.pontos_turisticos);
                println();

                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("✔️  %s venceu!\n", carta1.nome_pais);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("✔️  %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("⚖️  Empate!\n");
                }
                break;

            case 5:
                println();
                printf("📊 Comparação: Densidade Demográfica (menor vence)");
                printSeparator();                
                println();
                printf("%s: %.4f hab/km²\n", carta1.nome_pais, carta1.densidade);
                printf("%s: %.4f hab/km²\n", carta2.nome_pais, carta2.densidade);
                println();

                if (carta1.densidade < carta2.densidade) {
                    printf("✔️  %s venceu!\n", carta1.nome_pais);
                } else if (carta2.densidade < carta1.densidade) {
                    printf("✔️  %s venceu!\n", carta2.nome_pais);
                } else {
                    printf("⚖️  Empate!\n");
                }
                break;

            case 0:
                printf("👋  Saindo do programa...");
                println();
                break;

            default:
                printf("❌ Opção inválida! Tente novamente.\n");
        }

        println();

    } while (opcao != 0);

    // Restaura o código de página original do console
    SetConsoleOutputCP(CPAGE_DEFAULT);

    return 0;
}
