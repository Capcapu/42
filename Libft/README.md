# Libft - 42 School

Bibliothèque C personnalisée contenant les fonctions standards réimplémentées et des fonctions utilitaires.

## 📋 Description

Libft est le projet fondateur à l'école 42. Il contient des implémentations des fonctions de la libc et des fonctions utilitaires supplémentaires.

**Utilisation**: Base pour tous les projets suivants

## 🛠️ Compilation

```bash
make            # Crée une archive libft.a
make clean      # Nettoie les fichiers objets
make fclean     # Nettoie complètement
make re         # Recompile
```

## 📖 Utilisation

```bash
# Dans un Makefile
LIBFT = libft/libft.a
LIBFT_FLAGS = -L./libft -lft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft
```

## ✅ Notes

- Gestion correcte de la mémoire, aucun leak
- Respect de la norme 42
- Bonus: listes chaînées
