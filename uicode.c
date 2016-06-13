#include "uicode.h"

int read_int() {
    // Lê um inteiro da consola
    int opt = 0;
    scanf(" %d", &opt);
    return opt;
}

void read_string(char* buffer) {
    // Lê uma string da consola
    scanf(" %[^\n]s", buffer);
}

int print_main_menu() {
    //Imprime o menu principal do programa e devolve a número da opção desejada
    printf("Menu:\n");
    printf("1 - Ver produtos em stock\n");
    printf("2 - Adicionar novo produto\n");
    printf("3 - Alterar dados de um produto existente\n");
    printf("4 - Registar entrada de produtos em armazem\n");
    printf("5 - Registar saida de produtos\n");
    printf("6 - Mostrar registo de movimentos\n");
    printf("7 - Ajuda\n");
    printf("0 - Sair\n\n");

    printf("Escolha: ");
    return read_int();
}

int print_help_menu() {
    //Imprime o menu ajuda e devolve a opção desejada
    printf("\nMenu ajuda:\n\n");
    printf("1 - Ver produtos em stock\n");
    printf("2 - Adicionar novo produto\n");
    printf("3 - Alterar dados de um produto existente\n");
    printf("4 - Registar entrada de produtos em armazem\n");
    printf("5 - Registar saida de produtos\n");
    printf("6 - Verificar os movimentos de entradas e saidas de um produto\n\n");

    printf("Em que opcao necessita de ajuda? ");
    return read_int();
}

void print_help_opt(int opt) {
    //Imprime a mensagem de ajuda que foi escolhida no menu de ajuda
    switch (opt) {
    case 1:
        printf("Esta opcao vai fazer com que todos os produtos sejam mostrados no ecra.\n");
        printf("Sera apenas visualizado o nome e a quantidade em stock de tais produtos.\n");
        break;
    case 2:
        printf("Esta opcao serve para adicionar ao ficheiro um novo produto. Serao pedidas\n");
        printf(
                "Todas as informacoes necessarias (nome, descricao, referencia interna, estado, quantidade e data.\n");
        break;
    case 3:
        printf("Esta opcao serve para alterar dados de um produto ja existente no ficheiro.\n");
        printf(
                " Tera de escrever o nome do ficheiro que deseja alterar e posteriormente introduzir todas as informacoes sobre o mesmo.\n");
        break;
    case 4:
        printf("Esta opcao serve para adicionar uma certa quantidade a um produto existente\n");
        printf(
                " no ficheiro. Deve pesquisar pelo nome do produto em causa e posteriormente registar o numero a ser somada Ã  quantidade jÃ¡ existente\n");
        break;
    case 5:
        printf("Esta opcao serve para registar saidas de produto do armazem. Deve pesquisar\n");
        printf(
                " pelo nome do produto em causa e posteriormente registar o numero que deseja subtrair Ã  quantidade jÃ¡ existente.\n");
        break;
    case 6:
        printf("Esta opcao vai fazer com que o programa mostre os movimentos de entrada e\n");
        printf(
                " saida do armazem, de um produto. Deve pesquisar pelo produto em causa e posteriormente todos os movimentos serÃ£o mostrados no ecrÃ£.\n");
        break;
    default:
        printf("<< Opcao invalida >>");
    }
}

void print_product(product_t prod) {
    // Imprime os dados do produto na consola
    printf("   Codigo: %i\n", prod.refcode);
    printf("     Nome: %s\n", prod.name);
    printf("Descricao: %s\n", prod.description);
    printf("  Estado: ");
    if (prod.status == 1) {
      printf("valido\n");
    } else {
      printf("invalido\n");
    }
}

void print_lote(lote_t lote) {
    // Imprime os dados do lote na consola
    printf("       Lote ID: %i\n", lote.lotecode);
    printf("    Quantidade: %i\n", lote.quantity);
    printf("          Data: %i/%i/%i\n", lote.date.day, lote.date.month, lote.date.year);
}

void get_product_name(char* name) {
    //Obtém o produto selecionado
    printf("Nome do produto: ");
    read_string(name);
}

int get_unit_number() {
    // Obtém o número de unidades (usado para remover unidades do inventário)
    printf("Numero de unidades: ");
    return read_int();
}

product_t build_new_product() {
    // Cria um novo produto com os dados fornecidos pelo utilizador
    product_t newProd;

    printf("Nome do produto: ");
    read_string(newProd.name);

    printf("Descricao: ");
    read_string(newProd.description);

    printf("Referencia interna: ");
    newProd.refcode = read_int();

    printf("Estado: ");
    newProd.status = read_int();

    return newProd;
}

lote_t build_new_lote() {
    // Constroi um novo lote com os dados fornecidos pelo utilizador
    lote_t newLote;

    printf("Quantidade: ");
    newLote.quantity = read_int();

    printf("Id do lote: ");
    newLote.lotecode = read_int();

    newLote.date = build_new_date();
    return newLote;
}

date_t build_new_date() {
    // Cria uma nova data
    date_t newDate;

    printf("Data (dd-mm-aaaa): ");
    scanf(" %d-%d-%d", &newDate.day, &newDate.month, &newDate.year);

    return newDate;
}

void change_product_data(product_t* prod) {
    // Altera os dados de um produto baseado nas escolhas do utilizador
    printf("Novo nome do produto: ");
    read_string((*prod).name);

    printf("Nova descricao: ");
    read_string((*prod).description);

    printf("Novo estado: ");
    (*prod).status = read_int();
}

void print_splitter() {
    // Imprime um simples divisor de texto
    printf("\n_______________________________________________________________________\n");
}
