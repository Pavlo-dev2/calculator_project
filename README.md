# calculator_project
This is a CLI calculator implemented in C, supporting:

Arithmetic operations (+, -, *, /, ^)
Parentheses and operator precedence
Floating-point calculations
Recursive parsing of expressions

Installation:
1. Download the last version of C file
2. Compile it with cc _name_of_the_file -lm
3. Copy a.out file to /bin with cp a.out /bin/calculate

Example:
root@Mobile1516T:/home# calculate "(((3.14 * 3^2) * 5)/3) + (((3.14 * 3^2) * 5)/3)"
Result: 94.200005

#root@Mobile1516T:/home# calculate 2-3
Result: -1.000000

root@Mobile1516T:/home# calculate "(2+2)*(3+3)"
Result: 24.000000
