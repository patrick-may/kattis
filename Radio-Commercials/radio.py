spots, cost = map(int, input().strip().split())
people = map( lambda x: int(x) - cost, input().strip().split())

best_sum = -9999999
cum_sum = 0
# Kadane's!
for netprofit in people:
    cum_sum += netprofit

    if best_sum < cum_sum:
        best_sum = cum_sum 

    if cum_sum < 0:
        cum_sum = 0

print(best_sum)
