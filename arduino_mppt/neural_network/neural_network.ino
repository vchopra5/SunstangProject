
//First input is the irradiation, second input is the temperature:
//Paper:
//https://www.researchgate.net/publication/315692275_Maximum_Power_Point_Tracking_Control_of_PV_Electronic_System_using_Neural_Network

double inputs[2];
double hiddenLayer[5];
double output;

double hidden_1[5][2];
double hidden_2[5][2];

const int training_examples = 200;
const int generalization_examples = 50;
const int validation_examples = 50;

double trainingData[training_examples][3];
double generalizationData[generalization_examples][3];
double validationData[generalization_examples][3];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int row = 0; row<5; row++){
    for(int col=0; col<2; col++){
      hidden_1[row][col] = random(-50, 50)/100.0;
      hidden_2[row][col] = random(-50, 50)/100.0;
    }
  }
}

int i = 0;
int input = 3*training_examples;
int second_input = input + 300;

void loop() {
  // put your main code here, to run repeatedly:

  
  if (Serial.available() > 0 and i<input){
    double incomingByte = Serial.parseFloat();
    trainingData[i/3][i%3] = incomingByte;
  }
  if (Serial.available() > 0 and i<(input+300)){
    double incomingByte = Serial.parseFloat();
    generalizationData[(i-input)/3][i%3] = incomingByte;
  }
  if (Serial.available() > 0 and i<(second_input+300)){
    double incomingByte = Serial.parseFloat();
    validationData[(i-second_input)/3][i%3] = incomingByte;
  }
}

void optimization(){
  
}

