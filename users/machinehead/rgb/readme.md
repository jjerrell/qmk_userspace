# Userspace RGB Documentation

Features:

- Feature control
- Layer indication
    - Home Layer: Home-Row Mods
    - LOWER: Numpad and Arrows
    - RAISE: All keys
    - ADJUST: All keysj

## General Knowledge

### LED Flags

| Flag               | Example (Planck)                        |
| ------------------ | --------------------------------------- |
| LED_FLAG_KEYLIGHT  | Spacebar + All Alpha Keys               |
| LED_FLAG_INDICATOR | None                                    |
| LED_FLAG_UNDERGLOW | None                                    |
| LED_FLAG_MODIFIER  | All outer keys sans spacebar and tab(?) |

## Feature control

It is an expectation that any feature in here will only function if `RGB_MATRIX_CUSTOM_USER` is enabled. This flag is already enabled by default if `RGB_MATRIX_ENABLE` is enabled.

Effectively, there are two options to disable the logic:

- `RGB_MATRIX_ENABLE = no` - No RGB Matrix features will be compiled at all
- `RGB_MATRIX_CUSTOM_USER = no` - Default RGB Matrix logic will function. Nothing in here should be compiled.

### Contribution Guidelines

- Runtime
    - Toggling or disabling features on the fly should read/write from `userspace_config_t` from `machinehead_runtime.h`
- Compile time
    - For disparate implementations which should be entirely confined, addtional `config.h` definitions will be added and documented in the preceding section.

## Layer Indication

This feature enables sharing RGB layer indication logic across keyboards.

### Disabling/Toggling

SIMPLE_LAYER_INDICATION
ANIMATED_LAYER_INDICATION

### Configuration

#### **Required** Keymap-level

Each keymap must provide the following block, with the LEDs mapped appropriately. For example:

```c
// keyboards/zsa/planck_ez/glow/keymaps/machinehead/keymap.c
#ifdef RGB_MATRIX_CUSTOM_USER
const uint8_t home_led_mapping[] = {};
const uint8_t fn_led_mapping[] = {};
const uint8_t mod_led_mapping[] = {
    // shift
    13,
    22,
    // command
    14,
    21,
    // option/alt
    15,
    20,
    // control
    24,
    35
};
const uint8_t arrow_led_mapping[] = {2, 13, 14, 15};
const uint8_t numpad_led_mapping[] = {8, 9, 10, 20, 21, 22, 31, 32, 33, 34, 35};
#endif // RGB_MATRIX_CUSTOM_USER
```

Everything else is handled by the userspace implementation.

#### Layer LED Counts

Default counts are defined in `config_post.h`. Non-standard layouts may need to adjust. Example customization:

```h
// keyboards/generic/keymaps/user/config.h
#define HOME_LED_COUNT   0   // Not implemented at time of writing
#define FN_LED_COUNT     0   // Not implemented at time of writing
#define MOD_LED_COUNT    10  // Used on the home layer
#define ARROW_LED_COUNT  6   // Used on _LOWER
#define NUMPAD_LED_COUNT 12  // Usd on _LOWER
```

### Array/Mapping Lookups

Under the hood, a bitmap (`led_bitmap_t`) is created for each set of mappings. This makes lookup operations easier. For example:

```c
for (uint8_t i = led_min; i < led_max; i++) {
    if (led_in_group(&bitmap, i)) {
        rgb_matrix_set_color(i, RGB_RED);
    }
}
```

### Simple Layer Indication

By defining `SIMPLE_LAYER_INDICATION` in your config.h, you can enable the simple layer indication feature which simply illuminates the defined mappings based on layer state.

This particular feature is ultimately implemented via the `rgb_matrix_indicators_advanced_user` API. All non-configured LEDs are disabled at bootup via `keyboard_post_init_rgb_matrix`, which is called during `keyboard_post_init_user` if `RGB_MATRIX_CUSTOM_USER` is enabled.

### Animated Layer Indication

Defining `ANIMATED_LAYER_INDICATION` in your config.h, has the same underlying experience as the "simple layer indication" feature. The difference being that this feature will animate the lights.