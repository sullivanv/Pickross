#include "functions.h"

int		my_strlen(char *str)
{
  int   i;

  i = 0;
  while (*(str + i) != '\0')
  {
    i++;
  }
  return (i);
}

char  *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (*(src + i))
  {
    *(dest + i) = *(src + i);
    i++;
  }
  return (dest);
}

char  *my_strdup(char *str)
{
  char  *tab;

  if (str != NULL)
  {
    if ((tab =  malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
      return (NULL);
    else
      return (my_strcpy(tab, str));
  }
  return (NULL);
}

int   my_getnbr(char *str)
{
  int   count;
  int   i;
  int   value;
  int   h;

  count = 0;
  i = 0;
  h = 0;
  value = 0;
  while (str[i] != '\0' && h != 1)
  {
    if (str[i] == '-')
      count++;
    else if (str[i] >= '0' && str[i] <= '9')
    {
      value = ((value * 10) + (str[i] - 48));
      if ((str[i + 1] < '0') || (str[i + 1] > '9'))
        h = 1;
    }
    i++;
  }
  if (value == 2147483647 && (count % 2 != 0))
    value = -2147483647;
  else if (count % 2 != 0)
    value = value * (-1);
  return (value);
}

int   taille_file(char *dossier, int taille_file)
{
  int   handle;
  int   size;
  int   *content;

  size = 0;
  if (!(content = malloc((taille_file * sizeof(char)))))
    return (-1);
  handle = open(dossier, O_RDONLY);
  size = read(handle, content, taille_file * sizeof(char));
  close(handle);
  return (size);
}