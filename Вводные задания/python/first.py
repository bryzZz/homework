# Числа Армстронга
a = 1
while a < 32000:
  temp = 0
  for i in str(a):
    temp += int(i) ** len(str(a))
  if temp == a:
    print(temp, end = ', ')
  a += 1