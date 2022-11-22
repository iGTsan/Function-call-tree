#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int is_func_decl(char *s, char *s_next) {
	if (strchr(s, '(') == NULL)
		return 0; // ничего не объявляется
	if (strstr(s, "{") == NULL && strchr(s_next, '{') == NULL)
		return 0; // ничего не объявляется
	if (strstr(s, "if") != NULL)
		return 0; // конструкция if
	if (strstr(s, "for") != NULL)
		return 0; // цикл
	if (strstr(s, "while") != NULL)
		return 0; // цикл
	if (strstr(s, "switch") != NULL)
		return 0; // цикл
	return 1;
}

int is_func_name(char symb) {
	if (symb >= 'a' && symb <= 'z')
		return 1;
	if (symb >= 'A' && symb <= 'Z')
		return 1;
	if (symb >= '1' && symb <= '0')
		return 1;
	if (symb == '_')
		return 1;
	return 0;
}

char * get_call_func_name(char *s) {
	char *end = strchr(s, '(');
	// char *start = strchr()
	char *begin = end;
	begin--;
	while (begin >= s && is_func_name(*begin))
		begin--;
	begin++;
	int len = end - begin;
	// printf("%s %s %s %d\n", s, begin, end, len);
	char *name = calloc(len + 1, sizeof(char));
	strncpy(name, begin, len);
	return name;
}


char * get_decl_func_name(char *s) {
	// char *end = strstr(s, "(");
	// while (end[-1] == ' ' && end > s)
	// 	end--;
	// if (*end != '(')
	// 	end++;
	// char *end = strchr(s, '{');
	// while (end > s && end[-1] == ' ')
	// 	end--;
	// int len = end - s;
	// char *name = calloc(len + 1, sizeof(char));
	// strncpy(name, s, len);
	// return name;
	return get_call_func_name(s);
}

int is_func_call(char *s) {
	char *ptr;
	if ((ptr = strchr(s, '(')) == NULL)
		return 0; // ничего не вызывается
	if (strstr(s, "if") != NULL)
		return 0; // конструкция if
	if (strstr(s, "for") != NULL)
		return 0; // цикл
	if (strstr(s, "while") != NULL)
		return 0; // цикл
	if (strstr(s, "switch") != NULL)
		return 0; // цикл
	while (ptr >= s && !is_func_name(*ptr))
		ptr--;
	if (ptr < s)
		return 0;
	return 1;
}

int cnt_of_smth(char *s, char symb) {
	int res = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		if (s[i] == symb)
			res++;
	return res;
}

// int cnt_of_open(char *s) {
// 	return cnt_of_smth(s, '{');
// }

// int cnt_of_closed