float fVolt = 0;
float fVoltMax = 0;
float iVolt = 0;
float iVoltMax = 0;
int apin = A0;
float k = 10.72511; //8.580089 porpotionality Constant
float G = 0; 
float s = 0.3;
void setup() {
  
  Serial.begin(115200); // communication via serial at buad rate of 115200
  Serial.print("\nInitializing Non-Invasive Glucometer...\n");

  for (int i = 0; i<50; i++) {
    iVolt = (iVolt + (1/((1+s)*(1+s+s*s)))*analogRead(apin))/2;
    //Serial.print(iVolt);
    if (iVoltMax<iVolt) {iVoltMax=iVolt;}
    //Serial.print("\n");
    delay(100);
  }; 
  iVolt = iVoltMax;
  Serial.print("Place Finger between IR Transmiter and Reciever\n");
  
  delay(3000);

  Serial.print("Measuring Glucose...\nDon't Remove Your Finger\n");
  
  for (int i = 0; i<50; i++) {
    fVolt = (fVolt + (1/((1+s)*(1+s+s*s)))*analogRead(apin))/2;
    //Serial.print(fVolt);
    if (iVoltMax<iVolt) {iVoltMax=iVolt;}
    //Serial.print("\n");
    delay(200);
  };
  fVolt = fVoltMax;
  Serial.print("Voltage Difference is ");  
  Serial.print(-fVolt + iVolt);

  G = k * (-fVolt + iVolt);  
  
  Serial.print("\nEstimated Glucose is ");  
  Serial.print(G);
  Serial.print(" mg per dl");
  
}

void loop () {}
