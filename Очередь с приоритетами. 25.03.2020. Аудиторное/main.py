import heapq
from collections import namedtuple

Task = namedtuple('Task', 'priority, id, content')

class TaskFlow:
  def __init__(self):
    self._queue = []
    self._id = 0

  def push(self, priority, content):
    self._id += 1
    # минус priority, чтобы доставать задачи с наибольшим приоритетом
    heapq.heappush(self._queue, Task(-priority, self._id, content))
    return self._id

  def pop(self) -> Task:
    # мы извлекаем наименьший элемент 
    # в кортеже 3 элемента, сравнение идет слева направо
    # сначала по приоритету с минусом (т.е. достаем наибольший приоритет)
    # если приотритеты равны, то с наименьшим id (т.е. тот, что был добавлен раньше)
    return heapq.heappop(self._queue)

  def empty(self):
    return not self._queue
  
  def printQueue(self):
    while not self.empty():
      print(self.pop())

  def getMax(self):
    print(self.pop())

flow = TaskFlow()

flow.push(90, 'умывание')
flow.push(10, 'мыть тарелки')
flow.push(100, 'подъем')
flow.push(50, 'готовить завтрак')
flow.push(50, 'завтракать')

flow.getMax()
print('\n\n')
flow.printQueue()