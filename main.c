#include "functions.h"

int 	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int		taille_file_1;
		int 	taille_file_2;

		taille_file_1 = 0;
		taille_file_2 = 0;
		taille_file_1 = taille_file(argv[2], 300);
		taille_file_2 = taille_file(argv[3], 300);
		my_start(taille_file_1, taille_file_2, argv);
	}
	else
		my_putstr("Veuillez entrer la dimenssion et deux fichiers en arguments.\n");
	return (0);
}