#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------Structs-------------------------------------------*/
struct detail_s{
		char name[100];
		char description[300];
		char status[100];
		int refcode;
		int quantity;
	};

struct date{
		int day;
		int month;
		int year;
	};

//								   typedef

typedef struct detail_s product_t;
typedef struct date date_t;

/*---------------------------Funções auxiliares------------------------------------*/

void add_product(){
	FILE *fe = fopen("Ficheiro de existencias", "a+");
	FILE *fp = fopen("Ficheiro de produtos", "a+");
	product_t d;
	date_t a;



	printf("Nome do ficheiro: ");
	scanf("%s", d.name);

	printf("Descricao: ");
	scanf("%s", d.description);

	printf("Referencia interna: ");
	scanf("%i", &d.refcode);

	printf("Estado: ");
	scanf("%s", d.status);

	printf("Quantidade: ");
	scanf("%i", &d.quantity);

	printf("Data (dd-mm-aaaa): ");
	scanf("%i-%i-%i", &a.day, &a.month, &a.year);

	fwrite(&d, sizeof(d), 1, fe);
	fwrite(&d, sizeof(d), 1, fp);

	fclose(fp);
	fclose(fe);
}

void print_files(){

	FILE *fe = fopen("Ficheiro de existencias", "r");
	FILE *fp = fopen("Ficheiro de produtos", "r");

	product_t d;

	fread(&d, sizeof(d), 1, fe);
	fread(&d, sizeof(d), 1, fp);

	printf("--------------Inventario:--------------\n");
	printf("Nome do produto\t\tQuantidade\n");
	printf("%s\t\t\t%i\n\n", d.name, d.quantity);

	fclose(fe);
	fclose(fp);

}


//____________________________________MAIN_______________________________________________//

int main(){
	int dummy;

do{

	printf("Menu:\n");
	printf("1 - Ver produtos em stock\n");
	printf("2 - Adicionar novo produto\n");
	printf("3 - Alterar dados de um produto existente\n");
	printf("4 - Registar entrada de produtos em armazem\n");
	printf("5 - Registar saida de produtos\n");
	printf("6 - Registar os movimentos de entradas e saidas de um produto\n");
	printf("7 - Ajuda\n");
	printf("8 - Sair\n\n");


	printf("Escolha: ");
	scanf("%i", &dummy);


if(dummy == 1){
	print_files();
}
if(dummy == 2){
	add_product();
}


}while(dummy != 8);

}
