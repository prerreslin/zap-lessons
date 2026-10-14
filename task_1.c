#include <superkarel.h>

void turn_right();
void jump_over_right();
void jump_over_left();

int main() {
    turn_on("task_1.kw");
    set_step_delay(100);

    put_beeper();
    jump_over_right();

    turn_off();
    return 0;
}

void turn_right() {
    loop(3) {
        turn_left();
    }
}

void turn_west() {
    while (!facing_west()) {
        turn_left();
    }
}


void jump_over_right() {
    while(true) {
        turn_left();
        while(front_is_clear()) {
            step();
            if (right_is_clear()) {
                turn_right();
                while(front_is_clear()) {
                    step();
                    if (right_is_clear()) {
                        break;
                    }
                }
                break;
            }
        }
        turn_right();
        while(front_is_clear()) {
            if (beepers_present()) {
                pick_beeper();
                jump_over_left();
                return;
            }
            else {
                step();
            }
            if (beepers_present()) {
                pick_beeper();
                jump_over_left();
                return;
            }
        }
        turn_left();
    }
}

void jump_over_left() {
    while (true) {
        if (beepers_present()) {
            pick_beeper();
            return;
        }
        turn_right();
        while(front_is_clear()) {
            step();
            if (left_is_clear()) {
                turn_left();
                while(front_is_clear()) {
                    step();
                    if (left_is_clear()) {
                        break;
                    }
                }
                break;
            }
        }
        turn_left();
        while(front_is_clear()) {
            step();
        }
        turn_right();
    }
}
