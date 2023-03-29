from sys import stdin

def case(seq):
    if len(seq) == 0:
        return 0

    front, tail = seq[0], seq[1:]
    lis = 0
    for idx, elem in enumerate(tail):
        best_next = case(tail[idx:])
        if front < elem:
            best_next += 1 # we can "take" the head

        lis = max(best_next, lis)
    return lis

for line in stdin:
    subseq = list(map(int, input().split()))
    print(case(subseq))
    print(subseq)