#include <bits/stdc++.h>
using namespace std;
#define int long long int
struct cell{
    int x;
    int y;
    int level; 
    cell() {} 
    cell(int x, int y, int level) : x(x), y(y), level(level) {} 
};
bool isInside(int x, int y, int N){ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
} 

int BFS(int N, int knightPos[], int targetPos[]){
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
    bool visited[N+1][N+1];	
	for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++) 
            visited[i][j] = false;
	queue<cell> q;
	visited[knightPos[0]][knightPos[1]]=true;
	q.push(cell(knightPos[0], knightPos[1], 0));
	while(!q.empty()){
		cell s = q.front();
		cout<<s.level<<" "<<s.x<<" "<<s.y<<endl;
		q.pop();
		if(s.x == targetPos[0] && s.y == targetPos[1])
		    return s.level;
		for(int i=0; i<8; i++){
		    int x = s.x + dx[i];
		    int y = s.y + dy[i];
		    if(isInside(x, y, N) && !visited[x][y]){
		        visited[x][y]=true;
		        q.push(cell(x, y, s.level+1));
		    } 
		}
	}
}
void solve(){
	int N;
	cin>>N;  
	int knightPos[2], targetPos[2];
	cin>>knightPos[0]>>knightPos[1];
	cin>>targetPos[0]>>targetPos[1];
	cout<<BFS(N, knightPos, targetPos)<<endl;
}

int32_t main(){
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
