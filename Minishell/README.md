# Minishell - 42 School

Implémentation d'un shell Unix simplifié avec parsing, exécution de commandes, pipes et redirections.

## 📋 Description

Recréation d'un mini shell Bash avec les fonctionnalités essentielles:
- Exécution de commandes
- Pipes (`|`)
- Redirections (`<`, `>`, `>>`)
- Variables d'environnement
- Signaux (CTRL+C, CTRL+D, CTRL+\\)
- Builtins

## 🛠️ Compilation

```bash
make            # Crée l'exécutable minishell
make clean      # Nettoie les fichiers objets
make fclean     # Nettoie complètement
make re         # Recompile tout
```

### Dépendances

```bash
# Installer readline
sudo apt-get install libreadline-dev

# Copier la Libft dans le dossier
# Le Makefile attend un dossier "Libft" avec libft.a
```

## 📚 Utilisation

```bash
./minishell
```

Exemples de commandes:
```bash
minishell$ echo "Hello World"
minishell$ ls -la | grep txt
minishell$ cat < input.txt | wc -l > output.txt
minishell$ export PATH=/usr/bin
minishell$ cd ..
minishell$ pwd
minishell$ exit
```

## 🎯 Fonctionnalités

### Builtins implémentés
- `echo` (avec option `-n`)
- `cd` (avec chemin relatif ou absolu)
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

### Parsing et Exécution
- **Lexing**: Tokenization de la ligne de commande
- **Parsing**: Construction de l'arbre de commandes
- **Expansion**: Variables d'environnement (`$VAR`, `$?`)
- **Execution**: Fork, pipes, redirections

### Redirections
- `<` : Redirection d'entrée
- `>` : Redirection de sortie (écrase)
- `>>` : Redirection de sortie (append)

### Signaux
- `CTRL+C` : Interrompt la commande en cours
- `CTRL+D` : Quitte le shell (EOF)
- `CTRL+\` : Ignoré (comme bash)

## 📂 Structure du code

```
sources/
├── parsing/        # Analyse syntaxique
├── lexing/         # Tokenization
├── execution/      # Exécution des commandes
├── builtins/       # Commandes intégrées
├── signals/        # Gestion des signaux
├── memory_utils/   # Gestion mémoire
└── error/          # Gestion d'erreurs
```

## ✅ Notes

- **Version sans bonus** (pas de here-doc, pas d'opérateurs logiques)
- Utilise **readline** pour l'édition de ligne et l'historique
- Gestion complète de la mémoire (sans leaks)
- Respect de la norme 42
