def gettime(s):
    paren = s.find("(")
    s = s[paren + 1:]
    space = s.find(" ")
    return s[:space]


best_guess = "a"
print(best_guess)

# get the right length of the password
response = input()
if response == "ACCESS GRANTED":
        exit()
result = gettime(response)

# get longer
while result == "5":
    best_guess += "a"
    print(best_guess)
    response = input()
    if response == "ACCESS GRANTED":
        exit()
    result = gettime(response)

alph = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWyYxXzZ0123456789"
idx = 0
# brute force different options
while response != "ACCESS GRANTED":
    result = gettime(response)
    for pos in alph:
        # make new string with different character guess
        best_guess = best_guess[:idx] + pos + best_guess[idx+1:]
        print(best_guess)
        response = input()
        # quite early if done
        if response == "ACCESS GRANTED":
            exit()

        # see if time is longer or shorter
        if int(gettime(response)) > int(result):
            idx += 1
            result = gettime(response)
            break