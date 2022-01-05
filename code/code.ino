#define b1 2
#define b2 3
#define b3 4
#define b4 5
#define b5 6
#define b6 7
#define b7 8
#define b8 9
#define out 10
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

//defining note frequencies
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int n5 = 0;
int n6 = 0;
int n7 = 0;
int n8 = 0;

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
  pinMode(out, OUTPUT);
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
  if (bS1 == HIGH){
    digitalWrite(out, HIGH);
  }else{
    digitalWrite(out, LOW);
  }
}

void playNote(int interval){
  // this bit of math normalizes the counters target value so that all notes play
  // for the same length of time. the reason why division happens twice is because my nano
  // refused to divide a larger integer. The idea is t = (some constant)/interval
  int x = 0;
  int i = interval/10;
  int t = 10000/i;
  while (x < t){
    //output 1's and 0's on the provided interval
    digitalWrite(out, HIGH);
    delayMicroseconds(interval);
    digitalWrite(out, LOW);
    delayMicroseconds(interval);
    x+=1;
  }
}
