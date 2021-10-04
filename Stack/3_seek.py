class Stack:

    def __init__(self,size):
        self.size = size
        self.top  = -1
        self.data = [None]*size
    
    def push(self,element):
        if(self.isFull()): 
            print("Can not push to already full stack")
            return

        self.top += 1
        self.data[self.top] = element

    def isFull(self):
        if (self.top == self.size-1):
            return True
        return False

    def display(self):
        print("[",end=" ")
        for i in range(0,self.top+1):
            print(self.data[i],end=", ")
        print("]")
    
    def seek(self,index):
        if(index<0 or index>=self.size):
            print("Wrong Index")
            return -1
        return self.data[index]
    
        

s = Stack(5)
s.push(1)
s.push(4)
s.push(3)
s.display()
print(s.seek(6))
s.display()