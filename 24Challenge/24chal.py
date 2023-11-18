nums = [1, 4, 5, 6]

def container(solve: list[int], target: int):
    mem = []
    soln = []
    TARGET = target

    def bt(nums: list[int]) -> bool:
        if len(nums) == 1 and round(nums[0] - TARGET, 6) == 0:
           soln.append([v for v in mem]) 

        elif len(nums) <= 1:
            return False

        for x, n1 in enumerate(nums):
            for n2 in nums[x + 1:]:
                others = [i for i in nums] # deep copy
                others.remove(n1); others.remove(n2) # remove duplicates

                others.append(n1 + n2)
                mem.append(("+", n1, n2))
                bt(others)
                mem.pop()
                others.pop()
                
                others.append(n1 * n2)
                mem.append(("*", n1, n2))
                bt(others)
                mem.pop()
                others.pop()           

                others.append(n1 - n2)
                mem.append(("-", n1, n2))
                bt(others)
                mem.pop()
                others.pop()

                others.append(n2 - n1)
                mem.append(("-", n2, n1))
                bt(others)
                others.pop()
                mem.pop()

                if n1 != 0:
                    mem.append(("/", n2, n1))
                    others.append(n2 / n1)
                    bt(others)
                    others.pop()
                    mem.pop()

                if n2 != 0:
                    mem.append(("/", n1, n2))
                    others.append(n1 / n2)
                    bt(others)
                    others.pop()
                    mem.pop()

        return False
    
    bt(nums)
    return(soln)

solns = container(nums, 24)

for s in solns:
    print(s)

