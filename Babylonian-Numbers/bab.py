
def testcase():
    def applicator(i):
        return 0 if i == "" else int(i)
   
    num = list(map(applicator, input().strip().split(',')))
    l = len(num) - 1
    soln = 0
    for inv_pwr, val in enumerate(num):
        soln += val * 60**(l - inv_pwr)
    
    print(soln)

tc = int(input())

for _ in range(tc):
    testcase()
