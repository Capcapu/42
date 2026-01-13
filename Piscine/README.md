# Piscine - 42 School

Concours d'entrée de l'école 42. Introduction aux fondamentaux de la programmation en C et Unix.

## 📋 Description

La Piscine est une période intensive de 4 semaines où les candidats apprennent les bases:
- Programmation en C (variables, pointeurs, structures, fonctions)
- Shell Unix et scripting
- Algorithmique et logique de programmation

## 📂 Structure

```
C00-C07/        # Exercices progressifs en C
Shell00-01/     # Commandes Unix et Shell scripting
Rush01-02/      # Projets de groupe (2-3 jours)
Piscinereloaded/# Exercices à faire en début de tronc commun pour revoir les notions vues en piscine
```

## 🛠️ Compilation

Chaque exercice/projet a un main à décommenté ou un makefile:

```bash
cc C00/ex00.c
```

Ou pour les projets Rush:

```bash
cd Rush02
make
./rush-02
```

## 📚 Contenu

### C00 - Affichage et variables
- Affichage avec write
- Variables et types
- Boucles et conditions

### C01 - Pointeurs
- Utilisation des pointeurs
- Manipulation d'adresses
- Tableaux et pointeurs

### C02 - Strings
- Manipulation de chaînes de caractères
- Fonctions de conversion char

### C03 - Fonctions de la Libc 
- Recoder fonctions utiles

### C04 - Conversions
- Conversions int to char et inversement
- Conversions différentes bases

### C05 - Récursion avancée
- Problèmes mathématiques (factorielle, fibonacci)
- Optimisation

### C06 - Arguments de main
- argc et argv
- Parsing d'arguments

### C07 - Allocation mémoire
- malloc et free
- Structures dynamiques

### Shell00-Shell01
- Commandes de base Unix
- Scripting shell
- Variables d'environnement

