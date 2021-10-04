class Stack:

    def __init__(self,size):
        self.size = size
        self.top  = -1
        self.data = [None]*size
        #data list of given size
    
    def push(self,element):
        if(self.isFull()): 
            print("Can not push to already full stack")
            return

        self.top += 1
        self.data[self.top] = element
    

    def pop(self):
        if(self.isEmpty()):
            print("Can not pop from an empty stack")
            return -1
        
        self.top -= 1
        return self.data[self.top+1]
    

    #if top is less than 0 it means it is not poiting to any element of stack 
    #thus stack is empty
    def isEmpty(self):
        if (self.top < 0):
            return True
        return False
    

    def isFull(self):
        if (self.top == self.size-1):
            return True
        return False

    def display(self):
    
        print("[",end=" ")
        # for(int i=0;i<=top;i++)
        for i in range(0,self.top+1):
            # print(self.data[i],", ")
            print(self.data[i],end=", ")
        print("]")
        
    
s = Stack(5)
s.push(1)
s.push(4)
s.push(3)
s.display()
print('popped: ',s.pop())
s.pop()
s.pop()
s.display()