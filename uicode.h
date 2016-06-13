#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

#ifndef UICODE_H_
#define UICODE_H_

int print_main_menu();
int print_help_menu();
void print_help_opt(int opt);

void print_product(product_t prod);
void print_lote(lote_t lote);

void get_product_name(char* name);
int get_unit_number();

product_t build_new_product();
lote_t build_new_lote();
date_t build_new_date();

void change_product_data(product_t* prod);

void print_splitter();

#endif /* UICODE_H_ */
