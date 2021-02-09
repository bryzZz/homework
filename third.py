#Обрученные числа

def devsSum(num):
    s = 0
    for i in range(1, num):
        if num % i == 0:
            s += i
    return s

def findBetrothed(limit):
    res = []
    for i in range(1, limit):
        if i not in res:
            temp = devsSum(i)-1
            if i == devsSum(temp)-1 and i != temp-1:
                res.append(i)
                res.append(temp)
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

pairedOutput(findBetrothed(10000))