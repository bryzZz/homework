inputStr = input('Enter string: ')

arr = list(inputStr)

numGC = 0
for i in arr:
  if i == 'g' or i == 'c':
    numGC += 1

print((numGC / len(inputStr)) * 100)
