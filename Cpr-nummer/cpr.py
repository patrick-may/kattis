n = "".join(input().split("-"))
valid = (int(n[0])*4+int(n[1])*3+int(n[2])*2+int(n[3])*7+int(n[4])*6+int(n[5])*5+int(n[6])*4+int(n[7])*3+int(n[8])*2+int(n[9])*1)%11
print("1" if valid == 0 else "0")