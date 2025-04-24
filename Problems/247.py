import sys, math, random, string

def getClasses(data):
    classes = {}
    for entry in data:
        if entry[-1] not in classes:
            classes[entry[-1]] = 1
        else:
            classes[entry[-1]] += 1
    return classes
    
def calcEntropy(data):
    classes = getClasses(data)
    entropy = 0.0
    for key in classes:
        entropy += -float((classes[key]/(len(data)))) * math.log((classes[key]/(len(data))), 2)
    return entropy
    
def getAttributeValsF(data, attribute):
    attributeValues = {}
    for entry in data:
        e = entry[attribute]
        if e not in attributeValues:
            attributeValues[e] = 1
        else:
            attributeValues[e] += 1
    return attributeValues

def getUniqueAttributesVals(data, attribute):
    values = {}
    for entry in data:
        if entry[attribute] not in values:
            values[entry[attribute]] = 1
    return values

def calcInfoGain(data, attribute):
    newData = []
    count = 0
    systemEntropy = calcEntropy(data)
    attributeValues = getAttributeValsF(data, attribute)
    infoGain = 0.0
    for key in attributeValues:
        for entry in data:
            if entry[attribute] == key:
                count += 1
                newData.append([entry[attribute], entry[-1]])
        infoGain += count/len(data) * calcEntropy(newData)
        count = 0
        del newData[:] 
    infoGain = systemEntropy - infoGain
    return infoGain

def split(data, attribute, attributeValue):
    newData = []
    for entry in data:
        if entry[attribute] == attributeValue:
            toBeAdded = entry[:attribute]
            toBeAdded.extend(entry[attribute+1:])
            newData.append(toBeAdded)
    # for i in newData:
    #   print(newData)
    return newData

def chooseBestAttribute(data):
    numAttributes = len(data[0]) - 1
    bestInfoGain = 0.0
    bestAttribute = -1
    for i in range(numAttributes):
        currInfoGain = calcInfoGain(data, i)
        if currInfoGain > bestInfoGain:
            bestInfoGain = currInfoGain
            bestAttribute = i
    # print(bestAttribute, bestInfoGain)
    return bestAttribute

def createTree(data, attributes):
    classes = getClasses(data)
    for key in classes:                             
        if classes[key] == len(data):
            return key
    bestAtt = chooseBestAttribute(data)
    bestAttLabel = attributes[bestAtt]
    tree = {bestAttLabel:{}}
    del(attributes[bestAtt])                        
    
    vals = getUniqueAttributesVals(data, bestAtt)
    for key in vals:                                
        subTrees = attributes[:]
        tree[bestAttLabel][key] = createTree(split(data, bestAtt, key),subTrees) 
    return tree

def getBranches(tree):
    for key, value in tree.items():
        return value

def classify(testData, attributes, tree):
    if isinstance(tree, dict):
        for key, value in tree.items():
            if testData[attributes.index(key)] in getBranches(tree):
                return classify(testData, attributes, getBranches(tree)[testData[attributes.index(key)]])
    else:
        return tree

if __name__ == '__main__':

    # sys.stdin  = open('input.txt', 'r')
    # sys.stdout = open('output.txt', 'w')
    
    i, rules, queries, attributes = 0, [], [], []
    for line in sys.stdin:
        line, temp = line.rstrip(), []
        for inp in line.split(','):
            if (i == 0):
                line = line.split()
                n, m, k = int(line[0]), int(line[1]), int(line[2])
            if (i == 1):
                attributes.append(inp + random.choice(string.ascii_uppercase) + random.choice(string.digits) + random.choice(string.ascii_lowercase))
            temp.append(inp)
        if (i <= m and i != 0):
            rules.append(temp)
        elif (i > m):     
            queries.append(temp)
        i += 1
    attributes.pop()
    tree = createTree(rules, attributes[:])
    for i in range(k):
        decision = classify(queries[i], attributes, tree)
        print(decision)