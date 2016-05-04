#include "functions.h"
#include <time.h>

void	my_print_real_tab(t_info my_info)
{
  int i;
  int j;

  i = 0;
  j = 0;
  usleep(50000);
  my_putstr("\033c");
  while (i < my_info.nbligne)
    {
      while (j < my_info.nbcolonne)
	{
	  if (my_info.tab[i][j] == 1)
	    my_putstr("\033[42m  \033[0m");
	  if (my_info.tab[i][j] == 0)
	    my_putstr("\033[47m  \033[0m");
	  if (my_info.tab[i][j] == 2)
	  my_putstr("\033[41m  \033[0m");
	  j++;
	  }
      my_putchar('\n');
      j = 0;
      i++;
    }
}

int	my_count_total(int* row)
{
  int i;
  int total;

  i = 0;
  total = 0;
  while (row[i] != -1)
    {
      total = total + row[i];
      i++;
      if (i > 1)
	total++;
    }
  return (total);
}

int	**my_remplissage_col(int **tab, int *col, int j, int nbligne)
{
  int i;
  int x;
  int z;

  z = 0;
  i = 0;
  x = 0;
  while (col[i] != -1)
    {
      x = col[i];
      while (x > 0)
        {
          tab[z][j] = 1;
          x--;
          z++;
        }
      if (z < nbligne)
	tab[z][j] = 2;
      z++;
      i++;
    }
  return (tab);
}

int	*my_remplissage_row(int *tab, int *row, int nbcolonne)
{
  int i;
  int x;
  int j;

  i = 0;
  x = 0;
  j = 0;
  while (row[i] != -1)
    {
      x = row[i];
      while (x != 0)
	{
	  tab[j] = 1;
	  x--;
	  j++;
	}
      if (j < nbcolonne)
	tab[j] = 2;
      j++;
      i++;
    }
  return (tab); 
}

int	*my_remplissage_row2(int *tab, int *row, int nbcolonne)
{
  int i;
  int x;
  int j;
  int *s1;
  int *s2;

  j = 0;
  i = 0;
  while (row[i] != -1)
    {
      if (row[i] > nbcolonne / 2)
	{
	  x = row[i];
	  s1 = (int*)malloc(sizeof(int) * nbcolonne);
	  s2 = (int*)malloc(sizeof(int) * nbcolonne);
	  while (x > 0)
	    {
	      s1[j] = 1;
	      s2[(nbcolonne - 1) - j] = 1;
	      j++;
	      x--;
	    }
	  x = 0;
	  while (x < nbcolonne)
	    {
	      if (s1[x] == s2[x])
		tab[x] = 1;
	      x++;
	    } 
	}
      i++;
    }
  return (tab);
}

int	**my_remplissage_col2(int **tab, int *col, int nbligne, int y)
{
  int i;
  int *s1;
  int *s2;
  int x;
  int j;

  j = 0;
  i = 0;
  while (col[i] != -1)
    {
      if (col[i] > nbligne / 2)
        {
          x = col[i];
          s1 = (int*)malloc(sizeof(int) * nbligne);
          s2 = (int*)malloc(sizeof(int) * nbligne);
          while (x > 0)
            {
              s1[j] = 1;
              s2[(nbligne - 1) - j] = 1;
              j++;
              x--;
            }
          x = 0;
          while (x < nbligne)
            {
              if (s1[x] == s2[x])
                tab[x][y] = 1;
              x++;
            }
        }
      i++;
    }
  return (tab);
}


t_info	my_algo_row(t_info my_info)
{
  int i;
  int j;
  int total;

  i = 0;
  j = 0;
  while (i < my_info.nbligne)
    {
      if (my_info.row[i][0] == my_info.nbcolonne)
	{
	  while (j < my_info.nbcolonne)
	    {
	      my_info.tab[i][j] = 1;
	      j++;
	    }
	  j = 0;
	}
      else
	{
	  total = my_count_total(my_info.row[i]);
	  if (total == my_info.nbcolonne)
	    my_info.tab[i] = my_remplissage_row(my_info.tab[i], my_info.row[i], my_info.nbcolonne);
	  else if (total > (my_info.nbcolonne) / 2)
	    my_info.tab[i] = my_remplissage_row2(my_info.tab[i], my_info.row[i], my_info.nbcolonne);
	}
      i++;
    }
  return(my_info);
}

t_info	my_algo_col(t_info my_info)
{
  int i;
  int j;
  int total;

  i = 0;
  j = 0;
  while (j < my_info.nbcolonne)
    {
      if (my_info.col[0][j] == my_info.nbligne)
        {
          while (i < my_info.nbligne)
            {
              my_info.tab[i][j] = 1;
              i++;
            }
          i = 0;
        }
      else
	{
          total = my_count_total(my_info.col[j]);
	  if (total == my_info.nbligne)
	    my_info.tab = my_remplissage_col(my_info.tab, my_info.col[j], j, my_info.nbligne);
	  else if (total > (my_info.nbligne) / 2)
            my_info.tab = my_remplissage_col2(my_info.tab, my_info.col[j], my_info.nbligne, j);
	}
      j++;
    }
  return(my_info);
}


int**	my_new_tab(t_info my_info)
{
  int **tab;
  int i; 

  tab = (int **)malloc ( sizeof(int *)  *  my_info.nbligne);
  for (i = 0 ; i < my_info.nbligne ; i++){
    tab[i] = (int *)malloc (sizeof(int) * my_info.nbcolonne);
  }
  return (tab);
}

int	my_count_colrow(int *col)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (col[i] != -1)
    {
      count = count + col[i];
      i++;
    }
  return (count);
}

int	my_count_tab_col(int **tab, int x, int nbligne)
{
  int i;
  int count;

  count = 0;
  i = 0;
  while (i < nbligne)
    {
      if (tab[i][x] == 1)
	count = count + 1;
      i++;
    }
  return (count);
}

int	**my_remplissage_false_col(int **tab, int x, int nbligne)
{
  int i;

  i = 0;
  while (i < nbligne)
    {
      if (tab[i][x] != 1)
	tab[i][x] = 2;
      i++;
    }
  return (tab);
}

int	**my_search_true_col(t_info my_info, int x)
{
  int i;
  int j;
  int z;
  int zz;
  int count;

  count = 0;
  i = 0;
  j = 0;
  z = 0;
  while (i < my_info.nbligne)
    {
      zz = 0;
      while (my_info.tab[i][x] == 2 && i < my_info.nbligne - 1)
	i++;
      while (my_info.tab[i][x] != 2 && z == 0)
	{
	  i++;
	  j++;
	  if (i + 1 == my_info.nbligne && my_info.tab[i][x] != 2)
	    {
	      z = 1;
	      j++;
	    }
	}
      if (j == my_info.col[x][count])
	{
	  i = i - j;
	  count++;
	  while (my_info.tab[i][x] != 2 && zz == 0)
	    {
	      my_info.tab[i][x] = 1;
      	      i++;
	      if (i + 1 == my_info.nbligne)
		zz = 1;
	    }
	}
      else
	i++;
      j = 0;
    }
  return (my_info.tab);
}


t_info	my_search_false_col(t_info my_info)
{
  int x;
  int count;
  int count_tab;

  x = 0;
  while (x < my_info.nbcolonne)
    {
      count = my_count_colrow(my_info.col[x]);
      count_tab = my_count_tab_col(my_info.tab, x, my_info.nbligne);
      if (count == count_tab)
	{
	  my_info.tab = my_remplissage_false_col(my_info.tab, x, my_info.nbligne);
	  my_print_real_tab(my_info);
	}
            else
             	my_info.tab = my_search_true_col(my_info, x);
      x++;
    }
  return (my_info);
}


int     my_count_tab_row(int **tab, int x, int nbligne)
{
  int i;
  int count;

  count = 0;
  i = 0;
  while (i < nbligne)
    {
      if (tab[x][i] == 1)
        count = count + 1;
      i++;
    }
  return (count);
}

int	**my_remplissage_false_row(int **tab, int x, int nbligne)
{
  int i;

  i = 0;
  while (i < nbligne)
    {
      if (tab[x][i] != 1)
        tab[x][i] = 2;
      i++;
    }
  return (tab);
}

int	**my_search_true_row(t_info my_info, int x)
{
  int i;
  int j;
  int z;
  int zz;
  int count;

  count = 0;
  i = 0;
  j = 0;
  z = 0;
  while (i < my_info.nbcolonne)
    {
      zz = 0;
      while (my_info.tab[x][i] == 2 && i < my_info.nbcolonne - 1)
        i++;
      while (my_info.tab[x][i] != 2 && z == 0)
        {
          i++;
          j++;
          if (i + 1 == my_info.nbcolonne && my_info.tab[x][i] != 2)
            {
              z = 1;
              j++;
            }
        }
      if (j == my_info.row[x][count])
        {
          i = i - j;
          count++;
          while (my_info.tab[x][i] != 2 && zz == 0)
            {
              my_info.tab[x][i] = 1;
              i++;
              if (i + 1 == my_info.nbcolonne)
                zz = 1;
            }
        }
      else
        i++;
      j = 0;
    }
  return (my_info.tab);
}



t_info my_search_false_row(t_info my_info)
{
  int x;
  int count;
  int count_tab;

  x = 0;
  while (x < my_info.nbligne)
    {
      count = my_count_colrow(my_info.row[x]);
      count_tab = my_count_tab_row(my_info.tab, x, my_info.nbcolonne);
      if (count == count_tab)
        my_info.tab = my_remplissage_false_row(my_info.tab, x, my_info.nbcolonne);
                 else
       	my_info.tab = my_search_true_row(my_info, x);
      x++;
    }
  return (my_info);
}

int 	my_algo(int *result, char **argv, int **tab1, int **tab2)
{
  t_info my_info;
  int x;

  x = 0;

  my_info.nbligne = result[0];
  my_info.nbcolonne = result[1];
  my_info.col = tab1;
  my_info.row = tab2;
  my_info.tab = my_new_tab(my_info);
  my_print_real_tab(my_info);
  my_info = my_algo_row(my_info);
  my_print_real_tab(my_info);
  my_info = my_algo_col(my_info);
  while (x < 3)
    {
      my_info = my_search_false_col(my_info);
      my_info = my_search_false_row(my_info);
      my_print_real_tab(my_info);
      x++;
    }
  my_print_real_tab(my_info);
  my_putstr("\n");
  my_putstr(argv[0]);
  return (0);
}
