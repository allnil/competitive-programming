n_letters = input()
letters = list(input().split())
q = int(input())

for i in range(q):
  n = int(input()) - 1
  letter = letters[n]
  if letter != '?':
    print(letter)
  else:
    left, right = 0, 0
    leftL, rightL = '', ''
    for l in reversed(letters[:n]):
      print(l)
      if l != '?':
        leftL = l
        break
      left += 1
    if letters.__len__() > n + 1:
      for r in letters[n:]:
        print(r)
        if r != '?':
          rightL = r
          break
        right += 1
    print(f'{left} and {right} and {leftL} and {rightL}')
    if left == right and (leftL != ('?'or'')) and (rightL != ('?'or'')):
      print(f'middle of {leftL} and {rightL}')
    
