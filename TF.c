#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------Structs-------------------------------------------*/

typedef struct date_s {
		int day;
		int month;
		int year;
	} date_t;

typedef struct product_s {
		char name[100];
		char description[300];
		char status[100];
		int refcode;
	} product_t;

typedef struct product_quantity_s {
		int refcode;
		int quantity;
		date_t date;
	} product_quantity_t;

/*---------------------------Funções auxiliares------------------------------------*/

void add_product(){ //Adiciona um produto aos ficheiros fe e fp
	FILE *fe = fopen("Ficheiro de existencias", "a+");
	FILE *fp = fopen("Ficheiro de produtos", "a+");

	product_t d;
	date_t a;
	product_quantity_t b;

	b.date = a;

	printf("Nome do produto: ");
	scanf(" %[^\n]s", d.name);

	printf("Descricao: ");
	scanf(" %[^\n]s", d.description);

	printf("Referencia interna: ");
	scanf("%i", &d.refcode);
	b.refcode = d.refcode;

	printf("Estado: ");
	scanf(" %s[^\n]", d.status);

	printf("Quantidade: ");
	scanf("%i", &b.quantity);

	printf("Data (dd-mm-aaaa): ");
	scanf("%i-%i-%i", &a.day, &a.month, &a.year);

	fwrite(&b, sizeof(b), 1, fe);
	fwrite(&d, sizeof(d), 1, fp);

	fclose(fp);
	fclose(fe);
}

product_quantity_t search_refcode(int refcode) { // Pesquisa o refcode e devolve b
	FILE *fe = fopen("Ficheiro de existencias", "r");

	product_quantity_t b;

	while(fread(&b, sizeof(b), 1, fe) > 0){
		if(b.refcode == refcode){
			break;
		}
	}
	fclose(fe);
	return b;
}

void print_files(){ //Mostra no ecrã o nome e a quantidade de todos os produtos em stock

	FILE *fe = fopen("Ficheiro de existencias", "r");
	FILE *fp = fopen("Ficheiro de produtos", "r");

	if (fp == NULL) {
	printf("Erro ao abrir ficheiro \n");
	return;
	}

	if (fe == NULL) {
	printf("Erro ao abrir ficheiro \n");
	return;
	}


	product_t d;
	product_quantity_t b;

	printf("--------------Inventario:--------------\n");
	printf("Nome do produto\t\tQuantidade\n");
	while(fread(&d, sizeof(d), 1, fp) > 0){
		b = search_refcode(d.refcode);
		printf("%s\t\t\t%i\n", d.name, b.quantity);
	}
	printf("_______________________________________\n");

	fclose(fe);
	fclose(fp);

}

product_t search_files(char *Name){ // Pesquisa um produto no ficheiro fp pelo nome do mesmo e devolve d
	FILE *fp = fopen("Ficheiro de produtos", "r");

	product_t d;

	while(fread(&d, sizeof(d), 1, fp) > 0){
		if(strcmp(d.name, Name) == 0){
			break;
		}
	}
	fclose(fp);
	return d;
}

void delete_entry(product_t d, product_quantity_t refcode){ // Altera os dados de um produto
	FILE *fe = fopen("Ficheiro de existencias", "r");
	FILE *fp = fopen("Ficheiro de produtos", "r");
	FILE *fh = fopen("Helper File Product", "w");
	FILE *fhh = fopen("Helper File Quantity", "w");

	product_t ch;
	product_quantity_t b;

	while (fread(&ch, sizeof(ch), 1, fp) > 0) {
		if(strcmp(ch.name, d.name) == 0){
			fwrite(&d, sizeof(d), 1, fh);
		}else{
			fwrite(&ch, sizeof(d), 1, fh);
		}
	}
	while (fread(&b, sizeof(b), 1, fe) > 0) {
		if(b.refcode == refcode.refcode){
			fwrite(&b, sizeof(b), 1, fhh);
		}else{
			fwrite(&b, sizeof(b), 1, fhh);
		}
	}

	fclose(fp);
	fclose(fe);
	fclose(fh);
	fclose(fhh);

	remove("Ficheiro existencias");
	remove("Ficheiro de produtos");
	rename("Helper File Product", "Ficheiro de produtos");
	rename("Helper File Quantity", "Ficheiro de existencias");
}

void change_details(product_t *d, product_quantity_t *b){ // Pedido ao utilizador dos dados novos para a alteração

	date_t a;

	printf("Descricao: ");
	scanf(" %[^\n]s", (*d).description);

	printf("Referencia interna: ");
	scanf("%i", &(*d).refcode);

	printf("Estado: ");
	scanf(" %s[^\n]", (*d).status);

	printf("Quantidade: ");
	scanf("%i", &(*b).quantity);

	printf("Data (dd-mm-aaaa): ");
	scanf("%i-%i-%i", &a.day, &a.month, &a.year);
}

void help(){ // Menu ajuda, tudo o que é preciso na opção help, está aqui!
	int ch;

	printf("\nMenu ajuda:\n\n");
	printf("1 - Ver produtos em stock\n");
	printf("2 - Adicionar novo produto\n");
	printf("3 - Alterar dados de um produto existente\n");
	printf("4 - Registar entrada de produtos em armazem\n");
	printf("5 - Registar saida de produtos\n");
	printf("6 - Verificar os movimentos de entradas e saidas de um produto\n\n");

	printf("Em que opcao necessita de ajuda? ");
	scanf("%i", &ch);

	printf("\n");

	if(ch == 1){
		printf("Esta opcao vai fazer com que todos os produtos sejam mostrados no ecra. \nSera apenas visualizado o nome e a quantidade em stock de tais produtos.\n");
		printf("_______________________________________________________________________\n");
	}
	if(ch == 2){
		printf("Esta opcao serve para adicionar ao ficheiro um novo produto. Serao pedidas\n todas as informacoes necessarias (nome, descricao, referencia interna, estado, quantidade e data.\n");
		printf("_______________________________________________________________________\n");
	}
	if(ch == 3){
		printf("Esta opcao serve para alterar dados de um produto ja existente no ficheiro.\n Tera de escrever o nome do ficheiro que deseja alterar e posteriormente introduzir todas as informacoes sobre o mesmo.\n");
		printf("_______________________________________________________________________\n");
	}
	if(ch == 4){
		printf("Esta opcao serve para adicionar uma certa quantidade a um produto existente\n no ficheiro. Deve pesquisar pelo nome do produto em causa e posteriormente registar o numero a ser somada à quantidade já existente\n");
		printf("_______________________________________________________________________\n");
	}
	if(ch == 5){
		printf("Esta opcao serve para registar saidas de produto do armazem. Deve pesquisar\n pelo nome do produto em causa e posteriormente registar o numero que deseja subtrair à quantidade já existente.\n");
		printf("_______________________________________________________________________\n");
	}
	if(ch == 6){
		printf("Esta opcao vai fazer com que o programa mostre os movimentos de entrada e\n saida do armazem, de um produto. Deve pesquisar pelo produto em causa e posteriormente todos os movimentos serão mostrados no ecrã.\n");
		printf("_______________________________________________________________________\n");
	}
}

//____________________________________MAIN_______________________________________________//

int main(){
	int dummy;
	char Name[200];

	product_t d;
	product_quantity_t b;

do{

	printf("Menu:\n");
	printf("1 - Ver produtos em stock\n");
	printf("2 - Adicionar novo produto\n");
	printf("3 - Alterar dados de um produto existente\n");
	printf("4 - Registar entrada de produtos em armazem\n");
	printf("5 - Registar saida de produtos\n");
	printf("6 - Registar os movimentos de entradas e saidas de um produto\n");
	printf("7 - Ajuda\n");
	printf("0 - Sair\n\n");


	printf("Escolha: ");
	scanf("%i", &dummy);


if(dummy == 1){
	print_files();
}
if(dummy == 2){
	add_product();
}
if(dummy == 3){
	printf("Alterar dados de um produto\n\n");
	printf("Pesquisar produto: ");
	scanf(" %[^\n]s", Name);
	d = search_files(Name);
	b = search_refcode(d.refcode);
	change_details(&d, &b);
	delete_entry(d, b);
	printf("\nProduto alterado com sucesso!\n\n");
}
if(dummy==7){
	help();
}
if(dummy == 0){
	exit(0);
}

}while(dummy != 0);

}
