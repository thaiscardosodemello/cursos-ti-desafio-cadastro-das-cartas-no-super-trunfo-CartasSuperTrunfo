#include <stdio.h>
#include <windows.h>

struct Carta {
    char nome_pais[50];
    char codigo[10];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

void printSeparator() {
    printf("\n ─────────────────────────────────────────── \n");
}

void println() {
    printf("\n\n");
}

void mostrarMenuAtributos(int excluir) {
    if (excluir != 1) printf("   (1) População\n");
    if (excluir != 2) printf("   (2) Área\n");
    if (excluir != 3) printf("   (3) PIB\n");
    if (excluir != 4) printf("   (4) Pontos Turísticos\n");
    if (excluir != 5) printf("   (5) Densidade Demográfica\n");
}

float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0.0f;
    }
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    struct Carta carta1 = {
        "Brasil", "BR01", 211000000, 8515767.0f, 1868.0f, 25
    };
    struct Carta carta2 = {
        "Japão", "JP01", 125800000, 377975.0f, 4937.0f, 40
    };

    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    int attr1 = 0, attr2 = 0;

    printSeparator();
    printf("   🌍 SUPER TRUNFO - COMPARAÇÃO AVANÇADA");
    printSeparator();


    do {
        printf(" Escolha o PRIMEIRO atributo para comparação:");
        println();
        mostrarMenuAtributos(0);
        println();
        printf("Opção: ");
        scanf("%d", &attr1);
        println();
        if (attr1 < 1 || attr1 > 5) {
            printf("❌ Atributo inválido. Tente novamente.");
        }
    } while (attr1 < 1 || attr1 > 5);

    do {
        printf(" Escolha o SEGUNDO atributo (diferente do primeiro):\n");
        println();
        mostrarMenuAtributos(attr1);
        println();
        printf(" Opção: ");
        scanf("%d", &attr2);
        println();
        if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
            printf("❌ Atributo inválido ou repetido. Tente novamente.\n");
        }
    } while (attr2 < 1 || attr2 > 5 || attr2 == attr1);

    float valor1_attr1 = obterValor(carta1, attr1);
    float valor2_attr1 = obterValor(carta2, attr1);
    float valor1_attr2 = obterValor(carta1, attr2);
    float valor2_attr2 = obterValor(carta2, attr2);

    printf("   🌐  Países: %s vs %s", carta1.nome_pais, carta2.nome_pais);
    printSeparator();
    println();

    char* nomes_atributos[] = {
        "", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"
    };

    printf("1º Atributo (%s): %.2f x %.2f\n", nomes_atributos[attr1], valor1_attr1, valor2_attr1);
    printf("2º Atributo (%s): %.2f x %.2f\n", nomes_atributos[attr2], valor1_attr2, valor2_attr2);

    int pontos_carta1 = 0;
    int pontos_carta2 = 0;

    if (attr1 == 5) {
        pontos_carta1 += (valor1_attr1 < valor2_attr1) ? 1 : 0;
        pontos_carta2 += (valor2_attr1 < valor1_attr1) ? 1 : 0;
    } else {
        pontos_carta1 += (valor1_attr1 > valor2_attr1) ? 1 : 0;
        pontos_carta2 += (valor2_attr1 > valor1_attr1) ? 1 : 0;
    }

    if (attr2 == 5) {
        pontos_carta1 += (valor1_attr2 < valor2_attr2) ? 1 : 0;
        pontos_carta2 += (valor2_attr2 < valor1_attr2) ? 1 : 0;
    } else {
        pontos_carta1 += (valor1_attr2 > valor2_attr2) ? 1 : 0;
        pontos_carta2 += (valor2_attr2 > valor1_attr2) ? 1 : 0;
    }

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    println();
    printf("➕  Soma dos atributos:");
    println();
    printf("   %s: %.2f\n", carta1.nome_pais, soma1);
    printf("   %s: %.2f\n", carta2.nome_pais, soma2);
    println();

    printf("🏆 Resultado: ");
    if (soma1 > soma2) {
        printf("✔️  %s venceu!\n", carta1.nome_pais);
    } else if (soma2 > soma1) {
        printf("✔️  %s venceu!\n", carta2.nome_pais);
    } else {
        printf("⚖️  Empate!\n");
    }

    println();
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}
