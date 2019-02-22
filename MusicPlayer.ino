#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define FLAG        3
#define FLAG2       4
#define FLAG3       5
#define SPEAKER     2
#define BTN_USA     12
#define BTN_CANADA  11
#define BTN_UK      10
#define BTN_USSR    8
#define BTN_FRANCE  7
#define BTN_SONG    6

#include <Servo.h>
Servo canadaFlag;
Servo usaFlag;
Servo ussrFlag;

int NOTE_DUR = 137; // default duration of a 16th note -  137

bool usa = false, canada = false, uk = false, ussr = false, france = false, song = false;
int numUsa = 0, numCanada = 0, numUk = 0, numUssr = 0, numFrance = 0, numSong = 0;
 
/*
*   PLAY
*
*   plays a note for 3/4 of a duration and break for 1/4 of the duration
*   
*   note: the frequency in Hz of the note
*   dur: the duration of the total play and break in units of 16th notes 
*/
void play(unsigned int note, unsigned int dur) {
    tone(SPEAKER, note);
    delay(dur * NOTE_DUR);
    noTone(SPEAKER);
    delay(dur * NOTE_DUR / 3);
}

void setup() {
    pinMode(SPEAKER, OUTPUT);
    pinMode(BTN_USA, INPUT);
    pinMode(BTN_CANADA, INPUT);
    pinMode(BTN_UK, INPUT);
    pinMode(BTN_USSR, INPUT);
    pinMode(BTN_FRANCE, INPUT);

    canadaFlag.attach(FLAG);
    usaFlag.attach(FLAG2);
    ussrFlag.attach(FLAG3);

    Serial.begin(9600);
}

void loop() {
    /*
    musicDespacito();
    musicLucidDreams();
    musicMoBamba();
    musicUSA();
    musicCanada();
    musicUK();
    musicUSSR();
    */
    ussrFlag.write(90);
    canadaFlag.write(90);
    usaFlag.write(90);
    
    usa = digitalRead(BTN_USA);
    canada = digitalRead(BTN_CANADA);
    uk = digitalRead(BTN_UK);
    ussr = digitalRead(BTN_USSR);
    france = digitalRead(BTN_FRANCE);
    song = digitalRead(BTN_SONG);

    //Serial.print("USA: ");
    //Serial.println(usa);

    if(millis() < 2000)
      return;
    
    if (numUsa >= 25) {
      usaFlag.write(45);
      musicUSA();
      usaFlag.write(90);
      numUsa = 0;
    }   
    else if(numUsa > 0 && usa == false)
      numUsa = 0;
    else if(usa)
      numUsa++;

    //Serial.println(numUsa);

    if (numCanada >= 25) {
      canadaFlag.write(45);
      musicCanada();
      canadaFlag.write(90);
      numCanada = 0;
    }
    else if(numCanada > 0 && canada == false)
      numCanada = 0;
    else if(canada)
      numCanada++;

    Serial.println(numCanada);

    if (numUk >= 25) {
      musicUK();
      numUk = 0;
    }
    else if(numUk > 0 && uk == false)
      numUk = 0;
    else if(uk)
      numUk++;

    if (numUssr >= 25) {
      ussrFlag.write(45);
      musicUSSR();
      ussrFlag.write(90);
      numUssr = 0;
    }
    else if(numUssr > 0 && ussr == false)
      numUssr = 0; 
    else if(ussr)
      numUssr++;

    if(numFrance >= 25) {
      musicDespacito();
      numFrance = 0;
    }
    else if(numFrance > 0 && france == false)
      numFrance = 0;
    else if(france)
      numFrance++;

    if (numSong >= 25) {
      
      musicILoveIt();
      delay(1000);
      musicMoBamba();
      delay(1000);
      musicLucidDreams();
      delay(1000);
      musicFrance();
      delay(1000);
      musicCountryRoads();
      numSong = 0;
      
    }   
    else if(numSong > 0 && song == false)
      numSong = 0;
    else if(song)
      numSong++;

}


void musicUSA() {
    NOTE_DUR = 137;
    // START
    for(int i=0; i<2; i++) {    // repeat twice
        play(NOTE_G4, 3);
        play(NOTE_E4, 1);
        play(NOTE_C4, 4);   // m1,9
        play(NOTE_E4, 4);
        play(NOTE_G4, 4);
        play(NOTE_C5, 8);   // m2,10
        play(NOTE_E5, 3);
        play(NOTE_D5, 1);
        play(NOTE_C5, 4);   // m3,11
        play(NOTE_E4, 4);
        play(NOTE_FS4, 4);
        play(NOTE_G4, 8);   // m4,12
        play(NOTE_G4, 2);
        play(NOTE_G4, 2);
        play(NOTE_E5, 6);   // m5,13
        play(NOTE_D5, 2);
        play(NOTE_C5, 4);
        play(NOTE_B4, 8);   // m6,14
        play(NOTE_A4, 3);
        play(NOTE_B4, 1);
        play(NOTE_C5, 4);   // m7,15
        play(NOTE_C5, 4);
        play(NOTE_G4, 4);
        play(NOTE_E4, 4);   // m8,16
        play(NOTE_C4, 4);
    }
    play(NOTE_E5, 2);
    play(NOTE_E5, 2);
    play(NOTE_E5, 4);   // m17
    play(NOTE_F5, 4);
    play(NOTE_G5, 4);
    play(NOTE_G5, 8);   // m18
    play(NOTE_F5, 2);
    play(NOTE_E5, 2);
    play(NOTE_D5, 4);   // m19
    play(NOTE_E5, 4);
    play(NOTE_F5, 4);
    play(NOTE_F5, 8);   // m20
    play(NOTE_F5, 4);
    play(NOTE_E5, 6);   // m21
    play(NOTE_D5, 2);
    play(NOTE_C5, 4);
    play(NOTE_B4, 8);   // m22
    play(NOTE_A4, 3);
    play(NOTE_B4, 1);
    play(NOTE_C5, 4);   // m23
    play(NOTE_E4, 4);
    play(NOTE_FS4, 4);
    play(NOTE_G4, 8);   // m24
    play(NOTE_G4, 4);
    play(NOTE_C5, 4);   // m25
    play(NOTE_C5, 4);
    play(NOTE_C5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 4);   // m26
    play(NOTE_A4, 4);
    play(NOTE_A4, 4);
    play(NOTE_D5, 4);   // m27
    play(NOTE_F5, 2);
    play(NOTE_E5, 2);
    play(NOTE_D5, 2);
    play(NOTE_C5, 2);
    play(NOTE_C5, 4);   // m28
    play(NOTE_B4, 4);
    play(NOTE_G4, 2);
    play(NOTE_G4, 2);
    play(NOTE_C5, 6);   // m29
    play(NOTE_D5, 2);
    play(NOTE_E5, 2);
    play(NOTE_F5, 2);
    play(NOTE_G5, 8);   // m30
    play(NOTE_C5, 2);
    play(NOTE_D5, 2);
    play(NOTE_E5, 6);   // m31
    play(NOTE_F5, 2);
    play(NOTE_D5, 4);
    play(NOTE_C5, 12);  // m32 END
}

void musicCanada() {
    NOTE_DUR = 137;
    // START
    play(NOTE_A4, 8);   // m1
    play(NOTE_C5, 6);
    play(NOTE_C5, 2);
    play(NOTE_F4, 12);  // m2
    play(NOTE_G4, 4);
    play(NOTE_A4, 4);   // m3
    play(NOTE_AS4, 4);
    play(NOTE_C5, 4);
    play(NOTE_D5, 4);
    play(NOTE_G4, 16);  // m4
    play(NOTE_A4, 8);   // m5
    play(NOTE_B4, 6);
    play(NOTE_B4, 2);
    play(NOTE_C5, 12);  // m6
    play(NOTE_D5, 4);
    play(NOTE_E5, 4);   // m7
    play(NOTE_E5, 4);
    play(NOTE_D5, 4);
    play(NOTE_D5, 4);
    play(NOTE_C5, 12);  // m8
    for(int i=0; i<2; i++) {    // repeat twice
        play(NOTE_G4, 3);
        play(NOTE_A4, 1);
        play(NOTE_AS4, 6);  // m9,13
        play(NOTE_A4, 2);
        play(NOTE_G4, 4);
        play(NOTE_A4, 3);
        play(NOTE_AS4, 1);
        play(NOTE_C5, 6);   // m10,14
        play(NOTE_AS4, 2);
        play(NOTE_A4, 4);
        if(i == 0) {    // only play first time
            play(NOTE_AS4, 3);
            play(NOTE_C5, 1);
            play(NOTE_D5, 4);   // m11
            play(NOTE_C5, 4);
            play(NOTE_AS4, 4);
            play(NOTE_A4, 4);
            play(NOTE_G4, 12);  // m12
        }
    }
    play(NOTE_A4, 4);
    play(NOTE_G4, 4);   // m15
    play(NOTE_C5, 4);
    play(NOTE_C5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 2);
    play(NOTE_C5, 16);  // m16
    play(NOTE_A4, 8);   // m17
    play(NOTE_C5, 6);
    play(NOTE_C5, 2);
    play(NOTE_F4, 16);  // m18
    play(NOTE_AS4, 8);  // m19
    play(NOTE_D5, 6);
    play(NOTE_D5, 2);
    play(NOTE_G4, 16);  // m20
    play(NOTE_C5, 8);   // m21
    play(NOTE_CS5, 6);
    play(NOTE_CS5, 2);
    play(NOTE_D5, 4);   // m22
    play(NOTE_AS4, 4);
    play(NOTE_A4, 4);
    play(NOTE_G4, 4);
    play(NOTE_F4, 8);   // m23
    play(NOTE_G4, 8);
    play(NOTE_A4, 16);  // m24
    play(NOTE_C5, 8);   // m25
    play(NOTE_F5, 6);
    play(NOTE_F5, 2);
    play(NOTE_D5, 4);   // m26
    play(NOTE_AS4, 4);
    play(NOTE_A4, 4);
    play(NOTE_G4, 4);
    play(NOTE_C5, 8);   // m27
    play(NOTE_E4, 8);
    play(NOTE_F4, 16);  // m28 END
}

void musicUK() {
    // START
    usaFlag.write(45);
    delay(1000);
    ussrFlag.write(45);
    delay(1000);
    canadaFlag.write(45);
    delay(3000);
    usaFlag.write(90);
    ussrFlag.write(90);
    canadaFlag.write(90);
    play(NOTE_G4, 4);   // m1
    play(NOTE_G4, 4);
    play(NOTE_A4, 4);
    play(NOTE_FS4, 6);  // m2
    play(NOTE_G4, 2);
    play(NOTE_A4, 4);
    play(NOTE_B4, 4);   // m3
    play(NOTE_B4, 4);
    play(NOTE_C5, 4);
    play(NOTE_B4, 6);   // m4
    play(NOTE_A4, 2);
    play(NOTE_G4, 4);
    play(NOTE_A4, 4);   // m5
    play(NOTE_G4, 4);
    play(NOTE_FS4, 4);
    play(NOTE_G4, 12);  // m6
    play(NOTE_D5, 4);   // m7
    play(NOTE_D5, 4);
    play(NOTE_D5, 4);
    play(NOTE_D5, 6);   // m8
    play(NOTE_C5, 2);
    play(NOTE_B4, 4);
    play(NOTE_C5, 4);   // m9
    play(NOTE_C5, 4);
    play(NOTE_C5, 4);
    play(NOTE_C5, 6);   // m10
    play(NOTE_B4, 2);
    play(NOTE_A4, 4);
    play(NOTE_B4, 4);   // m11
    play(NOTE_C5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_G4, 2);
    play(NOTE_B4, 6);   // m12
    play(NOTE_C5, 2);
    play(NOTE_D5, 4);
    play(NOTE_E5, 2);   // m13
    play(NOTE_C5, 2);
    play(NOTE_B4, 4);
    play(NOTE_A4, 4);
    play(NOTE_G4, 12);  // m14 END
}

void musicUSSR(){
  bool repeat = false;
  play(NOTE_C5, 12); //m1
  delay(NOTE_DUR*2);
  play(NOTE_G4, 2);
  for(int i = 0; i < 2; i++) { //this repeats and has second ending
    play(NOTE_C5, 4); //m2
    play(NOTE_G4, 3);
    play(NOTE_A4, 1);
    play(NOTE_B4, 4);
    play(NOTE_E4, 2);
    play(NOTE_E4, 2); 
    play(NOTE_A4, 4); //m3
    play(NOTE_G4, 3);
    play(NOTE_F4, 1);
    play(NOTE_G4, 4);
    play(NOTE_C4, 2);
    play(NOTE_C4, 2);
    play(NOTE_D4, 4); //m4
    play(NOTE_D4, 3);
    play(NOTE_E4, 1);
    play(NOTE_F4, 4);
    play(NOTE_F4, 3);
    play(NOTE_G4, 1);
    play(NOTE_A4, 4); //m5
    play(NOTE_B4, 2);
    play(NOTE_C5, 2);
    play(NOTE_D5, 6);
    play(NOTE_G4, 2);
    play(NOTE_E5, 4); //m6
    play(NOTE_D5, 3);
    play(NOTE_C5, 1);
    play(NOTE_D5, 4);
    play(NOTE_B4, 2);
    play(NOTE_G4, 2);
    play(NOTE_C5, 4); //m7
    play(NOTE_B4, 3);
    play(NOTE_A4, 1);
    play(NOTE_B4, 4);
    play(NOTE_E4, 2);
    play(NOTE_E4, 2);
    play(NOTE_A4, 4); //m8
    play(NOTE_G4, 3);
    play(NOTE_F4, 1);
    play(NOTE_G4, 4);
    play(NOTE_C4, 3);
    play(NOTE_C4, 1);
    play(NOTE_C5, 4); //m9
    play(NOTE_B4, 3);
    play(NOTE_A4, 1);
    play(NOTE_G4, 2);
    play(NOTE_B4, 2);
    play(NOTE_C5, 2);
    play(NOTE_D5, 2);
    play(NOTE_E5, 8); //m9 
    play(NOTE_D5, 2);
    play(NOTE_C5, 2);
    play(NOTE_B4, 2);
    play(NOTE_C5, 2);
    play(NOTE_D5, 6); //m10
    play(NOTE_G4, 2);
    play(NOTE_G4, 2);
    play(NOTE_B4, 2);
    play(NOTE_C5, 2);
    play(NOTE_D5, 2);
    play(NOTE_C5, 8); //m11
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_G4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 6); //m12
    play(NOTE_E4, 2);
    play(NOTE_E4, 2);
    play(NOTE_G4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 2);
    play(NOTE_C5, 4); //m13
    play(NOTE_A4, 3);
    play(NOTE_B4, 1);
    play(NOTE_C5, 4);
    play(NOTE_A4, 3);
    play(NOTE_B4, 1);
    play(NOTE_C5, 4); //m14
    play(NOTE_A4, 2); 
    play(NOTE_C5, 2);
    play(NOTE_F5, 6);
    delay(2*NOTE_DUR);
    play(NOTE_F5, 8); //m15
    play(NOTE_E5, 2);
    play(NOTE_D5, 2);
    play(NOTE_C5, 2);
    play(NOTE_D5, 2);
    play(NOTE_E5, 6); //m16
    play(NOTE_C5, 2);
    play(NOTE_C5, 8);
    play(NOTE_D5, 8); //m17
    play(NOTE_C5, 2);
    play(NOTE_B4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 2);
    play(NOTE_C5, 6); //m18
    play(NOTE_A4, 2);
    play(NOTE_A4, 8);
    if(repeat == false) { //play first ending 
      play(NOTE_C5, 4); //m19
      play(NOTE_B4, 3);
      play(NOTE_A4, 1);
      play(NOTE_G4, 4);
      play(NOTE_C4, 3);
      play(NOTE_C4, 1);
      play(NOTE_C5, 4); //m20
      play(NOTE_B4, 3);
      play(NOTE_A4, 1);
      play(NOTE_G4, 4);
      play(NOTE_G4, 2);
      play(NOTE_G4, 2);
      repeat = true;
    } else {//play second ending
      play(NOTE_C5, 4); 
      play(NOTE_B4, 3);
      play(NOTE_A4, 1);
      play(NOTE_G4, 4);
      play(NOTE_C4, 3);
      play(NOTE_C4, 1);
      play(NOTE_G4, 8); //next measure
      play(NOTE_A4, 4);
      play(NOTE_B4, 4);
      play(NOTE_C5, 10); //last measure
    }
  }
   
}

void musicFrance() {
    play(NOTE_D4, 1);
    play(NOTE_D4, 3);
    play(NOTE_D4, 1);
    play(NOTE_G4, 4); // m1
    play(NOTE_G4, 4);
    play(NOTE_A4, 4);
    play(NOTE_A4, 4);
    play(NOTE_D5, 6); // m2
    play(NOTE_B4, 2);
    play(NOTE_G4, 3);
    play(NOTE_G4, 1);
    play(NOTE_B4, 3);
    play(NOTE_G4, 1);
    play(NOTE_E4, 4); // m3
    play(NOTE_C5, 8);
    play(NOTE_A4, 3);
    play(NOTE_FS4, 1);
    play(NOTE_G4, 8); // m4
    delay(4 * NOTE_DUR);
    play(NOTE_G4, 3);
    play(NOTE_A4, 1);
    play(NOTE_B4, 4); // m5
    play(NOTE_B4, 4);
    play(NOTE_B4, 4);
    play(NOTE_C5, 3);
    play(NOTE_B4, 1);
    play(NOTE_B4, 4); // m6
    play(NOTE_A4, 4);
    delay(4 * NOTE_DUR);
    play(NOTE_A4, 3);
    play(NOTE_B4, 1);
    play(NOTE_C5, 4); // m7
    play(NOTE_C5, 4);
    play(NOTE_C5, 4);
    play(NOTE_D5, 3);
    play(NOTE_C5, 1);
    play(NOTE_B4, 8); // m8
    delay(4 * NOTE_DUR);
    play(NOTE_D5, 3);
    play(NOTE_D5, 1);
    play(NOTE_D5, 4); // m9
    play(NOTE_B4, 3);
    play(NOTE_G4, 1);
    play(NOTE_D5, 4);
    play(NOTE_B4, 3);
    play(NOTE_G4, 1);
    play(NOTE_D4, 8); // m10
    delay(3 * NOTE_DUR);
    play(NOTE_D4, 1);
    play(NOTE_D4, 3);
    play(NOTE_FS4, 1);
    play(NOTE_A4, 8); // m11
    play(NOTE_C5, 4);
    play(NOTE_A4, 3);
    play(NOTE_FS4, 1);
    play(NOTE_A4, 4); // m12
    play(NOTE_G4, 4);
    play(NOTE_F4, 8);
    play(NOTE_E4, 4); // m13
    play(NOTE_G4, 3);
    play(NOTE_G4, 1);
    play(NOTE_G4, 4);
    play(NOTE_FS4, 3);
    play(NOTE_G4, 1);
    play(NOTE_A4, 12);  // m14
    delay(2 * NOTE_DUR);
    play(NOTE_A4, 2);
    play(NOTE_AS4, 6);  // m15
    play(NOTE_AS4, 2);
    play(NOTE_AS4, 2);
    play(NOTE_AS4, 2);
    play(NOTE_C5, 2);
    play(NOTE_D5, 2);
    play(NOTE_A4, 12);  // m16
    play(NOTE_AS4, 2);
    play(NOTE_A4, 2);
    play(NOTE_G4, 6); // m17
    play(NOTE_G4, 2);
    play(NOTE_G4, 2);
    play(NOTE_AS4, 2);
    play(NOTE_A4, 2);
    play(NOTE_G4, 2);
    play(NOTE_G4, 4); // m18
    play(NOTE_FS4, 4);
    delay(7 * NOTE_DUR);
    play(NOTE_D5, 1);
    play(NOTE_D5, 11);  // m19
    play(NOTE_D5, 1);
    play(NOTE_B4, 3);
    play(NOTE_G4, 1);
    play(NOTE_A4, 12);  // m20
    delay(3 * NOTE_DUR);
    play(NOTE_D5, 1);
    play(NOTE_D5, 11);  // m21
    play(NOTE_D5, 1);
    play(NOTE_B4, 3);
    play(NOTE_G4, 1);
    play(NOTE_A4, 12);  // m22
    play(NOTE_D4, 4);
    play(NOTE_G4, 8); // m23
    delay(4 * NOTE_DUR);
    play(NOTE_A4, 4);
    play(NOTE_B4, 8); // m24
    delay(8 * NOTE_DUR);
    play(NOTE_C5, 8); // m25
    play(NOTE_D5, 4);
    play(NOTE_E5, 4);
    play(NOTE_A4, 12);  // m26
    play(NOTE_E5, 4);
    play(NOTE_D5, 11);  // m27
    play(NOTE_B4, 1);
    play(NOTE_C5, 3);
    play(NOTE_A4, 1);
    play(NOTE_G4, 16);  //28 END   
}

void musicMoBamba() {
  NOTE_DUR = 154;
  for(int j=0; j<2; j++) {
    usaFlag.write(45);
    canadaFlag.write(90);
    ussrFlag.write(90);
    for(int i=0; i<5; i++) {
      play(NOTE_G6, 1);
      play(NOTE_F6, 1);
      play(NOTE_E6, 2);
      if(i == 2 || i == 4) continue;
      play(NOTE_D6, 2);
    }
    usaFlag.write(90);
    canadaFlag.write(45);
    ussrFlag.write(45);
    delay(2 * NOTE_DUR);  
    if(j == 1) break;
    play(NOTE_G6, 1);
    play(NOTE_F6, 1);
    play(NOTE_E6, 1);
    delay(1 * NOTE_DUR);
  }
  for(int i=0; i<2; i++) {
    usaFlag.write(90);
    canadaFlag.write(180);
    ussrFlag.write(90);
    play(NOTE_B2, 2);
    play(NOTE_B2, 1);
    play(NOTE_B2, 1);
    play(NOTE_E3, 12);
    usaFlag.write(180);
    canadaFlag.write(90);
    play(NOTE_E3, 4);
    play(NOTE_F3, 6);
    usaFlag.write(90);
    canadaFlag.write(180);
    ussrFlag.write(180);
    play(NOTE_B2, 6);
  }
  usaFlag.write(90);
  canadaFlag.write(90);
  ussrFlag.write(90);
}

void musicLucidDreams() {
  NOTE_DUR = 67;
  for(int i=0; i<2; i++) {
    play(NOTE_A4, 4);
    play(NOTE_FS3, 2);
    play(NOTE_CS4, 4);
    play(NOTE_A4, 4);
    play(NOTE_E3, 2);
    play(NOTE_GS4, 4);
    play(NOTE_E3, 2);
    play(NOTE_CS4, 4);
    play(NOTE_GS4, 4);
    play(NOTE_D3, 2);
    play(NOTE_FS4, 4);
    play(NOTE_D3, 2);
    play(NOTE_B3, 4);
    play(NOTE_FS4, 4);
    play(NOTE_D3, 2);
    play(NOTE_FS4, 4);
    play(NOTE_B3, 4);
    if(i == 1) break;
    play(NOTE_F4, 8);
  }
  play(NOTE_F4, 6);
  play(NOTE_CS3, 2);
  play(NOTE_D3, 4);
  play(NOTE_B3, 2);
  play(NOTE_FS4, 4);
  play(NOTE_B3, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 6);
  play(NOTE_FS4, 4);
  play(NOTE_B3, 6);
  play(NOTE_A2, 2);
  play(NOTE_B3, 6);
  play(NOTE_E4, 6);
  play(NOTE_A3, 4);
  play(NOTE_CS3, 4);
  play(NOTE_GS3, 2);
  play(NOTE_GS4, 2);
  play(NOTE_F4, 8);
  play(NOTE_FS4, 6);
  play(NOTE_E4, 6);
  play(NOTE_D4, 4);
  play(NOTE_CS4, 6);
  play(NOTE_CS4, 10);
  play(NOTE_CS4, 24);
  delay(8 * NOTE_DUR);
  for(int i=0; i<3; i++) {
    delay(4 * NOTE_DUR);
    play(NOTE_CS5, 4);
    play(NOTE_CS5, 3);
    play(NOTE_A4, 3);
    play(NOTE_A4, 2);
    play(NOTE_E5, 3);
    play(NOTE_D5, 3);
    play(NOTE_CS5, 2);
    if(i == 2) break;
    play(NOTE_CS5, 4);
    play(NOTE_B4, 4);
  }
  play(NOTE_CS5, 3);
  play(NOTE_B4, 3);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 3);
  play(NOTE_CS5, 3);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 3);
  play(NOTE_B4, 3);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 3);
  play(NOTE_CS5, 3);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 4);
  play(NOTE_B4, 4);
  play(NOTE_A4, 8);
  for(int i=0; i<2; i++) {
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4);
    play(NOTE_A4, 2);
    play(NOTE_A4, 4);
  }
  for(int i=0; i<2; i++) {
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4);
  }
  for(int i=0; i<2; i++) {
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
  }
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_B4, 4);
  play(NOTE_A4, 4);
}


void musicDespacito() {
  NOTE_DUR = 58;
  
  usaFlag.write(30);
  delay(1000);
  usaFlag.write(90);
  canadaFlag.write(30);
  delay(1000);
  canadaFlag.write(90);
  ussrFlag.write(30);
  delay(1000);
  ussrFlag.write(150);
  delay(1000);
  canadaFlag.write(150);
  delay(1000);
  usaFlag.write(50);
  delay(1000);
  ussrFlag.write(90);
  canadaFlag.write(90);
  usaFlag.write(90);
 
  play(NOTE_D4, 1);
  play(NOTE_FS4, 1);
  play(NOTE_B4, 1);
  play(NOTE_D5, 1);
  play(NOTE_CS5, 1);
  play(NOTE_B4, 1);
  play(NOTE_AS4, 1);
  play(NOTE_B4, 16); //m2
  delay(NOTE_DUR*6);
  play(NOTE_B4, 6);
  play(NOTE_CS5, 6);
  play(NOTE_D5, 6);
  play(NOTE_E5, 6); //m3
  play(NOTE_FS5, 7);
  play(NOTE_D5, 7);
  play(NOTE_FS5, 8);
  play(NOTE_D5, 8);
  play(NOTE_FS5, 22);
  delay(NOTE_DUR*4);
  ussrFlag.write(0);
  play(NOTE_FS4, 2); //m4
  play(NOTE_D5, 6);
  ussrFlag.write(90);
  usaFlag.write(0);
  play(NOTE_E4, 2);
  play(NOTE_CS5, 6);
  usaFlag.write(90);
  canadaFlag.write(45);
  play(NOTE_D4, 2);
  play(NOTE_B4, 4); //m5
  canadaFlag.write(90);
  play(NOTE_D4, 2);
  play(NOTE_FS4, 4);
  play(NOTE_B4, 2);
  play(NOTE_D4, 4);
  play(NOTE_B4, 4);
  play(NOTE_D4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 2);
  play(NOTE_B4, 4); //m6
  play(NOTE_D4, 2);
  play(NOTE_G4, 4);
  play(NOTE_B4, 2);
  play(NOTE_D4, 4);
  play(NOTE_B4, 4);
  play(NOTE_D4, 2);
  play(NOTE_G4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 4); //m7
  play(NOTE_FS4, 2);
  play(NOTE_A4, 4);
  play(NOTE_D5, 2);
  play(NOTE_FS4, 4);
  play(NOTE_D5, 4);
  play(NOTE_FS4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 2);
  play(NOTE_E5, 12); //m8
  delay(NOTE_DUR*2);
  ussrFlag.write(0);
  play(NOTE_FS4, 2); 
  play(NOTE_D5, 6);
  ussrFlag.write(90);
  usaFlag.write(0);
  play(NOTE_E4, 2);
  play(NOTE_CS5, 6);
  usaFlag.write(90);
  canadaFlag.write(45);
  play(NOTE_D4, 2);
  play(NOTE_B4, 10); //m9
  canadaFlag.write(90);
  play(NOTE_FS4, 2);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 3);
  play(NOTE_E5, 3);
  play(NOTE_D5, 3);
  play(NOTE_CS5, 3);
  play(NOTE_B4, 3);
  play(NOTE_A4, 3);
  play(NOTE_G4, 6); //m10
  play(NOTE_D5, 6);
  play(NOTE_D5, 20);
  play(NOTE_D5, 4); //m11
  play(NOTE_A4, 4);
  play(NOTE_D5, 4); 
  play(NOTE_A4, 4);
  play(NOTE_D5, 4); 
  play(NOTE_A4, 4);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_CS5, 13); //m12
  delay(NOTE_DUR*21);
  play(NOTE_B4, 10); //m13
  play(NOTE_FS4, 2);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 3);
  play(NOTE_E5, 3);
  play(NOTE_D5, 3);
  play(NOTE_CS5, 3);
  play(NOTE_B4, 3);
  play(NOTE_A4, 3);
  play(NOTE_G4, 6); //m14
  play(NOTE_D5, 6);
  play(NOTE_D5, 20);
  play(NOTE_D5, 4); //m15
  play(NOTE_A4, 4);
  play(NOTE_D5, 4); 
  play(NOTE_A4, 4);
  play(NOTE_D5, 4); 
  play(NOTE_A4, 4);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_CS5, 12);//m16
  delay(NOTE_DUR*6);
  ussrFlag.write(0);
  play(NOTE_FS4, 2); 
  play(NOTE_D5, 6);
  ussrFlag.write(90);
  usaFlag.write(0);
  play(NOTE_E4, 2);
  play(NOTE_CS5, 6);
  usaFlag.write(90);
  canadaFlag.write(45);
  play(NOTE_D4, 2);
  play(NOTE_B4, 10); //m17
  canadaFlag.write(90);
  play(NOTE_FS4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4);
  play(NOTE_CS5, 4);
  play(NOTE_B4, 8); //m18
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4);
  play(NOTE_E5, 4);
  play(NOTE_A4, 8); //m19
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 4); //tie into m20
  play(NOTE_CS5, 22);
  delay(NOTE_DUR*4);
  play(NOTE_B4, 8); //m21
  play(NOTE_B4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4);
  play(NOTE_CS5, 4);
  play(NOTE_B4, 8); //m22
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_A4, 10); //m23
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 4); //tie into m24
  play(NOTE_CS5, 14);
  delay(NOTE_DUR*3);
  for(int i = 0; i < 2; i++) {
    canadaFlag.write(45);
    play(NOTE_D5, 9);
    canadaFlag.write(90);
    usaFlag.write(45);
    play(NOTE_CS5, 10);
    usaFlag.write(90);
    ussrFlag.write(45);
    play(NOTE_B4, 4); //m25
    play(NOTE_FS4, 4);
    ussrFlag.write(90);
    play(NOTE_FS4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_FS4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 4);
    play(NOTE_A4, 2);
    play(NOTE_B4, 4);//tie into m26
    play(NOTE_G4, 6);
    play(NOTE_G4, 2);
    play(NOTE_G4, 2);
    play(NOTE_G4, 2);
    play(NOTE_G4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 2);
    play(NOTE_B4, 4);
    play(NOTE_CS5, 2);
    play(NOTE_D5, 4); //tie into m27
    play(NOTE_A4, 6);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_A4, 2);
    play(NOTE_D5, 2);
    play(NOTE_D5, 2);
    play(NOTE_D5, 2);
    play(NOTE_D5, 4);
    play(NOTE_E5, 2);
    play(NOTE_E5, 4); //tie into m28
    play(NOTE_CS5, 6);
    delay(NOTE_DUR*8);
  } 
  play(NOTE_E5, 8);
  play(NOTE_E5, 8);
  canadaFlag.write(70);
  play(NOTE_FS5, 2); //m33
  play(NOTE_E5, 2);
  canadaFlag.write(90);
  ussrFlag.write(70);
  play(NOTE_FS5, 2); 
  play(NOTE_E5, 2);
  ussrFlag.write(90);
  play(NOTE_FS5, 4); 
  play(NOTE_E5, 2); 
  play(NOTE_FS5, 4); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4); //tie into m34
  play(NOTE_D5, 12);
  play(NOTE_D5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4);
  play(NOTE_A5, 2);
  play(NOTE_G5, 4);//tie into m35
  play(NOTE_FS5, 14);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  delay(NOTE_DUR*2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m36
  play(NOTE_E5, 6);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_CS5, 4);
  play(NOTE_D5, 4);
  play(NOTE_FS5, 2); //m37
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4); //tie into m38
  play(NOTE_D5, 12);
  play(NOTE_D5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4);
  play(NOTE_A5, 2);
  play(NOTE_G5, 4); //tie into m39
  play(NOTE_FS5, 14);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  delay(NOTE_DUR*2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m40
  play(NOTE_E5, 14);
  delay(NOTE_DUR*2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2); //m41
  play(NOTE_CS5, 1);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 1);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 1); //m42
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 1);
  play(NOTE_B4, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2); //m43
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2); //m44
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2); //m45
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_E5, 4);
  play(NOTE_D5, 4);
  play(NOTE_D5, 1);
  play(NOTE_D5, 2);
  play(NOTE_D5, 1);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2); //m46
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_E5, 4);
  play(NOTE_D5, 2);
  delay(NOTE_DUR*2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2); //m47
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_A5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_E5, 4);
  play(NOTE_E5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 4); //m48
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 4);
  play(NOTE_B4, 4);
  delay(NOTE_DUR*4);
  play(NOTE_B4, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 4); //m49
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4);
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); //m50
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 4);
  play(NOTE_B4, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_D5, 2);
  play(NOTE_E5, 4); //m51
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_D5, 2);
  play(NOTE_E5, 4);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 4); //m52
  play(NOTE_CS5, 2); 
  play(NOTE_CS5, 4); 
  play(NOTE_CS5, 2); 
  play(NOTE_CS5, 2); 
  play(NOTE_B4, 2); 
  play(NOTE_D5, 4); 
  play(NOTE_B4, 2); 
  play(NOTE_FS4, 2); 
  play(NOTE_D5, 4); 
  play(NOTE_D5, 2); 
  play(NOTE_CS5, 2); 
  play(NOTE_B4, 4); //m53
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4);
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); //m54
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 4);
  play(NOTE_B4, 4); 
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_D5, 2);
  play(NOTE_E5, 4); //m55
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_D5, 2);
  play(NOTE_E5, 4);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 4); //m56
  play(NOTE_CS5, 2);
  play(NOTE_CS5, 4);
  play(NOTE_CS5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_D5, 4);
  play(NOTE_CS5, 4);
  play(NOTE_B4, 4);
  play(NOTE_B4, 20); //tie into m57
  delay(NOTE_DUR*2);
  canadaFlag.write(45);
  play(NOTE_D5, 9);
  canadaFlag.write(90);
  usaFlag.write(45);
  play(NOTE_CS5, 10);
  usaFlag.write(90);
  ussrFlag.write(45);
  play(NOTE_B4, 4); //m58
  play(NOTE_FS4, 4);
  ussrFlag.write(90);
  play(NOTE_FS4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_FS4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 4);
  play(NOTE_A4, 2);
  play(NOTE_B4, 4);//tie into m59
  play(NOTE_G4, 6);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 4);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4); //tie into m60
  play(NOTE_A4, 6);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 4); //tie into m61
  play(NOTE_CS5, 6);
  delay(NOTE_DUR*8);
  play(NOTE_E5, 8);
  play(NOTE_E5, 8);
  play(NOTE_FS5, 2); //m62
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4); 
  play(NOTE_E5, 2); 
  play(NOTE_FS5, 4); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4); //tie into m63
  play(NOTE_D5, 12);
  play(NOTE_D5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4);
  play(NOTE_A5, 2);
  play(NOTE_G5, 4);//tie into m64
  play(NOTE_FS5, 14);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  delay(NOTE_DUR*2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m65
  play(NOTE_E5, 6);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_CS5, 4);
  play(NOTE_D5, 4);
  play(NOTE_FS5, 2); //m66
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4); //tie into m67
  play(NOTE_D5, 12);
  play(NOTE_D5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4);
  play(NOTE_A5, 2);
  play(NOTE_G5, 4); //tie into m68
  play(NOTE_FS5, 14);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  delay(NOTE_DUR*2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m69
  play(NOTE_E5, 14);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_E5, 2);
  play(NOTE_CS5, 4);
  play(NOTE_D5, 4);
  play(NOTE_FS5, 2); //m70
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4); 
  play(NOTE_E5, 2); 
  play(NOTE_FS5, 4); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 2); 
  play(NOTE_E5, 2);
  play(NOTE_FS5, 4);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4); //tie into m71
  play(NOTE_D5, 12);
  play(NOTE_D5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 4);
  play(NOTE_A5, 2);
  play(NOTE_G5, 4);//tie into m72
  play(NOTE_FS5, 14);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  delay(NOTE_DUR*2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m73
  play(NOTE_E5, 14); 
  play(NOTE_D5, 8);
  play(NOTE_CS5, 8);
  play(NOTE_B4, 4); //m74
  play(NOTE_FS4, 4); 
  play(NOTE_FS4, 2); 
  play(NOTE_FS4, 2); 
  play(NOTE_FS4, 2); 
  play(NOTE_FS4, 2); 
  play(NOTE_FS4, 2); 
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 4);
  play(NOTE_A4, 2); 
  play(NOTE_B4, 4); //tie into m75
  play(NOTE_G4, 6);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 2);
  play(NOTE_B4, 4);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 4); //tie into m76
  play(NOTE_A4, 6);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_A4, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 4);
  play(NOTE_E5, 2);
  play(NOTE_E5, 4); //tie into m77
  play(NOTE_CS5, 6);
  delay(NOTE_DUR*12);
  play(NOTE_B4, 4);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 4); //m78
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); 
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); //m79
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 4);
  play(NOTE_B4, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2); //m80
  play(NOTE_FS5, 14);
  delay(NOTE_DUR*2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m81
  play(NOTE_E5, 6);
  delay(NOTE_DUR*12);
  play(NOTE_B4, 4);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); //m82
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); 
  play(NOTE_B4, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 4); //m83
  play(NOTE_G4, 2);
  play(NOTE_G4, 2);
  play(NOTE_D5, 4);
  play(NOTE_D5, 2);
  play(NOTE_D5, 2);
  play(NOTE_B4, 4);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_G5, 2); //m84
  play(NOTE_FS5, 14);
  delay(NOTE_DUR*2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_FS5, 2);
  play(NOTE_A5, 2);
  play(NOTE_G5, 2);
  play(NOTE_FS5, 4); //tie into m85
  play(NOTE_E5, 6);
  delay(NOTE_DUR*8);
  ussrFlag.write(0);
  play(NOTE_D5, 8);
  ussrFlag.write(90);
  usaFlag.write(0);
  play(NOTE_CS5, 9);
  usaFlag.write(90);
  canadaFlag.write(0);
  play(NOTE_CS5, 4); //m86
  canadaFlag.write(180);
  usaFlag.write(180);
  ussrFlag.write(180);
  play(NOTE_B4, 60);
  canadaFlag.write(90);
  usaFlag.write(90);
  ussrFlag.write(90);
  
}

void musicILoveIt() {
  NOTE_DUR = 108;
  for(int i=0; i<4; i++) {
    play(NOTE_DS3, 4);
    if(i == 3) break;
    play(NOTE_D3, 3);
    play(NOTE_G3, 3);
    play(NOTE_G2, 3);
    play(NOTE_G2, 3);
  }
  play(NOTE_D3, 2);
  for(int i=0; i<4; i++) {
    play(NOTE_G4, 2);
    play(NOTE_D5, 2);
    play(NOTE_C5, 2);
    play(NOTE_C5, 2);
    play(NOTE_AS4, 2);
    play(NOTE_AS4, 2);
    delay(4 * NOTE_DUR);
    for(int j=0; j<2; j++) {
      play(NOTE_AS4, 2);
      play(NOTE_A4, 2);
      play(NOTE_AS4, 2);
      delay(2 * NOTE_DUR);
    }
  }
}

void musicCountryRoads() {
  NOTE_DUR = 68;
  
  play(NOTE_C4, 2);
  play(NOTE_CS4, 2);
  play(NOTE_E4, 4);
  play(NOTE_FS4, 6);
  play(NOTE_CS4, 2); //m5
  play(NOTE_A3, 6);
  play(NOTE_E4, 2);
  play(NOTE_E4, 6);
  play(NOTE_FS4, 6); //m6
  play(NOTE_E4, 10);
  delay(NOTE_DUR*8);
  play(NOTE_FS4, 4);
  play(NOTE_E4, 2);
  play(NOTE_FS4, 4); //tie into m7
  play(NOTE_A4, 14);
  delay(NOTE_DUR*8);
  play(NOTE_B4, 2);
  play(NOTE_B4, 6);
  play(NOTE_CS5, 6); //m7
  play(NOTE_B4, 10);
  play(NOTE_FS4, 4); //m8
  play(NOTE_FS4, 4);
  play(NOTE_FS4, 4);
  play(NOTE_E4, 4);
  play(NOTE_FS4, 2);
  play(NOTE_A4, 14);
  delay(NOTE_DUR*8);
  play(NOTE_E4, 2);
  play(NOTE_E4, 6);
  play(NOTE_FS4, 6); //m15
  play(NOTE_E4, 10);
  play(NOTE_FS4, 2);
  play(NOTE_A4, 6);
  play(NOTE_A4, 2);
  play(NOTE_CS5, 6);
  play(NOTE_CS5, 16); //m17
  play(NOTE_B4, 4); //m18
  play(NOTE_B4, 4); 
  play(NOTE_B4, 4); 
  play(NOTE_B4, 4); 
  play(NOTE_CS5, 6); 
  play(NOTE_B4, 10); 
  play(NOTE_FS4, 4); 
  play(NOTE_A4, 4); 
  play(NOTE_A4, 4); 
  play(NOTE_B4, 2); 
  play(NOTE_A4, 10);
  play(NOTE_A4, 4); 
  play(NOTE_B4, 4); 
  play(NOTE_CS5, 24);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 4); 
  play(NOTE_B4, 24);
  play(NOTE_CS5, 4);
  play(NOTE_B4, 4);
  play(NOTE_A4, 24);
  play(NOTE_CS5, 4);
  play(NOTE_E5, 4);
  play(NOTE_FS5, 24);
  play(NOTE_FS5, 6);
  play(NOTE_FS5, 2);
  play(NOTE_E5, 4);
  play(NOTE_CS5, 20);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 4);
  play(NOTE_B4, 4);
  play(NOTE_CS5, 20);
  play(NOTE_CS5, 2);
  play(NOTE_B4, 2);
  play(NOTE_A4, 4);
  play(NOTE_A4, 24);
  play(NOTE_A4, 4);
  play(NOTE_B4, 4);
  play(NOTE_A4, 16);
}
