/* --------------------------------- *
/*   VARIATION TUI (CONFIGURATION)   *
 * [CONTAINS ONLY ASCII DEFINATIONS] *
 * --------------------------------- */
#ifndef _VN_CONF_H
#define _VN_CONF_H
/* -------------------------------- *
 * ASCII ESCAPE SEQUENCE RESET CODE *
 * -------------------------------- */
#define esc_reset "\033[0m" 
/* -------------------------------- *
 *  MUST BE USED AFTER COLOR CODES  */

/* --------------------------------- *
 * ASCII ESCAPE SEQUENCE TEXT STYLES *
 * --------------------------------- */
#define text_bold "\033[1m"
#define text_italic "\033[3m"
#define text_underline "\033[4m"
#define text_blink "\033[5m"
#define text_strikethrough "\033[9m"
/* --------------------------------- */

/* ----------------------------------- *
 * ASCII ESCAPE SEQUENCE UTILITY CODES *
 * ----------------------------------- */
#define clear_screen "\033[2J\033[H"
#define cursor_visible "\033[?25h"
#define cursor_invisible "\033[?25l"
/* ----------------------------------- */

#endif /* MADE BY @hanilr */