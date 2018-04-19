
void search(){

}




vector<int> maxRestTime(int numCities, int numRoads, int** travelTime,
						int numDeliveries, int** timeLimit)
{
    
}
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED


class Point
{
    public:
    int t;
    int cost;
     Point(int t,int cost)
     {
         this->t = t;
         this->cost = cost;
     }
};

void search(int used[],int dist[], vector<Point> graph[],int numCities)
{
    int minp = 0;
    for(int i = 1;i <= numCities;i++)
    {
        if(!used[i] && dist[i] < dist[minp])
        {
            minp = i;
        }
    }
    
    if(minp == 0)
    {
        return;
    }
    
    used[minp] = 1;
    
    for(int i = 0;i < graph[minp].size();i++)
    {
        Point p = graph[minp][i];
        dist[p.t] = min( dist[p.t], dist[minp] + p.cost);
    }
    
    search(used, dist, graph, numCities);
    
}
vector<int> maxRestTime(int numCities, int numRoads, int** travelTime,
						int numDeliveries, int** timeLimit)
{
    // WRITE YOUR CODE HERE
    //int  graph[numCities+1][numCities+1];
    vector<Point>  graph[numCities+1];
    int used[numCities+1];
    fill(used, used+numCities+1,0);
    int dist[numCities+1];
    fill(dist, used+numCities+1,100000007);
    
    dist[1] = 0;
    
    for(int i = 0; i< numRoads;i++)
    {
         int s = travelTime[i][0];
         int t = travelTime[i][1];
         int cost = travelTime[i][2];
         graph[s].push_back(Point(t,cost));
    }
    
     search(used, dist, graph,numCities);
     vector<int> res;
     for(int i = 0;  i <  numDeliveries;i++)
     {
           res.push_back(timeLimit[i][1] - (2 * dist[timeLimit[i][0]]));
     }
    
    
    
    return res;
    
}
// FUNCTION SIGNATURE ENDS