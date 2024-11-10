Recursive Descend Parser for arithmetic expression containing + and * (eg:a+a*a)
Enter an arithmetic expression : 6+6

Accepted..!!!

E → T E'
E' → + E | ε
T → F T'
T' → * T | ε
F → id | (E)