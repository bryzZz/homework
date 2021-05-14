import random, modules.hammingCode as hammingCode

def makeMistake(encodedMsg):
  placeToCurrupt = random.randint(0, (len(encodedMsg) - 1))
  curruptedBit = ''
  if encodedMsg[placeToCurrupt] == '0':
    curruptedBit = '1'
  else:
    curruptedBit = '0'
  
  tempList = list(encodedMsg)
  tempList[placeToCurrupt] = curruptedBit
  encodedMsg = ''.join(tempList)

  return encodedMsg

# inp = input('Enter your message: ')
inp = 'Nik'
print('\n\nYour msg:', inp)

encodedMsg = hammingCode.encode(inp)
print('Encoded msg:',encodedMsg)

mistake = input('Do you want to make a mistake in a random place?(y/n)')
while mistake == 'y':
  encodedMsg = makeMistake(encodedMsg)
  print('Artificially corrupted msg:', encodedMsg)
  mistake = input('Do you want to make a mistake in a random place?(y/n)')

try:
  print('How the client can decode this without error correction:', hammingCode.decode(encodedMsg))
except UnicodeDecodeError:
  print('Ooops there are too many errors in this message and the program cannot decode it')
  exit(0)

decodedMsgWithCorrection = hammingCode.decodeWithCorrection(encodedMsg)
if decodedMsgWithCorrection == inp:
  print('How the client can decode this with error correction:', decodedMsgWithCorrection)
else:
  print('How the client can decode this with error correction:', decodedMsgWithCorrection)
  print('Oops so many mistakes :(')