nums = map(int, input().split())
stuffs = [1, 1, 2, 2, 2, 8]

for right, real in zip(nums, stuffs):
    print(real - right, end=" ")