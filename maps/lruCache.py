class node:
    def __init__(self, key, val):
        self.key=key
        self.val=val
        self.prev=None
        self.next=None


class LRUCache:
    def __init__(self, capacity: int):
        self.size = capacity
        self.d={}
        self.head = node(-1, -1)
        self.tail = node(-1, -1)
        self.head.next=self.tail
        self.tail.prev=self.head
        
    def addNode(self, temp):
        nxt = self.head.next
        #add to the head
        #connection half 1
        self.head.next=temp
        temp.prev=self.head

        #half 2
        nxt.prev=temp
        temp.next=nxt

    def deleteNode(self, temp):
        temp_next=temp.next
        temp_prev=temp.prev

        temp_prev.next=temp_next
        temp_next.prev=temp_prev
    
    def get(self, key: int) -> int:
        # whethet the key has come or not
        if key not in self.d:
            return -1
        
        ansValue = self.d[key].val
        #delete the node from LL, map
        self.deleteNode(self.d[key])
        self.d.pop(key)

        #add the value again (new place in the LL, new node in the map)
        temp  = node(key,ansValue)
        self.addNode(temp) # add to the head
        self.d[key]=temp

        return ansValue

    def put(self, key: int, value: int) -> None:
        #the node is already present
        if key in self.d:
            self.deleteNode(self.d[key])
            self.d.pop(key)
        
        #if i am inserting a new pair, size is full, i will delete lru
        if self.size == len(self.d):
            #remove lru, order is imp
            self.d.pop(self.tail.prev.key)
            self.deleteNode(self.tail.prev)
            
        #add
        temp = node(key, value)
        self.addNode(temp) # add to the head
        self.d[key]=temp

        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
