from sys import stdin

stdin.readline()

words = []
for _ in stdin.readlines():
    words.append(set(_.strip()))

haystack = set('abcdefghijklmnopqrstuvwxyz')

def backtrack(need, index):
    
    if len(need) == 0:
        return 1

    if index >= len(words):
        return 0

   # take
    takect = backtrack(need - words[index], index + 1)

    # don't take
    dontct = backtrack(need, index + 1) 

    return takect + dontct

soln = backtrack(haystack, 0)
print(soln)