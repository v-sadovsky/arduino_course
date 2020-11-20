#define BUZ_PIN 5
#define C_1   261.63
#define Cs_1  277.18
#define D_1   293.66
#define Ds_1  311.13
#define E_1   329.63
#define F_1   349.23
#define Fs_1  369.99
#define G_1   392
#define Gs_1  415.30
#define A_1   440
#define As_1  466.16
#define B_1   493.88
#define C_2   523.25

#define OCTAVE  8

float gamma_notes[] = {C_1, D_1, E_1, F_1, G_1, A_1, B_1, C_2};

void setup() {
  pinMode(BUZ_PIN, OUTPUT);
  for (int i = 0; i < OCTAVE; i++) {
    tone(BUZ_PIN, gamma_notes[i]);
    delay(500);
    noTone(BUZ_PIN);
  }

  delay(1000);

  for (int i = OCTAVE-1; i >= 0; i--) {
    tone(BUZ_PIN, gamma_notes[i]);
    delay(500);
    noTone(BUZ_PIN);
  }
}

void loop() {

}
