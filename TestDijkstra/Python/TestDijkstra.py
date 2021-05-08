# TestDijkstra.py
# 08/05/2021

# Definition of the graph table
# Node init
graph = {}
graph["init"] = {}
graph["init"]["a"] = 6
graph["init"]["b"] = 2
# Node a
graph["a"] = {}
graph["a"]["end"] = 1
# Node b
graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["end"] = 5
# Node end
graph["end"] = {}

# Definition of the costs table
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["end"] = float("inf")

# Definition of the parents
parents = {}
parents["a"] = "init"
parents["b"] = "init"
parents["end"] = None

# Definition of array to count processed nodes
processed = []


# findNodeWithMinorCost(costs)
# Description: This function find the node not processed with the minor cost.
def findNodeWithMinorCost(costs):
    minorCost = float("inf")
    nodeWithMinorCost = None
    for node in costs :
        cost = costs[node]
        if cost < minorCost and node not in processed :
            minorCost = cost
            nodeWithMinorCost = node
    return nodeWithMinorCost

# getMinorCostPath(parents, end, init)
# Description: Compute the parents table in reverse and return the optimal path
def getMinorCostPath(parents, end, init) :
    node = end
    path = [end]
    while node is not init :
        node = parents[node]
        path.append(node)
    path.reverse()
    return path

# Dijkstra algorithm
node = findNodeWithMinorCost(costs)
while node is not None : 
    cost = costs[node]
    neighbours = graph[node]
    for n in neighbours.keys() :
        newCost = cost + neighbours[n]
        if costs[n] > newCost :
            costs[n] = newCost
            parents[n] = node
    processed.append(node)
    node = findNodeWithMinorCost(costs)

path = getMinorCostPath(parents, "end", "init")
print("Optimal path fot the graph:", path)

