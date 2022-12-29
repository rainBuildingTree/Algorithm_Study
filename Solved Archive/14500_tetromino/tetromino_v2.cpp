#include <iostream>
using namespace std;

enum TetriminoType {Bar=0, Cube, L, S, T};
enum Direction {R=0, D, L, U};
// Bar: bbbb

// Cube: cc
//       cc

// L: lll
//      l

// S: ss
//     ss

// T: ttt
//     t

int tetromino_patterns[5][4][2];
tetromino_patterns[Bar][R][0] = 

