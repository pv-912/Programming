#include <iostream>

using namespace std;
#define N  4
bool solveMazeUtil(int maze[N][N], int i, int j, int res[N][N]){
	if(i == N-1 && j == N-1 && maze[i][j] == 1)
		return true;

	res[i][j] = 1;
	if(maze[i+1][j] == 1 && i<N && j<N){
		solveMazeUtil(maze, i+1, j, res);
		return true;
	}
	if(maze[i][j+1] == 1 && i<N && j<N){
		solveMazeUtil(maze, i, j+1, res);
		return true;
	}

	res[i][j] = 0;
	return false;

}

void solveMaze(int maze[N][N]){
	int i = 0, j = 0;
	int res[N][N] = {0};
	solveMazeUtil(maze, i, j, res);
	for(int i = 0;i<N;i++){
		for(int j = 0; j<N; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze); 
    return 0; 
}