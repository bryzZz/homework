def movef(move):
  if move == 'l':
    if move in field[currentCords['y']][currentCords['x']]:
      return True
    field[currentCords['y']][currentCords['x']].append(move)
    secondField[currentCords['y']][currentCords['x']] = move
    if currentCords['x'] == 0:
      currentCords['x'] = 3
    else:
      currentCords['x'] -= 1
  elif move == 'r':
    if move in field[currentCords['y']][currentCords['x']]:
      return True
    field[currentCords['y']][currentCords['x']].append(move)
    secondField[currentCords['y']][currentCords['x']] = move
    if currentCords['x'] == 3:
      currentCords['x'] = 0
    else:
      currentCords['x'] += 1
  elif move == 'd':
    if move in field[currentCords['y']][currentCords['x']]:
      return True
    field[currentCords['y']][currentCords['x']].append(move)
    secondField[currentCords['y']][currentCords['x']] = move
    if currentCords['y'] == 3:
      currentCords['y'] = 0
    else:
      currentCords['y'] += 1
  elif move == 'u':
    if move in field[currentCords['y']][currentCords['x']]:
      return True
    field[currentCords['y']][currentCords['x']].append(move)
    secondField[currentCords['y']][currentCords['x']] = move
    if currentCords['y'] == 0:
      currentCords['y'] = 3
    else:
      currentCords['y'] -= 1

  return False

secondField = [
  ['#', '#', '#', '#'],
  ['#', '#', '#', '#'],
  ['#', '#', '#', '#'],
  ['#', '#', '#', '#']
]

field = [
  [[], [], [], []],
  [[], [], [], []],
  [[], [], [], []],
  [[], [], [], []]
]

moves = ['l', 'r', 'u', 'd']

currentCords = {
  'y': 0, 
  'x': 0
}

move = input('move: ').lower()

while(move):
  if (move in moves):
    if movef(move):
      print('again here: ', currentCords)
      for item in field:
        print(item)
      break

    secondField[currentCords['y']][currentCords['x']] = 'o'

    for item in secondField:
      print(item)
    
    move = input('move: ').lower()
  else:
    print('incorrect')
    break;
