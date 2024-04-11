class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class MyLinkedList:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        current = self.head
        for i in range(index):
            if current is None:
                return -1
            current = current.next
        if current is None:
            return -1
        return current.val

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.head = Node(val, self.head)

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        """
        if self.head is None:
            self.head = Node(val)
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = Node(val)

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index <= 0 :
            self.addAtHead(val)
        else:
            current = self.head
            
            for i in range(index - 1):
                if current is None:
                    return
                current = current.next
            if current is None:
                return
            
            new_node = Node(val)
            new_node.next = current.next
            current.next = new_node

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index < 0:
            return
        if index == 0:
            self.head = self.head.next
        else:
            current = self.head
            for i in range(index - 1):
                if current is None:
                    return
                current = current.next
            if current is None or current.next is None:
                return
            current.next = current.next.next