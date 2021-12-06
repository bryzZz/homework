class Node:
    def __init__(self, id, value):
        self.id = id
        self.value = value

        self.visited = False
        self.connections = []

    def connect(self, node, weight):
        self.connections.append({"node": node, "weight": weight})