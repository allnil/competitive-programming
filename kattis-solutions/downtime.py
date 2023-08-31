import sys
import math

params = input()
n, cap = [int(x) for x in params.split()]

timeline = [0] * 101

for line in sys.stdin:
  x = int(line)
  timeline[math.floor(x/1000)] += 1

min = 0
for i in range(0, 100):
  need = math.ceil(timeline[i]/cap)
  if min < need:
    min = need

print(min)



