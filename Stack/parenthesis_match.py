
# /*LIST FOR PERFORMING STACK OPERATIONS*/
class Node:
    def __init__(self,value):
        self.data = value
        self.next = None
    
    def get_data(self):
        return self.data
    
class List:
    def __init__(self,value=None):
        if(value==None):
            self.list_length=0
            self.head = None
            self.tail = None
            return
        
        self.newNode = Node(value)
        self.head = self.newNode
        self.tail = self.newNode
        self.tail.next = None
        self.list_length = 1
    

    def insert(self,index,value):
        if(index > self.list_length or index<0):
            print("exception: List 'insert' method:  passed index '",
                        index,"' not in index range [0," ,self.list_length, "]\n")
            exit(-1)
        
        newNode = Node(value)
        index_pointer = self.head

        if(index == self.list_length):
            self.tail = newNode
        self.list_length+=1

        if(index==0):
            newNode.next = self.head
            self.head    = newNode
            self.tail    = newNode
            return newNode
        

        # for(let i=0 i<index-1 i++)
        for i in range(index-1):
            index_pointer = index_pointer.next
        
        newNode.next       = index_pointer.next
        index_pointer.next = newNode
        return newNode
    
    def remove(self,index):
        if(index > self.list_length-1 or index<0):
            print("\nInvalid index for remove method\n")
            return None
        
        self.list_length-=1

        if(index==0):
            return_node = self.head
            self.head=self.head.next
            return return_node
        
        index_pointer = self.head
        # for(let i=0i<index-1i++) 
        for i in range(index-1):
            index_pointer = index_pointer.next

        return_node = index_pointer.next
        index_pointer.next = index_pointer.next.next
        if(index_pointer.next==None):
            self.tail = index_pointer

        return return_node
    

    def len(self):
        return self.list_length
    

    # display()
    
    #     current = self.head
    #     if (current == None)
        
    #         print("[]\n")
    #         return
        
    #     while(current != None)
        
    #         print(current.data,"\n") 
    #         current = current.next
        
    



class Stack:
    def __init__(self,size):
        self.size = size
        self.top  = None
        self.data = List()
    

    def push(self,element):
        if(self.isFull()):
            # print("Can not push to full stack")
            return
        self.top = self.data.insert(0,element)
        
    

    def pop(self):
        if(self.isEmpty()):
            # print("Can not pop from empty stack")
            return -1

        self.top = self.data.remove(0)
        return self.top.get_data()
    

    def isFull(self):
        if (self.data.len() == self.size):
            return True
        return False

    def isEmpty(self):    
        if (self.data.len() == 0):
            return True
        return False
    
    def display(self):
        self.data.display()
    

text = "print('Hello there its a normal text')))\ndef fun(e):{{return e})"

parenthesis   = Stack(len(text))
curly_bracket = Stack(len(text))

col_counter  = 1
line_counter = 1

for i in text:
    if(i=='('):
        parenthesis.push(1)

    elif(i==')'):
        if(parenthesis.pop() == -1):
            print("\n[-]Parenthesis not opened properly at col ",col_counter,
            " and line ",line_counter)
        
    elif(i=='{'):
        curly_bracket.push(1)
    
    elif(i=='}'):
        if(curly_bracket.pop() == -1):
            print("\n[-]Curly Brackets not opened properly at col ",col_counter,
            " and line ",line_counter)
    
    elif(i=='\n'):
        line_counter+=1
        col_counter=0
    
    col_counter+=1


if(not parenthesis.isEmpty()):
    print("\n[-]Parenthesis not closed properly\n")

if(not curly_bracket.isEmpty()):
    print("\n[-]Curly Brackets not closed properly\n")
