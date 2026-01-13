# Push_swap - 42 School

Algorithme de tri optimisé utilisant deux stacks et un ensemble d'opérations limitées.

## 📋 Description

Tri d'un tableau d'entiers avec le minimum d'opérations possible en utilisant **deux stacks** (a et b).

**Challenge**: Minimiser le nombre de mouvements tout en respectant les contraintes.

## 🛠️ Compilation

```bash
make            # Crée l'exécutable push_swap
make clean      # Nettoie
make fclean     # Nettoie complètement
make bonus      # Compile le checker (optionnel)
```

## 📚 Utilisation

```bash
./push_swap 3 1 2
./push_swap 5 2 8 1 9 3

# Avec le checker (bonus)
ARG="3 1 2"; ./push_swap $ARG | ./checker $ARG
```

## 🔑 Opérations autorisées

**Sur la stack a:**
- `pa` : Push (top du b vers top du a)
- `ra` : Rotate (décale tous les éléments vers le haut)
- `rra` : Reverse rotate (décale vers le bas)

**Sur la stack b:**
- `pb` : Push (top du a vers top du b)
- `rb` : Rotate
- `rrb` : Reverse rotate

**Sur les deux:**
- `ss` : Execute sa et sb simultanément
- `rr` : Execute ra et rb
- `rrr` : Execute rra et rrb

## 📊 Performance

```
3 nombres:    3-5 opérations
5 nombres:    12 opérations (théorique)
100 nombres:  700-900 opérations
500 nombres:  5500-7000 opérations
```

## 🎯 Approches possibles

Algorithme de tri Turkish

## 📖 Structure

```
Stack A: [3, 1, 2] (input)
Stack B: []

Opérations: pb, pb, pa, pb, pa, ra...
Résultat:
Stack A: [1, 2, 3]
Stack B: []
```

## ✅ Notes

- Gestion efficace de la mémoire
- Optimisation de l'algorithme
- Respect de la norme 42
