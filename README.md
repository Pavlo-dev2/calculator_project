# calculator_project

<h2>This is a CLI calculator implemented in C, supporting:</h2>
<ul>
<li>Arithmetic operations (+, -, *, /, ^)</li>
<li>Parentheses and operator precedence</li>
<li>Floating-point calculations</li>
<li>Recursive parsing of expressions</li>
</ul>

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
