# Mary Kohl
# 12 October 2019
# CISC 4597
# countQueens and beamSearch
# known bugs: none

from numpy import zeros
import random

"""printQueens function
    takes a list of queens and prints out a nxn board
    @param listQueens: the array that contains the location of the queens """
def printQueens(listQueens):
    a = zeros([len(listQueens),len(listQueens)])
    for i in range(0, len(listQueens)):
        for j in range(0, listQueens[i]+1):
            if (listQueens[i] == (j)):
                a[j,i] = 1
    print("Board:")
    print (a)

""" countQueens function
    takes a list and finds how many queens conflict
    @param: listQueens: the array containing the location of the queens
    returns number of conflictingQueens"""
def countQueens(listQueens):
    conflictingQueens = 0
    copyQueens = listQueens.copy() #make copy to pop
    for i in listQueens:
        copyQueens.pop(0) #get first value in list
        iterator = 1
        for j in copyQueens:
            if i == j: #check rows
                conflictingQueens+=1
            if ((j == i+iterator) or (j == i-iterator)): #check diagonals
                conflictingQueens+=1
            iterator+=1
    return(conflictingQueens)

""" randomQueens function
    @param size: the size of the array that will be returned
    returns an array of random numbers in the range """
def randomQueens(size):
    randomState = []
    for i in range(0, size):
        randomState.append(random.randint(0, size-1))
    return randomState

""" getSucc function
    @param givenState: array for the successors to be found
    @param size: the size of the array
    returns an array of successors """
def getSucc(givenState, size):
    succ = [] #empty array that will be added to
    iterator = 0
    for x in givenState:
        stateCopy = givenState.copy()
        if x > 0:
            stateCopy[iterator] -= 1 #decrease values in state
            succ.append(stateCopy)
        if x < (size - 1):
            stateCopy[iterator] += 1 #increase values in state
            succ.append(stateCopy)
        iterator+=1
    return succ

""" beamSearch function
    original attempt was to make beam search recursive and experiences a memory leak
    I changed the function to use a while loop instead
    @param k: beam size
    @param size: size of the board / array
    returns final state or -1 if nothing is found """
def beamSearch(k, size):
    kStates = [] #empty array of states to be added to
    cost = 0 #counter for cost
    max = 100000 #max amount of iterations before NoSolution is returned
    found = 0 #boolean value for if solution has been found
    while (found == 0):
        if kStates: #if states is null the next if statement would produce an error
                if(countQueens(kStates[0]) == 0):
                    found = 1 #update found
                    print("Soltion found for ", size, " x ", size, " board")
                    print(kStates[0])
                    printQueens(kStates[0]) #print board for proof of solution
                    return(kStates[0])
                    break

        if (cost > max): #no solution found in the given time
            print("No Solution Found")
            return(-1)
            break

        for i in range(k): #add random arrays to your states
            kStates.append(randomQueens(size))

        copyStates = kStates.copy() #copy array
        for x in copyStates:
            for newStates in getSucc(x, size):
                kStates.append(newStates) #add new states to states

        kStates.sort(key = countQueens) #sorts ascending by conflicting queens (from: https://www.programiz.com/python-programming/methods/list/sort)

        kStates = kStates[:k+1] #all states up to k+1

        cost+=1

# Given string in class
listQueens = [3,1,0,4,6,7,1,5]
printQueens(listQueens)
conflictingQueens = countQueens(listQueens.copy())
print("conflictingQueens: ", conflictingQueens)

# Secondary Test String
listQueens2 = [1,2,0,4,7,7,1,5]
printQueens(listQueens2)
conflictingQueens = countQueens(listQueens2.copy())
print("conflictingQueens: ", conflictingQueens)

# BeamSearch
size = 8 # size by size board
k = 10
states = []
print("BeamSearch of beam size: ", k, " and board size of: ", size, " x ", size)
beamSearch(k, size)

