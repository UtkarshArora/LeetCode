class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        heap = []
        res = []
        numCount = Counter(nums)
        for (num, freq) in numCount.items():
            heapq.heappush(heap, (-freq, num))
        for _ in range(k):
            res.append(heapq.heappop(heap)[1])
        return res