class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}} ;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        vector<vector<int>>newimage=image;
        int starting=newimage[sr][sc];
        if(starting==color)return newimage;
        queue<p>q;
        q.push({sr,sc});
       newimage[sr][sc]=color;
      
        auto issafe=[&](int x,int y){
           return x>=0 && y>=0 && x<n && y<newimage[x].size() && newimage[x][y]==starting;
        };
        while(!q.empty()){
            int m=q.size();
            while(m--){
                p find=q.front();
                int new_sr=find.first;
                int new_sc=find.second;
                q.pop();
                for(auto &dir:directions){
                    int x=new_sr+dir[0];
                    int y=new_sc+dir[1];
                    
                    if(issafe(x,y)){
                        q.push({x,y});
                        newimage[x][y]=color;
                    }
                }
            }
        }
          return newimage;
    }
};


/////////////////////////////////////////////////////////////////////////////////    dfs    ///////////////////////////
class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];

        if (startColor == color) return image;

        function<void(int, int)> dfs = [&](int x, int y) {
            image[x][y] = color;
            for (auto dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == startColor) {
                    dfs(nx, ny);
                }
            }
        };

        dfs(sr, sc); // start the recursion
        return image;
    }
};
/////////////////////////////  python /////
from collections import deque

class Solution:
    def floodFill(self, image, sr, sc, color):
        n = len(image)
        m = len(image[0])
        new_image = [row[:] for row in image]  # Deep copy of the image
        starting = new_image[sr][sc]

        if starting == color:
            return new_image

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right

        def issafe(x, y):
            return 0 <= x < n and 0 <= y < len(new_image[x]) and new_image[x][y] == starting

        q = deque()
        q.append((sr, sc))
        new_image[sr][sc] = color

        while q:
            size = len(q)
            for _ in range(size):
                new_sr, new_sc = q.popleft()
                for dx, dy in directions:
                    x, y = new_sr + dx, new_sc + dy
                    if issafe(x, y):
                        q.append((x, y))
                        new_image[x][y] = color

        return new_image
/////////////////////////
class Solution:
    def floodFill(self, image, sr, sc, color):
        n = len(image)
        m = len(image[0])
        new_image = [row[:] for row in image]
        starting = new_image[sr][sc]

        if starting == color:
            return new_image

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        def dfs(x, y):
            if x < 0 or y < 0 or x >= n or y >= len(new_image[x]):
                return
            if new_image[x][y] != starting:
                return

            new_image[x][y] = color

            for dx, dy in directions:
                dfs(x + dx, y + dy)

        dfs(sr, sc)
        return new_image

