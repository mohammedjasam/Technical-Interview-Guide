class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.hash_map = {}
        self._list = []
        self.node_map = {}
        self.capacity = capacity
        self.n = 0
    
    # @return an integer
    def get(self, key):
        if not self.hash_map.get(key, None):
            return -1
            
        else:
            index = self.node_map.get(key, None)
            self._list.pop(index)
            self._list.append(key)
            self.node_map[key] = self.n-1
            return self.hash_map[key]
    

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if self.n == self.capacity:
            last_val = self._list[0]
            self._list.pop(0)
            self.node_map.pop(last_val, None)
            self.hash_map.pop(last_val, None)
            self.n -= 1


        self.hash_map[key] = value
        self._list.append(key)
        self.n += 1
        self.node_map[key] = self.n - 1
        

        