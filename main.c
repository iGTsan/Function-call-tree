#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "str_proc.h"

#define MAXLEN 1000

int main() {
	FILE *fi, *fo;
	fi = fopen("test.c", "rt");
	fo = fopen("out.txt", "wt");
	func_table table;
	init(&table);
	if (fi == NULL || fo == NULL)
		return 0;
	char prev[MAXLEN] = {0};
	char line[MAXLEN];

	while (!feof(fi)) {
		char *ptr = fgets(line, MAXLEN, fi);
		if (ptr == NULL) 
			break;
		if (is_func_decl(prev, line)) {
			char *name = get_decl_func_name(prev);
			add_func_massive(&table, name);
			int cnt = cnt_of_smth(prev, '{');
			strcpy(prev, line);

			while (!feof(fi) && cnt) {
				char *ptr = fgets(line, MAXLEN, fi);
				if (ptr == NULL) 
					break;
				if (is_func_call(prev)) {
					name = get_call_func_name(prev);
					add_func(&(table.funcs[table.len - 1]), name);
				}
				cnt += cnt_of_smth(prev, '{');
				cnt -= cnt_of_smth(prev, '}');
				strcpy(prev, line);
			}
		}
		strcpy(prev, line);
	}
	print(&table, fo);
	delete(&table);

	fclose(fi);
	fclose(fo);
	return 0;
}