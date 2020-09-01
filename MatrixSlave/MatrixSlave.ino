#include "FastLED.h"  // Include FastLED Library
#define NUM_LEDS 256 //  The number of LEDS on matrix
#define DATA_PIN 3  //  Data-In of matrix
#define BRIGHTNESS 64
#define DEBUG
CRGB leds[NUM_LEDS];
char state;
char received = 'X';
int t=0;


void setup() {
	pinMode(DATA_PIN, OUTPUT);
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	Serial.begin(38400); 
}

void select_action(char s) {
	switch(s) {
		case 'L': // X-Axis Left
#ifdef DEBUG
			Serial.println("X-Axis Left");
#endif
			LeftArrowBlink();
		break;
		case 'R': // X-Axis Right
#ifdef DEBUG
			Serial.println("X-Axis Right");
#endif
			RightArrowBlink();
		break;
		case 'U': // Y-Axis Up
			ExclamationMarkBlink();
		break;
		case 'D': // Y-Axis Down
			RedSquareBlink();
		break;
		case 'N': // Clear / Reset
			Clear();
		break;
	}
}

int check_serial() {
	if (Serial.available() > 0) { // Checks whether data is comming from the serial port
		received = Serial.read();
#ifdef DEBUG
		Serial.print("Received: ");
		Serial.println(received);
		Serial.print("State: ");
		Serial.println(state);
#endif

		switch(received) {
			case 'L': // X-Axis Left
				state=received;
				return 1;
			break;
			case 'R': // X-Axis Right
				state=received;
				return 1;
			break;
			case 'U': // Y-Axis Up
				state=received;
				return 1;
			break;
			case 'D': // Y-Axis Down
				state=received;
				return 1;
			break;
			case 'N': // Clear / Reset
				state=received;
				return 1;
			break;
		}
	}
	return 0;
}

int check_interrupt(int wait) {
	int count = wait/100;
	for (int i=0; i<count; i++) {
		delay(100);
		if (check_serial()) {
			return 1;
		}
	}
}

void loop() {
	check_serial();
	select_action(state);
}

void light_leds(int start, int end) {
	for (int led=start; led<=end; led++) {
		leds [ led ] = CRGB (0,255,0);
	}
}

void LeftArrowBlink() { // Function that is called when Vx is <= 100 and shows a Left Blinking Arrow on the matrix
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
	if (check_interrupt(1000)) {
		return;
	}
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
	if (check_interrupt(1000)) {
		return;
	}
	FastLED.clear();
	for (t=0; t<3; t++) {
		FastLED.clear();
		light_leds(119,136);
		light_leds(151,168);
		light_leds(183,186);
		light_leds(197,200);
		light_leds(215,218);
		light_leds(229,232);
		light_leds(247,250);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
		light_leds(0,63);
		light_leds(76,83);
		light_leds(108,115);
		light_leds(140,147);
		light_leds(172,179);
		light_leds(204,211);
		light_leds(236,243);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
	}
	Serial.write('A');
}


void RightArrowBlink()  {// Function that is called when Vx is >= 1000 and shows a Right Blinking Arrow on the matrix
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
	if (check_interrupt(1000)) {
		return;
	}
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
	if (check_interrupt(1000)) {
		return;
	}
	FastLED.clear();
	for (t=0; t<3; t++) {
		FastLED.clear();
		light_leds(0,3);
		light_leds(28,35);
		light_leds(60,67);
		light_leds(92,99);
		light_leds(124,131);
		light_leds(156,163);
		light_leds(188,255);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
		light_leds(0,3);
		light_leds(28,35);
		light_leds(60,67);
		light_leds(92,99);
		light_leds(124,131);
		light_leds(156,163);
		light_leds(188,255);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
	}
	Serial.write('D');
}


void ExclamationMarkBlink()  {   
	for (t=0; t<3; t++) {
		FastLED.clear();
		light_leds(1,4);
		light_leds(26,37);
		light_leds(57,71);
		light_leds(87,104);
		light_leds(118,123);
		light_leds(133,152);
		light_leds(168,171);
		light_leds(181,181);
		light_leds(205,211);
		light_leds(236,242);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
	}
	for (t=0; t<3; t++) {
		FastLED.clear();
		light_leds(5,8);
		light_leds(23,26);
		light_leds(37,40);
		light_leds(55,58);
		light_leds(69,72);
		light_leds(87,104);
		light_leds(119,136);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
		light_leds(12,19);
		light_leds(44,51);
		light_leds(77,83);
		light_leds(108,115);
		light_leds(140,147);
		light_leds(172,179);
		light_leds(192,255);
		FastLED.show();
		if (check_interrupt(300)) {
			return;
		}
		FastLED.clear();
	}
	Serial.write('W');
}


void RedSquareBlink()  {
	FastLED.clear();
	fill_solid (leds, NUM_LEDS, CRGB::Red);
	FastLED.setBrightness(BRIGHTNESS);
	FastLED.show();
	if (check_interrupt(500)) {
		return;
	}
	FastLED.clear();
	FastLED.show();
	if (check_interrupt(500)) {
		return;
	}
	Serial.write('S');
}


void Clear()  {
	FastLED.clear();
	fill_solid (leds, NUM_LEDS, CRGB::Blue);
	FastLED.setBrightness(BRIGHTNESS);
	FastLED.show();
	if (check_interrupt(500)) {
		return;
	}
	FastLED.clear();
	FastLED.show();
	if (check_interrupt(500)) {
		return;
	}
	Serial.write('C');
}
