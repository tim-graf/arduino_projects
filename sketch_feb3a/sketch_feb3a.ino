int red_pin = 11;
int yellow_pin = 10;
int green_pin = 9;

int fg_red_pin = 5;
int fg_green_pin = 6;

int base_duration = 3000;
int transition_duration = 1000;

void light_setting(bool red, bool yellow, bool green){
  
  if (red) {
    digitalWrite(red_pin, HIGH);
  } else {
    digitalWrite(red_pin, LOW);
  };
  if (yellow) {
    digitalWrite(yellow_pin, HIGH);
  } else {
    digitalWrite(yellow_pin, LOW);
  };
  if (green) {
    digitalWrite(green_pin, HIGH);
  } else {
    digitalWrite(green_pin, LOW);
  };
};


void fg_light_setting(bool red, bool green){
  if (red) {
    digitalWrite(fg_red_pin, HIGH);
  } else {
    digitalWrite(fg_red_pin, LOW);
  };

  if (green) {
    digitalWrite(fg_green_pin, HIGH);
  } else {
    digitalWrite(fg_green_pin, LOW);
  };
};

void red_phase (int green_red_time){
  light_setting(true, false, false);
  fg_light_setting(false, true);
  delay(green_red_time);
};

void red_to_green (int yellow_time){
  light_setting(true,true,false);
  delay(yellow_time);
};

void green_phase (int green_red_time){
  light_setting(false, false, true);
  fg_light_setting(true, false);
  delay(green_red_time);
};

void green_to_red(int yellow_time) {
light_setting(false, true, false);
delay(yellow_time);
};


void setup() {
  // put your setup code here, to run once:
pinMode(red_pin, OUTPUT);
pinMode(yellow_pin, OUTPUT);
pinMode(green_pin, OUTPUT);
pinMode(fg_red_pin, OUTPUT);
pinMode(fg_green_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
red_phase(base_duration);
red_to_green(transition_duration);
green_phase(base_duration);
green_to_red(transition_duration);
}
