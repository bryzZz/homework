def getAllList(FInput):
  allList = []
  for line in FInput:
    allList.append(line)
  allList = allList[1:]
  return allList
def getPersons(AllList):
  persons = []
  authorphrases = []
  for i in range(0, len(allList)):
    person = allList[i].split('.')[0]
    if(person not in persons and not len(person.split(' ')) > 2):
      persons.append(person)
    elif len(person.split(' ')) > 2:
      authorphrases.append(person)
  return [persons, authorphrases]
def GetListOfPersonsAndPhrases(Persons, AllList):
  listOfPersonsAndPhrases = []
  for person in Persons:
    tempList = []
    tempList.append(person)
    for i in range(0, len(AllList)):
      isPerson = AllList[i].split('.')[0]
      if isPerson == person:
        tempList.append(str(i+2) + ")" + (''.join(AllList[i].split('.', 1)[1:])[:-1]))
    listOfPersonsAndPhrases.append(tempList)
  return listOfPersonsAndPhrases
def outPut(norm, outFile):
  for i in range(0, len(norm)):
    outFile.write(str(norm[i][0]) + ': \n')
    for j in range(1, len(norm[i])):
      outFile.write(str(norm[i][j]) + '\n')
    outFile.write('\n')
fInput = open('input.txt')
allList = getAllList(fInput)
fInput.close()
persons = getPersons(allList)
norm = GetListOfPersonsAndPhrases(persons[0], allList)
output = open('output.txt', 'w')
outPut(norm, output)
for item in persons[1]:
  output.write(str(item) + '\n')
output.close()