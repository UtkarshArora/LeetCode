class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        heap = []
        freqMap = {}
        for n in nums:
            freqMap[n] = 1 + freqMap.get(n, 0)
        
        for key, value in freqMap.items():
            heapq.heappush(heap, (-value, key))
        
        res = []
        while len(res) < k:
            res.append(heapq.heappop(heap)[1])
        
        return res