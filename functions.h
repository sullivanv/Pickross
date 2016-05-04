#ifndef __include_file_h__
#define __include_file_h__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void my_putchar(char c);
void my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
int my_getnbr(char *str);
int my_strlen(char *str);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *str);
void my_put_nbr(int nb);
int taille_file(char *dossier, int taille_file);
int my_start(int taille_file_1, int taille_file_2, char **argv);
int **sort_file(char *dossier, int taille_file, int dim);
int **my_sort(char *content, int dim);
void my_print_tab(int** tab);
int *my_parse_arg_1(char *str);
char **my_tab(void);
int check_file_size(char *dossier, int taille_file);
int my_algo(int *result, char **argv, int **tab1, int **tab2);

typedef struct s_info
{
  int nbligne;
  int nbcolonne;
  int **tab;
  int **col;
  int **row;
}	t_info;

#endif
