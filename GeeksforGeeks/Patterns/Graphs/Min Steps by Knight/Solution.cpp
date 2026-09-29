class Solution {
	public:
	
	class store {
		public:
		int x, y, dist;
		
		store(int x, int y, int dist) {
			this->x = x;
			this->y = y;
			this->dist = dist;
		}
	};
	
	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
		// Code here
		
		int startX = knightPos[0]-1;
		int startY = knightPos[1]-1;
		int endX = targetPos[0]-1;
		int endY = targetPos[1]-1;
	    vector<vector<bool>> vis(n, vector<bool>(n, false));	
	    
		queue<store> q;
		
		store s = store(startX, startY, 0);
		q.push(s);
	    vis[startX][startY] = true;
		
		while (!q.empty()) {
			store s = q.front();
			q.pop();
			int x = s.x;
			int y = s.y;
			int dist = s.dist;
			
			if( x==endX && y==endY ){
			    return dist;
			}
			
			
			int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
			int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
			
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
				    store s = store( nx, ny, dist+1);
					vis[nx][ny] = true;
					q.push(s);
				}
			}
			
		}
		
		return -1;
		
	}
};
