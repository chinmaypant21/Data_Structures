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

    
    ''' For removing Node from a given index we have to assign the next pointer of the previous node
        from the index node to the next node of the index node, due to which index node will be thrown out
        of the linked list.
        previous->next = index->next  ::: --> previous-> next = previous->next->next
    '''
    def remove(self,index):
        if(index > self.length-1 or index<0):
            print("\nInvalid index for remove method\n")
            return

        self.length-=1

        if(index==0):
            self.head=self.head.next
            return

        index_pointer = self.head
        for i in range(index-1):
            index_pointer = index_pointer.next
        index_pointer.next = index_pointer.next.next
        if(index_pointer.next==None):
            self.tail = index_pointer

    
    def display(self):
        current = self.head
        while(current != None):
            print(current.data)
            current = current.next

    
    

l = List(5)
l.push(6)
l.push(7)
l.push(8)
l.remove(3)
l.display()