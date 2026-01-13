# C++ Modules (CPP00-CPP04) - 42 School

Introduction à la programmation orientée objet (OOP) en C++98.

## 📋 Description

Série de 5 modules progressifs pour apprendre le C++ et l'OOP:
- Syntaxe C++
- Classes et objets
- Forme canonique et opérateurs de surchage d'opération
- Héritage et polymorphisme
- Classes abstraites

**Standard**: C++98 (pas de C++11/14/17)

## 🛠️ Compilation

Chaque exercice a son propre Makefile:

```bash
cd CPP00/ex00
make            # Compile l'exercice
./nomExercice   # Lance le programme
make clean      # Nettoie
make fclean     # Nettoie complètement
```

## 📚 Contenu des modules

### CPP00 - Bases du C++

**Concepts**:
- Espaces de noms (namespace)
- Classes et instances
- Fonctions membres
- stdio streams
- Listes d'initialisation
- Static vs const

### CPP01 - Mémoire et Références

**Concepts**:
- Allocation mémoire (`new`/`delete`)
- Références vs pointeurs
- Switch statement
- Pointeurs sur fonctions membres
- Fichiers (ifstream/ofstream)

### CPP02 - Surcharge d'opérateurs

**Concepts**:
- Surcharge d'opérateurs
- Forme canonique Orthodoxe
- Nombres à virgule fixe
- Copy constructor
- Opérateur d'affectation

**Forme canonique**:
```cpp
class MyClass {
public:
    MyClass();                              // Constructeur par défaut
    MyClass(const MyClass &src);            // Copy constructor
    MyClass &operator=(const MyClass &rhs); // Opérateur d'affectation
    ~MyClass();                             // Destructeur
};
```

### CPP03 - Héritage

**Concepts**:
- Héritage simple
- Héritage multiple
- Diamond problem

### CPP04 - Polymorphisme

**Concepts**:
- Polymorphisme
- Classes abstraites
- Fonctions virtuelles pures
- Interfaces
- Deep copy vs Shallow copy

**Syntaxe**:
```cpp
class Abstract {
public:
    virtual void method() = 0;  // Fonction virtuelle pure
    virtual ~Abstract() {}      // Destructeur virtuel
};

class Concrete : public Abstract {
public:
    void method() { /* ... */ } // Implémentation
};
```

## 📖 Scripts utiles

### Générer une classe
```bash
cd CPP
./generate_class.sh MyClassName
# Génère: MyClassName.hpp et MyClassName.cpp avec forme canonique
```

### Créer des couleurs pour des affichages clairs des tests
```bash
./create_colors.sh
# Utilitaire pour les couleurs dans le terminal
```

## 📚 Ressources

- C++98 Reference
- cplusplus.com
- Orthodox Canonical Form (Coplien)
