

int base_duration = 3000;
int transition_duration = 1000;

class TrafficLight {
private:
  int red_pin;
  int yellow_pin;
  int green_pin; 
  int base_duration;
  int transition_duration;
  void init() {
    pinMode(red_pin, OUTPUT);
    pinMode(yellow_pin, OUTPUT);
    pinMode(green_pin, OUTPUT);
  };
  void light_setting(bool red, bool yellow, bool green) {
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

  void red_phase() {
    light_setting(true, false, false);
    //delay(base_duration);
  };

  void red_to_green() {
    light_setting(true, true, false);
    //delay(transition_duration);
  };

  void green_phase() {
    light_setting(false, false, true);
    //delay(base_duration);
  };

  void green_to_red() {
    light_setting(false, true, false);
    //delay(transition_duration);
  };
public:
  TrafficLight(int red_pin, int yellow_pin, int green_pin, int base_duration, int transition_duration, bool is_master=true) {
    this->red_pin = red_pin;
    this->yellow_pin = yellow_pin;
    this->green_pin = green_pin;
    this->base_duration = base_duration;
    this->transition_duration = transition_duration;
    this->is_master=is_master;
    init();
  };

  bool is_master;  
 

  void phases (int ii){
    switch (ii) {
      case 1:
        red_phase();
        break;
      case 2:
        red_to_green();
        break;
      case 3:
        green_phase();
        break;
      case 4:
        green_to_red();
        break;
        };
    };
  

  

  void on() {

  for (int ii = 1; ii < 5; ii++){
    int kk[4] = {3,4, 1, 2};
    int jj;
    if (is_master) {jj = ii;} else {jj = kk[ii-1];};
    phases(jj);
    if (ii % 2 != 0){
      delay(base_duration);
    } else {
      delay(transition_duration);
    };
  };
};
};

TrafficLight masterTl(11,10,9, base_duration, transition_duration);
TrafficLight slaveTl(5,6,7, base_duration, transition_duration,false);

void setup() {
  // put your setup code here, to run once:
  // pinMode(red_pin, OUTPUT);
  // pinMode(yellow_pin, OUTPUT);
  // pinMode(green_pin, OUTPUT);
  // pinMode(fg_red_pin, OUTPUT);
  // pinMode(fg_green_pin, OUTPUT);
}


void crossing (TrafficLight master, TrafficLight slave){
    for (int ii = 1; ii < 5; ii++){
    int kk[4] = {3, 4, 1, 2};
    master.phases(ii);
    slave.phases(kk[ii-1]);
    if (ii % 2 != 0){
      delay(base_duration);
    } else {
      delay(transition_duration);
    };
  };
};



void loop() {
  // put your main code here, to run repeatedly:
  // red_phase(base_duration);
  // red_to_green(transition_duration);
  // green_phase(base_duration);
  // green_to_red(transition_duration);
  crossing(masterTl,slaveTl);
}
