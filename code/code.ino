#define b1, 1
#define b2, 2
#define b3, 3
#define b4, 4
#define b5, 5
#define b6, 6
#define b7, 7
#define b8, 8
//button definitions, the nano v3 has 14 digital pins so why
//not just wire one up to each

//Defining button states
int bS1 = 0;
int bS2 = 0;
int bS3 = 0;
int bS4 = 0;
int bS5 = 0;
int bS6 = 0;
int bS7 = 0;
int bS8 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(b5, INPUT);
  pinMode(b6, INPUT);
  pinMode(b7, INPUT);
  pinMode(b8, INPUT);
}

void loop() {
  // read in all of the button states to bSx respectively
  bS1 = digitalRead(b1);
  bS2 = digitalRead(b2);
  bS3 = digitalRead(b3);
  bS4 = digitalRead(b4);
  bS5 = digitalRead(b5);
  bS6 = digitalRead(b6);
  bS7 = digitalRead(b7);
  bS8 = digitalRead(b8);
}
