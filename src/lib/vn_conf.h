/*   VARIATION UI (CONFIGURATION)    */
/* [CONTAINS ONLY ASCII DEFINATIONS] */

#ifndef _VN_CONF_H
#define _VN_CONF_H
    /* ASCII ESCAPE SEQUENCE RESET CODE */
    #define esc_reset "\033[0m" /* MUST BE USED AFTER COLOR CODES */

    /* ASCII ESCAPE SEQUENCE TEXT STYLES */
    #define text_bold "\033[1m" /* BOLD */
    #define text_italic "\033[3m" /* ITALIC */
    #define text_underline "\033[4m" /* UNDERLINE */
    #define text_blink "\033[5m" /* BLINK */
    #define text_strikethrough "\033[9m" /* STRIKETHROUGH */

    /* ASCII ESCAPE SEQUENCE UTILITY CODES */
    #define clear_screen "\033[2J\033[H" /* CLEAR SCREEN */
    #define cursor_visible "\033[?25h" /* SET CURSOR VISIBLE */
    #define cursor_invisible "\033[?25l" /* SET CURSOR INVISIBLE */
#endif /* MADE BY @hanilr */