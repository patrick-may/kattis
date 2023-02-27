from functools import lru_cache
# small case size means brute force could work here...
case = input()

# simple longest increasing substring adaptation
@lru_cache(maxsize=None)
def lis(case, idx, prev):
    if idx == len(case):
        return 0

    take, dontTake = 0, lis(case, idx + 1, prev)
    if(case[idx] > prev):
        take = 1 + lis(case, idx + 1, case[idx])
    return max(take, dontTake)
    
print(26 - lis(case, 0, chr(ord('a') - 1)))
