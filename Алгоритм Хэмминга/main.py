def toBinary(string):
  return "".join([format(ord(char),'#010b')[2:] for char in string])

def decodeOneWord(word):
  N = 1
  while(N != 32):
    checkBit = ''
    i = N - 1
    # print(word, ' i = ', i, ' N = ', N)
    while(i < len(word)):
      checkBit += word[i:i+N]
      # print(checkBit, ' i = ', i, ' N = ', N)
      i += (N * 2)

    j = 0
    for item in checkBit:
      if item == '1':
        j += 1
    if j % 2 == 0:
      checkBit = 0
    else:
      checkBit = 1

    for k in range(len(word)):
      if word[k] == 'x':
        wordArr = list(word)
        wordArr[k] = str(checkBit)
        word = ''.join(wordArr)
        break
    
    N *= 2

  return word

def decode(binaryMsg):
  result = ''
  while(binaryMsg):
    word = binaryMsg[:16]

    word = 'xx' + word
    word = word[:3] + 'x' + word[3:]
    word = word[:7] + 'x' + word[7:]
    word = word[:15] + 'x' + word[15:]

    result += decodeOneWord(word)

    binaryMsg = binaryMsg[16:]

  return result

def encode(decodedBinaryMsg):
  result = ''
  while(decodedBinaryMsg):
    word = decodedBinaryMsg[:16]

    result += decodeOneWord(word)

    decodedBinaryMsg = decodedBinaryMsg[16:]

  return result
  # corruptedBit = 0

  # while(decodedBinaryMsg):
  #   word = decodedBinaryMsg[:16]

  #   N = 1
  #   while(N != 32):
  #     checkBit = ''
  #     i = N - 1
  #     # print(word, ' i = ', i, ' N = ', N)
  #     while(i < len(word)):
  #       checkBit += word[i:i+N]
  #       # print(checkBit, ' i = ', i, ' N = ', N)
  #       i += (N * 2)

  #     j = 0
  #     for item in checkBit:
  #       if item == '1':
  #         j += 1
      
  #     if j % 2 != 0:
  #       corruptedBit += N
      
  #     N *= 2

  #   decodedBinaryMsg = decodedBinaryMsg[16:]  

arr16 = ['x', 'x', 0, 'x', 0, 0, 0, 'x', 0, 0, 0, 0, 0, 0, 0, 'x']

# inp = input('Enter anything: ')
inp = 'Nikita'
print('you enter:\t\t\t ', inp)
binInp = toBinary(inp)
print('binary view:\t\t ', binInp)
decBinInp = decode(binInp)
print('hemming decoded msg: ', decBinInp)
encDecBinInp = encode(decBinInp)
print('encoded msg:\t\t ', encDecBinInp)
temp = list(decBinInp)

print('take mistake here between the chopsticks: ', ''.join(list(decBinInp)))

print(end = '\n\n')
print('hemming decoded(bit inside house is hemming decoded): ', end = '')
hDecoded = decode(toBinary(inp))
while(hDecoded):
  oneWord = hDecoded[:16]
  i = 0
  while(i < len(oneWord)):
    if arr16[i] == 'x':
      print('/' + oneWord[i] + '\\', end = '')
    else:
      print(oneWord[i], end = '')

    i += 1
  hDecoded = hDecoded[16:]
print()
