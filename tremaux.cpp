#include <iostream>
using namespace std;

class coord{
    public:
    int x, y;

    coord(int x, int y){
        this->x=x;
        this->y=y;
    }

    coord(){
        this->x=-1;
        this->y=-1;
    }

    bool operator==(coord c){
        if ((c.x==this->x) && (c.y==this->y))
            return true;
        else
            return false;
    }

    coord(coord &c){
        this->x=c.x;
        this->y=c.y;
    }
};

void printmaze(int maze[][100], coord c, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (i==c.x && j==c.y){
                cout<<"X";
            }
            else{
                cout<<maze[i][j];
            }
        }
        cout<<"\n";
    }
}

bool junction(int maze[][100], coord c){
    int count=0;
    if (maze[c.x+1][c.y]!=1){
        count++;
    }
    if (maze[c.x-1][c.y]!=1){
        count++;
    }
    if (maze[c.x][c.y+1]!=1){
        count++;
    }
    if (maze[c.x][c.y-1]!=1){
        count++;
    }
    if (count>2){
        return true;
    }
    else{
        return false;
    }
}

bool visited(int maze[][100], coord c){
    if (maze[c.x+1][c.y]==-1 || maze[c.x-1][c.y]==-1 || maze[c.x][c.y+1]==-1 || maze[c.x][c.y-1]==-1){
        return true;
    }
    else{
        return false;
    }
}

coord minadj(int maze[][100], coord c){
    coord minc=c;
    if (maze[minc.x][minc.y]<maze[c.x+1][c.y]){
        minc.x=c.x+1;
    }
    if (maze[minc.x][minc.y]<maze[c.x-1][c.y]){
        minc.x=c.x-1;
    }
    if (maze[minc.x][minc.y]<maze[c.x][c.y+1]){
        minc.x=c.x;
        minc.y=c.y+1;
    }
    if (maze[minc.x][minc.y]<maze[c.x][c.y-1]){
        minc.x=c.x;
        minc.y==c.y-1;
    }
    return minc;
}

bool invalid(int maze[][100], coord c){
    if (maze[c.x+1][c.y]==-2 || maze[c.x-1][c.y]==-2 || maze[c.x][c.y+1]==-2 || maze[c.x][c.y-1]==-2){
        return true;
    }
    else{
        return false;
    }
}

int tremaux(int maze[][100], coord curr, coord end, coord prev, int r, int c){
    printmaze(maze, curr, r, c);

    coord next;
    int diff_x, diff_y;

    if (curr==end){
        return 1;
    }

    if ( invalid(maze, curr)){
        return -1;
    }

    if (junction(maze, curr)){
        maze[prev.x][prev.y]--;
        
        if (maze[prev.x][prev.y]==-2){
            tremaux(maze, minadj(maze, curr), end, curr, r, c);
        }
        else if (visited(maze, curr)){
            tremaux(maze, prev, end, curr, r, c);
        }
        //For not visited, it's the same as non junction - pick the first free path you can find
    }

    diff_x=curr.x-prev.x;
    diff_y=curr.y-prev.y;

    if (maze[curr.x + diff_x ][curr.y + diff_y]!=1){
        next.x=curr.x + diff_x;
        next.y=curr.y + diff_y;
    }
    else if (maze[curr.x + diff_y ][curr.y + diff_x]!=1){
        next.x=curr.x + diff_y;
        next.y=curr.y + diff_x;
    }
    else if (maze[curr.x - diff_y ][curr.y - diff_x]!=1){
        next.x=curr.x - diff_y;
        next.y=curr.y - diff_x;
    }
    else{
        next=curr;
    }

    tremaux(maze, next, end, curr, r, c);
    return 0;
}

int main(){
    cout<<"hello";
    
    int maze[][100]=
    {
        11111
        10001
        10101
        10101
        10101
        10101
        10101
        10101
        10111
        10100000000000000000
        
    }

    return 0;
}