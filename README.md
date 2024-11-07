# push_swap: integer sorting

![pushswapgiflow](https://github.com/user-attachments/assets/413b89d1-9628-48e5-9b66-7c34556ea80c)

_(visualization of the program using [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer))_
 
This is a 42 School project. The goal was to sort integers passed as arguments from smallest to biggest in the least amount of steps using only 2 stacks.

Passed with the highest 100/100 score. To do that your program had to sort 100 random numbers in fewer than 700 operations and for 500 random numbers, there should be no more than 5500 operations.

## How to run

```
git clone git@github.com:kirkram/push_swap.git
cd push_swap
make
```
The input should be a set of integers, the output will be the commands performed to sort the two stacks.
There is a checker program for mac and linux to verify the results. The alternative is to use the visualizer mentioned above.

#### Checker
It will work as follows:
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
```
Replace `checker_OS` with `checker_Mac` or `checker_linux`. If the program `checker_OS` displays "KO", it means that push_swap came up
with a list of instructions that doesn’t sort the numbers.
