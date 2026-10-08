#define TRIG_PIN D5   // GPIO14
#define ECHO_PIN D6   // GPIO12
#define LED_PIN  D1   // GPIO5

long duration;
float distance=15;
int i = 0;

void setup()
 {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // LED off initially
}

void loop()
 {
  distance = Read_Ultrasonic();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(i>2)
  {
  // Turn LED on if object is closer than 14 cm
    if (distance <= 14.0) 
    {
      digitalWrite(LED_PIN, HIGH);
      delay(12000);
    } 
    else 
    {
      digitalWrite(LED_PIN, LOW);
    }
  }
  i++;
  
}

float Read_Ultrasonic()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo time
  duration = pulseIn(ECHO_PIN, HIGH);
  int dist = duration * 0.034 / 2;
  delay(500);
  return dist;

}
