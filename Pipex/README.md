# Pipex - 42 School

Reproduction du comportement des pipes Unix avec gestion des processus enfants.

## 📋 Description

Simulation de la commande shell: `cmd1 | cmd2`

Objectif: Apprendre à gérer les **processus enfants**, les **pipes**, et les **redirections** d'entrée/sortie.

## 🛠️ Compilation

```bash
make            # Crée l'exécutable pipex
make clean      # Nettoie
make fclean     # Nettoie complètement
make bonus      # Compile la version bonus
```

## 📚 Utilisation

```bash
./pipex infile cmd1 cmd2 outfile

# Équivalent shell:
< infile cmd1 | cmd2 > outfile
```

### Exemples

```bash
./pipex input.txt "cat" "wc -l" output.txt
# Équivalent: cat input.txt | wc -l > output.txt

./pipex input.txt "grep hello" "sort" output.txt
# Équivalent: grep hello < input.txt | sort > output.txt
```

## 🔑 Concepts clés

### Processus et Fork

Utilisation de processus enfants car execve(), remplace le processus dans lequel il est implémenté.

```c
pid_t child = fork();
if (child == 0) {
    // Processus enfant
    execve(path, args, envp);
} else {
    // Processus parent
    waitpid(child, NULL, 0);
}
```

### Pipes
```c
int fd[2];
pipe(fd);           // fd[0] = lecture, fd[1] = écriture
close(fd[0]);       // Parent ferme la lecture
close(fd[1]);       // Enfant ferme l'écriture
```

### Redirections
```c
dup2(fd_in, STDIN_FILENO);    // Entrée depuis fichier
dup2(fd_out, STDOUT_FILENO);  // Sortie vers fichier
```

## 📊 Flux d'exécution

```
Parent Process
    ├─ Fork Child 1
    │   ├─ Ouvre infile
    │   ├─ Redirige stdin vers infile
    │   ├─ Crée pipe
    │   ├─ Redirige stdout vers pipe
    │   └─ Execute cmd1
    │
    └─ Fork Child 2
        ├─ Redirige stdin depuis pipe
        ├─ Ouvre outfile
        ├─ Redirige stdout vers outfile
        └─ Execute cmd2
```

## 🎯 Bonus

Gestion de **multiples pipes**:
```bash
./pipex infile cmd1 cmd2 cmd3 ... cmdN outfile
# Équivalent: cmd1 < infile | cmd2 | cmd3 | ... | cmdN > outfile
```

## ✅ Notes

- Parsing
- Respect de la norme 42
- Bonus: Multiples commandes enchaînées
