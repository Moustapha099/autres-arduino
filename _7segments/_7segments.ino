/**
 * Exemple de code pour un unique afficheur 7 segments.
 */

/* Broches des différents segments de l'afficheur */
const byte PIN_SEGMENT_A = 2;
const byte PIN_SEGMENT_B = 3;
const byte PIN_SEGMENT_C = 4;
const byte PIN_SEGMENT_D = 5;
const byte PIN_SEGMENT_E = 6;
const byte PIN_SEGMENT_F = 7;
const byte PIN_SEGMENT_G = 8;
const byte PIN_SEGMENT_DP = 9;

/* Décommenter si utilisation d'un afficheur 7 segments à ANODE commune */
//#define _7SEG_COMMON_ANODE

/* Table de correspondance valeur -> états des segments de l'afficheur */
const byte LUT_ETATS_SEGMENTS[] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111,
  0b01110111,
  0b01111100,
  0b00111001,
  0b01011110,
  0b01111001,
  0b01110001
};


/** Fonction setup() */
void setup() {
  
  /* Toutes les broches en sorties */
  pinMode(PIN_SEGMENT_A, OUTPUT);
  digitalWrite(PIN_SEGMENT_A, LOW);
  pinMode(PIN_SEGMENT_B, OUTPUT);
  digitalWrite(PIN_SEGMENT_B, LOW);
  pinMode(PIN_SEGMENT_C, OUTPUT);
  digitalWrite(PIN_SEGMENT_C, LOW);
  pinMode(PIN_SEGMENT_D, OUTPUT);
  digitalWrite(PIN_SEGMENT_D, LOW);
  pinMode(PIN_SEGMENT_E, OUTPUT);
  digitalWrite(PIN_SEGMENT_E, LOW);
  pinMode(PIN_SEGMENT_F, OUTPUT);
  digitalWrite(PIN_SEGMENT_F, LOW);
  pinMode(PIN_SEGMENT_G, OUTPUT);
  digitalWrite(PIN_SEGMENT_G, LOW);
  pinMode(PIN_SEGMENT_DP, OUTPUT);
  digitalWrite(PIN_SEGMENT_DP, LOW);
}


/** Fonction loop() */
void loop() {
  static byte chiffre = 0;
  static byte etat_dp = 0;

  /* Affiche le chiffre */
  affiche_chiffre_7seg(chiffre, etat_dp);

  /* Incrémente le chiffre de 0 à 15 */
  if (++chiffre == 16) {
    chiffre = 0;
  }

  /* Fait clignoter le point décimal (inverse l'état à chaque fois) */
  etat_dp = !etat_dp;

  /* Délai pour la démo */
  delay(1000);
}

/** Fonction permettant d'afficher un chiffre sur un afficheur 7 segments */
void affiche_chiffre_7seg(byte chiffre, byte dp) {

  /* Simple sécurité */
  if (chiffre > 15)
    return; // Accepte uniquement des valeurs de 0 à 15.

  /* Conversion chiffre -> états des segments */
  byte segments = LUT_ETATS_SEGMENTS[chiffre];

  /* Affichage */
#ifndef _7SEG_COMMON_ANODE
  digitalWrite(PIN_SEGMENT_A, bitRead(segments, 0));
  digitalWrite(PIN_SEGMENT_B, bitRead(segments, 1));
  digitalWrite(PIN_SEGMENT_C, bitRead(segments, 2));
  digitalWrite(PIN_SEGMENT_D, bitRead(segments, 3));
  digitalWrite(PIN_SEGMENT_E, bitRead(segments, 4));
  digitalWrite(PIN_SEGMENT_F, bitRead(segments, 5));
  digitalWrite(PIN_SEGMENT_G, bitRead(segments, 6));
  digitalWrite(PIN_SEGMENT_DP, dp);
#else
  digitalWrite(PIN_SEGMENT_A, !bitRead(segments, 0));
  digitalWrite(PIN_SEGMENT_B, !bitRead(segments, 1));
  digitalWrite(PIN_SEGMENT_C, !bitRead(segments, 2));
  digitalWrite(PIN_SEGMENT_D, !bitRead(segments, 3));
  digitalWrite(PIN_SEGMENT_E, !bitRead(segments, 4));
  digitalWrite(PIN_SEGMENT_F, !bitRead(segments, 5));
  digitalWrite(PIN_SEGMENT_G, !bitRead(segments, 6));
  digitalWrite(PIN_SEGMENT_DP, !dp);
#endif
}
