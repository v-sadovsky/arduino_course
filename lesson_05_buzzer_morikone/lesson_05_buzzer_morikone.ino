#include "notes.h"

#define BUZ_PIN 5
#define TRACK_LENGTH  38

float track[] = {E_2, Fs_2, Gs_2, A_2, B_2, C_3, D_3, C_3, B_2, C_3, C_3, B_2, C_3,
                 C_3, D_3, E_3, B_2, A_2, B_2, B_2, A_2, B_2, PAUSE, 
                 A_2, G_2, A_2, A_2, G_2, A_2, A_2, B_2, C_3, Gs_2, Fs_2, Gs_2, Gs_2, Fs_2, Gs_2,};
                 
int duration[] = {QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, QUARTER, WHOLE, QUARTER, QUARTER, WHOLE,
                  QUARTER, HALF, HALF, QUARTER, QUARTER, WHOLE, QUARTER, QUARTER, WHOLE, HALF, QUARTER, QUARTER, WHOLE, QUARTER, 
                  QUARTER, WHOLE, QUARTER, HALF, HALF, QUARTER, QUARTER, WHOLE, QUARTER, QUARTER, WHOLE,};

void setup() {
  pinMode(BUZ_PIN, OUTPUT);
  for (int i = 0; i < TRACK_LENGTH; i++) {
    int noteDuration = BASE_DURATION / duration[i];
    tone(BUZ_PIN, track[i], noteDuration);
    int pause = noteDuration * 1.05;
    delay(pause);
  }
}

void loop() {

}
