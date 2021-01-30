import heapq, math, sys

infinity = float('inf')

class Node():
        def __init__(self, position, fscore=infinity, gscore=infinity, parent = None):
            self.fscore, self.gscore, self.position, self.parent = fscore, gscore, position, parent
            
        def __lt__(self, otherNode):
            return self.fscore < otherNode.fscore
            
class AStar():

    def __init__(self, start, grid, height, width):
        self.start, self.grid, self.height, self.width = start, grid, height, width

    def heuristic(self, end, distance = "Manhattan"):
        (x1, y1), (x2, y2) = self.start, end
        if (distance == "Manhattan"):
            return abs(x1 - x2) + abs(y1 - y2)
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

    def nodeNeighbours(self, pos):
        (x, y) = pos
        return [(dx, dy) for (dx, dy) in [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)] if 0 <= dx < self.width and 0 <= dy < self.height and self.grid[dy][dx] == 0]

    def getPath(self, endPoint):
        current, path = endPoint, []
        while current.position != self.start:
            path.append(current.position)
            current = current.parent
        path.append(self.start)
        return list(reversed(path))

    def computePath(self, end):
        openList, closedList, nodeDict = [], set(), {}
        currentNode = Node(self.start, fscore=self.heuristic(end), gscore = 0)
        heapq.heappush(openList, currentNode)
        while openList:
            currentNode = heapq.heappop(openList)
            if currentNode.position == end:
                return self.getPath(currentNode)
            else:
                closedList.add(currentNode)
                neighbours = []
                for toCheck in self.nodeNeighbours(currentNode.position):
                    if toCheck not in nodeDict.keys():
                        nodeDict[toCheck] = Node(toCheck)
                        neighbours.append(nodeDict[toCheck])
                
                for neighbour in neighbours:
                    newGscore = currentNode.gscore + 1
                    if neighbour in openList and newGscore < neighbour.gscore:
                        openList.remove(neighbour)
                    if newGscore < neighbour.gscore and neighbour in closedList:
                        closedList.remove(neighbour)
                    if neighbour not in openList and neighbour not in closedList:
                        neighbour.gscore = newGscore
                        neighbour.fscore = neighbour.gscore + self.heuristic(neighbour.position)
                        neighbour.parent = currentNode
                        heapq.heappush(openList, neighbour)
                    heapq.heapify(openList)
        return None
        
if __name__ == '__main__':
    
    sys.stdin  = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
    matrix = [[int(num) for num in line.split()] for line in sys.stdin]
    size = matrix.pop(0)
    coordinates = matrix.pop(0)
    n, m = size[0], size[1]
    x1, y1, y2, x2 = coordinates[0], coordinates[1], coordinates[2], coordinates[3]
    path = AStar((x1-1, y1-1), matrix, n, m).computePath((y2-1, x2-1))
    print(len(path))
    for pos in path:
        print(pos[0] + 1, pos[1] + 1)
#IsDiagonalAllowed
# elif (distance == "Diagonal"):
#     return max(abs(x1 - x2), abs(y1 - y2))
#[(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1), (x -1, y-1), (x + 1, y + 1), (x -1, y + 1), (x + 1, y -1)]