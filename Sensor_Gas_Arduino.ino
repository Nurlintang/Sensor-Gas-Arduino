//c++ code

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //Setting LCD RS E D4 D5 D6 D7

const int merah1 = 6; //merah1 adalah LED 1 di pin 6
const int hijau2 = 5; //hijau2 adalah LED 2 di pin 5
const int biru3 = 4; //biru 3 adalah LED 3 di pin 4
const int piezo = 7; //Piezo di pin 7
const int sensor = A0; //Sensor di pin A0
float out_sensor;
float hslsensor;


void setup() { //Inisialisasi program
  pinMode(merah1, OUTPUT); //merah1 sebagai output
  pinMode (hijau2, OUTPUT); //hijau2 sebagai output
  pinMode (biru3, OUTPUT); //biru3 sebagai output
  pinMode (piezo, OUTPUT); //piezo sebagai output
  pinMode (sensor, INPUT); //sensor sebagai input  
  Serial.begin(9600); //kecepatan band rate 9600
  
  lcd.begin(16, 2); //jenis LCD 16x2
  lcd.print("PRAKTIKUM IoT"); //Tertulis keterangan pada LCD
  delay (1500); //Berhenti selama  1500 milidetik
  lcd.clear(); //Tulisan di LCD terhapus
}

void loop() { //Menjalankan program
 out_sensor = analogRead(sensor);
 hslsensor = ((out_sensor * 0.004883*1024)/4)*9.47265625;
  
//Jika hslsensor kurang dari 1200 maka program akan dieksekusi
  if(hslsensor < 1200){
  {
    digitalWrite(merah1, LOW); //Semua LED mati
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
  }
   lcd.setCursor(0,0);
   lcd.print ("Sensor Mati  "); //Tertulis keterangan pada LCD
   lcd.setCursor(0,1);
   lcd.print ("         ");
   lcd.setCursor(8,1);
   lcd.print ("   ");
   noTone(piezo); //Piezo mati
  }
  
/*Jika hslsensor lebih dari sama dengan 1200 
  dan kurang dari 1700 maka program akan dieksekusi*/
  else if(hslsensor >= 1200 && hslsensor < 1700){
  {{
    digitalWrite(merah1, HIGH); //Semua LED menyala
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
  }
   delay(900);} //Berhenti selama 900 milidetik
  {{
    digitalWrite(merah1, LOW); //Semua LED mati
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
  }
   delay(900);} 
    
   lcd.setCursor(0,0);
   lcd.print ("Keadaan Aman "); //Tertulis keterangan pada LCD
   lcd.setCursor(0,1);
   lcd.print (hslsensor);
   lcd.setCursor(8,1);
   lcd.print ("PPM");
   noTone(piezo); //Piezo mati
  }
  
/*Jika hslsensor lebih dari sama dengan 1700 
  dan kurang dari 2400 maka program akan dieksekusi*/
  else if(hslsensor >= 1700 && hslsensor < 2400){
  {{
    digitalWrite(merah1, HIGH); //Semua LED menyala
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
    tone(piezo, 400); //Piezo menyala
  }
   delay(600);} //Berhenti selama 600 milidetik
  {{
    digitalWrite(merah1, LOW); //Semua LED mati
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
    noTone(piezo); //Piezo berhenti
  }
   delay(600);}
    
   lcd.setCursor(0,0);
   lcd.print ("Gas Meningkat"); //Tertulis keterangan pada LCD
   lcd.setCursor(0,1);
   lcd.print (hslsensor);
   lcd.setCursor(8,1);
   lcd.print ("PPM");
  }
  
/*Jika hslsensor lebih dari sama dengan 2400 
  dan kurang dari 3700 maka program akan dieksekusi*/
  else if(hslsensor >= 2400 && hslsensor < 3700){
  {{
    digitalWrite(merah1, HIGH); //Semua LED menyala
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
  }
   delay(400);} //Berhenti selama 400 milidetik
  {{
    digitalWrite(merah1, LOW); //Semua LED mati
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
  }
   delay(400);}
    
    lcd.setCursor(0,0);
    lcd.print ("WASPADA!!!   "); //Tertulis keterangan pada LCD
    lcd.setCursor(0,1);
    lcd.print (hslsensor);
    lcd.setCursor(8,1);
    lcd.print ("PPM");
    tone(piezo, 400); //Piezo menyala
  }
 
//Jika hslsensor lebih dari 3700 maka program akan dieksekusi
  else if(hslsensor > 3700){
  {{
    digitalWrite(merah1, HIGH); //Semua LED menyala
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
    tone(piezo, 400); //Piezo menyala
  }
   delay(200);} //Berhenti selama 200 milidetik
  {{
    digitalWrite(merah1, LOW); //Semua LED mati
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
    tone(piezo, 300); //Piezo menyala
  }
   delay(200);}
    
    lcd.setCursor(0,0);
    lcd.print ("BERBAHAYA!!!  "); //Tertulis keterangan pada LCD
    lcd.setCursor(0,1);
    lcd.print (hslsensor);
    lcd.setCursor(8,1);
    lcd.print ("PPM");
  }
}