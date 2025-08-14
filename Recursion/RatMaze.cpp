// Link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution {
  public:
    bool isSafe(vector<vector<int>> maze,int n,int x,int y,vector<vector<int>> visited)
    {
        if((x>=0 && x<n) && (y>=0 && y<n) && maze[x][y] == 1 && visited[x][y] == 0)
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> maze,int n,int srcx,int srcy,vector<vector<int>>visited,
    string path,vector<string> &ans)
    {
      //Base case : Reached the destination
        if(srcx == n-1 && srcy == n-1)
        {
            ans.push_back(path);
            return;
        }
        visited[srcx][srcy] = 1;
        
        //Move Down
        int x = srcx+1;
        int y = srcy;
        if(isSafe(maze,n,x,y,visited))
        {
            path.push_back('D');
            solve(maze,n,x,y,visited,path,ans);
            path.pop_back();
        }
        //Move left
        x = srcx;
        y = srcy - 1;
        if(isSafe(maze,n,x,y,visited))
        {
            path.push_back('L');
            solve(maze,n,x,y,visited,path,ans);
            path.pop_back();
        }  
        //Move Right
        x = srcx;
        y = srcy + 1;
        if(isSafe(maze,n,x,y,visited))
        {
            path.push_back('R');
            solve(maze,n,x,y,visited,path,ans);
            path.pop_back();
        }
        //Move Up
        x = srcx - 1;
        y = srcy;
        if(isSafe(maze,n,x,y,visited))
        {
            path.push_back('U');
            solve(maze,n,x,y,visited,path,ans);
            path.pop_back();
        }
        visited[srcx][srcy] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        if(maze[0][0] == 0)
        {
            return ans;
        }
        
        vector<vector<int>> visited = maze;
        int n = maze.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                visited[i][j] = 0;
            }
        }
        int srcx = 0;
        int srcy = 0;
        string path = "";
        solve(maze,n,srcx,srcy,visited,path,ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
