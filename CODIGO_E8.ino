int sensor1 = A0;
int sensor2 = A1;
int led_verde = 10;
int led_amarillo = 9;
int led_rojo = 8;
int extractor1 = 11;
int motordeagua = 12;

// Inicializacion de numeros enteros del sensor1 y sensor2
long adcSensor1 = 0; 
long adcSensor2 = 0;

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(extractor1, OUTPUT);
  pinMode(motordeagua, OUTPUT);


  digitalWrite(motordeagua, LOW);
  digitalWrite(extractor1, LOW);


  Serial.begin(9600);
}
// Lectura del sensor 1
void loop() {
  adcSensor1 = analogRead(sensor1);
  delay(1);
  adcSensor2 = analogRead(sensor2);
  delay(1);

  Serial.print("Sensor 1: ");
  Serial.println(adcSensor1);
  Serial.print("Sensor 2: ");
  Serial.println(adcSensor2);

  if (adcSensor1 > 315) {
    digitalWrite(extractor1, HIGH);
    digitalWrite(motordeagua, HIGH);

    
    float delta = 100*(adcSensor1- adcSensor2)/adcSensor1;
    Serial.print("DELTA: ");
    Serial.println(delta);
    
    if (delta > 35) {
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_amarillo, LOW);
      digitalWrite(led_rojo, LOW);
  
  }   else if (delta >20 && delta <= 35) {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, HIGH);
        digitalWrite(led_rojo, LOW);
      
  }   else if (delta <= 20) {
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarillo, LOW);
        digitalWrite(led_rojo, HIGH);
  }
    
} else {
    digitalWrite(extractor1, LOW);
    digitalWrite(motordeagua, LOW);
    pinMode(sensor2, LOW);
    pinMode(led_verde, LOW);
    pinMode(led_amarillo, LOW);
    pinMode(led_rojo, LOW);
 }
 delay(500);
}
