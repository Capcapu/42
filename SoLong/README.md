# SoLong - 42 School

Jeu 2D développé avec la bibliothèque graphique minilibx.

## 📋 Description

Petit jeu d'aventure 2D où le joueur doit:
1. Collecter tous les éléments (collectibles)
2. Atteindre la sortie

## 🛠️ Compilation

```bash
make            # Compilation complète
make clean      # Supprime les fichiers objets
make fclean     # Supprime tout
```

## 🎮 Utilisation

```bash
./so_long map/map.ber
```

Les cartes doivent être au format `.ber` avec les éléments:
- `1` : mur
- `0` : espace libre
- `P` : position du joueur
- `E` : sortie
- `C` : collectible

### Exemple de carte:
```
11111111
1P0000C1
10000001
1C0000E1
11111111
```

## 🎮 Contrôles

- `W` / `↑` : Haut
- `A` / `←` : Gauche
- `S` / `↓` : Bas
- `D` / `→` : Droite
- `ESC` : Quitter

## 📚 Fonctionnalités

### Essentielles
- ✅ Affichage d'une carte
- ✅ Mouvement du joueur (4 directions)
- ✅ Gestion des collectibles
- ✅ Condition de victoire (tous les collectibles + sortie)
- ✅ Affichage du nombre de mouvements

## 🎨 Éléments du code

- Parsing de la carte
- Gestion des événements (clavier)
- Boucle de jeu
- Rendu graphique

## ✅ Notes

- Respect de la norme 42
- Pas de memory leaks
