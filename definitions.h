// definitions

// commands
#define GOFORWARD           'w'
#define GOBACK              'x'
#define GOLEFT              'a'
#define GORIGHT             'd'
#define STOP                's'
#define GODIAGONALLEFT      'e'
#define GODIAGONALRIGHT     'q'
#define GODIAGONALBACKRIGHT 'c'
#define GODIAGONALBACKLEFT  'z'
#define TURNLEFT            'f'
#define TURNRIGHT           'r'

#define CHANGE_SPEED_FASTER 'p'
#define CHANGE_SPEED_SLOWER 'o'

#define AUTONOMIC_MODE      'm'

// constants
#define CHECK_INTERVAL      1000
#define MAX_SPEED           255
#define MIN_SPEED           30
#define SPEED_INCREMENT     10

enum Mode { MANUAL, STOPPED, GOING_FORWARD, GOING_BACKWARD, TURNING_L, TURNING_R };
