# Cub3D - 42 School

Moteur de rendu 3D utilisant la technique du **raycasting**, inspiré de Wolfenstein 3D.

## 📋 Description

Création d'un jeu 3D en vue first-person avec:
- Moteur raycasting pour le rendu 3D
- Parser de carte personnalisé (format `.cub`)
- Textures murales
- Déplacement du joueur
- Gestion des collisions

**Moteur graphique**: minilibx (wrapper X11)

## 🛠️ Compilation

```bash
make            # Version standard
make bonus      # Version bonus
make clean      # Nettoie les .o
make fclean     # Nettoie complètement
make re         # Recompile
```

## 📚 Utilisation

```bash
./cub3D map/test.cub
./cub3D_bonus map/test_bonus.cub    # Version bonus
```

### Format de carte (.cub)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,230,220

        1111111111111
        1000000000001
        1000000000001
111111111000N00000001
100000000000000000001
100000000000000000001
100000001111111111111
10000000011
11111111111
```

**Éléments**:
- `1` : Mur
- `0` : Espace libre
- `N/S/E/W` : Position et orientation initiale du joueur
- `NO/SO/WE/EA` : Textures pour chaque direction
- `F` : Couleur du sol (RGB)
- `C` : Couleur du plafond (RGB)

## 🎮 Contrôles

### Déplacements
- `W` : Avancer
- `S` : Reculer
- `A` : Se déplacer à gauche
- `D` : Se déplacer à droite

### Vision
- `←` : Tourner la caméra à gauche
- `→` : Tourner la caméra à droite

### Autre
- `ESC` : Quitter le jeu
- `X` (fermer la fenêtre) : Quitter

## 🎯 Fonctionnalités

### Essentielles
- ✅ Raycasting complet
- ✅ Textures différentes pour chaque direction (N, S, E, W)
- ✅ Parsing et validation de carte
- ✅ Gestion des collisions
- ✅ Déplacements fluides
- ✅ Rotation de la caméra

### Bonus
- 🎁 Minimap
- 🎁 Sprites animés murs
- 🎁 Rotation souris

## 🔧 Algorithme Raycasting

1. **Pour chaque colonne de pixels** sur l'écran:
   - Lance un rayon depuis la position du joueur
   - Calcule l'intersection avec le mur le plus proche (DDA)
   - Détermine la hauteur du mur à afficher
   - Applique la texture appropriée

2. **Optimisations**:
   - Utilisation de l'algorithme DDA (Digital Differential Analysis)
   - Pre-calcul des distances

## 📂 Structure

```
sources/          # Code version standard
sources_bonus/    # Code version bonus
includes/         # Headers
Libft/           # Bibliothèque personnalisée
minilibx-linux/  # Bibliothèque graphique
map/valide/      # Cartes de test
```

## ✅ Notes

- Respect de la norme 42
- Gestion complète de la mémoire (sans leaks)
- Validation stricte des cartes
