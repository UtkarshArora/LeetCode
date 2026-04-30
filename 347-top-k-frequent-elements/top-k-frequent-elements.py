class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        heap = []
        freqMap = {}
        for n in nums:
            freqMap[n] = 1 + freqMap.get(n, 0)
        
        for key, value in freqMap.items():
            heapq.heappush(heap, (value, key))
            if(len(heap) > k):
                heapq.heappop(heap)
        
        res = []
        while heap:
            res.append(heapq.heappop(heap)[1])
        
        return res