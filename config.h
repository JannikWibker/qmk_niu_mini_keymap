#pragma once

#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE

/* this allows custom led indicators to be on while led effects are off */
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

/* rgb lighting will be switched off when host goes to sleep */
#define RGBLIGHT_SLEEP

#define BACKLIGHT_TIMEOUT 2 // in minutes

/* tap and hold (mod tap, layer tap; ) */
#define RETRO_TAPPING
#define PERMISSIVE_HOLD
#define TAPPING_TERM 100

/* mouse speed & acceleration */
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_INTERVAL 32
#define MOUSEKEY_TIME_TO_MAX 40

/* one shot */
#define ONESHOT_TAP_TOGGLE 2

/* led colors */
#define LINUX_COLORS        RGB_PURPLE
#define MACOS_COLORS        RGB_WHITE
#define CAPS_COLORS         RGB_BLUE
#define WPM0_COLORS         RGB_WHITE
#define WPM1_COLORS         RGB_TEAL
#define WPM2_COLORS         RGB_PINK
#define WPM3_COLORS         RGB_RED
#define LED_OFF_COLORS      0, 0, 0
#define LAYER_BASE_COLORS   RGB_WHITE
#define LAYER_LOWER_COLORS  RGB_CYAN
#define LAYER_RAISE_COLORS  RGB_GREEN
#define LAYER_ADJUST_COLORS RGB_RED

#define LAYER_VIM_INSERT_COLORS RGB_MAGENTA
#define LAYER_VIM_NORMAL_COLORS RGB_PINK
#define LAYER_VIM_VISUAL_COLORS RGB_GREEN

/*  -- BEHAVIOUR & OS SPECIFIC KEYS --  */

/* #define WPM_INDICATOR */
#define LAYER_INDICATOR
#define CAPSLOCK_INDICATOR
#define OS_INDICATOR

/* choose wether to have capslock or modtap key */
// #define CAPSLOCK_KEY

/* backslash key on both Linux and MacOS */
#define _L_BACKSLASH RALT(KC_7)
#define _M_BACKSLASH LSFT(RALT(KC_7))


/* slash key on both Linux and MacOS */
#define _L_SLASH LSFT(KC_7)
#define _M_SLASH LSFT(KC_7)


/* asterisks key on both Linux and MacOS; assuming german layout */
#define _L_ASTERISKS LSFT(KC_0)
#define _M_ASTERISKS LSFT(KC_0) // potentially customize for usage with default osx-layout


/* dollar sign on both Linux and MaxOS; assuming german layout */
#define _L_DOLLAR LSFT(KC_4)
#define _M_DOLLAR LSFT(KC_4) // this is potentially redefined somewhere else (see ENABLE_NON_US_BSLASH)


#define _BACKWARDS LCTL(KC_PGUP)
#define _FORWARDS  LCTL(KC_PGDN)


/* tab normally, but L_LOWER / M_LOWER when held down */
#define _L_TAB_LOWER LT(_L_LOWER, KC_TAB)
#define _M_TAB_LOWER LT(_M_LOWER, KC_TAB)


/* apple fn key (mapped to F20, needs to be software remapped); if shift is pressed as well handle as if ADJUST was pressed */
#define _M_FN_RAW KC_F20


/* esc normally, but (left) control when held down */
#define _CTRL_ESC MT(MOD_LCTL, KC_ESC)


/* space normally, but (left) control when held down */ // TODO: currently not being used
#define _CTRL_SPC MT(MOD_LCTL, KC_SPC)


/* enter normally, but (right) shift when held down */
#define _RSFT_RET MT(MOD_RSFT, KC_ENT) // TODO: currently not being used


/* left arrow normally, but (right) gui when held down */
#define _GUI_MINS  MT(MOD_RGUI, KC_MINS)


/* right arrow normally, but (right) shift when held down */
#define _CTL_EQL MT(MOD_RCTL, KC_EQL)


/* wether to enable vim emulation mode
  (this is an extra layer which allows to use some vim like commands
  (or rather 2 layers for each operating system => 4 layers))
*/
#define ENABLE_VIM_MODE


/* replace dedicated dollar sign key with non_us_backslash on macOS (macOS uses the non_us_backslash for
   keyboard shortcuts (sometimes; could be dependant on layout; afaik grave is sometimes used as well))
*/
#define ENABLE_NON_US_BSLASH

/*
  wether or not to invert scrolling direction on macOS (macOS has "scroll direction: natural" which
  is natural  on a trackpad but reversed for normal scroll wheels; this just swaps the buttons)
*/
// #define INVERT_MACOS_SCROLL


/* this makes sure that layer_state_set_user is called when vim changes mode */
#define VIM_CALL_LAYER_STATE_CHANGE_ON_MODE_SWITCH


/*one shot key which (in conjunction with userspace code) switches to lower layer and activates shift */
#define _L_MT_S_LOWER OSL(_L_LOWER)
#define _M_MT_S_LOWER OSL(_M_LOWER)

#ifdef ENABLE_NON_US_BSLASH
#undef _M_DOLLAR
#define _M_DOLLAR KC_NONUS_BSLASH
#endif

#ifdef CAPSLOCK_KEY
#define _L_CAPSLOCK KC_CAPS
#define _M_CAPSLOCK KC_CAPS
#else
#define _L_CAPSLOCK _L_MT_S_LOWER
#define _M_CAPSLOCK _M_MT_S_LOWER
#endif

#ifdef INVERT_MACOS_SCROLL
#define _M_MS_UP KC_MS_D
#define _M_MS_DW KC_MS_U
#else
#define _M_MS_UP KC_MS_U
#define _M_MS_DW KC_MS_D
#endif