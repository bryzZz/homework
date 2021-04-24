def toTernaryString (n):
  if n == 0:
    return '0'
  nums = []
  while n:
    n, r = divmod(n, 3)
    nums.append(str(r))
  return ''.join(reversed(nums))

def toDecimal(num):
  result = 0
  lenth = len(num) - 1
  for i in range(len(num)):
    result += int(num[i]) * pow(3, lenth)
    lenth -= 1
  return result

num = int(input('Enter num: '))
ternaryStr = toTernaryString(num)

ONEMORESTRING = ''
for i in range (len(ternaryStr)):
  ONEMORESTRING += ternaryStr[i]
  ONEMORESTRING += ternaryStr[i]

result = toDecimal(ONEMORESTRING)

print(result)
