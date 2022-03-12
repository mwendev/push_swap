# push_swap

## Info

This programme sort numbers by using two stacks and a limited set of instructions. It gives you a set of operations as output. The goal is to implement sorting algorithms of choice and sort numbers with smallest number of moves.
Leakproofed.

- Grade: 98/100
- Keywords: Sorting algorithms/ Battery concept and handling elements/ Algorithm implementation
- Skills: Imperative programming/ Rigor/ Algorithms & AI/ Unix

## Game rules

- The game is composed of 2 stacks named `a` and `b`.
- To start with:
  - `a` contains a random numbe of either positive or negative numbers without any duplications, passed via terminal arguments (you must handle wrong input).
  - `b` is empty.
- The goal is to sort in ascending order numbers into stack a.
- To do this you have the following operations at your disposal:
  - `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - `ss` : `sa` and `sb` at the same time.
  - `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  - `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  - `rr` : `ra` and `rb` at the same time.
  - `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
  - `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
  - `rrr` : `rra` and `rrb` at the same time.
- At the end stack `b` must be emtpy and all integers must be sorted in ascending order in stack `a`.

## Solution

- To build the stacks: circular doubly linked list
- To sort the numbers: improved quick sort

## How to use

- Clone and cd to the repo

- Compile with make

- Execute `push_swap` with the numbers to sort as arguments

```sh
./push_swap 4 3 1 0 2
```

- If you want to sort large quantity of numbers (500 numbers with a range -1000 - 1000)

```sh
ARG=`seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '`; ./push_swap $ARG
```

- To check if the programme sorts the numbers correctly: pipe the output to executable ./checker/checker_Mac

```sh
./push_swap 4 3 1 0 2 | ./checker/checker_Mac 4 3 1 0 2
```

or

```sh
ARG=ARG=`seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '`; ./push_swap $ARG | ./checker/checker_Mac $ARG
```
