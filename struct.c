#include "struct.h"

void init(func_table *table){
	table->name = NULL;
	table->funcs = NULL;
	table->len = 0;
	table->max_len = 0;
}

void add_func_massive(func_table *table, char * name) {
	if (table->len == table->max_len) {
		table->max_len = table->max_len * 2 + 1;
		table->name = realloc(table->name, table->max_len * sizeof(char *));
		table->funcs = realloc(table->funcs, table->max_len * sizeof(func_massive));
	}
	table->name[table->len] = name;
	table->funcs[table->len].name = NULL;
	table->funcs[table->len].len = 0;
	table->funcs[table->len].max_len = 0;
	table->len++;
}

void add_func(func_massive *mass, char * name) {
	if (mass->len == mass->max_len) {
		mass->max_len = mass->max_len * 2 + 1;
		mass->name = realloc(mass->name, mass->max_len * sizeof(char *));
	}
	mass->name[mass->len] = name;
	mass->len++;
}

void print(func_table *table, FILE *f) {
	for (int i = 0; i < table->len; i++) {
		fprintf(f, "%s {\n", table->name[i]);
		for (int j = 0; j < table->funcs[i].len; j++)
			fprintf(f, "\t%s\n", table->funcs[i].name[j]);
		fprintf(f, "}\n");
	}
}

void delete(func_table *table) {
	for (int i = 0; i < table->len; i++) {
		for (int j = 0; j < table->funcs[i].len; j++)
			free(table->funcs[i].name[j]);
		free(table->name[i]);
		free(table->funcs[i].name);
	}
	free(table->funcs);	
	free(table->name);	
}