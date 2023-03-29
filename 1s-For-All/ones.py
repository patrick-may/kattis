
def bottom_up(goal):
    dp = [0]*(goal + 1) # index by the number itself
    dp[1] = 1 # first positive number 1 takes 1 '1' to construct

    for step in range(2, goal+1):
        # is it better to choose to add?
        best = dp[step-1] + 1 
        for i in range(1, step//2 + 1):
            best = min(best, dp[step-i] + dp[i])
        
        # is best form to multiply?
        f = 2
        while f * f <= step:
            if step % f == 0:
                best = min(dp[f] + dp[step//f], best) 
            f += 1

        # what if its to concatentate?
        strnum = str(step)

        for idx in range(1, len(strnum)):
            front = strnum[:idx]
            tail = strnum[idx:]
            if tail[0] == '0':
                continue
            best = min(best, dp[int(front)] + dp[int(tail)])
        
        dp[step] = best

    print(dp[goal])

        
a = int(input())
bottom_up(a)