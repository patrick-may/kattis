
sek = int(input())

trans = 0
while sek >= 500:
    sek -= 500
    trans += 1

twos = 0
while sek >= 200:
    sek -= 200
    trans += 1
    twos += 1

ones = 0
while sek > 0:
    sek -= 100
    trans += 1
    ones += 1

five_reduc = min(twos // 2, ones)
twos -= min(twos//2, ones)
ones -= min(twos, ones)
trans -= 2*five_reduc
trans -= ones//2
print(trans)