import sys, random, math
from collections import defaultdict

def eucldist(p0,p1):
    dist = 0.0
    for i in range(0,len(p0)):
        dist += (p0[i] - p1[i])**2
    return math.sqrt(dist)

def newMeans(dataSet, assignments):
    newMeans = defaultdict(list)
    for assignment, point in zip(assignments, dataSet):
        newMeans[assignment].append(point)
    return newMeans
    
def kmeans(k, datapoints):
    d = len(datapoints[0]) 
    Max_Iterations = 1000
    i = 0
    cluster = [0] * len(datapoints)
    prev_cluster = [-1] * len(datapoints)
    cluster_centers = []
    for i in range(0,k):
        new_cluster = []
        cluster_centers += [random.choice(datapoints)]
        force_recalculation = False
    
    while (cluster != prev_cluster) or (i > Max_Iterations) or (force_recalculation) :
        prev_cluster = list(cluster)
        force_recalculation = False
        i += 1
        for p in range(0,len(datapoints)):
            min_dist = float("inf")
            for c in range(0,len(cluster_centers)):
                dist = eucldist(datapoints[p],cluster_centers[c])
                if (dist < min_dist):
                    min_dist = dist  
                    cluster[p] = c
        for _k in range(0,len(cluster_centers)):
            new_center = [0] * d
            members = 0
            for p in range(0,len(datapoints)):
                if (cluster[p] == _k):
                    for j in range(0,d):
                        new_center[j] += datapoints[p][j]
                    members += 1
            for j in range(0,d):
                if members != 0:
                    new_center[j] = new_center[j] / float(members) 
                else: 
                    new_center = random.choice(datapoints)
                    force_recalculation = True
            
            cluster_centers[_k] = new_center
    
    means = list(newMeans(datapoints, cluster).values())
    distance = 0
    for i, j in zip(cluster_centers, means):
        for element in j:
            distance += eucldist(i, element)
            
    #printing output
    print(distance)
    for i in range(k):
        l = means[i]
        print('%g' % cluster_centers[i][0], '%g' % cluster_centers[i][1], len(l), end=' ')
        for j in range(len(l)):
            print(datapoints.index(l[j]) + 1, end=' ')
        print()

    return None
    
if __name__ == '__main__':

    sys.stdin  = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
    i, points = 0, []
    for line in sys.stdin:
        line = line.rstrip().split()
        line[0], line[1] = int(line[0]), int(line[1])
        if (i == 0):
            k = line[1]
        else:
            points.append(line)
        i = -1
    
    kmeans(k, points)