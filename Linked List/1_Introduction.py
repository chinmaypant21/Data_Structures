class Node:
    def __init__(self,value=0):

        self.data = value #This will store the value of the data
        self.next = None #This is a reference will point to the next node

class List:
    def __init__(self,value=0):

        newNode = Node(value) #Creating an instance of Node
        self.head = newNode #Referencing head to newNode
        self.tail = newNode
        self.length=1

n = Node(10)
print(n)