# Work Userspace

Goal: Optimize layers for home vs. work experiences.

- Scenario 1: At work and using a **Mac** to do engineering tasks
    - Uses lots of GUI and CTRL
- Scenario 2: At home using **Ubuntu Budgie w/ Studio** to do engineering tasks
    - Favors CTRL and ALT
- Scenario 3: At home using **Windows** to do engineering tasks
    - Favors CTRL and ALT
- Scenario 4: Gaming
    - GUI = BAD
    - Favor CTRL/SHIFT/ALT Placement

Targets: 

- Moonlander
- PlanckEZ

## Plan

1. Activate sounds to indicate mode switch
2. CTRL+GUI Swap (Macro's included)
3. System Test - Replay layer sound OR Flash lights: 1 flash = work; 2 flashes = home
4. Game layer accessible from home only
5. Game layer forces normal CMD/GUI behavior
6. Read up on OS detection
7. Macros for the linux command to toggle built-in keyboard

## Design

- [x] ~Add data structure for the userspace to be aware of state~
    - [ ] ~Check the state at bootup before any auto-switching~
- [x] Add `work_mode_is_active`
- [x] Add `keymap_mode_test` to userspace
    - Implement at keymap level
- [x] Add `user_mode_switch` to switch modes and activate `keymap_mode_test`
- [ ] Change modifier backlight colors per mode
    - Work: Standard (Goldenleaf?)
    - Home: Blue
    - Game: Red movement indicators
        - QWERTY (LHS offset)
        - Other common keys with distinct colors (Alert location/user, comms, etc)
        - Accessible ESC and TILDE
- [x] Common key location for Home/Work switch
- [ ] Common & conveniently-toggled location for Home/Game switch
