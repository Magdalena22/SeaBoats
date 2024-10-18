#define ULTR_TIMEOUT    5000

struct UltrasonicSensor
{
    int trigger_pin;
    int echo_pin;
};

int getDistance(UltrasonicSensor sensor);
