#ifndef STRUCTS_H_
#define STRUCTS_H_

//
// Structs
typedef struct date_s {
    int day;
    int month;
    int year;
} date_t;

typedef struct product_s {
    char name[100];
    char description[300];
    int status;
    int refcode;
} product_t;

typedef struct lote_s {
    int refcode;
    int lotecode;
    int quantity;
    date_t date;
} lote_t;

#endif /* STRUCTS_H_ */
