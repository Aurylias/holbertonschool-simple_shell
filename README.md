# Simple Shell

Un shell UNIX minimaliste écrit en C, inspiré de `sh`. Il lit une commande, la cherche dans le `PATH`, l'exécute dans un processus fils et attend sa terminaison.

## Description

`simple_shell` fonctionne en boucle : il affiche une invite, lit une ligne, la découpe en arguments, puis :

- si la commande est un builtin (`exit`, `env`), il l'exécute directement dans le processus courant ;
- sinon, il cherche l'exécutable dans le `PATH`, crée un processus fils avec `fork`, et lance le programme avec `execve`.

Le shell fonctionne aussi bien en mode interactif (avec une invite `->$ `) qu'en mode non-interactif, via un pipe ou un fichier redirigé sur l'entrée standard.

## Compilation

Le projet se compile avec :

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## Utilisation

Mode interactif :

```
$ ./simple_shell
->$ /bin/ls
simple_shell  simple_shell.c  simple_shell.h
->$ exit
$
```

Mode non-interactif :

```
$ echo "/bin/ls" | ./simple_shell
simple_shell  simple_shell.c  simple_shell.h
```

## Commandes internes (builtins)

| Commande | Description                          |
|----------|---------------------------------------|
| `exit`   | Quitte le shell                       |
| `env`    | Affiche les variables d'environnement |

## Structure du projet

| Fichier                    | Rôle                                                              |
|-----------------------------|--------------------------------------------------------------------|
| `simple_shell.c`            | Point d'entrée, boucle principale du shell                        |
| `prompt.c`                  | Affiche l'invite et lit la ligne saisie par l'utilisateur         |
| `extract_command_args.c`    | Découpe la ligne saisie en tableau d'arguments                    |
| `find_path.c`                | Recherche l'exécutable dans les répertoires du `PATH`             |
| `create_child.c`             | Crée le processus fils et exécute la commande avec `execve`       |
| `free_argv.c`                | Libère la mémoire allouée pour le tableau d'arguments             |
| `built-in.c`                 | Implémente les commandes internes `exit` et `env`                 |
| `simple_shell.h`             | Prototypes des fonctions et includes communs                      |

## Fonctions et appels système autorisés

Toutes les fonctions de `string.h`, ainsi que :

`access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `printf`, `fprintf`, `vfprintf`, `sprintf`, `putchar`, `read`, `readdir`, `signal`, `stat` (`__xstat`), `lstat` (`__lxstat`), `fstat` (`__fxstat`), `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`.

## Ce que ce projet permet de comprendre

- Le fonctionnement d'un shell
- Ce que sont un `pid` et un `ppid`
- Comment manipuler l'environnement du processus courant
- La différence entre une fonction et un appel système
- Comment créer des processus
- Les trois prototypes de `main`
- Comment le shell utilise le `PATH` pour trouver les programmes
- Comment exécuter un autre programme avec l'appel système `execve`
- Comment suspendre l'exécution d'un processus jusqu'à la fin d'un de ses fils
- Ce qu'est `EOF` (fin de fichier)

## Auteur

Projet réalisé par Jean De Foucault-Lebel et Bryce Vermorel dans le cadre d'un cursus de programmation système en C.
