
#include <iostream>
#include <cstring>
#include <queue>

struct State{
    int x1;
    int y1;
    int x2;
    int y2;
    int stepCount;
};

void print(const char ** board, const int row, const int col){
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j)
            std::cout << board[i][j];
        std::cout << std::endl;
    }
}

State getInitState(const char ** board, const int row, const int col){
    State s;
    s.stepCount = 0;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(board[i][j] == 'A'){
                s.x1 = i;
                s.y1 = j;
            }else if(board[i][j] == 'B'){
                s.x2 = i;
                s.y2 = j;
            }
        }
    }
}

int solve(const char ** board, const int row, const int col){
    bool visited[row][col][row][col];

    for(int i=0;i<row;++i)
        for(int j=0;j<row;++j)
            for(int k=0;k<row;++k)
                for(int l=0;l<col;++l)
                    visited[i][j][k][l] = false;

    std::queue<State> q;
    State initState = getInitState(board, row, col);
    q.push(initState);
    while(!q.empty()){
        State s = q.front();
        q.pop();

    }


    print(board, row, col);

    return 0;
}

int main(){
    const char *board[] =
        {"AB.................X",
         "XXXXXXXXXXXXXXXXXXX.",
         "X..................X",
         ".XXXXXXXXXXXXXXXXXXX",
         "X..................X",
         "XXXXXXXXXXXXXXXXXXX.",
         "X..................X",
         ".XXXXXXXXXXXXXXXXXXX",
         "X..................X",
         "XXXXXXXXXXXXXXXXXXX.",
         "X..................X",
         ".XXXXXXXXXXXXXXXXXXX",
         "X..................X",
         "XXXXXXXXXXXXXXXXXXX.",
         "X..................X",
         ".XXXXXXXXXXXXXXXXXXX",
         "X..................X",
         "XXXXXXXXXXXXXXXXXXX.",
         "...................X",
         ".XXXXXXXXXXXXXXXXXXX"};

        int row = sizeof(board) / sizeof(char *);
        int col = std::strlen(board[0]);
        solve(board, row, col);

}

