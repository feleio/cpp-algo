
#include <iostream>
#include <cstring>
#include <queue>

class  State{
public:
    State()
    : m_x1(-1), m_y1(-1), m_x2(-1), m_y2(-1), m_stepCount(0) {}

    State(std::pair<int,int> a, std::pair<int,int> b, int stepCount)
    : m_x1(a.first), m_y1(a.second), m_x2(b.first), m_y2(b.second), m_stepCount(stepCount) {}

    void print(){
        std::cout << "(" << m_x1 << ", " << m_y1 << ") (" << m_x2 << ", " << m_y2 << ") " << m_stepCount << std::endl;
    }

    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
    int m_stepCount;
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
    s.m_stepCount = 0;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(board[i][j] == 'A'){
                s.m_x1 = i;
                s.m_y1 = j;
            }else if(board[i][j] == 'B'){
                s.m_x2 = i;
                s.m_y2 = j;
            }
        }
    }
    return s;
}

std::pair<int,int> change(std::pair<int,int> x, int c){
    switch(c){
        case 0:
        return std::pair<int,int>(x.first, x.second);
        case 1:
        return std::pair<int,int>(x.first + 1, x.second);
        case 2:
        return std::pair<int,int>(x.first, x.second + 1);
        case 3:
        return std::pair<int,int>(x.first - 1, x.second);
        case 4:
        return std::pair<int,int>(x.first, x.second - 1);
        case 5:
        return std::pair<int,int>(x.first + 1, x.second + 1);
        case 6:
        return std::pair<int,int>(x.first - 1, x.second - 1);
        case 7:
        return std::pair<int,int>(x.first + 1, x.second - 1);
        case 8:
        return std::pair<int,int>(x.first - 1, x.second + 1);
        default:
        return std::pair<int,int>(-1,-1);
    }
}

int solve(const char ** board, const int row, const int col){
    bool visited[row][col][row][col];

    for(int i=0;i<row;++i)
        for(int j=0;j<col;++j)
            for(int k=0;k<row;++k)
                for(int l=0;l<col;++l)
                    visited[i][j][k][l] = false;

    std::queue<State> q;
    State initState = getInitState(board, row, col);
    visited[initState.m_x1][initState.m_y1][initState.m_x2][initState.m_y2] = true;
    q.push(initState);
    while(!q.empty()){
        State s = q.front();
        q.pop();

        for(int i=0;i<=8;++i)
            for(int j=0;j<=8;++j){
                std::pair<int,int> a(s.m_x1, s.m_y1);
                std::pair<int,int> b(s.m_x2, s.m_y2);
                std::pair<int,int> changeA = change(a, i);
                std::pair<int,int> changeB = change(b, j);

                if(i == 0 && j == 0)
                    continue;
                
                if(changeA.first < 0 || changeA.first >= row 
                    || changeB.first < 0 || changeB.first >= row
                    || changeA.second < 0 || changeA.second >= col
                    || changeB.second < 0 || changeB.second >= col)
                    continue;

                if(board[changeA.first][changeA.second] == 'X'
                    || board[changeB.first][changeB.second] == 'X')
                    continue;

                if(a == changeB && b == changeA)
                    continue;

                if(changeA == changeB)
                    continue;

                if(visited[changeA.first][changeA.second][changeB.first][changeB.second])
                    continue;

                if(initState.m_x1 == changeB.first && initState.m_y1 == changeB.second
                    && initState.m_x2 == changeA.first && initState.m_y2 == changeA.second)
                    return s.m_stepCount + 1; 

                visited[changeA.first][changeA.second][changeB.first][changeB.second] = true;

                q.push(State(std::pair<int,int>(changeA.first, changeA.second)
                    ,std::pair<int,int>(changeB.first, changeB.second), s.m_stepCount + 1));
            }

    }

    return -1;
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
        std::cout << "ans : " << solve(board, row, col) <<std::endl;

}

