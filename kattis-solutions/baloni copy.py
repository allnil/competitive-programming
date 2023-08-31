from collections import defaultdict

n = 0
fl = True
for line in sys.stdin:
  if fl is False:
    l = [int(x) for x in line.split()]
    cnt = 0

    while True:
      traversed = True
      arrow = 0
      for i in range(0, n):
        if l[i] != 0 and l[i] == arrow:
          arrow -= 1
          l[i] = 0
          continue
        
        if arrow == 0 and l[i] != 0:
          arrow = l[i]
          l[i] = 0
          arrow -= 1
          cnt += 1

        if l[i] != 0:
          traversed = False
        
      if traversed:
        break
    print(cnt)        
  else:
    fl = False
    l = [int(x) for x in line.split()]
    n = l[0]
  