matrix = [
  [0, 3, 1, 7, 5, 9, 8, 6, 4, 2],
  [7, 0, 9, 2, 1, 5, 4, 8, 6, 3],
  [4, 2, 0, 6, 8, 7, 1, 3, 5, 9],
  [1, 7, 5, 0, 9, 8, 3, 4, 2, 6],
  [6, 1, 2, 3, 0, 4, 5, 9, 7, 8],
  [3, 6, 7, 4, 2, 0, 9, 5, 8, 1],
  [5, 8, 6, 9, 7, 2, 0, 1, 3, 4],
  [8, 9, 4, 5, 3, 6, 2, 0, 1, 7],
  [9, 4, 3, 8, 6, 1, 7, 2, 0, 5],
  [2, 5, 8, 1, 4, 3, 6, 7, 9, 0]
]

inputData = []
outputData = []

def permutations(data):
  permutations = []

  for i in range(len(data) - 2):
    arr = list(data)
    arr[i], arr[i+1] = arr[i+1], arr[i]
    permutations.append(''.join(arr))

  return permutations

def getCheckSum(num):
  intermediate = 0
  for item in str(num):
    intermediate = matrix[intermediate][int(item)]
  return intermediate

inputFile = open('input.txt')
for line in inputFile:
  inputData.append(str(int(line)))

for item in inputData:
  if getCheckSum(item) == 0:
    outputData.append(item)
    continue
  for i in permutations(item):
    if getCheckSum(i) == 0:
      outputData.append(i)

f = open("output.txt", "w")
for item in outputData:
  f.write(item + '\n')
f.close()
