octal = int(input())

base = 0

#convert to base 10
idx = 0
while octal > 0:
    trail = octal % 10
    octal //= 10
    base += trail * 8**idx
    #print(trail, 8**idx)
    idx += 1

# convert from 10 to 16
ans = ""
lookup="0123456789ABCDEF"
pwr = 0
b2 = base
while base > 0:
    trail = base % 16
    base //= 16
    ans = lookup[trail] + ans
    
print(ans)      
print(f"{str(hex(b2))[2:].upper()}")