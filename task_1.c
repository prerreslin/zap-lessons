#include <superkarel.h>

void turn_right();
void jump_over_right();
void jump_over_left();
int if_beeper();

int main() {
    turn_on("task_1.kw");
    set_step_delay(0);

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

int if_beeper() {
    if (beepers_present()) {
        pick_beeper();
        turn_west();
        return 1;
    }
    else {
        return 0;
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
            if (if_beeper()) {
                jump_over_left();
                return;
            }
            step();
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
