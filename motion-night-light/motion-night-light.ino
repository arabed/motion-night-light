/**
 * Night Motion Light
 * Version 1.0
 * A. Bedrossian - CA - Oct.2024
 */

#define RELEASE_VERSION  "1.0"
#define RELEASE_DATE     "10-19-2024"

#define gpioD1LedOut  15
#define gpioD2LedOut  14
#define gpioD3LedOut  16
#define gpioMotionIn   9
#define gpioPhotoIn   19

#define SERIAL_OUT_ENABLED

int cnt = 0;
int photoAvrg = 0;
int led[] = {0,0,0};
int ledCnt = 0;

void setup() {
  pinMode(LED_BUILTIN_TX,INPUT);
  pinMode(LED_BUILTIN_RX,INPUT);

  #if defined(SERIAL_OUT_ENABLED)
  Serial.begin(115200); /* Begin Serial Communication with 115200 Baud Rate */
  Serial.println("");
  #endif
  // initialize GPIO 5 as an output
  pinMode(gpioD1LedOut, OUTPUT);
  pinMode(gpioD2LedOut, OUTPUT);
  pinMode(gpioD3LedOut, OUTPUT);
  pinMode(gpioMotionIn, INPUT);
}

void loop() {
  cnt++;
  int motion = digitalRead(gpioMotionIn);
  int photo = analogRead(gpioPhotoIn);
  photoAvrg += photo;
  photoAvrg /= 2;
  #if defined(SERIAL_OUT_ENABLED)
  Serial.print(cnt);
  Serial.print(" Motion:");
  Serial.println(motion);
  Serial.print("Photo: ");
  Serial.print(photoAvrg);
  Serial.print(" ");
  Serial.println(photo);
  #endif

  if( ledCnt >= 3 )
  {
    ledCnt = 0;
  }
  if( photoAvrg <= 10 && motion == 1 )
  {
    led[ledCnt] = 1;
  }
  else
  {
    led[ledCnt] = 0;
  }
  if( cnt % 10 == 0 )
  {
    ledCnt++;
  }

  digitalWrite(gpioD1LedOut, led[0]);
  digitalWrite(gpioD2LedOut, led[1]);
  digitalWrite(gpioD3LedOut, led[2]);

  delay(100);
}

