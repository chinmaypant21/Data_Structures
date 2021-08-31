class Node:

    def __init__(self,value=0):
        self.data=value
        self.next = None

class List:

    def __init__(self,value=0):
        
        firstNode = Node(value)
        self.head = firstNode
        self.tail = firstNode
        self.length=1

    '''
     * insert method takes a value (data) as parameter.
     * It creates a newnode object of type node and assign data=value
     * Currently tail is the last element of list, and we set next of the tail to reference newNode
     * Now the end node = newNode thus now tail is a reference to newnode
     '''
    def insert(self,value):

        newNode = Node(value)
        self.tail.next = newNode
        self.tail = newNode
        newNode.next = None
        self.length+=1

l = List(5)
l.insert(6)
l.insert(7)
l.insert(8)
