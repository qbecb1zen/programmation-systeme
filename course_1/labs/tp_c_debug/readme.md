# Utiliser GDB

## Question 1: Utiliser GDB

### 1.1: Gagner avec à la “loyale”

<hr>

Rien à faire, juste rentrer des valeurs en faisant une dichotomie

### 1.2: Retrouver le secret avec GDB

<hr>

```sh
gdb get_secret
```

Il suffit d'ajouter un breakpoint à la ligne du secret, `break 12`, récupérer le secret `p secret` puis run le programme pour jouer `run` et voilà c'est fini :)

### 1.3: Effectuer une attaque “Format String”

<hr>

```sh
gdb get_secret
```

On peut lister les élements de la mémoire: `disas main`, on obtient directement la position en mémoire, les fonctions appelées etc..

### 1.4

<hr>

```sh
gdb get_secret
```

Ici on va localiser en mémoire la partie contenant le secret, et à partir de là, puis `x/10x ...` pour avoir le contenu en hexa, à partir de là on peut obtenir le secret

## Question 2: Débogage avec GDB et Valgrind

<hr>
