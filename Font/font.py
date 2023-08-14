from sys import stdin

ct = int(stdin.readline())

words = [0] * ct

for idx in range(ct):
    words[idx] = set(stdin.readline().strip())

haystack = set("abcdefghijklmnopqrstuvwxyz")


def backtrack(need, index):
    if len(need) == 0:
        # how many possible ways to combine the remaining word choices
        return 2 ** (len(words) - index)

    if index >= len(words):
        return 0

    # take
    takect = backtrack(need - words[index], index + 1)

    # don't take
    dontct = backtrack(need, index + 1)

    return takect + dontct


soln = backtrack(haystack, 0)
print(soln)
