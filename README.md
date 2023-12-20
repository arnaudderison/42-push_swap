<h1 align="center">
	42 - Push_swap
</h1>
<p align="center">
    <i>Because Swap_push is less natural</i>
</p>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/arnaudderison/42-push_swap?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/arnaudderison/42-push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/arnaudderison/42-push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/arnaudderison/42-push_swap?color=green" />
</p>


## Goals 📝

> The main objective of this project is to sort data on a stack, using a limited set of operations and minimizing the number of these operations.

## Details 🔎
<b>Operations available:</b>
| Operations  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

<b>The program must work this way:</b>
```shell
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
```

## Tip for you 😋

<b>Radix pseudo code :</b>

```peudocode
fonction tri_radix(pile A):
max_val = trouver_max(pile A)
nb_bits = calculer_nb_bits(max_val)

pour chaque bit de 0 à nb_bits:
	pour chaque nombre dans pile A:
		si le bit actuel du nombre est 0:
			pb()  # pousser sur la pile B
		sinon:
			laisser sur la pile A

	tant que pile B n'est pas vide:
		pa()  # ramener tous les éléments sur la pile A
```