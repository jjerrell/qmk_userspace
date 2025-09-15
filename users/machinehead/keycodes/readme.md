# Keycode Goals

## Macro Layer

- Window manipulation and auto-layout
- Mouse controls
  - The Voyager trackbacll would be nice. A second for Moonlander, yes... case is a problem though.

```c
// Note: This region will be for Macro's specific to the Rectangle app on MacOS.
//  In an effort to avoid conflicts with other apps and deal with the complexity
//  of this feature, Rectangle shortcuts will need to be remapped accordingly
#define SWP_APP LGUI_T(KC_TAB)

#pragma region WINDOW_QUARTERS
#define LF_LQTR HYPR_T(KC_Q) // Left quarter
#define LF_CQTR HYPR_T(KC_D) // Left-center quarter
#define RT_CQTR HYPR_T(KC_R) // Right-center quarter
#define RT_RQTR HYPR_T(KC_W) // Right quarter
#pragma endregion WINDOW_QUARTERS

#pragma region WINDOW_THIRDS
#define LF_TTRD HYPR_T(KC_A) // Left two-thirds
#define LF_THRD HYPR_T(KC_S) // Left third
#define CN_THRD HYPR_T(KC_H) // Center third
#define RT_THRD HYPR_T(KC_T) // Right third
#define RT_TTRD HYPR_T(KC_G) // Right two-thirds

#define CN_TTRD KC_LALT // TODO: Rectangle shortcut for center 2/3 (May only be scriptable or require package changes)
#pragma endregion WINDOW_THIRDS

#pragma region WINDOW_HALVES
#define LF_HALF HYPR_T(KC_TODO) // TODO: Rectangle shortcut for left 1/3
#define CN_HALF KC_LALT // TODO: Rectangle shortcut for center 1/2 (may need set)
#define RT_HALF KC_LALT // TODO: Rectangle shortcut for right 1/2
#pragma endregion WINDOW_HALVES

#pragma region WORKSPACE_LAYOUTS
// TODO: Macros to arrange two windows in the same workspace in a L 2/3:1/3, R 1/3:2/3 layout and, 1/3:1/3:1/3
#define LY_LFT3 (LF_THRD & SWP_APP & RT_THRD) // TODO: No way this is valid syntax. But this is the gist.
#define LY_RGT3 (RT_THRD & SWP_APP & LF_THRD) // TODO: No way this is valid syntax. But this is the gist.
#define LY_THRD (LF_THRD & SWP_APP & CN_THRD & RT_THRD) // TODO: No way this is valid syntax. But this is the gist.
// TODO: Macros to arrange two windows in the same worspace in a 1/2:1/2 layout
#define LY_HALF (LF_HALF & SWP_APP & RT_HALF) // TODO: No way this is valid syntax. But this is the gist.
// TODO: Center, wide. Half is undefined by default and may be insufficient.
//  - Will need to use one of the 2/3 or 3/4 options chained with a "center" command.
//  - Rectangle source code reveals existance of centerTwoThirds and centerThreeFourths. It's unclear without
//    further research on a Mac machine, whether these can be set easily or if they are only available for scripting.
//  See: https://github.com/rxhanson/Rectangle/blob/62285d5f468c1ceff7aa04fc79a230b567b517ee/Rectangle/WindowAction.swift#L100-L101C5
#define LY_CNTR KC_LALT // TODO: Big TODO above this
#define LY_CRLF KC_LALT // TODO: Whatever the smallest remaining space to the left is
#define LY_CRRT KC_LALT // TODO: Whatever the smallest remaining space to the right is
#define LY_PROM KC_LALT // TODO: 3 window layout with a promininent center window. Chain LY_CNTR + LY_CRLF + LY_CRRT with cmd/tab's
#pragma endregion WORKSPACE_LAYOUTS
```
