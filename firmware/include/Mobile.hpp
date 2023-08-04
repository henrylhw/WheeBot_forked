#pragma once

class Motor {
 protected:
  int Pin1;
  int Pin2;
  int pwmPin;
  int pwmValue;

 public:
  Motor(int Pin1, int Pin2, int pwmPin) : Pin1(Pin1), Pin2(Pin2), pwmPin(pwmPin) {
    update(0);
    pinMode(Pin1,OUTPUT);
    pinMode(Pin2,OUTPUT);
    pinMode(pwmPin,OUTPUT);
  }

  void update(int pwmValue) {
    if (pwmValue > 0) {
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      analogWrite(pwmPin, pwmValue);
      // analogWrite(Pin1, pwmValue);
      // analogWrite(Pin2, 0);
      this->pwmValue = pwmValue;
    } else if (pwmValue < 0) {
      // analogWrite(Pin1, 0);
      // analogWrite(Pin2, -pwmValue);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      analogWrite(pwmPin, pwmValue);
      this->pwmValue = pwmValue;
    } else {  // Motor brake
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      analogWrite(pwmPin, 0);
      this->pwmValue = 0;
    }
  }
  int getpwmValue() { return pwmValue; }
};

class Mobile {
 private:
  Motor rightMotor;
  Motor leftMotor;

 public:
  Mobile(Motor rightMotor, Motor leftMotor)
      : rightMotor(rightMotor), leftMotor(leftMotor) {}

  void updatePWM(int right, int left) {
    rightMotor.update(right);
    leftMotor.update(left);
  }

  void getPWM(int *right, int *left) {
    if (right != nullptr) {
      *right = rightMotor.getpwmValue();
    }
    if (left != nullptr) {
      *left = leftMotor.getpwmValue();
    }
  }
  inline void stop() { updatePWM(0, 0); }
};
