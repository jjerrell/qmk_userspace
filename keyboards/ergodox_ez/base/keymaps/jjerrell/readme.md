# Jacob Jerrell's Ergodox Ez Layout

The original edition Ergodox EZ with a black case, unlabeled white keycaps, and 3 indicator-style LEDs.

> Sadly, after handling years of considerable load, this board is more or less unusable. Depending on the situation, a Planck or a Moondlander now share the burden.
>
> The firmware seen here is maintained for the sake of memory. Perhaps I'll disassemble the boards one day and put it all in one of those picture frames 🚀!
>
> R.I.P. old companion. May our keystrokes echo through eternity.

## General

The LEDs are used for two things:

1. If on a default layer, it lights up one indicator each for Shift and Alt. Control and Command/Win share one of the indicators, increasing in brightness if both are held
2. Tri-state and special layer indication or announcement

## Layouts

### Empty ASCII Layout 

```
.---------------------------------------------. .---------------------------------------------.
|       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
!-------+-----+-----+-----+-----+-------------! !-------+-----+-----+-----+-----+-----+-------!
|       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
!-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
|       |     |     |     |     |     |-------! !-------!     |     |     |     |     |       |
!-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
|       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
'-------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+-------'
|      |     |     |     |     |                             !     |     |     |     |      |
'------------------------------'                             '------------------------------'
                              .---------------. .---------------.
                              |       |       | !       |       |
                      .-------+-------+-------! !-------+-------+-------.
                      !       !       |       | !       |       !       !
                      !       !       !-------! !-------!       !       !
                      |       |       |       | !       |       |       |
                      '-----------------------' '-----------------------'
```

### Empty Wrapper

```c
---------- LEFT HAND -----------   ---------- RIGHT HAND ----------
(                                                                    \
L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                        L55,L56,   R50,R51,                          \
                            L54,   R52,                              \
                    L53,L52,L51,   R55,R54,R53                       \
)
```

## Vendor Changelog

* Dec 2016:
  * Added LED keys
  * Refreshed layout graphic, comes from http://configure.ergodox-ez.com now.
* Sep 22, 2016:
  * Created a new key in layer 1 (bottom-corner key) that resets the EEPROM.
* Feb 2, 2016 (V1.1): 
  * Made the right-hand quote key double as Cmd/Win on hold. So you get ' when you tap it, " when you tap it with Shift, and Cmd or Win when you hold it. You can then use it as a modifier, or just press and hold it for a moment (and then let go) to send a single Cmd or Win keystroke (handy for opening the Start menu on Windows).

This is what we ship with out of the factory. :) The image says it all:

![Default](https://i.imgur.com/Be53jH7.png)