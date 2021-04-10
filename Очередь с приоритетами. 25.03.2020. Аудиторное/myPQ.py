import json
class myQ:
  def __init__(self):
    self._dct = {}

  def push(self, item, priority):
    if (priority in self._dct.keys()):
      self._dct[priority].append(item)
    else:
      self._dct[priority] = []
      self._dct[priority].append(item)

  def pop(self, item):
    if (item in self._dct.keys()):
      self._dct[item].pop()
      if (not bool(self._dct[item])):
        self._dct.pop(item)
    else:
      print("queue is empty")
    return(item)
  
  def printQueue(self):
    print(json.dumps(self._dct, sort_keys=True, indent=2))
  
  def getMax(self):
    if (bool(self._dct.keys())):
      a = max(self._dct.keys())
      print(self._dct[a][-1])
    else:
      print("queue is empty")

myq = myQ()

myq.push(11, 10)
myq.push(12, 20)
myq.push(13, 20)
myq.push(14, 1)
myq.push(15, 5)

myq.pop(10)

myq.printQueue()

print()

myq.getMax()
