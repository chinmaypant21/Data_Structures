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


    def add(self,value):

        newNode = Node(value)
        self.tail.next = newNode
        self.tail = newNode
        newNode.next = None
        self.length+=1


    # We can display the Linked List by either iterative method or recursive method
    def displayIterative(self):

        '''It is just like displaying an array using loop 
        and printing element at 'i'th index then incrementing i'''
        current = self.head
        while(current != None):
            print(current.data)
            current = current.next

    def __recursivePrinter(self,current):
        print(current.data) 
        if current.next != None:
            self.__recursivePrinter(current.next)

    '''
     param start: node from where to begin printing values
     '''
    def displayRecursive(self,start=None):

        if start==None:
             start=self.head; 
        self.__recursivePrinter(start)

l = List(5)
l.add(6)
l.add(7)
l.add(8)
l.displayIterative()
l.displayRecursive()