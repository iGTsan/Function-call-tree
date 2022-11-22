#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct func_massive {
	char ** name;
	int len;
	int max_len;
} func_massive;

typedef struct func_table {
	char ** name;
	func_massive * funcs;
	int len;
	int max_len;
} func_table;

void init(func_table *table);

void add_func_massive(func_table *table, char * name);

void add_func(func_massive *mass, char * name);

void print(func_table *table, FILE *f);

void delete(func_table *table);

#endif