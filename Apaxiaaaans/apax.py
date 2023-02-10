# these simple ones are just much faster
# to zing out in python
word = input()
soln = word[0]
prior = word[0]
for c in word[1:]:
    if prior != c:
        soln += c
    prior = c

print(soln)


