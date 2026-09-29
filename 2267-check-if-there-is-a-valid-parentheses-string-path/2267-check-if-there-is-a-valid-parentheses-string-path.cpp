/*
Insights : 
- string of balanced bracket will always have an even length, overall length would be m + n - 1 
- if the count midway drops to negative it means there is an additional ")" hence it can be returned false immediately.
- so to memoize we hve three params - i , j, count-->n+m-1
- as we can see from the constraints t[101][101][201]
*/

class Solution {
public:
    int m,n;
    int t[101][101][201];
    bool solve(int i, int j, int cnt,vector<vector<char>>& grid ){
        if(grid[i][j]=='(') cnt+=1;
        if(grid[i][j]==')') cnt-=1;
        if(i==m-1 && j==n-1) {
            return cnt==0? true:false;
        }        
        if(cnt < 0) return false;
        if(t[i][j][cnt]!=-1) return t[i][j][cnt];


        // move right
        if(i+1 < m) if(solve(i+1,j,cnt,grid)) return t[i][j][cnt] = true;
        // move down
        if(j+1 < n) if(solve(i,j+1,cnt,grid)) return t[i][j][cnt] = true;
        return t[i][j][cnt] = false;

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(t,-1,sizeof(t));
        m = grid.size();
        n = grid[0].size();
        if(grid[0][0]==')') return false;
        if((m+n-1)%2) return false;
        return solve(0,0,0,grid);
    }
};