vector<int> toCompleteParallelogram(int rows, int cols, char** positionsInPark,
									int euclidX, int euclidY, int monteX,
									int monteY)        
{
    // WRITE YOUR CODE HERE
    vector<int> res;
    int ax,ay;
    int dx,dy;
    
    for(int i = 0;i < rows;i++)
    {
    	for(int j = 0;j < cols;j++)
    	{
    		if(positionsInPark[i][j] == '+')
    		{
    			if( ((i + 1 == euclidX)&&(j + 1 == euclidY)) || ((i + 1 == monteX)&&(j + 1 == monteY)) )
    			{
    				continue;
    			}
    			else
    			{
    				ax = i + 1;
    				ay = j + 1;
    			}
    		}
    	}
    }

    dx = (monteX - ax) +  euclidX;
    dy = (monteY - ay) +  euclidY;

    res.push_back(dx);
    res.push_back(dy);

    return res;
}