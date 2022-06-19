#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define _GNU_SOURCE
#define MAX_CHAR_LEN 6

struct list_flag
{
    int NUMBER_LINE; // нумеруем все строки
    int REMOVE_BLANK_LINES; // удалаяем пустые строки
    int NUMBER_NOBLANK_LINES; // нумеруем только не пустыне строки
    int MARK_END_LINES; // отмечаем конец строки 
    int REPLACE_TAB; // заменям tab
};

struct option long_options[] = {
    {"number", 0, 0, 'n'},
    {"number-nonblank", 0, 0, 'b'},        
    {"squeeze-blank", 0, 0, 's'},
    };


struct cat_struct {
    char buffer[MAX_CHAR_LEN];
    int line;
    int nl;
    int prev_prev;
    int prev;
};

typedef struct list_flag list_flag;
typedef struct cat_struct cat_struct;

int parser (int, char **, list_flag *, char **, int *);
void s21_cat (int, char **);
int check_flag(int, char **, list_flag *);
int check_long_flag(int, char **, list_flag *);
void wr_flag_debag(list_flag *);
void init(list_flag *);
int remove_blank_lines (char ch, cat_struct *c, list_flag *flag);
void mark_end_lines(char ch, cat_struct *c, list_flag *flag);
void replace_tabs(char ch, cat_struct *c, list_flag *flag);
void number_lines(char ch, cat_struct *c, list_flag *flag);
void write_file(FILE * file, list_flag *flag, int reset);
int check_file(int argc, char ** argv, char ** file_list, int *len_file_list);