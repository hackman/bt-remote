#include "FastLED.h"  // Include FastLED Library
#define NUM_LEDS 256 //  The number of LEDS on matrix
#define DATA_PIN 3  //  Data-In of matrix
#define BRIGHTNESS 64
CRGB leds[NUM_LEDS];
char state;
int t=0;


void setup() {


  pinMode(DATA_PIN, OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(38400); 

}

void loop() {

  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read();
  }
  if (state == 'L') { // X-Axis Left
    LeftArrowBlink();
  }
  if (state == 'R') { // X-Axis Right
    RightArrowBlink();
  }
  if (state == 'U') { // Y-Axis Up
    ExclamationMarkBlink();
  }
  if (state == 'D') { // Y-Axis Down
    RedSquareBlink();
  }
  if (state == 'N') { // Clear / Reset
    Clear();
  }
}

void light_leds(int start, int end) {
  for (int led=start; led<=end; led++) {
	leds [ led ] = CRGB (0,255,0);
  }
}

void LeftArrowBlink() { // Function that is called when Vx is <= 100 and shows a Left Blinking Arrow on the matrix

  while (state == 'L') {
  FastLED.clear();
  light_leds(6,24);
  light_leds(40,54);
  light_leds(72,88);
  light_leds(102,122);
  light_leds(132,144);
  light_leds(150,156);
  light_leds(162,168);
  light_leds(184,190);
  light_leds(192,198);
  light_leds(218,222);
  light_leds(226,228);
  light_leds(252,252);
   FastLED.show();
   delay(1000);
   FastLED.clear();
  light_leds(0,63);
  light_leds(76,83);
  light_leds(108,115);
  light_leds(119,136);
  light_leds(140,147);
  light_leds(151,168);
  light_leds(172,179);
  light_leds(183,186);
  light_leds(197,200);
  light_leds(204,211);
  light_leds(215,218);
  light_leds(229,232);
  light_leds(236,243);
  light_leds(247,250);
   FastLED.show();
   delay(1000);
   FastLED.clear();
  for (t=0;t<3;t=t+1){
	FastLED.clear();
	light_leds(119,136);
	light_leds(151,168);
	light_leds(183,186);
	light_leds(197,200);
	light_leds(215,218);
	light_leds(229,232);
	light_leds(247,250);
	FastLED.show();
	delay(300);
	FastLED.clear();
	light_leds(0,63);
	light_leds(76,83);
	light_leds(108,115);
	light_leds(140,147);
	light_leds(172,179);
	light_leds(204,211);
	light_leds(236,243);
	FastLED.show();
	delay(300);
	FastLED.clear();
   }
   t=0;
  Serial.write('A');
  } 
}


void RightArrowBlink()  {// Function that is called when Vx is >= 1000 and shows a Right Blinking Arrow on the matrix

  while (state == 'R') {
  FastLED.clear();
	light_leds(12,12);
	light_leds(18,20);
	light_leds(42,54);
	light_leds(72,78);
	light_leds(82,88);
	light_leds(96,96);
	light_leds(102,108);
	light_leds(116,122);
	light_leds(126,130);
	light_leds(132,138);
	light_leds(150,168);
	light_leds(184,198);
	light_leds(216,232);
	light_leds(246,255);
   FastLED.show();
   delay(1000);
   FastLED.clear();
	light_leds(0,3);
	light_leds(7,10);
	light_leds(21,24);
	light_leds(28,35);
	light_leds(39,42);
	light_leds(53,56);
	light_leds(60,67);
	light_leds(71,74);
	light_leds(80,88);
	light_leds(92,99);
	light_leds(103,143);
	light_leds(156,163);
	light_leds(188,255);
   FastLED.show();
   delay(1000);
   FastLED.clear();
  for (t=0;t<3;t=t+1){
   FastLED.clear();
	light_leds(0,3);
	light_leds(28,35);
	light_leds(60,67);
	light_leds(92,99);
	light_leds(124,131);
	light_leds(156,163);
	light_leds(188,255);
   FastLED.show();
   delay(300);
   FastLED.clear();
	light_leds(0,3);
	light_leds(28,35);
	light_leds(60,67);
	light_leds(92,99);
	light_leds(124,131);
	light_leds(156,163);
	light_leds(188,255);
   FastLED.show();
   delay(300);
   FastLED.clear();
   }
   t=0;
  Serial.write('D');
  }
}


void ExclamationMarkBlink()  { 
  
  while (state == 'U') {

  for (t=0;t<3;t=t+1){
  FastLED.clear();
leds [  1 ] = CRGB (255,0,0);
leds [  2 ] = CRGB (255,0,0);
leds [  3 ] = CRGB (255,0,0);
leds [  3 ] = CRGB (255,0,0);
leds [  4 ] = CRGB (255,0,0);
leds [  26  ] = CRGB (255,0,0);
leds [  27  ] = CRGB (255,0,0);
leds [  28  ] = CRGB (255,0,0);
leds [  28  ] = CRGB (255,0,0);
leds [  29  ] = CRGB (255,0,0);
leds [  30  ] = CRGB (255,0,0);
leds [  31  ] = CRGB (255,0,0);
leds [  32  ] = CRGB (255,0,0);
leds [  33  ] = CRGB (255,0,0);
leds [  34  ] = CRGB (255,0,0);
leds [  35  ] = CRGB (255,0,0);
leds [  35  ] = CRGB (255,0,0);
leds [  36  ] = CRGB (255,0,0);
leds [  37  ] = CRGB (255,0,0);
leds [  57  ] = CRGB (255,0,0);
leds [  58  ] = CRGB (255,0,0);
leds [  59  ] = CRGB (255,0,0);
leds [  60  ] = CRGB (255,0,0);
leds [  60  ] = CRGB (255,0,0);
leds [  61  ] = CRGB (255,0,0);
leds [  62  ] = CRGB (255,0,0);
leds [  63  ] = CRGB (255,0,0);
leds [  64  ] = CRGB (255,0,0);
leds [  65  ] = CRGB (255,0,0);
leds [  66  ] = CRGB (255,0,0);
leds [  67  ] = CRGB (255,0,0);
leds [  67  ] = CRGB (255,0,0);
leds [  68  ] = CRGB (255,0,0);
leds [  69  ] = CRGB (255,0,0);
leds [  70  ] = CRGB (255,0,0);
leds [  71  ] = CRGB (255,0,0);
leds [  87  ] = CRGB (255,0,0);
leds [  88  ] = CRGB (255,0,0);
leds [  89  ] = CRGB (255,0,0);
leds [  90  ] = CRGB (255,0,0);
leds [  91  ] = CRGB (255,0,0);
leds [  92  ] = CRGB (255,0,0);
leds [  92  ] = CRGB (255,0,0);
leds [  93  ] = CRGB (255,0,0);
leds [  94  ] = CRGB (255,0,0);
leds [  99  ] = CRGB (255,0,0);
leds [  99  ] = CRGB (255,0,0);
leds [  100 ] = CRGB (255,0,0);
leds [  101 ] = CRGB (255,0,0);
leds [  102 ] = CRGB (255,0,0);
leds [  103 ] = CRGB (255,0,0);
leds [  104 ] = CRGB (255,0,0);
leds [  118 ] = CRGB (255,0,0);
leds [  119 ] = CRGB (255,0,0);
leds [  120 ] = CRGB (255,0,0);
leds [  121 ] = CRGB (255,0,0);
leds [  122 ] = CRGB (255,0,0);
leds [  123 ] = CRGB (255,0,0);
leds [  133 ] = CRGB (255,0,0);
leds [  134 ] = CRGB (255,0,0);
leds [  135 ] = CRGB (255,0,0);
leds [  136 ] = CRGB (255,0,0);
leds [  137 ] = CRGB (255,0,0);
leds [  138 ] = CRGB (255,0,0);
leds [  149 ] = CRGB (255,0,0);
leds [  150 ] = CRGB (255,0,0);
leds [  151 ] = CRGB (255,0,0);
leds [  152 ] = CRGB (255,0,0);
leds [  168 ] = CRGB (255,0,0);
leds [  169 ] = CRGB (255,0,0);
leds [  170 ] = CRGB (255,0,0);
leds [  171 ] = CRGB (255,0,0);
leds [  181 ] = CRGB (255,0,0);
leds [  205 ] = CRGB (255,0,0);
leds [  206 ] = CRGB (255,0,0);
leds [  208 ] = CRGB (255,0,0);
leds [  209 ] = CRGB (255,0,0);
leds [  210 ] = CRGB (255,0,0);
leds [  211 ] = CRGB (255,0,0);
leds [  236 ] = CRGB (255,0,0);
leds [  237 ] = CRGB (255,0,0);
leds [  238 ] = CRGB (255,0,0);
leds [  239 ] = CRGB (255,0,0);
leds [  241 ] = CRGB (255,0,0);
leds [  242 ] = CRGB (255,0,0);
   FastLED.show();
   delay(300);
   FastLED.clear();
   }
  t=0;
  for (t=0;t<3;t=t+1){
   FastLED.clear();
leds [  5 ] = CRGB (255,0,0);
leds [  6 ] = CRGB (255,0,0);
leds [  7 ] = CRGB (255,0,0);
leds [  8 ] = CRGB (255,0,0);
leds [  23  ] = CRGB (255,0,0);
leds [  24  ] = CRGB (255,0,0);
leds [  25  ] = CRGB (255,0,0);
leds [  26  ] = CRGB (255,0,0);
leds [  37  ] = CRGB (255,0,0);
leds [  38  ] = CRGB (255,0,0);
leds [  39  ] = CRGB (255,0,0);
leds [  40  ] = CRGB (255,0,0);
leds [  55  ] = CRGB (255,0,0);
leds [  56  ] = CRGB (255,0,0);
leds [  57  ] = CRGB (255,0,0);
leds [  58  ] = CRGB (255,0,0);
leds [  69  ] = CRGB (255,0,0);
leds [  70  ] = CRGB (255,0,0);
leds [  71  ] = CRGB (255,0,0);
leds [  72  ] = CRGB (255,0,0);
leds [  87  ] = CRGB (255,0,0);
leds [  88  ] = CRGB (255,0,0);
leds [  89  ] = CRGB (255,0,0);
leds [  90  ] = CRGB (255,0,0);
leds [  91  ] = CRGB (255,0,0);
leds [  92  ] = CRGB (255,0,0);
leds [  93  ] = CRGB (255,0,0);
leds [  94  ] = CRGB (255,0,0);
leds [  95  ] = CRGB (255,0,0);
leds [  96  ] = CRGB (255,0,0);
leds [  97  ] = CRGB (255,0,0);
leds [  98  ] = CRGB (255,0,0);
leds [  99  ] = CRGB (255,0,0);
leds [  100 ] = CRGB (255,0,0);
leds [  101 ] = CRGB (255,0,0);
leds [  102 ] = CRGB (255,0,0);
leds [  103 ] = CRGB (255,0,0);
leds [  104 ] = CRGB (255,0,0);
leds [  119 ] = CRGB (255,0,0);
leds [  120 ] = CRGB (255,0,0);
leds [  121 ] = CRGB (255,0,0);
leds [  122 ] = CRGB (255,0,0);
leds [  123 ] = CRGB (255,0,0);
leds [  124 ] = CRGB (255,0,0);
leds [  125 ] = CRGB (255,0,0);
leds [  126 ] = CRGB (255,0,0);
leds [  127 ] = CRGB (255,0,0);
leds [  128 ] = CRGB (255,0,0);
leds [  129 ] = CRGB (255,0,0);
leds [  130 ] = CRGB (255,0,0);
leds [  131 ] = CRGB (255,0,0);
leds [  132 ] = CRGB (255,0,0);
leds [  133 ] = CRGB (255,0,0);
leds [  134 ] = CRGB (255,0,0);
leds [  135 ] = CRGB (255,0,0);
leds [  136 ] = CRGB (255,0,0);
   FastLED.show();
   delay(300);
   FastLED.clear();
leds [  12  ] = CRGB (0,255,0);
leds [  13  ] = CRGB (0,255,0);
leds [  14  ] = CRGB (0,255,0);
leds [  15  ] = CRGB (0,255,0);
leds [  16  ] = CRGB (0,255,0);
leds [  17  ] = CRGB (0,255,0);
leds [  18  ] = CRGB (0,255,0);
leds [  19  ] = CRGB (0,255,0);
leds [  44  ] = CRGB (0,255,0);
leds [  45  ] = CRGB (0,255,0);
leds [  46  ] = CRGB (0,255,0);
leds [  47  ] = CRGB (0,255,0);
leds [  48  ] = CRGB (0,255,0);
leds [  49  ] = CRGB (0,255,0);
leds [  50  ] = CRGB (0,255,0);
leds [  51  ] = CRGB (0,255,0);
leds [  76  ] = CRGB (0,255,0);
leds [  77  ] = CRGB (0,255,0);
leds [  78  ] = CRGB (0,255,0);
leds [  79  ] = CRGB (0,255,0);
leds [  80  ] = CRGB (0,255,0);
leds [  81  ] = CRGB (0,255,0);
leds [  82  ] = CRGB (0,255,0);
leds [  83  ] = CRGB (0,255,0);
leds [  108 ] = CRGB (0,255,0);
leds [  109 ] = CRGB (0,255,0);
leds [  110 ] = CRGB (0,255,0);
leds [  111 ] = CRGB (0,255,0);
leds [  112 ] = CRGB (0,255,0);
leds [  113 ] = CRGB (0,255,0);
leds [  114 ] = CRGB (0,255,0);
leds [  115 ] = CRGB (0,255,0);
leds [  140 ] = CRGB (0,255,0);
leds [  141 ] = CRGB (0,255,0);
leds [  142 ] = CRGB (0,255,0);
leds [  143 ] = CRGB (0,255,0);
leds [  144 ] = CRGB (0,255,0);
leds [  145 ] = CRGB (0,255,0);
leds [  146 ] = CRGB (0,255,0);
leds [  147 ] = CRGB (0,255,0);
leds [  172 ] = CRGB (0,255,0);
leds [  173 ] = CRGB (0,255,0);
leds [  174 ] = CRGB (0,255,0);
leds [  175 ] = CRGB (0,255,0);
leds [  176 ] = CRGB (0,255,0);
leds [  177 ] = CRGB (0,255,0);
leds [  178 ] = CRGB (0,255,0);
leds [  179 ] = CRGB (0,255,0);
leds [  192 ] = CRGB (0,255,0);
leds [  193 ] = CRGB (0,255,0);
leds [  194 ] = CRGB (0,255,0);
leds [  195 ] = CRGB (0,255,0);
leds [  196 ] = CRGB (0,255,0);
leds [  197 ] = CRGB (0,255,0);
leds [  198 ] = CRGB (0,255,0);
leds [  199 ] = CRGB (0,255,0);
leds [  200 ] = CRGB (0,255,0);
leds [  201 ] = CRGB (0,255,0);
leds [  202 ] = CRGB (0,255,0);
leds [  203 ] = CRGB (0,255,0);
leds [  204 ] = CRGB (0,255,0);
leds [  205 ] = CRGB (0,255,0);
leds [  206 ] = CRGB (0,255,0);
leds [  207 ] = CRGB (0,255,0);
leds [  208 ] = CRGB (0,255,0);
leds [  209 ] = CRGB (0,255,0);
leds [  210 ] = CRGB (0,255,0);
leds [  211 ] = CRGB (0,255,0);
leds [  212 ] = CRGB (0,255,0);
leds [  213 ] = CRGB (0,255,0);
leds [  214 ] = CRGB (0,255,0);
leds [  215 ] = CRGB (0,255,0);
leds [  216 ] = CRGB (0,255,0);
leds [  217 ] = CRGB (0,255,0);
leds [  218 ] = CRGB (0,255,0);
leds [  219 ] = CRGB (0,255,0);
leds [  220 ] = CRGB (0,255,0);
leds [  221 ] = CRGB (0,255,0);
leds [  222 ] = CRGB (0,255,0);
leds [  223 ] = CRGB (0,255,0);
leds [  224 ] = CRGB (0,255,0);
leds [  225 ] = CRGB (0,255,0);
leds [  226 ] = CRGB (0,255,0);
leds [  227 ] = CRGB (0,255,0);
leds [  228 ] = CRGB (0,255,0);
leds [  229 ] = CRGB (0,255,0);
leds [  230 ] = CRGB (0,255,0);
leds [  231 ] = CRGB (0,255,0);
leds [  232 ] = CRGB (0,255,0);
leds [  233 ] = CRGB (0,255,0);
leds [  234 ] = CRGB (0,255,0);
leds [  235 ] = CRGB (0,255,0);
leds [  236 ] = CRGB (0,255,0);
leds [  237 ] = CRGB (0,255,0);
leds [  238 ] = CRGB (0,255,0);
leds [  239 ] = CRGB (0,255,0);
leds [  240 ] = CRGB (0,255,0);
leds [  241 ] = CRGB (0,255,0);
leds [  242 ] = CRGB (0,255,0);
leds [  243 ] = CRGB (0,255,0);
leds [  244 ] = CRGB (0,255,0);
leds [  245 ] = CRGB (0,255,0);
leds [  246 ] = CRGB (0,255,0);
leds [  247 ] = CRGB (0,255,0);
leds [  248 ] = CRGB (0,255,0);
leds [  249 ] = CRGB (0,255,0);
leds [  250 ] = CRGB (0,255,0);
leds [  251 ] = CRGB (0,255,0);
leds [  252 ] = CRGB (0,255,0);
leds [  253 ] = CRGB (0,255,0);
leds [  254 ] = CRGB (0,255,0);
leds [  255 ] = CRGB (0,255,0);
   FastLED.show();
   delay(300);
   FastLED.clear();
   }
   t=0;
  Serial.write('W');
  }   
}


void RedSquareBlink()  {

  while (state == 'D') {
  FastLED.clear();
  fill_solid (leds, NUM_LEDS, CRGB::Red);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
  delay(500);
  FastLED.clear();
  FastLED.show();
  delay(500);
  Serial.write('S');
  }   
}


void Clear()  {

  while (state == 'N') {
  FastLED.clear();
  fill_solid (leds, NUM_LEDS, CRGB::Blue);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
  delay(500);
  FastLED.clear();
  FastLED.show();
  delay(500);
  Serial.write('C'); 
}
}
