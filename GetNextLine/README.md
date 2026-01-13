# GetNextLine - 42 School

Fonction pour lire un fichier ligne par ligne de manière efficace.

## 📋 Description

Implémentation d'une fonction `get_next_line()` qui lit un fichier descriptor ligne par ligne (separateur '\n') et retourne une ligne complète.


## 🛠️ Compilation

```bash
# Version standard
cc get_next_line.c get_next_line_utils.c

# Version bonus (plusieurs descripteurs)
cc get_next_line_bonus.c get_next_line_utils_bonus.c
```

## 📚 Utilisation

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🔑 Caractéristiques

- ✅ Retourne une ligne à la fois
- ✅ Lecture jusqu'à `\n` ou fin de fichier
- ✅ Buffer statique optimisé (configurable avec `-D BUFFER_SIZE`)
- ✅ Gestion de plusieurs descripteurs (bonus)
- ✅ Pas de memory leaks

## 📖 BUFFER_SIZE

```bash
# Tailles courantes
gcc -D BUFFER_SIZE=1 ...      # Très lent, lit 1 char à la fois
gcc -D BUFFER_SIZE=42 ...     # Recommandé
gcc -D BUFFER_SIZE=1024 ...   # Plus rapide
gcc -D BUFFER_SIZE=10000 ...  # Très rapide
```

## ✅ Notes

- Fonction static pour garder le contexte entre appels
- Bonus: Gestion de plusieurs descripteurs de fichiers simultanément
