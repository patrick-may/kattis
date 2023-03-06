# gotta love eval! big W for python
from sys import stdin

for line in stdin:
    print(f"{eval(line):.2f}")