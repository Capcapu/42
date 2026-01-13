# NetPractice - 42 School

Exercices pratiques de configuration réseau TCP/IP et calcul de sous-réseaux.

## 📋 Description

Projet d'apprentissage des réseaux informatiques avec:
- Configuration d'adresses IP
- Calcul de masques de sous-réseau
- Tables de routage
- Communication entre réseaux
- 10 niveaux de difficulté croissante

**Format**: Exercices interactifs via interface web

## 🎯 Objectifs

Comprendre et maîtriser:
- Adressage IPv4
- Masques de sous-réseau (CIDR)
- Tables de routage
- Passerelles (Gateway)
- Communication inter-réseau

## 📚 Concepts clés

### Adresse IP

Format: `192.168.1.10`
- 4 octets (0-255)
- Identifie un appareil sur le réseau

### Masque de sous-réseau

Format: `255.255.255.0` ou `/24` (CIDR)
- Détermine la partie réseau vs hôte
- Définit la taille du réseau

Exemples:
- `/24` = `255.255.255.0` → 256 adresses (254 utilisables)
- `/25` = `255.255.255.128` → 128 adresses
- `/30` = `255.255.255.252` → 4 adresses (2 utilisables)

### Plage d'adresses

Pour `192.168.1.0/24`:
- **Réseau**: `192.168.1.0`
- **Première IP utilisable**: `192.168.1.1`
- **Dernière IP utilisable**: `192.168.1.254`

### Gateway (Passerelle)

- Permet la communication entre réseaux différents
- Généralement la première ou dernière IP du réseau
- Exemple: `192.168.1.1` ou `192.168.1.254`

## 🔢 Calculs utiles

### Nombre d'hôtes

Formule: $2^{(32-prefix)} - 2$

Exemples:
- `/24` → $2^8 - 2 = 254$ hôtes
- `/25` → $2^7 - 2 = 126$ hôtes
- `/30` → $2^2 - 2 = 2$ hôtes

### Conversion CIDR ↔ Masque décimal

| CIDR | Masque | Hôtes |
|------|--------|-------|
| /8 | 255.0.0.0 | 16,777,214 |
| /16 | 255.255.0.0 | 65,534 |
| /24 | 255.255.255.0 | 254 |
| /25 | 255.255.255.128 | 126 |
| /26 | 255.255.255.192 | 62 |
| /27 | 255.255.255.224 | 30 |
| /28 | 255.255.255.240 | 14 |
| /29 | 255.255.255.248 | 6 |
| /30 | 255.255.255.252 | 2 |

## 📊 Niveaux

### Level 1-3 : Basique
- Configuration d'adresses IP simples
- Masques de sous-réseau
- Communication directe

### Level 4-6 : Intermédiaire
- Tables de routage
- Passerelles
- Sous-réseaux multiples

### Level 7-9 : Avancé
- Routage complexe
- Multiples routeurs
- Optimisation des masques

### Level 10 : Expert
- Architecture réseau complète
- Routage multi-niveaux
- Optimisation totale

## 🛠️ Utilisation

Les fichiers `.json` contiennent les configurations des niveaux:

```bash
# Ouvrir dans l'interface web fournie par 42
# Ou éditer manuellement les JSON

cat level1.json
cat level5.json
```

## ✅ Notes

- Pas de code à écrire
- Exercices pratiques de configuration
- Validation automatique des solutions sur une plateforme de 42
