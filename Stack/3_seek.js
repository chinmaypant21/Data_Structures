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

    seek(index)
    {
        if(index<0 || index>=this.size)
        {
            console.log("\nWrong Index\n")
            return -1;
        }

        return this.data[index];
    }

}

s = new Stack(5);
s.push(1);
s.push(4);
s.push(3);
s.display();
console.log("seek",s.seek(2))
s.display();