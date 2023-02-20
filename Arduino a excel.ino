double fnc_ultrasonic_distance(int _t, int _e){
	unsigned long dur=0;
	digitalWrite(_t, LOW);
	delayMicroseconds(5);
	digitalWrite(_t, HIGH);
	delayMicroseconds(10);
	digitalWrite(_t, LOW);
	dur = pulseIn(_e, HIGH, 18000);
	if(dur==0)return 999.0;
	return (dur/57);
}
int lectura; //JL
void setup()
{
  	pinMode(2, OUTPUT);
	pinMode(3, INPUT);

	Serial.begin(9600);
Serial.print("LABEL,hora;lectura");
	Serial.flush();
	while(Serial.available()>0)Serial.read();

}


void loop()
{
lectura=(fnc_ultrasonic_distance(2,3));
  	//Serial.println(fnc_ultrasonic_distance(2,3));
Serial.print("DATA,TIME,");
Serial.println(lectura);
delay(1000);
}