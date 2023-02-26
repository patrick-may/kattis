inp = int(input())
l_bound = inp
r_bound = inp
while l_bound % 100 != 99:
    l_bound -= 1

while r_bound % 100 != 99:
    r_bound += 1

l_dist = inp - l_bound
r_dist = r_bound - inp
print(r_bound if r_dist <= l_dist or l_bound < 1 else l_bound)