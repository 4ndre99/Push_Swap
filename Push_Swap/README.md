*This project has been created as part of the 42 curriculum by ade-arau and marcooli*

# Description

Push Swap is a sorting program that sorts a stack of integers using a limited set of operations and an auxiliary stack. The challenge is not simply to sort the numbers, but to do so using the fewest possible operations. This implementation includes multiple sorting strategies and an adaptive mode that automatically chooses the most suitable algorithm based on the disorder of the input. The strategies used were the following:


## Simple Strategy

Best suited for nearly sorted or very small inputs.
Uses repeated extraction of the smallest element and reinsertion.

## Medium Strategy

A cost-based approach that goes by the name of **Turk** that moves elements to stack B, calculates the cheapest move available, optimizes rotations and rebuilds stack A efficiently. This strategy relies on:

- Target nodes
- Move planning
- Operation cost comparison
- Combined rotations (`rr` / `rrr`)

## Complex Strategy

A strategy used for large datasets and is based on a binary **Radix Sort**, chosen for its predictable performance and compatibility with the limited Push Swap operations. Before sorting, all values are converted into rank values, replacing each number with its position in the sorted sequence. These ranks are generated using **Quicksort** on a copy of the input, allowing the algorithm to effiently normalize the dataset. Once ranked, the numbers are processed bit by bit through Radix Sort until the stack is fully sorted. Strategy advantages:

- Deterministic performance
- Simple implementation
- Excellent compatibility with Push Swap operations
- Strong results for 100 and 500 number benchmarks

## Adaptive Strategy

This is the input default mode if no tag has been aplied.
The program evaluates the disorder of the input and automatically chooses the most appropriate strategy.

```text
Low disorder     -> Simple
Medium disorder  -> Medium
High disorder    -> Complex
```

This allows the program to adapt its behavior instead of relying on a single algorithm.

## Allowed Operations

### Swap

```text
sa  - swap first two elements of stack A
sb  - swap first two elements of stack B
ss  - sa and sb simultaneously
```

### Push

```text
pa  - push top element from B to A
pb  - push top element from A to B
```

### Rotate

```text
ra  - rotate stack A up
rb  - rotate stack B up
rr  - ra and rb simultaneously
```

### Reverse Rotate

```text
rra - rotate stack A down
rrb - rotate stack B down
rrr - rra and rrb simultaneously
```

# Instructions

## Compilation

Compile the mandatory part:

```bash
make
```

Compile the bonus checker:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Full cleanup:

```bash
make fclean
```

Rebuild:

```bash
make re
```

## Usage

### Basic

The program can handle the arguments in multiple strings, if no flags are called the strategy used is adaptive:

```bash
./push_swap "4" 2 "8 1" 3
```
Example output:

```text
pb
ra
pb
sa
pa
pa
```
### Using Strategy

Use the tag `--simple`, `--medium`, `--complex` or `--adaptive` for the algorithm you want to use, for example:

```bash
./push_swap --simple 3 2 1
```
### Benchmark Mode

This mode is intended for analyzing operation counts and comparing strategy performance during development. The tag `--bench` must be presented before the chosen strategy, like so:
```bash
./push_swap --bench --simple 3 2 1 4
```
Output:
```bash
pb
sa
rrr
pa
ra
ra
[bench] disorder:	50.00%
[bench] strategy:	Simple  /  O(n^2)
[bench] total_ops:	6
[bench] sa:  1  sb:  0  ss:  0  pa:  1  pb:  1
[bench] ra:  2  rb:  0  rr:  0  rra:  0 rrb:  0  rrr:  1
```
### Bonus Checker

The bonus program reproduces the stack behavior and validates a sequence of operations.

```bash
./push_swap 5 1 4 2 3 | ./checker 5 1 4 2 3
```

Output:

```text
OK
```

or

```text
KO
```

## Error Handling

The program correctly handles:

- Non-numeric arguments
- Integer overflows
- Duplicate values
- Invalid formatting
- Empty inputs

Example:

```bash
./push_swap 1 2 2 3
```

Output:

```text
Error
```

# Resources

The following resources were used to understand and implement the algorithms and data structures involved in this project:

* Push Swap subject documentation (42 School)
* Quicksort algorithm documentation and tutorials
* Radix Sort algorithm documentation and tutorials
* Stack Overflow discussions related to algorithm optimization and C programming
* Manual pages (`man`) for standard C library functions

## AI Usage

AI tools were used as learning and documentation aids throughout the project. They were primarily used to clarify algorithm concepts, review implementation ideas, explain edge cases, and assist in writing project documentation. All project logic, algorithm implementation, debugging, testing, and final code decisions were developed and validated manually by the author.