#define sensorR 3
#define sensorL 2
#define speedR 4
#define speedL 5 
byte IN[]={6,7,8,9};
byte moving[4][4]={{1,0,1,0}, //forward
{0,0,1,0}, //Left
{1,0,0,0}, //Right
{0,0,0,0}}; //Stop
void setup()
{
for (int i=6;i<=11;i++){
pinMode(i,OUTPUT);}
pinMode(sensorR,INPUT);
pinMode(sensorL,INPUT);
}

void loop()
{
if (digitalRead(sensorR) && digitalRead(sensorL)){
for (int i=0;i<=3;i++){digitalWrite(IN[i],moving[0][i]);}}
else if (!digitalRead(sensorL) && digitalRead(sensorR)){
for (int i=0;i<=3;i++){digitalWrite(IN[i],moving[1][i]);}}
else if (digitalRead(sensorR) && !digitalRead(sensorR)){
for (int i=0;i<=3;i++){digitalWrite(IN[i],moving[2][i]);}}
while (!digitalRead(sensorL) && !digitalRead(sensorR)){
for (int i=0;i<=3;i++){digitalWrite(IN[i],moving[3][i]);}}
analogWrite(speedL,80* digitalRead(sensorR));
analogWrite(speedR,80*digitalRead(sensorL));
}