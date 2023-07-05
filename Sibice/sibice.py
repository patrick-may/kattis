N, W, H = map(int, input().strip().split())
from sys import stdin

longest = ( W * W + H * H ) ** 0.5
for line in stdin:
    line = int(line.strip())
    print("DA" if line <=longest else "NE")

