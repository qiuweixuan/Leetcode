#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point
{
public:
	int t;
	int cost;
	Point(int t, int cost)
	{
		this->t = t;
		this->cost = cost;
	}
};

void search(int used[], int dist[], vector<Point> graph[], int numCities)
{
	int minp = 0;
	for (int i = 1;i <= numCities;i++)
	{
		if (!used[i] && dist[i] < dist[minp])
		{
			minp = i;
		}
	}
	
	if (minp == 0)
	{
		return;
	}

	used[minp] = 1;

	/*
	for (int i = 0;i < graph[minp].size();i++)
	{
		Point p = graph[minp][i];
		dist[p.t] = min(dist[p.t], dist[minp] + p.cost);
	}
	*/
	
	for (vector<Point>::iterator  it = graph[minp].begin();
		it != graph[minp].end();it++)
	{
		Point p = *it;
		dist[p.t] = min(dist[p.t], dist[minp] + p.cost);
	}

	search(used, dist, graph, numCities);

}
vector<int> maxRestTime(int numCities, int numRoads, int** travelTime,
	int numDeliveries, int** timeLimit)
{

	//int  graph[numCities+1][numCities+1];
	//vector<Point>*graph = new vector<Point>[numCities + 1];
	vector<Point> graph[10000 + 1];
	//int* used = new int[numCities + 1];
	int used[10000 + 1];
	fill(used, used + numCities + 1, 0);
	//int* dist = new int[numCities + 1];
	int dist[10000 + 1];
	fill(dist, dist + numCities + 1, 100000007);

	dist[1] = 0;

	for (int i = 0; i< numRoads;i++)
	{
		int s = travelTime[i][0];
		int t = travelTime[i][1];
		int cost = travelTime[i][2];
		graph[s].push_back(Point(t, cost));
	}

	search(used, dist, graph, numCities);
	vector<int> res;
	for (int i = 0; i < numDeliveries;i++)
	{
		int relax;
		if (timeLimit[i][1] > (2 * dist[timeLimit[i][0]]))
		{
			relax = timeLimit[i][1] - (2 * dist[timeLimit[i][0]]);
		}
		else
		{
			relax = 0;
		}
		res.push_back(relax);
	}



	return res;

}


int main() {
	int numCities = 4;
	int numRoads = 4;

	int	store1[4][3] =
	{
		{ 1,2,5 },
		{ 2,3,10 },
		{ 3,4,20 },
		{ 1,4,1 }
	};
	int** travelTime = new int*[4];
	for (int i = 0;i < 4;i++)
	{
		travelTime[i] = new int[3];
		for (int j = 0;j < 3;j++)
		{
			travelTime[i][j] = store1[i][j];
		}
	}
		
	
	int numDeliveries = 2;

	int store2[2][2] =
	{
		{2,65},
		{3,15}
	};
	int** timeLimit = new int*[2];
	for (int i = 0;i < 2;i++)
	{
		timeLimit[i] = new int[2];
		for (int j = 0;j < 2;j++)
		{
			timeLimit[i][j] = store2[i][j];
		}
	}


	vector<int>res = maxRestTime(numCities, numRoads, travelTime,
		numDeliveries,timeLimit);


	for (vector<int>::iterator  it = res.begin();
		it != res.end();it++)
	{
		int cost = *it;
		cout << cost << endl;
	}

	system("pause");
	return 0;
}