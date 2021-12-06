import json
from Node import Node

def getDataFromJSON(path):
    f = open(path)
    data = json.load(f)
    f.close()

    return data

def loadNodes(nodesData):
    nodes = []

    for nodeData in nodesData:
        node = Node(nodeData['id'], nodeData['value'])
        nodes.append(node)

    for i in range(len(nodesData)):
        nodeConnections = nodesData[i]['connections']

        for connection in nodeConnections:
            for j in range(len(nodes)):
                if nodes[j].id == connection['nodeId']:
                    nodes[i].connect(nodes[j], connection['weight'])

    return nodes

def dfs(v, t):
    if (v == t): return True
    if (v.visited == True): return False

    v.visited = True

    for i in range(len(v.connections)):
        if v.connections[i].visited == False:
            reached = dfs(v.connections[i], t)
            if reached == True: return True

    return False

def dijkstraAlg(startNode, endNode):
    C = None
    CWeight = 999999
    for connection in startNode.connections:
        if connection['weight'] < CWeight:
            CWeight = connection['weight']
            C = connection['node']
    
    if C == endNode: return True

nodesData = getDataFromJSON('./data.json')['nodes']
nodes = loadNodes(nodesData)

# print(dfs(nodes[2], nodes[8]))

# print(dijkstraAlg(nodes, nodes[0], nodes[1]))
