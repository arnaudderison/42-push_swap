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


## Summury

> not yet written

## Radix pseudo code

```
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