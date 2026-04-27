class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] outdegree = new int[numCourses];
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] courses : prerequisites) {
            int index = courses[0];
            int course = courses[1];
            adjList.get(course).add(index);
            outdegree[index]++;
        }
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (outdegree[i] == 0) {
                q.offer(i);
            }
        }
        int count_courses = 0;
        while (!q.isEmpty()) {
            int course = q.poll();
            count_courses++;
            for (int c : adjList.get(course)) {
                outdegree[c]--;
                if (outdegree[c] == 0)
                    q.offer(c);
            }
        }
        return count_courses == numCourses;
    }
}