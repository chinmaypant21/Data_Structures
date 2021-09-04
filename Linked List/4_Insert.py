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

    def push(self,value):

        newNode = Node(value)
        self.tail.next = newNode
        self.tail = newNode
        newNode.next = None
        self.length+=1
    
    def insert(self,value,index):
        if (index > self.length or index<0):
            print("Invalid index for insert method")
            return

        newNode = Node(value)
        index_pointer = self.head
        self.length+=1
        '''If we have to insert at head, in that case there is no element before that
        so we have to change the statement for self case'''
        if(index==0):
            newNode.next=self.head
            self.head=newNode
            return
        
        for i in range(index-1):
            index_pointer = index_pointer.next
        
        newNode.next=index_pointer.next
        index_pointer.next=newNode
    
    def display(self):
        current = self.head
        while(current != None):
            print(current.data)
            current = current.next
    

l = List(5)
l.push(6)
l.push(7)
l.push(8)
l.insert(4,0)
l.display()