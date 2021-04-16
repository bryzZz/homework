def is_complete(H):
  arr = H.split(',')
  arr = list(map(int, arr))

  print(arr)
  
  for i in range(0, (len(arr) - 2) // 2):
    if not (arr[i] <= arr[2 * i + 1]):
      return False
    if not (arr[i] <= arr[2 * i + 2]):
      return False

  return True

print(is_complete('1, 4, 2, 3, 4, 5, 6'))