/*
  CH552TinyPad

  created 2023
  by @ctes091x for use with CH55xduino

  cli board options: usb_settings=user148

*/

//For windows user, if you ever played with other HID device with the same PID C55D
//You may need to uninstall the previous driver completely        


#ifndef USER_USB_RAM
#error "This example needs to be compiled with a USER USB setting"
#endif

#include "./src/userUsbHidKeyboard/USBHIDKeyboard.h"

#define BUTTON1_PIN 33
#define BUTTON2_PIN 34
#define BUTTON3_PIN 35
#define BUTTON4_PIN 30
#define BUTTON5_PIN 31
#define BUTTON6_PIN 11

#define LED_BUILTIN 10

bool button1PressPrev = false;
bool button2PressPrev = false;
bool button3PressPrev = false;
bool button4PressPrev = false;
bool button5PressPrev = false;
bool button6PressPrev = false;

void setup() {
  USBInit();
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  pinMode(BUTTON5_PIN, INPUT_PULLUP);
  pinMode(BUTTON6_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void errorBlink() {
  while(true){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(40);
    digitalWrite(LED_BUILTIN, LOW);
    delay(10);
  }
}

void loop() {
  //button 1 is mapped to letter 'a'
  bool button1Press = !digitalRead(BUTTON1_PIN);
  if (button1PressPrev != button1Press) {
    button1PressPrev = button1Press;
    if (button1Press) {
      Keyboard_press('a');
    } else {
      Keyboard_release('a');
    }
  }

  //button 2 is mapped to [Win+R]->'code'
  bool button2Press = !digitalRead(BUTTON2_PIN);
  if (button2PressPrev != button2Press) {
    button2PressPrev = button2Press;
    if (button2Press) {
      Keyboard_press(KEY_LEFT_GUI);
      Keyboard_press('r');
      Keyboard_releaseAll();
      delay(100);
      Keyboard_write('c');
      Keyboard_write('o');
      Keyboard_write('d');
      Keyboard_write('e');
      Keyboard_write(0xE0);
      // Keyboard_press(KEY_LEFT_ALT);
      // Keyboard_write(KEY_TAB);
      // Keyboard_release(KEY_LEFT_ALT);
    }
  }

  // bool button3Press = !digitalRead(BUTTON3_PIN);
  // if (button3PressPrev != button3Press) {
  //   button3PressPrev = button3Press;
  //   if (button3Press) {
  //     Keyboard_press('a');
  //   }
  // }
  digitalWrite(LED_BUILTIN, !digitalRead(BUTTON3_PIN));

  bool button4Press = !digitalRead(BUTTON4_PIN);
  if (button4PressPrev != button4Press) {
    button4PressPrev = button4Press;
    if (button4Press) {
      Keyboard_press(KEY_LEFT_CTRL);
      Keyboard_press(KEY_LEFT_GUI);
      Keyboard_press(KEY_LEFT_ARROW);
      Keyboard_releaseAll();
    }
  }
  bool button5Press = !digitalRead(BUTTON5_PIN);
  if (button5PressPrev != button5Press) {
    button5PressPrev = button5Press;
    if (button5Press) {
      Keyboard_press(KEY_LEFT_GUI);
      Keyboard_press(KEY_TAB);
      Keyboard_releaseAll();
    }
  }
  bool button6Press = !digitalRead(BUTTON6_PIN);
  if (button6PressPrev != button6Press) {
    button6PressPrev = button6Press;
    if (button6Press) {
      Keyboard_press(KEY_LEFT_CTRL);
      Keyboard_press(KEY_LEFT_GUI);
      Keyboard_press(KEY_RIGHT_ARROW);
      Keyboard_releaseAll();
    }
  }

  //button 3 is mapped to Capslock
  // bool button3Press = !digitalRead(BUTTON3_PIN);
  // if (button3PressPrev != button3Press) {
  //   button3PressPrev = button3Press;
  //   if (button3Press) {
  //     Keyboard_press(KEY_CAPS_LOCK);
  //     delay(100); //a quick capslock press is not recognized on mac
  //     Keyboard_release(KEY_CAPS_LOCK);
  //   }
  // }

  //map capsLock to LED
  //Bit 0: NUM lock, Bit 1: CAPS lock, Bit 2: SCROLL lock, Bit 3: Compose, Bit 4: Kana,
  // if (Keyboard_getLEDStatus() & 2) {
  //   digitalWrite(LED_BUILTIN, HIGH);
  // } else {
  //   digitalWrite(LED_BUILTIN, LOWco);
  // }

  delay(50);  //naive debouncing

}
