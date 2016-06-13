#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

#ifndef FILEIO_H_
#define FILEIO_H_
#define LOTE_FILE     "Ficheiro de existencias"
#define PROD_FILE     "Ficheiro de produtos"
#define MOVEMENT_FILE "Ficheiro de movimentos"

product_t find_product(char* name);
lote_t find_first_lote(int refcode);
int find_lotes(int refcode, lote_t* lotearray);

void change_saved_product(product_t prod);
void change_saved_lote(lote_t lote);

void delete_saved_lote(lote_t lote);

void save_new_product(product_t prod);
void save_new_lote(lote_t lote);

void save_movement_log(char* message);
void print_movement_log();

#endif /* FILEIO_H_ */
