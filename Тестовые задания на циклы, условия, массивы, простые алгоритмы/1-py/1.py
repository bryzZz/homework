import math

def getColorsCount(dots):
  #set for marked dots
  visited = set()
  #variable for color count
  colorCount = 0

  #recursion function for each dot
  def recursion(dot):
    #mark current dot
    visited.add(dot)
    #cycle to find dots with (dist <= 1) to current dot
    for i in range(len(dots)):
      #if we were in visited dot => go out
      if i in visited: continue
      #find distance between currentdot and dot in cycle
      dist = math.sqrt((dots[i][0] - dots[dot][0]) ** 2 + (dots[i][1] - dots[dot][1]) ** 2)
      #id (dist <= 1) start new recurcion cycle
      if dist <= 1:
        recursion(i)
  
  #cycle to walk all paths
  while(len(dots) != 0):
    #start finding path
    recursion(0)
    #delete marked dots from main array
    newArr = []
    for i in range(len(dots)):
      if i in visited: continue
      newArr.append(dots[i])
    dots = newArr

    #add color for all path
    colorCount += 1
    #clear set with marked dots for other paths
    visited.clear()

  return colorCount 

#reed data from file
dots = []
f = open('input.txt')
for line in f:
  minArr = line.split(' ')
  dots.append([int(minArr[0]), int(minArr[1])])

#print function result
print(getColorsCount(dots))