#include "ultrasoniccontrol.h"
#include <Arduino.h>

int getDistance(UltrasonicSensor sensor)
{
    // setup
    pinMode(sensor.trigger_pin, OUTPUT);
    pinMode(sensor.echo_pin, INPUT);
    digitalWrite(sensor.trigger_pin, LOW);
    delayMicroseconds(2);
    // send 10us pulse
    digitalWrite(sensor.trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor.trigger_pin, LOW);

    // get measurement
    int measurement = (int)pulseIn(sensor.echo_pin, HIGH, ULTR_TIMEOUT);
    // in cm
    // int distance = (int)(measurement / 2 / 29.1);
    
    // return distance;
    return measurement;
}
