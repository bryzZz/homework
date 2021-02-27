import random

def outPut(list1):
  for i in list1:
    print(i)

def generateList(n, m):
  list1 = [[j for j in range(m)] for i in range(n)]
  for i in range(0, len(list1)):
    for j in range(0, len(list1[i])):
      list1[i][j] = random.randint(10, 40)
  return list1

def findBiggest(list1):
  sumOfStr = [sum(list1[0]), 0]
  for i in range(1, len(list1)):
    if(int(sum(list1[i])) > int(sumOfStr[0])):
      sumOfStr[0] = sum(list1[i])
      sumOfStr[1] = i
  return sumOfStr

n = int(input('Enter n: '))
m = int(input('Enter m: '))

list1 = generateList(n, m)
outPut(list1)

biggest = findBiggest(list1)
print(str(biggest[1]+1) + ': ' + str(biggest[0]) + ' =', list1[biggest[1]], end = '')
