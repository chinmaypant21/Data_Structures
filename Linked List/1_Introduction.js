class Node
{
    constructor(value=0)
    {   
        this.data = value
        this.next = null
    }  
}

class List
{
    constructor(value=0)
    {
        newNode = new Node(value)
        this.head = newNode
        this.tail = newNode
        this.length=1
    }
};

const n = new Node(10);
console.log(n);