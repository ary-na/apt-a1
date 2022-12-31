#ifndef COSC_ASSIGN_ONE_TYPES
#define COSC_ASSIGN_ONE_TYPES

#include <cmath>


// #define ENV_DIM                     20
#define ROWS                        60
#define COLS                        60
#define NODE_LIST_ARRAY_MAX_SIZE    ROWS * COLS

// A 2D array to represent the environment or observations
// REMEMBER: in an environment, the location (x,y) is found by maze[y][x]!
//typedef char Env[ENV_DIM][ENV_DIM];
typedef char **Env;

#define SYMBOL_WALL     '='
#define SYMBOL_EMPTY    '.'
#define SYMBOL_GOAL     'G'
#define SYMBOL_START    'S'

#define SYMBOL_MOVE_RIGHT   '>'
#define SYMBOL_MOVE_LEFT   '<'
#define SYMBOL_MOVE_UP   '^'
#define SYMBOL_MOVE_DOWN   'v'


#endif // COSC_ASSIGN_ONE_TYPES