#define b1 2
#define b2 3
#define b3 4
#define b4 5
#define b5 6
#define b6 7
#define b7 8
#define b8 9
#define out 10
#define analog1 A1
//button definitions, the nano v3 has 14 digital pins so why
//not just wire one up to each

//Defining button states
int buttonStates[8];

//defining note frequencies
int noteFreqs[8];

//startFreq is the lowest note that can be made
int startFreq = 6000;

// analog value read in by the pot
int aRead = 0;

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
  //play all of the notes in sucession
  for(int i=0; i<8; ++i){
    noteFreqs[i] = 3331;
  }
}

void loop() {
  // read in all of the button states to bSx respectively
  buttonStates[0] = digitalRead(b1);
  buttonStates[1] = digitalRead(b2);
  buttonStates[2] = digitalRead(b3);
  buttonStates[3] = digitalRead(b4);
  buttonStates[4] = digitalRead(b5);
  buttonStates[5] = digitalRead(b6);
  buttonStates[6] = digitalRead(b7);
  buttonStates[7] = digitalRead(b8);
  aRead = analogRead(analog1)*4;
  setFreq();
  for(int i=0; i<8; ++i){
    playNote(noteFreqs[i]);
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

void setFreq(){
  for(int i=0; i<8; ++i){
    if (buttonStates[i] == HIGH){
      noteFreqs[i] = startFreq - aRead;
    }
  }
}
