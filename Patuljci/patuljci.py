nums = []
for _ in range(9):
    nums.append(int(input().strip()))

b1, b2 = -1, -1
for x in range(9):
    for y in range(x + 1, 9):
        if sum(nums) - (nums[x] + nums[y]) == 100:
            b1 = nums[x]
            b2 = nums[y]
            for n in nums:
                if n != b1 and n != b2:
                    print(n)
            exit()
