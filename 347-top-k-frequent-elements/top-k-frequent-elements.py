class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        heap = [(-freq, num) for num, freq in counts.items()]
        heapq.heapify(heap)
        res = [heapq.heappop(heap)[1] for _ in range(k)]
        return res