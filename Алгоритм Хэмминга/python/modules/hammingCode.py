import modules.bitsOperations as bitsOperations

def encode(msg):
  msgInBits = bitsOperations.text_to_bits(msg)
  # print('msg In bits:', msgInBits)
  #get arr of words
  words = []
  while(msgInBits):
    word = msgInBits[:8]
    arr8 = ['x', 'x', '_', 'x', '_', '_', '_', 'x']
    # arr16 = ['x', 'x', '_', 'x', '_', '_', '_', 'x', '_', '_', '_', '_', '_', '_', '_', 'x']

    #add check bits to word
    for item in word:
      if '_' in arr8:
        for i in range(len(arr8)):
          if(arr8[i] == '_'):
            arr8[i] = item
            break
      else:
        arr8.append(item)
      
    # while '_' in arr16:
    #   arr16.pop()
    # for i in range(len(arr16)):
    #   if arr16[i] == '_':
    #     arr16[i] = '0'
    
    words.append(''.join(arr8))
    msgInBits = msgInBits[8:]

  result = ''
  for item in words:
    result += _culcOneWordCheckBits(item)
  
  return result

def decode(encodedMsg):
  decodedMsg = ''
  while(encodedMsg):
    word = encodedMsg[:12]
    Cclient = _culcOneWordCheckBits(word)
    decodedMsg += _deleteCheckBitsFromWord(Cclient)
    encodedMsg = encodedMsg[12:]
  
  return bitsOperations.text_from_bits(decodedMsg)

def decodeWithCorrection(encodedMsg):
  encodedMsgWithCorrections = ''
  while encodedMsg:
    word = encodedMsg[:12]
    word = _culcOneWordCheckBits(word)
    word = _correctWord(word)
    encodedMsgWithCorrections += _deleteCheckBitsFromWord(word)
    # print('corrected word without check bits:', encodedMsgWithCorrections)
    encodedMsg = encodedMsg[12:]
  return bitsOperations.text_from_bits(encodedMsgWithCorrections)

def _correctWord(word):
  def culcCorruptedBit(word):
    corruptedBit = 0
    word = list(word)
    N = 1
    while(N != 16):
      if word[N-1] == '1':
        corruptedBit += (N)
      N *= 2
    if corruptedBit == 0:
      return None
    return (corruptedBit-1)
  
  corruptedPlace = culcCorruptedBit(word)
  if corruptedPlace != None:
    # print('corruptedPlace: ', corruptedPlace)
    word = list(word)
    if word[corruptedPlace] == '0':
      word[corruptedPlace] = '1'
    else:
      word[corruptedPlace] = '0'
    word = ''.join(word)
    # print('corrected word:', word)
  return word

def _culcOneWordCheckBits(word):
  N = 1
  while(N != 16):
    checkBit = ''
    #get dependent bits
    i = N - 1
    while(i < len(word)):
      checkBit += word[i:i+N]
      i += (N * 2)

    #parity check
    j = 0
    for item in checkBit:
      if item == '1':
        j += 1
    if j % 2 == 0:
      checkBit = 0
    else:
      checkBit = 1

    #set check bit to his place
    word = list(word)
    word[N-1] = str(checkBit)
    word = ''.join(word)

    N *= 2
  
  return word

def _deleteCheckBitsFromWord(word):
  word = list(word)
  N = 1
  while(N != 16):
    word[N-1] = 'x'
    N *= 2
  while 'x' in word:
    word.remove('x')
  return ''.join(word)