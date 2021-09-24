class Node
{
    constructor(value=0)
    {
        this.data=value
        this.next = null
    }
}

class List
{
    constructor(value=0)
    { 
        const firstNode = new Node(value)
        this.head = firstNode
        this.tail = firstNode
        this.length = 1
    }

    push(value)
    {
        const newNode = new Node(value)
        this.tail.next = newNode
        this.tail = newNode
        newNode.next = null
        this.length++
    }

     /*
    We can display the Linked List by either iterative method or recursive method
    */
    displayIterative()
    {
        /*It is just like displaying an array using loop 
        and printing element at 'i'th index then incrementing i*/
        var current = this.head;
        while(current != null)
        {
            console.log(current.data); 
            current = current.next;
        }
    }

    /**
     * @param current is the node from where values will begin printing
     */
    displayReflexive(current=this.head)
    {
        console.log(current.data);
        if (current.next !=null) 
        this.displayReflexive(current.next);
    }

    /*Here we didn't needed to make two functions for implementing recursive display
    because in JS we can pass the class member as the default value of the argumemnt (this.head in this case)
    for class method*/
}

l = new List(5)
l.push(6)
l.push(7)
l.push(8)
l.displayIterative()
l.displayReflexive()