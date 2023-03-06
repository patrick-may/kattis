# gotta love eval! big W for python
from sys import stdin

for l in stdin:
    print(f"{eval(l):.2f}")