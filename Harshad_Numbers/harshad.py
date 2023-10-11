def is_harshad(val):
    digsum = sum([int(i) for i in str(val)])
    return val % digsum == 0

num = input()
numnum = int(num)
while (True):
    if (is_harshad(numnum)):
        print(numnum)
        exit()
    numnum += 1
