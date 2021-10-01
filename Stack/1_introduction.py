class Stack:
    '''
     * In a stack, we add and remove elements only from the top of the stack.
     * We can not access an element directly that is not at the top of the stack
     * For implementing a stack, we need the size of stack, top pointer of stack to maintain
     * operations and a data structure (like array or linked list) to store elements.
    '''
    def __init__(self,size):
        self.__size = size
        self.__top  = -1
        self.__data = []
    
s = Stack(5)