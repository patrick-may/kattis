from sys import stdin
import math
# somethings borken here
for case in stdin:
    D, V = map(int, case.strip().split())
    if D == V and D == 0:
        exit
    total = math.pi * ((D/2) ** 2) * D 
    wood = total - V
    cones = math.pi * ((D / 2) ** 2) * (D/3)
    shape = wood - cones 
    cyl = shape * 1.5 
    r = (cyl / (2 * math.pi)) * (1/3)
    print(r * 2)

