// https://leetcode.com/problems/reconstruct-itinerary/
// 332. Reconstruct Itinerary

// BFS
class Solution {
    private int flights = 0;
    private Map<String, boolean[]> visited;
    private List<String> res;
    private Map<String,LinkedList<String>> graph;
    /**
     * Use backtracking to check that each path is feasible
     * @param route Current visited route
     * @param src The last airport string(IATA code)
     * @return Whether current route is available
     */
    private boolean backtracking(LinkedList<String> route, String src){
        if(this.flights + 1 == route.size() ){
            this.res = (List<String>)route.clone();
            return true;
        }
        if(!this.graph.containsKey(src))
            return false;
        LinkedList<String> dsts = this.graph.get(src);
        int i = 0;
        boolean[] visitedList = this.visited.get(src);
        for(String dst : dsts){
            if(!visitedList[i]){
                visitedList[i] = true;
                route.add(dst);
            
                boolean ret = this.backtracking(route, dst);

                route.pollLast();
                visitedList[i] = false;
                if (ret)
                    return true;
            }
            ++i;
        }
        
        return false;
    }
    /**
     * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order.
     * @param tickets List of tickets in form of [from, to]
     * @return The itinerary order of airports
     */
    public List<String> findItinerary(List<List<String>> tickets) {
        if(tickets == null || tickets.size() == 0) return null;
        
        // build graph
        this.graph = new HashMap<>();
        for(List<String> ticket : tickets){
            if(graph.containsKey(ticket.get(0))){
                graph.get(ticket.get(0)).add(ticket.get(1));
            }
            else{
                LinkedList<String> toAdd = new LinkedList<String>();
                toAdd.add(ticket.get(1));
                graph.put(ticket.get(0),toAdd);
            }
        }
        // order the destinations & init visited map
        this.visited = new HashMap<>();
        graph.forEach((k, v) -> {
            Collections.sort(v);
            this.visited.put(k, new boolean[v.size()]);
        });
        // record flights number to help backtracking stop
        this.flights = tickets.size();
        // backtracking
        LinkedList<String> route = new LinkedList<String>();
        route.add("JFK");
        this.backtracking(route,"JFK");
        
        return this.res;
    }
    
}

// DFS (Eulerian path)
class Solution {
    // origin -> list of destinations
    HashMap<String, LinkedList<String>> flightMap = new HashMap<>();
    LinkedList<String> result = null;
    /**
     * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order.
     * @param tickets List of tickets in form of [from, to]
     * @return The itinerary order of airports
     */
    public List<String> findItinerary(List<List<String>> tickets) {
      // Step 1). build the graph first
      for(List<String> ticket : tickets) {
        String origin = ticket.get(0);
        String dest = ticket.get(1);
        if (this.flightMap.containsKey(origin)) {
          LinkedList<String> destList = this.flightMap.get(origin);
          destList.add(dest);
        } else {
          LinkedList<String> destList = new LinkedList<String>();
          destList.add(dest);
          this.flightMap.put(origin, destList);
        }
      }
  
      // Step 2). order the destinations
      this.flightMap.forEach((key, value) -> Collections.sort(value));
  
      this.result = new LinkedList<String>();
      // Step 3). post-order DFS
      this.DFS("JFK");
      return this.result;
    }
    
    /**
     * Postorder traverse to find the correct way
     * @param origin Last airport(source airport)
     */
    protected void DFS(String origin) {
      // Visit all the outgoing edges first.
      if (this.flightMap.containsKey(origin)) {
        LinkedList<String> destList = this.flightMap.get(origin);
        while (!destList.isEmpty()) {
          // while we visit the edge, we trim it off from graph.
          String dest = destList.pollFirst();
          DFS(dest);
        }
      }
      // add the airport to the head of the itinerary
      this.result.offerFirst(origin);
    }
  }