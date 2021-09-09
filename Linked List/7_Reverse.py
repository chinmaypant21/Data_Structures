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

    # N elements copied from LL to array, then N elements copied from array to LL,
    # thus Time Complexity = O(2n) = O(n)
    def reverse_data(self):
        data_array = []
        current=self.head
        while(current!=None):
            data_array.append(current.data)
            current=current.next

        current=self.head
        while(current!=None):
            current.data=data_array.pop()
            current=current.next
        
    

    '''
     * Reversing using slider Poers method.
     * @brief In self method, we create thiree poers, one poing to the
     * current element we are working on, one on the previous element, and one on the next element
     * At starting prev and curr poer are poing to None, and after poer to head
     * then we slide poers to next location and while doing it, we po the 'next' of current to 
     * previous. We do self untill 'after' poer gets to None.
    '''
    def reverse_nodes(self):
        previous = None
        current = None
        after = self.head
        while(after!=None):
            previous=current
            current=after
            after=after.next
            current.next=previous
        self.head=current
    
    def reverse_recursive(self):
        self.reverse_recursive_method(None,self.head)

    def reverse_recursive_method(self,previous,current):
        if(current==None):
            self.head=previous
            return
        
        self.reverse_recursive_method(current,current.next)
        current.next=previous
    
    

l = List(0)
l.push(6)
l.push(7)
l.push(8)
# l.reverse_data()
# l.reverse_nodes()
l.reverse_recursive()
l.display()