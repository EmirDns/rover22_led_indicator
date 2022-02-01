#include <Arduino.h>
#include "ros.h"
#include "std_msgs/String.h"

#define IN1 5
#define IN2 6
#define IN3 7

std_msgs::String incoming_string;
String my_Str;

void red();
void blue();
void green();
void turn_off();
void ledCallback(const std_msgs::String &incoming_string);

ros::NodeHandle nh;
ros::Subscriber<std_msgs::String> led_Sub("led_topic", ledCallback);

void setup() {
  nh.initNode();
  nh.subscribe(led_Sub);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
}

void loop() {
  nh.spinOnce();
  delay(1);
}

void red(void){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
}

void blue(void){
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
}

void green(void){
  digitalWrite(IN3,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

void turn_off(void){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
}

void ledCallback(const std_msgs::String &incoming_string){
  my_Str=incoming_string.data;
  if(my_Str=="R"){
    red();
  }
  if(my_Str=="B"){
    blue();
  }
  if(my_Str=="G"){
    green();
  }
  if(my_Str=="T"){
    turn_off();
  }
  delay(10);
}


