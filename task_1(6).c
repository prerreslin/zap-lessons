#include <superkarel.h>

void turn_right();
void face_to_north();
void face_to_south();
void face_to_east();
void face_to_west();
void jump_right();
void jump_left();
void sstep();

int main() {
	turn_on("task_1.kw");
    
    if (beepers_present()) {
        pick_beeper();
        face_to_west();
    }
    else {
        face_to_north();
        sstep();
        if (beepers_present()) {
            pick_beeper();
            face_to_south();
            sstep();
            face_to_west();
        }
        else {
                face_to_south();
                sstep();
                put_beeper();
                jump_right();
                face_to_south();
                while (front_is_clear()) {
                    step();
                }
                jump_left();
                face_to_west();
        }
    }

    turn_off();
    return 0;
}

void sstep() {
    if (front_is_clear()) {
        step();
    }
}

void jump_left() {
    while (true) {
        face_to_north();
        sstep();
        if (beepers_present()) {
                pick_beeper();
                break;
        }   
        while (left_is_blocked() && front_is_clear()) {
                sstep();
                if (beepers_present()) {
                        pick_beeper();
                        return;
                }             
        }
        face_to_west();
        sstep();
        if (beepers_present()) {
                pick_beeper();
                break;
        } 
        while (left_is_blocked() && front_is_clear()) {
                sstep();
                if (beepers_present()) {
                        pick_beeper();
                        return;
                }
        }
        if (facing_north() && front_is_blocked() && left_is_blocked()) {
            return;
        }
        face_to_south();
        sstep();
        if (beepers_present()) {
                pick_beeper();
                break;
        }
        while (left_is_blocked() && front_is_clear()) {
                sstep();
                if (beepers_present()) {
                        pick_beeper();
                        return;
                }    
        }
    }
}

void jump_right() {
    while (true) {
        face_to_north();
        sstep();
        if (beepers_present()) {
                 pick_beeper();
                 break;
        }
        while (right_is_blocked() && front_is_clear()) {
                sstep();
                if (beepers_present()) {
                        pick_beeper();
                        return;
                }
        }
        face_to_east();
        sstep();
        if (beepers_present()) {
                pick_beeper();
                break;
        }
        while (right_is_blocked() && front_is_clear()) {
                sstep();
                if (beepers_present()) {
                        pick_beeper();
                        return;
                }
        }
        face_to_south();
        sstep();
        if (beepers_present()) {
                pick_beeper();
                break;
        }
        while (right_is_blocked() && front_is_clear()) {
                sstep();
                if (beepers_present()) {
                        pick_beeper();
                        return;
                }
        }
    }
}

void turn_right() {
	set_step_delay(0);
	loop (3) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_north() {
	set_step_delay(0);
	while (!facing_north()) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_south() {
	set_step_delay(0);
	while (!facing_south()) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_east() {
	set_step_delay(0);
	while (!facing_east()) {
		turn_left();
	}
	set_step_delay(100);
}

void face_to_west() {
	set_step_delay(0);
	while (!facing_west()) {
		turn_left();
	}
	set_step_delay(100);
}
