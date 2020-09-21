# BFS & DFS

## Template of BFS & DFS on 2D array

```java
void DFS(char[][] grid, int r, int c) {
    LinkedList<Pair<Integer, Integer>> queue = new LinkedList<Pair<Integer, Integer>>();
    queue.offer(new Pair<>(r, c));
    while (!queue.isEmpty()) {
        Pair<Integer, Integer> pair = queue.pollLast();  // only change
        int row = pair.first, col = pair.second;
        
        // process code here

        // go deeper
        if (col < this.COLS - 1)
        queue.offer(new Pair<>(row, col + 1));
        if (row < this.ROWS - 1)
        queue.offer(new Pair<>(row + 1, col));
        if (col > 0)
        queue.offer(new Pair<>(row, col - 1));
        if (row > 0)
        queue.offer(new Pair<>(row - 1, col));
    }
}

void BFS(char[][] grid, int r, int c) {
    LinkedList<Pair<Integer, Integer>> queue = new LinkedList<Pair<Integer, Integer>>();
    queue.offer(new Pair<>(r, c));
    while (!queue.isEmpty()) {
        Pair<Integer, Integer> pair = queue.pollFirst();  // only change
        int row = pair.first, col = pair.second;

        // process code here

        // go deeper
        if (col < this.COLS - 1)
        queue.offer(new Pair<>(row, col + 1));
        if (row < this.ROWS - 1)
        queue.offer(new Pair<>(row + 1, col));
        if (col > 0)
        queue.offer(new Pair<>(row, col - 1));
        if (row > 0)
        queue.offer(new Pair<>(row - 1, col));
    }
}
```