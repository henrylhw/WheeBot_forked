#pragma once

#define __DEBUG__

#define __ESP32_BLE__   // enable navigation by ios app
                        // https://apps.apple.com/us/app/goble-bluetooth-4-0-controller/id950937437

#define __ROS__ // enable navigation by ROS [cmd_vel] topic

#define HAS_SPEED_SENSOR 1

// gpio pins assignment
#define MOTOR_RIGHT_GPIO_PIN1 18
#define MOTOR_RIGHT_GPIO_PIN2 19
#define MOTOR_RIGHT_PWM_PIN 5

#define MOTOR_LEFT_GPIO_PIN1 32
#define MOTOR_LEFT_GPIO_PIN2 33
#define MOTOR_LEFT_PWM_PIN 25

#if HAS_SPEED_SENSOR
#define GPIO_PIN_SPEED_L 26
#define GPIO_PIN_SPEED_R 14
#endif

#define SERIAL_RX2_PIN 16
#define SERIAL_TX2_PIN 17

//
#define Console Serial
#define CONSOLE_BAUD_RATE   115200


