/*
 * INTELLILED class
 * 
 * @autor: Thomas Winkler
 * @copyright: 2019-11-17
 * @lizence: CC0
 */

#include <Arduino.h>
#include "intelliled.h"


/*
 * construct INTELLILED
 * port = OUTPUT PORT #
 * optional: port1 = OUTPUT for multi color led
 */
INTELLILED::INTELLILED(void) {
}


INTELLILED::INTELLILED(int port, int port1) {
  begin(port, port1);
}


void INTELLILED::begin(int port, int port1) {
  
  _led_port = port;
  _led_port1 = port1;
  _led_color = 0;
  _blink_time = 0;
  _timeout = millis();

  // set INTELLILED ports to OUTPUT
  pinMode(_led_port, OUTPUT);
  
  if (_led_port1) {
    pinMode(_led_port1, OUTPUT);
  }

  _reset();
}


/*
 * set invert
 * false: high = on
 * true: high = off
 */
void INTELLILED::invert(bool inverted) {
  _inverted = inverted;  
}


/*
 * set blink time in ms
 */
void INTELLILED::blink(int blink_time) {

  _flash_off();
  _blink_time = blink_time;
}


/*
 * set flash time in ms
 * INTELLILED is on for 5mx
 */
void INTELLILED::flash(int blink_time) {
  _blink_time = blink_time;
  _flash_on();
}


/*
 * switch led on
 */
void INTELLILED::on(void) {
  _reset();
  _on();
}

/*
 * switch led off
 */
void INTELLILED::off(void) {
  _reset();  
}

/*
 * toggle INTELLILED
 */
void INTELLILED::toggle(void) {

  if (digitalRead(_led_port)) {
    _off();
  }
  else {
    _on();
  }
}

/*
 * set color for multicolor led
 * don't effect normal led
 */

void INTELLILED::color(int color) {
  _led_color = color;
}

/*
 * update led: blink or flash
 * is to be called in the main loop
 */
void INTELLILED::update(void) {

  if (_blink_time != 0) {

    // timeout > change status
    if (millis() > (_timeout + (int)_blink_time)) {

      // flash
      if (_flash_status == true) {
        _on();
        delay(10);
        _off();
      }

      // blink
      else {
        toggle();
      }
      _timeout = millis();
    }

  }
}




/*
 * reset blink time and switch off
 */
void INTELLILED::_reset(void) {
  blink(0);
  _off();
}

/*
 * set led port[s] on
 */
void INTELLILED::_on(void) {

  // set led inverted
  if (_inverted) {
      digitalWrite(_led_port, LOW);
  }

  // set color led high = on
  else {

    // multicolor INTELLILED
    if (_led_port1) {
  
      switch(_led_color) {
        case INTELLILED_RED:
          digitalWrite(_led_port, HIGH);
          digitalWrite(_led_port1, LOW);
          break;
  
        case INTELLILED_GREEN:
          digitalWrite(_led_port, LOW);
          digitalWrite(_led_port1, HIGH);
          break;
  
       case INTELLILED_YELLOW:
          digitalWrite(_led_port, HIGH);
          digitalWrite(_led_port1, HIGH);
          break;
      }
    }
    else {
      digitalWrite(_led_port, HIGH);
    }
  }
}


/*
 * set led ports off
 */
void INTELLILED::_off(void) {

  // set led inverted
  if (_inverted) {
    digitalWrite(_led_port, HIGH);
  }

  // leds off
  else {
    
    digitalWrite(_led_port, LOW);
  
    if (_led_port1) {
      digitalWrite(_led_port1, LOW);
    }
  }
}

/*
 * switch flash mode on
 */
void INTELLILED::_flash_on(void) {
  _flash_status = true;
}

/*
 * switch flash mode off
 */
void INTELLILED::_flash_off(void) {
  _flash_status = false;
}
