#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uicode.h"
#include "structs.h"
#include "fileio.h"

//
// Assinaturas das funções
void handle_opt(int opt);
void show_help();
void print_products();
void add_new_product();
void change_product();
void add_prod_units();
void remove_prod_units();

//
// Métodos de implementação
int main(int argv, char** argc) {
    int opt;
    do {
        opt = print_main_menu();
        handle_opt(opt);
    } while (opt != 0);
    return 0;
}

void handle_opt(int opt) {
    print_splitter();
    switch (opt) {
    case 0:
        break;
    case 1:
        // Mostra os produtos no ecrã
        print_products();
        break;
    case 2:
        // Adiciona um novo produto
        add_new_product();
        break;
    case 3:
        // Altera os dados de um produto
        change_product();
        break;
    case 4:
        // Adiciona unidades a um determinado produto
        add_prod_units();
        break;
    case 5:
        // Remove unidades a um determinado produto
        remove_prod_units();
        break;
    case 6:
        // Histórico de movimentos
        print_movement_log();
        break;
    case 7:
        // Mostra o menu de ajuda
        show_help();
        break;
    default:
        printf("<< Opção invalida >>");
    }
    print_splitter();
}

void show_help() {
    int opt = print_help_menu();
    print_help_opt(opt);
}

void print_products() {
    // Leitura do ficheiro de produtos
    FILE *f = fopen(PROD_FILE, "r");

    int i, n;
    product_t curProd;
    lote_t loteArray[50];
    while (fread(&curProd, sizeof(curProd), 1, f) > 0) {
        // Para cada produto, procura a quantidade
        n = find_lotes(curProd.refcode, loteArray);

        // Imprime cada produto (dados + quantidade)
        print_product(curProd);
        for (i = 0; i < n; i++) {
            print_lote(loteArray[i]);
            if (i < n - 1)
                printf("      -- -- --\n");
        }

        printf("---- ---- ----\n");
    }
    fclose(f);
}

void add_new_product() {
    // Cria um novo produto
    product_t newProd = build_new_product();
    // Guarda os dados no ficheiro
    save_new_product(newProd);
}

void change_product() {
    // Procura produto
    char name[100];
    product_t curProd;

    get_product_name(name);
    curProd = find_product(name);

    // Altera dados
    change_product_data(&curProd);

    // Torna a guardar os dados no ficheiro
    change_saved_product(curProd);
}

void add_prod_units() {
    // Procura produto
    char name[100];
    product_t curProd;
    lote_t newLote;

    get_product_name(name);
    curProd = find_product(name);

    // Cria novo lote
    newLote = build_new_lote();
    newLote.refcode = curProd.refcode;

    // Guarda no ficheiro
    save_new_lote(newLote);

    // Adiciona entrada no ficheiro de movimentos
    char msgBuffer[1024];
    snprintf(msgBuffer, sizeof(msgBuffer), "%i novas unidades introduzidas para o produto '%s'",
            newLote.quantity, curProd.name);
    save_movement_log(msgBuffer);
}

void remove_prod_units() {
    // Procura produto
    char name[100];
    product_t curProd;
    lote_t curLote;

    get_product_name(name);
    curProd = find_product(name);

    // Obtém o número de unidades a remover
    int units = get_unit_number();

    char msgBuffer[1024];
    snprintf(msgBuffer, sizeof(msgBuffer), "%i unidades encomendadas", units);
    save_movement_log(msgBuffer);

    // Remove unidades do lote
    int left = units;
    while (left > 0) {
        // Obtém o primeiro lote valido (FIFO)
        curLote = find_first_lote(curProd.refcode);
        if (curLote.quantity > left) {
            // Se o lote currente tiver unidades suficientes, remove as unidades necessárias e guarda as alterações
            curLote.quantity -= left;
            change_saved_lote(curLote);
            // Adiciona entrada no ficheiro de movimentos
            snprintf(msgBuffer, sizeof(msgBuffer), "    %i unidades removidas do lote %i", left,
            			curLote.lotecode);
            save_movement_log(msgBuffer);
            left = 0;
        } else {
            // Se o lote currente não tiver unidades suficientes, retira todas as unidades e apaga o lote
            left -= curLote.quantity;
            delete_saved_lote(curLote);
            // Adiciona entrada no ficheiro de movimentos
            snprintf(msgBuffer, sizeof(msgBuffer),
                    "    %i unidades removidas do lote %i - lote removido do sistema",
                    curLote.quantity, curLote.lotecode);
            save_movement_log(msgBuffer);
            curLote.quantity = 0;
        }
    }
}
