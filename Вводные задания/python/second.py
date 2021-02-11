#Дружественные числа

def devsSum(num):
    s = 0
    for i in range(1, num):
        if num % i == 0:
            s += i
    return s

def findFrends(limit):
    res = []
    for i in range(1, limit):
        if i not in res:
            temp = devsSum(i)
            if i == devsSum(temp) and i != temp:
                res.append(i)
                res.append(temp)
                # print(i)
                # print(temp, end = ", ")
    return res

def pairedOutput(inlist):
  toggle = False
  for i in range(0, len(inlist)):
    if toggle == False:
      print(inlist[i], end = ', ')
      toggle = True
    else:
      print(inlist[i])
      toggle = False

pairedOutput(findFrends(10000))