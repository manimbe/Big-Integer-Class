# Big Integer Class
## Overview
This repository is a C++ class for dealing with Big Integers (Bignteger), and licensed under [MIT License](https://github.com/manimbe/Big-Integer-Class/blob/main/LICENSE).

Originally this class was thought to solve the problems from the [Project Euler](https://projecteuler.net/) that requires the implementation of big integers.

## Supported operators

### Relational operators

| Operator | Description |
| -------- | -------- |
| == | Equal to |
| != | Not equal to |
| < | Less than |
| <= | Less than or equal to |
| > | Greater than |
| >= | Greater than or equal to |

### Arithmetic operators

| Operator | Description |
| -------- | -------- |
| + | Addition |
| - | Subtraction |
| * | Multiplication |
| / | Division |
| % | Modulo |

### Other operators

| Operator | Description |
| -------- | -------- |
| = | Assignment operator |
| << | Insertion operator |

## Usage example

```
#include <Bignteger.cpp>
```

```
Bignteger first_number = "123456789";

Bignteger second_number;
second_number = "-987654321";

Bignteger result = first_number * second_number;

if(first_number > second_number){
  std::cout << result << std::endl;
}
```

```
Result: -121932631112635269
```
