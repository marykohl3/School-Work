# Mary Kohl
# 1 October 2019
# CISC 4597
# aSearch function from uniform cost
# known bugs: none

import heapq

""" updated map from bfs, now containing the distance """
succ = {'o': ((75,'z'),(140, 's')),
        'z': ((71, 'o'), (75, 'a')),
        'a': ((75, 'z'), (118, 't'), (140, 's')),
        't': ((111, 'l'),( 118, 'a')),
        'l': ((70, 'm'), (111, 't')),
        'm': ((70, 'l'), (75, 'd')),
        'd': ((75, 'm'), (120, 'c')),
        'c': ((120, 'd'),(146,'r'), (138, 'p')),
        'r': ((146, 'c'),(80, 's'), (146, 'p')),
        's': ((80, 'r'), (140, 'a'),(151, 'o'), (99, 'f')),
        'f': ((99, 's'), (211,'b')),
        'p': ((138,'c'), (97,'r'),(101, 'b')),
        'b': ((101,'p'), (211,'f'))
        }

"""a data structure to represent the straight-line distance from each city to Bucharest"""
succDict = {
    "a": 366,
    "b": 0,
    "c": 160,
    "d": 242,
    "e": 161,
    "f": 176,
    "g": 77,
    "h": 151,
    "i": 226,
    "l": 244,
    "m": 241,
    "n": 234,
    "o": 380,
    "p": 100,
    "r": 193,
    "s": 253,
    "t": 329,
    "u": 80,
    "v": 199,
    "z": 374
}

""" search node function
    @param distance: distnace from start node
    @param state: state of the node
    @param history: history of the node """
def searchnode(distance, state, history, pathcost):
    return(distance, state, history, pathcost)

""" select node function
    returns the top of the fringe """
def selectnode(fringe):
    return heapq.heappop(fringe)

""" a*search function for romania
    updated from previous uniform cost function
    @param fringe: the current node being searched from
    @param goal: goal city we are trying to find a path to
    returns the history from start to finish nodes """
def aSearch(fringe, goal):
    start = selectnode(fringe)
    distance = start[0]
    cityname = start[1]
    history = start[2]
    pathcost = start[3] #to calculate the cost and taking the heuristics into account

    print("Checking from city ", cityname, " at level: ", distance)

    if cityname == goal:
        print("Route to ", goal, " from ", history[0]," is: ", history)
        return history

    for newcity in succ[cityname]:
        newhistory = list(history)

        # Check if node is not in history
        if newcity[1]  not in history:
            newPathcost = pathcost + newcity[0] # for straight line search
            newhistory.append(newcity[1])
            newnode = searchnode((newPathcost + succDict[newcity[1]]), newcity[1], newhistory, newPathcost)
            heapq.heappush(fringe, newnode) #push newnode to fringe

    return aSearch(fringe, goal)

#Find path A to B
print("A to B")
startcity='a'
goalcity='b'
startnode = searchnode(0, startcity, [startcity], 0)
fringe = [startnode]
list(fringe)
path = aSearch(fringe, goalcity)

#Find path T to B
print("T to B")
startcity='t'
startnode = searchnode(0, startcity, [startcity], 0)
fringe = [startnode]
list(fringe)
path = aSearch(fringe, goalcity)

