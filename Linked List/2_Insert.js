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

}

l = new List(5)
l.insert(6)
l.insert(7)
l.insert(8)
