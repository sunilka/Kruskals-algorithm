# Kruskals-algorithm
Implementing the Kruskals algorithm for minimum spanning tree


<i><b>Below are the steps for finding MST using Kruskal’s algorithm</b></i>

<ol>
  <li>Sort all the edges in non-decreasing order of their weight.</li>
  <li>Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.</li>
  <li>Repeat step#2 until there are (V-1) edges in the spanning tree.</li>
 
</ol>
