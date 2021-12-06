# push_swap

## Description

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.

## Requirement

- gcc or Clang
- GNU Make

## Instructions

- `sa`:  swap a - swap the first 2 elements at the top of stack a.
- `sb`:  swap b - swap the first 2 elements at the top of stack b.
- `ss`:  sa and sb at the same time.
- `pa`:  push a - take the first element at the top of b and put it at the top of a.
- `pb`:  push b - take the first element at the top of a and put it at the top of b.
- `ra`:  rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb`:  rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr`:  ra and rb at the same time.
- `rra`: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb`: reverse rotate b - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrr`: rra and rrb at the same time.

## Usage

```
git clone https://github.com/ryo-manba/push_swap
cd push_swap && make
```
An executable named `push_swap` and `checker` will be created.
```
./push_swap 2 4 3 1 # Outputs a command to sort an stack.
sa
rra
sa
ra

./checker 2 4 3 1 # Check that it is sorted correctly.
sa
rra
sa
ra
Ctrl+D
OK
```

## Author

[twitter](https://twitter.com/ryo_manba)

## Licence

All code is released under the [MIT](https://github.com/ryo-manba/push_swap/blob/main/LICENSE) license
