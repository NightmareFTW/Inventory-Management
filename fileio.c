#include "fileio.h"

product_t find_product(char* name) {
    // Abre o ficheiro de produtos
    FILE *f = fopen(PROD_FILE, "r");

    // Percorrer a lista de produtos
    product_t curProd;
    while (fread(&curProd, sizeof(curProd), 1, f) > 0) {
        if (strcmp(curProd.name, name) == 0) {
            // Sair se curProd corresponder ao nome pesquisado
            break;
        }
    }
    fclose(f);
    return curProd;
}

lote_t find_first_lote(int refcode) {
    // Abrir ficheiro de existencias
    FILE *f = fopen(LOTE_FILE, "r");
    lote_t curLote;

    if (f == NULL) {
        // Se o ficheiro não existir
        return curLote;
    }

    // Percorrer a lista para cada lote
    while (fread(&curLote, sizeof(curLote), 1, f) > 0) {
        if (curLote.refcode == refcode) {
            // Sair se o curLote corresponder ao refcode pesquisado
            break;
        }
    }
    fclose(f);
    return curLote;
}

int find_lotes(int refcode, lote_t* lotearray) {
    // Abrir o ficheiro de existencias
    FILE *f = fopen(LOTE_FILE, "r");

    if (f == NULL) {
        //Se o ficheiro não existir
        return 0;
    }

    // Percorrer a lista para cada lote
    int n = 0;
    lote_t curLote;
    while (fread(&curLote, sizeof(curLote), 1, f) > 0) {
        if (curLote.refcode == refcode) {
            // Add lote to array if refcode matches
            lotearray[n++] = curLote;
        }
    }
    fclose(f);
    return n;
}

void change_saved_product(product_t prod) {
    // Nome do ficheiro temporário
    char* temp_file = "__helperfile";

    // Abre ficheiros
    FILE *f = fopen(PROD_FILE, "r");
    FILE *f_tmp = fopen(temp_file, "w");

    // Percorrer a lista para cada produto do ficheiro de produtos
    product_t curProd;
    while (fread(&curProd, sizeof(curProd), 1, f) > 0) {
        if (curProd.refcode == prod.refcode) {
            // Escreve um novo produto se o refcode corresponder
            fwrite(&prod, sizeof(prod), 1, f_tmp);
        } else {
            // Escreve o produto antigo se o refcode não corresponder
            fwrite(&curProd, sizeof(curProd), 1, f_tmp);
        }
    }
    fclose(f);
    fclose(f_tmp);

    //Roda ficheiros - Substitui o ficheiro original pelo ficheiro helper
    remove (PROD_FILE);
    rename(temp_file, PROD_FILE);
}

void change_saved_lote(lote_t lote) {
    // Nome do ficheiro temporário
    char* temp_file = "__helperfile";

    // Abre ficheiros
    FILE *f = fopen(LOTE_FILE, "r");
    FILE *f_tmp = fopen(temp_file, "w");

    // Percorre a lista para cada lote
    lote_t curLote;
    while (fread(&curLote, sizeof(curLote), 1, f) > 0) {
        if (curLote.lotecode == lote.lotecode) {
            // Escreve os dados de um novo lote se o lotecode corresponder
            fwrite(&lote, sizeof(lote), 1, f_tmp);
        } else {
            // Escreve os lote antigo se o lotecode não corresponder
            fwrite(&curLote, sizeof(curLote), 1, f_tmp);
        }
    }
    fclose(f);
    fclose(f_tmp);

    // Roda ficheiros - Substitui o ficheiro original pelo ficheiro helper
    remove (LOTE_FILE);
    rename(temp_file, LOTE_FILE);
}

void delete_saved_lote(lote_t lote) {
    // Temp file name Nome do ficheiro temporário
    char* temp_file = "__helperfile";

    // Abrir ficheiros
    FILE *f = fopen(LOTE_FILE, "r");
    FILE *f_tmp = fopen(temp_file, "w");

    // Percorrer os lotes
    lote_t curLote;
    while (fread(&curLote, sizeof(curLote), 1, f) > 0) {
        if (curLote.lotecode == lote.lotecode) {
            // Não alterar nada caso o lotecode corresponder (apagar lote)
        } else {
            // Escrever o lote antigo se o lotecode não corresponder
            fwrite(&curLote, sizeof(curLote), 1, f_tmp);
        }
    }
    fclose(f);
    fclose(f_tmp);

    // Roda ficheiros - Substitui o ficheiro original pelo ficheiro helper
    remove (LOTE_FILE);
    rename(temp_file, LOTE_FILE);
}

void save_new_product(product_t prod) {
    // Abrir ficheiro de produtos
    FILE *f = fopen(PROD_FILE, "a");
    // Acrescenta novo produto ao ficheiro
    fwrite(&prod, sizeof(prod), 1, f);
    fclose(f);
}

void save_new_lote(lote_t lote) {
    // Abre o ficheiro de existencias
    FILE *f = fopen(LOTE_FILE, "a");
    // Acrescenta novo lote ao ficheiro
    fwrite(&lote, sizeof(lote), 1, f);
    fclose(f);
}

void save_movement_log(char* message) {
    // Abre o ficheiro de movimentos
    FILE *f = fopen(MOVEMENT_FILE, "a");
    // Acrescenta nova entrada no ficheiro de movimentos
    fprintf(f, "%s\n", message);
    fclose(f);
}

void print_movement_log() {
    // Abre o ficheiro de movimentos
    FILE *f = fopen(MOVEMENT_FILE, "r");
    char ch;
    do {
        //Percorrer o ficheiro de movimentos e imprimir na consola
        ch = fgetc(f);
        if (ch != EOF) {
            printf("%c", ch);
        }
    } while (ch != EOF);
    fclose(f);
}
