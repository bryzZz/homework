def HeapSort(arr):
  for start in range((len(arr)) // 2, -1, -1):
    siftDown(arr, start, len(arr) - 1) 

  print(arr)
  for end in range(len(arr) - 1, 0, -1): 
    arr[end], arr[0] = arr[0], arr[end]
    siftDown(arr, 0, end - 1)
  return arr

def siftDown(arr, start, end):
  root = start 

  while True:
    child = root * 2 + 1
    if child > end: break 

    if child + 1 <= end and arr[child] < arr[child + 1]:
      child += 1

    if arr[root] < arr[child]:
      arr[root], arr[child] = arr[child], arr[root]
      root = child
    else:
      break

print([12, 11, 13, 5, 6, 7, 10, 15])
print(HeapSort([12, 11, 13, 5, 6, 7, 10, 15]))
