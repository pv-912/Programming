#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 4
void printSolution(int sol[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}

bool isSafe(int maze[N][N], int x, int y){
	
}

bool solveUtil(int res[N][N], int i, int j ){
	
}

void solve(){
	int res[N][N] = { {0, 0, 0, 0},
				         {0, 0, 0, 0},
				         {0, 0, 0, 0},
				         {0, 0, 0, 0}
    };
	int i = 0, j = 0;
	solveUtil(res,i,j);
		printSolution(res);
}

int main(){
    solve();
    return 0;
}