/*
 * INTELLILED class
 * 
 * @autor: Thomas Winkler
 * @copyright: 2019-11-17
 * @lizence: CC0
 */

/*
 * This software is open source under the creative commons CC0 license
 */
 
/*
 * The INTELLILED class controlles an output for display.
 * With set_blink a blink style can be added, updated with the blink() method.
 * 
 * blink(int): set the blink time in ms
 * flash(): the INTELLILED only flashes 10 ms in the speed set by time()
 *
 * on(): switch the led on
 * off(): switch the led off
 *
 * color(COLOR): set a color when two ports are defined
 * offColor(COLOR): set a color instead of off state
 * 
 * forceFlash(time): set a time to flash, even at on state
 */

#ifndef INTELLILED_H
#define INTELLILED_H

#define INTELLILED_RED 0
#define INTELLILED_GREEN 1
#define INTELLILED_YELLOW 2


class INTELLILED {

  public:
    INTELLILED(void);
    INTELLILED(int port, int port1=false);
    void begin(int port, int port1=false);
    void setBlink(int);
    void forceBlink(int);
    void blink(int);
    void flash(int);
    void on(void);
    void off(void);
    void color(int);
    void color(int, int);
    void offColor(int);
    void toggle(void);
    void update(void);

  private:
    bool _is_on;
    int _force_blink;
    bool _flash_status;

    int _led_port;
    int _led_port1;
    
    int _led_color;
    int _led_color1;
    bool _off_color;
    
    double _timeout;
    int _blink_time;

	void _set_led(int);
    void _clear_led(void);
    void _on(void);
    void _off(void);
    void _flash_on(void);
    void _flash_off(void);
    void _reset(void);
};


#endif
