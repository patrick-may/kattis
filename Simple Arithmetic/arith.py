from decimal import Decimal # much easier with Decimal library!! 
a, b, c =   [Decimal(i) for i in input().split(" ")]
val = a * (b / c)
print(val)

# this was such a simple problem that its very easy in python... now to push some rust syntax to be wary of