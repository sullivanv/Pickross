#include "functions.h"

int 	my_start(int taille_file_1, int taille_file_2, char **argv)
{
	int 	**tab1;
	int 	**tab2;
	int 	*result;
	int 	check_1;
	int 	check_2;

	check_1 = check_file_size(argv[2], taille_file_1);
	check_2 = check_file_size(argv[3], taille_file_2);

	result = malloc(2 * sizeof(int));
	result = my_parse_arg_1(argv[1]);

	if (result[0] == -1 || result[1] == -1)
		return (-1);
	else if (check_1 != result[1] || check_2 != result[0])
	{
		my_putstr("Les dimension en arguments ne correspondent pas au fichier\nformat: [row * col]\n");
		return (-1);
	}
	tab1 = sort_file(argv[2], taille_file_1, result[1]);
	tab2 = sort_file(argv[3], taille_file_2, result[0]);
	if (tab1[0][0] != -3 && tab2[0][0] != -3)
		my_algo(result, argv, tab1, tab2);
	else
		my_putstr("Votre fichier ne doit contenir que des nombres.\n");
	return (1);
}

int 	check_file_size(char *dossier, int taille_file)
{
	int 	handle;
	int		size;
	char	*content;
	int		result;
	int 	i;

	result = 0;
  	size = 0;
  	i = 0;
  	if ((content = malloc((taille_file * sizeof(char)))) == NULL)
    	return (-1);
  	handle = open(dossier, O_RDONLY);
  	size = read(handle, content, taille_file * sizeof(char));
  	close(handle);
  	while (content[i] != '\0')
	{
		if (content[i] == '\n')
			result += 1;
		i++;
	}
  	return (result + 1);
}

int 	*my_parse_arg_1(char *str)
{
	int		i;
	int 	z;
	int 	c;
	int 	f;
	int 	s;
	int 	*tab;
	char 	**stock;
	int 	check;

	tab = malloc(2 * sizeof(int));
	stock = my_tab();
	i = z = -1;
	c = f = s = check = 0;
	while (str[c] != '\0')
	{
		if ((str[c] - 48) >= 0 && (str[c] - 48) <= 9)
		{
			stock[f][s] = str[c];
			s++;
		}
		if (str[c] == '*')
		{
			check += 1;
			f++;
			s = 0;
		}
		c++;
	}
	if (check == 1)
	{
		i = my_getnbr(stock[0]);
		z = my_getnbr(stock[1]);
	}
	else
	{
		i = -1;
		z = -1;
	}
	tab[0] = i;
	tab[1] = z;
	return (tab);
}

char	**my_tab(void)
{
	char 	**stock;
	int 	i;

	i = 0;
	stock = malloc(10 * sizeof(char*));
	while (i < 10)
	{
		stock[i] = malloc(10 * sizeof(char));
		i++;
	}
	return (stock);
}

int   **sort_file(char *dossier, int taille_file, int dim)
{
	int 	handle;
	int		size;
	char	*content;
	int		**error;

	error = malloc(1 * sizeof(int*));
  	error[0] = malloc(1 * sizeof(int));
  	error[0][0] = -1;
  	size = 0;
  	if ((content = malloc((taille_file * sizeof(char)))) == NULL)
    	return (error);
  	handle = open(dossier, O_RDONLY);
  	size = read(handle, content, taille_file * sizeof(char));
  	close(handle);
  	error = my_sort(content, dim);
  	return (error);
}

int 	**my_sort(char *content, int dim)
{
	int 	i, convert, a, b, limit;
	int 	**tab;

	a = 0;
	b = 0;
	limit = 0;
	convert = 0;
	i = 0;
	tab = malloc((dim + 1) * sizeof(int*));
	while (limit < dim + 1)
	{
		tab[limit] = malloc(15 * sizeof(int));
		limit++;
	}
	while (content[i] != '\0')
	{
		if (content[i] == '\n')
		{
			tab[a][b] = -1;
			b = 0;
			a++;
		}
		else
		{
			convert = content[i] - 48;
			if (content[i] - 48 >= 0 && content[i] - 48 <= 9)
			{
				while (content[i + 1] != '\n' && content[i + 1] != '.' && content[i + 1] != '\0')
				{
					if (content[i + 1] - 48 >= 0 && content[i + 1] - 48 <= 9)
						convert = (convert * 10) + (content[i + 1] - 48);
					else if (content[i + 1] != '.' && content[i + 1] != '\n' && content[i + 1] != '\0')
					{
						tab[0][0] = -3;
						return (tab);
					}
					i++;
				}
			}
			if (content[i] != '.')
			{
				tab[a][b] = convert;
				b++;
			}
		}
		i++;
	}
	tab[a][b] = -1;
	return (tab);
}