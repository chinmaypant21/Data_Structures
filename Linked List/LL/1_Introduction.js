class Node
{
    constructor(value=0)
    {   
        this.data = value //This will store the value of the data
        this.next = null //This is a reference will point to the next node
    }  
}

class List  //This is the LinkedList
{
    constructor(value=0)
    {
        newNode = new Node(value) //This creates the instance of Node object
        this.head = newNode
        this.tail = newNode
        this.length=1
    }
};

const n = new Node(10);
console.log(n);