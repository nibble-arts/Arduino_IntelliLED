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
 * flash_on(): the INTELLILED only flashes 10 ms in the speed set by time()
 * flass_off(): normal blinking mode
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
    void blink(int blink_time);
    void flash(int blink_time);
    void invert(bool inverted);
    void on(void);
    void off(void);
    void color(int color);
    void color(int color, int color1);
    void toggle(void);
    void update(void);

  private:
    int _led_port;
    int _led_port1;
    int _led_color;
    int _led_color1;
    bool _inverted;
    double _timeout;
    int _blink_time;
    bool _flash_status;

	void _set_led(int);
    void _on(void);
    void _off(void);
    void _flash_on(void);
    void _flash_off(void);
    void _reset(void);
};


#endif
