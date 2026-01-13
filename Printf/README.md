# Printf - 42 School

Réimplémentation de la fonction `printf()` de la libc.

## 📋 Description

Implémentation d'une fonction printf personnalisée capable de gérer les formats principaux:
- `%d` et `%i` : entiers signés
- `%u` : entiers non signés
- `%x` et `%X` : hexadécimal (minuscules/majuscules)
- `%o` : octal
- `%c` : caractère
- `%s` : chaîne de caractères
- `%p` : pointeur
- `%%` : affiche un %

## 🛠️ Compilation

```bash
make            # Crée ft_printf.a
make clean      # Nettoie les fichiers objets
make fclean     # Nettoie complètement
./LibftPrintf     # Lance le programme test
```

Pour tester le programme :
- Décommenter le main dans ft_printf.c
- tester manuellement
```bash
cc -Wall -Wextra -Werror ft_printf.c ft_printf_outils.c ft_printf_outils2.c -L./Libft -lft -o ft_printf
./ft_printf
```