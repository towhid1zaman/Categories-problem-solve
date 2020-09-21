# Articulation Point
 **Basic Definition : From an undirected graph if we remove some node or vertices with their edeges and then the connected components are increaces then we call this node Articulation point** 

Articulation point using tarjan algorithm:
 
 **some steps:**
 
 * Conditions for AP,
 * 1.if its root node then its must have at least two child
 * 2.visitTime of node <= lowtime of any adjecent node
 * 
 * lowTime Updation,
 * 1.When parent node in dfs traversal return from any child node,
 *	lowTime[parent] = min(lowTime[parent], lowTime[child])
 *
 * When Back edge exist,
 * 1.lowTime[current node] = min(lowTime[current node], VisitTime[that node]) 
 
 **Back Edge**
 
 Basically an edge that create a cycle then its called a back edge. Back edge connect a node to his ancestor, which isnot directly his parent.
 
 Back edge never be a bridges.
 
 
 # Bridges
 **Basic Definition : From an undirected graph if we remove some edges and then the connected components are increaces then we call this edges Bridges or Articulation edges**


 Articulation edges/Bridges using tarjan algorithm:
 * Conditions for AP,
 * visitTime of node < lowtime of any adjecent node
 * 
 * lowTime Updation,
 * lowTime[v] = min(lowTime[v], lowTime[to])
 *
 * When Back edge exist,
 * lowTime[v] = min( lowTime[v], visitTime[to])
 
