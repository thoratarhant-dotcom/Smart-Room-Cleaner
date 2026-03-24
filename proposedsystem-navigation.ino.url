#define GRID_ROWS 20
#define GRID_COLS 20
#define OBSTACLE_THRESHOLD 20

int8_t grid[GRID_ROWS][GRID_COLS];
int gridX = GRID_COLS / 2;
int gridY = GRID_ROWS / 2;
int heading = 0;

struct Point { int x; int y; };
Point dfsStack[GRID_ROWS * GRID_COLS];
int stackTop = -1;

bool dfsMoveForward() {
  int dxArr[4] = {0,1,0,-1};
  int dyArr[4] = {-1,0,1,0};

  int priorities[4] = {heading,(heading+3)%4,(heading+1)%4,(heading+2)%4};

  for (int p=0;p<4;p++) {
    int dir = priorities[p];
    int nx = gridX + dxArr[dir];
    int ny = gridY + dyArr[dir];

    if (nx<0||nx>=GRID_COLS||ny<0||ny>=GRID_ROWS) continue;
    if (grid[ny][nx]==0) {
      rotateTo(dir);
      float dist = quickDistanceForward();
      if (dist<=OBSTACLE_THRESHOLD) {
        grid[ny][nx] = -1;
        continue;
      }
      moveOneCellForward();
      heading = dir;
      gridX = nx;
      gridY = ny;
      grid[gridY][gridX] = 1;
      dfsStack[++stackTop] = {gridX,gridY};
      return true;
    }
  }
  return false;
}

void backtrack() {
  while (stackTop>0) {
    stackTop--;
    Point prev = dfsStack[stackTop];
    int dx = prev.x - gridX;
    int dy = prev.y - gridY;
    int dir = dirFromDelta(dx,dy);
    if (dir==-1) continue;
    rotateTo(dir);
    moveOneCellForward();
    heading = dir;
    gridX = prev.x;
    gridY = prev.y;
    if (hasUnvisitedNeighbour(gridX,gridY)) break;
  }
}

bool hasUnvisitedNeighbour(int cx,int cy) {
  int dxArr[4]={0,1,0,-1};
  int dyArr[4]={-1,0,1,0};
  for(int d=0;d<4;d++){
    int nx=cx+dxArr[d],ny=cy+dyArr[d];
    if(nx>=0&&nx<GRID_COLS&&ny>=0&&ny<GRID_ROWS)
      if(grid[ny][nx]==0) return true;
  }
  return false;
}

int dirFromDelta(int dx,int dy){
  if(dx==0&&dy==-1) return 0;
  if(dx==1&&dy==0) return 1;
  if(dx==0&&dy==1) return 2;
  if(dx==-1&&dy==0) return 3;
  return -1;
}
