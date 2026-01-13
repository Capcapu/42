# Philosopher - 42 School

Simulation du problème des philosophers à table avec gestion de threads et mutex.

## 📋 Description

Implémentation du problème classique de synchronisation et concurrence: les "philosophers" mangent et pensent à une table. Chacun a besoin de **2 fourchettes** (à sa gauche et droite) pour manger.

**Challenge**: Éviter les deadlocks et race conditions tout en maximisant la concurrence.

## 🛠️ Compilation

```bash
make            # Crée l'exécutable philo
make clean      # Nettoie
make fclean     # Nettoie complètement
```

## 📚 Utilisation

```bash
./philo [nombre_de_philosophers] [temps_pour_mourir] [temps_pour_manger] [temps_pour_penser] [nombre_repas]

# Exemples
./philo 5 800 200 200
./philo 4 410 200 200 10
./philo 1 800 200 200
```

### Paramètres

- `nombre_de_philosophers` : Nombre de threads
- `temps_pour_mourir` : Temps avant la mort du philosophe (ms)
- `temps_pour_manger` : Durée du repas (ms)
- `temps_pour_penser` : Durée de la pensée (ms)
- `nombre_repas` (optionnel) : Nombre de fois que chacun doit manger (défaut: infini)

## 🔑 Concepts clés

### Threads et Mutex
- Chaque philosophe = 1 thread
- Chaque fourchette = 1 mutex

### États du philosophe
1. **Penser** (`thinking`)
2. **Prendre une fourchette** (`has fork 1`)
3. **Manger** (`eating`)
4. **Dormir** (`sleeping`)

### Format de sortie
```
[timestamp] [philosopher_id] is thinking
[timestamp] [philosopher_id] has taken a fork
[timestamp] [philosopher_id] is eating
[timestamp] [philosopher_id] is sleeping
[timestamp] [philosopher_id] died
```

## 🎯 Règles importantes

- ✅ Philosopher meurt s'il ne mange pas à temps
- ✅ Pas de race condition sur les timestamps
- ✅ Un philosophe ne peut pas être surveillé par plus d'1 thread
- ✅ Un philosophe ne peut pas prendre la fourchette d'un autre


## ✅ Notes

- Utilisation de `pthread` et `mutex`
- Gestion des microseconds (`usleep`)
- Respect de la norme 42

