class MyWord:
    def __init__(self, freq, word):
        self.freq=freq
        self.word=word

    # it will return true/false
    def __lt__(self, other): # the function handing the less than operator, this needs to be overwritten
        # when to return true, when false
        #true=dont need to change the order
        #false=when i have to change the order
        # if the freq are not same->to place lesser freq word above
        if self.freq!=other.freq:
            if self.freq<other.freq:
                return True
            else:
                return False
        else:
            if self.word<other.word: # higher lexo word should be at the top
                return False
            else:
                return True


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d={}
        #counting
        for w in words:
            if w in d:
                d[w]+=1
            else:
                d[w]=1
        
        #inserting inheap
        min_heap = list()
        for word, count in d.items(): # key as well as the value
            obj = MyWord(count, word)
            heapq.heappush(min_heap, obj)
            if len(min_heap)>k:
                heapq.heappop(min_heap)

        #we have the words, just removing from the heap and saving in ans 
        ans=[]
        while len(min_heap)>0:
            ans.append(heapq.heappop(min_heap).word)
        
        #just reversing and return
        return ans[::-1]





        
