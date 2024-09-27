unordered_map<Vertex*, PathVertexInfo*> DijkstraShortestPath(Graph& graph, Vertex* startVertex) {
   // Create the unordered_map for vertex information
   unordered_map<Vertex*, PathVertexInfo*> info;

   // Put all graph vertices in both the info unordered_map and the
   // vector of unvisited vertices
   vector<PathVertexInfo*> unvisited;
   for (Vertex* vertex : graph.GetVertices()) {
      PathVertexInfo* vertexInfo = new PathVertexInfo(vertex);
      unvisited.push_back(vertexInfo);
      info[vertex] = vertexInfo;
   }

   // startVertex has a distance of 0 from itself
   info[startVertex]->distance = 0.0;

   // Iterate through all vertices in the priority queue
   while (unvisited.size() > 0) {
      // Remove info with minimum distance
      PathVertexInfo* currentInfo = PathVertexInfo::RemoveMin(unvisited);

      // Check potential path lengths from the current vertex to all neighbors
      for (Edge* edge : *graph.GetEdgesFrom(currentInfo->vertex)) {
         Vertex* adjacentVertex = edge->toVertex;
         double alternativePathDistance = currentInfo->distance + edge->weight;

         // If a shorter path from startVertex to adjacentVertex is found,
         // update adjacentVertex's distance and predecessor
         PathVertexInfo* adjacentInfo = info[adjacentVertex];
         if (alternativePathDistance < adjacentInfo->distance) {
            adjacentInfo->distance = alternativePathDistance;
            adjacentInfo->predecessor = currentInfo->vertex;
         }
      }
   }

   return info;
}
