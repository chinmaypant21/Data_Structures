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

    def display(self):
        current = self.head
        while(current != None):
            print(current.data)
            current = current.next
    
    # Merging two Sorted LinkedList
    def merge(self,l2):
    
        '''
          Initially Pointer first will point to the head of current LinkedList
          Initially Pointer second will point to the head of second LinkedList.
        '''
        first = (self).head
        second = l2.head

        '''
          Because we are merging sorted Lists, so our current head should point
          to the element which is smaller in the of the two elements of both Lists.
         '''
        if(first.data < second.data):
            first = first.next #initially head is already same as first
        else:
            self.head = second
            second = second.next
        
        # This last pointer will point to the element before 'first' or 'second' pointer and 
        # it will help to make nodes point in such a way that the resultant list is all sorted
        last = self.head
        last.next = None
        
        while(first != None and second != None):
        
            '''
            If value at the Node to which first pointer is pointing is 
            greater that the value for second, then the node after the last node should be 
            the second one because its value is smaller than the first one.
            And after self, the 'last' pointer will point to the second Node and
            'second' pointer will point to the next node of current node.
            '''
            if(first.data>second.data):
                last.next=second
                last = second
                second = second.next
            
            else:
                last.next=first
                last = first
                first = first.next     

        last.next = None
        '''Now, if any of the pointers pointing first or second list are not null,
        It means that some values are still remaining in that List.
        So we point out next pointer of out last node to that Node(because definitely, the value(s))
        that are remaining in that node are greater that the value at last node and all Lists are sorted.
        '''
        if(first!=None):
             last.next=first
        elif(second!=None):
            last.next=second
    
    
    

l = List(0)
l.push(6)
l.push(7)
l.push(8)
l2 = List(1)
l2.push(3)
l2.push(5)
l2.push(7)
l.merge(l2)
l.display()