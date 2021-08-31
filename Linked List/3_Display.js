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
        this.length++
    }

    /**
     * insert method takes a value (data) as parameter.
     * It creates a newnode object of type node with data=value
     * Currently tail is the last element of list, and we set next of the tail to reference newNode
     * Now the end node = newNode thus now tail is a reference to newnode
     */
    insert(value)
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
l.insert(6)
l.insert(7)
l.insert(8)
l.displayIterative()
l.displayReflexive()