//statement- There are n cities numbered from 0 to n-1. Given arr edges where edges[i] = [fromi, toi,weighti] represents a bidirectional & weighted edge betw cities fromi & toi, & given integer dist Threshold. find out city with smallest no of cities that are reachable through some path & whose dist is at most Threshold Dis, If there are multiple such cities, our ans will be city with greatest num.
//           Note: dist of a path, connecting cities i & j are equal to sum of edges' weights along that path


//(optimal) -using floyd warshall algo t.c- O(v ^ 3)  s.c- O(v ^ 2)
int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX)); // Initialize distance matrix with a large value (INT_MAX)

    for (auto it : edges) { // Set distance for each edge
        dist[it[0]][it[1]] = it[2]; // Set distance from city1 to city2
        dist[it[1]][it[0]] = it[2]; // Set distance from city2 to city1
    }

    for (int i = 0; i < n; i++) dist[i][i] = 0; // Set diagonal to 0, as distance from a city to itself is 0

    for (int k = 0; k < n; k++) { // Apply Floyd-Warshall Algorithm to find shortest paths between all pairs of cities

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue; // Update distance if a shorter path is found

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n; // Initialize variables to track city with least reachable cities
    int cityNo = -1;
    for (int city = 0; city < n; city++) { // Check each city and count number of cities within threshold distance
        int cnt = 0;

        for (int adjCity = 0; adjCity < n; adjCity++) {
            if (dist[city][adjCity] <= distanceThreshold) cnt++; // If distance to adjacent city is within threshold, increment count
        }

        if (cnt <= cntCity) { // Update city with least number of reachable cities
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}