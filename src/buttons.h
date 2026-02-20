#ifndef GAMEPAD_BUTTONS_H
#define GAMEPAD_BUTTONS_H

#include <queue>
#include <Arduino.h>

#include "config.h"

enum button_state_t{
    BUT_NONE,
    BUT_PRESSED,
    BUT_RELEASED,
    BUT_STILL_PRESSED,
    BUT_STILL_RELEASED
};

class Gamepad_buttons{
    std::queue < uint8_t > button_buff;

    uint8_t latest_state, previous_state = INVERT_BUTTONS_STATE * -1;

public:
    uint64_t last_event_time[BUTTONS_N];

    Gamepad_buttons() = default;

    void init();


    /**
     * @brief Get latest state of the specific button stored by system
     * 
     * @param id button id
     * @return true: pressed
     * @return false: unpressed
     */
    bool get_latest_state(uint8_t id);

    /**
     * @brief Get current state of the specific button
     * 
     * @param id button id
     * @return true 
     * @return false 
     */
    bool read_state(uint8_t id);



    /**
     * @brief Add button event artificially
     * 
     * @param state new state raw data
     */
    void add_button_event(uint8_t &state);

    /**
     * @brief Get buttons data for the next event in queue. After call the event is considered as handled
     * 
     * @return uint8_t*: array of `BUTTONS_N` elements with state of each button according to its id
     */
    uint8_t* get_button_event();

    /**
     * @brief Checks are there any unhandled buttons events
     * 
     * @return true: unhandled events are present
     * @return false: no new events
     */
    bool event_available();

    /**
     * @brief Forced button event queue clear
     * 
     */
    void clear_queue();
};

#endif