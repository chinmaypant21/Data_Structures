class Stack
{
    constructor(size)
    {
        this.size = size;
        this.top  = -1;
        this.data = {};
    }

    
    push(element)
    {
        if(this.isFull())
        {
            console.log("Can not push to already full stack");
            return;
        }

        this.top++;
        this.data[this.top] = element;
    }

    pop()
    {
        if(this.isEmpty())
        {
            console.log("Can not pop from an empty stack");
            return -1;
        }
        // top--;
        return this.data[this.top--];
    }

    //if top is less than 0 it means it is not poiting to any element of stack 
    //thus stack is empty
    isEmpty()
    {
        if (this.top < 0)
            return true;
        return false;
    }

    isFull()
    {
         if (this.top == this.size-1)
            return true;
        return false;

    }

    display()
    {
        for(let i=0;i<=this.top;i++)
        {
            console.log(this.data[i]);
        }
    }

}

s = new Stack(5);
s.push(1);
s.push(4);
s.push(3);
s.display();
console.log('popped: ',s.pop());
s.pop();
s.pop();
s.display();