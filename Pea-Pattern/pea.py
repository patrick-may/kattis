from collections import Counter

# take in an integer n, and construct the next number to be:
# [freq of lowest digit] [the digit] [frequency of next digit] [next digit]
def next_num(n):
    soln = ""
    for digit, freq in sorted(Counter(str(n)).items()):
        soln += str(freq) + digit
    return int(soln)

# read in input
start, goal = map(int, input().split())
idx = 1
seen = set()
# loop up to 100 times
while idx <= 100:
    # if our current sequence value is the goal, quit
    if start == goal:
        print(idx)
        break

    # if we've seen it before, quit also, we are in a cycle
    if start in seen:
        print("Does not appear")
        break
    # add the number to our 'seen' set and go to next index and next num in seq
    seen.add(start)
    start = next_num(start)
    idx += 1

# edge case for when we bored
if idx == 101:
    print("I'm bored")