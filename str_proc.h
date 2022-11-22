#ifndef STR_PROC_H
#define STR_PROC_H

int is_func_decl(char *s, char *s_next);

char * get_decl_func_name(char *s);

int is_func_call(char *s);

char * get_call_func_name(char *s);

int cnt_of_smth(char *s, char symb);

#endif