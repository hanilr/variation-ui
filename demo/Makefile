# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#                  DEMO TEST MAKEFILE                  #
# ---------------------------------------------------- #

CC = gcc
ANSI = -std=c89

_color = color/main.c
_general = general_function/main.c

_bg = widget/vn_bg/main.c
_frame = widget/vn_frame/main.c
_label = widget/vn_label/main.c
_line = widget/vn_line/main.c
_progress = widget/vn_progress/main.c
_notification = widget/vn_notif/main.c
_timer = widget/vn_timer/main.c

_all = $(_color) $(_general) $(_bg) $(_frame) $(_label) $(_line) $(_progress)

.PHONY: run compile _color _general _bg _frame _label _line _progress _notification _timer test clean 

run:
	@echo ""
	@echo "\t\t\033[38;2;55;55;200m[\033[38;2;233;233;233mMake List\033[38;2;55;55;200m]"
	@echo "\033[0m"
	@echo "\033[38;2;55;200;55m1.\033[38;2;233;233;233m Show make list \033[38;2;200;55;55m\033[1m'make' or 'make run'\033[0m"
	@echo "\033[38;2;55;200;55m2.\033[38;2;233;233;233m Compile all demo files \033[38;2;200;55;55m\033[1m'make compile'\033[0m"
	@echo "\033[38;2;55;200;55m3.\033[38;2;233;233;233m Compile demo files by their names \033[38;2;200;55;55m\033[1m'make _bg'\033[0m"
	@echo "\033[38;2;55;200;55m4.\033[38;2;233;233;233m Test all compiled files \033[38;2;200;55;55m\033[1m'make test'\033[0m"
	@echo "\033[38;2;55;200;55m5.\033[38;2;233;233;233m Delete all compiled files \033[38;2;200;55;55m\033[1m'make clean'\033[0m"
	@echo ""

compile: $(_all)
	@$(CC) $(ANSI) $(_color) -o _color
	@$(CC) $(ANSI) $(_general) -o _general
	@$(CC) $(ANSI) $(_bg) -o _bg
	@$(CC) $(ANSI) $(_frame) -o _frame
	@$(CC) $(ANSI) $(_label) -o _label
	@$(CC) $(ANSI) $(_line) -o _line
	@$(CC) $(ANSI) $(_progress) -o _progress
	@$(CC) $(ANSI) $(_notification) -o _notification
	@$(CC) $(ANSI) $(_timer) -o _timer
	
	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------ \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mAll\033[0m\033[38;2;233;233;233m demo files compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------ \033[38;2;55;200;55m] "
	@echo "\033[0m"

_color: $(_color)
	@$(CC) $(ANSI) $(_color) -o _color

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mColor\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_general: $(_general)
	@$(CC) $(ANSI) $(_general) -o _general

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m --------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mGeneral\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m --------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_bg: $(_bg)
	@$(CC) $(ANSI) $(_bg) -o _bg

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ---------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mBg\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ---------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_frame: $(_frame)
	@$(CC) $(ANSI) $(_frame) -o _frame

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mFrame\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_label: $(_label)
	@$(CC) $(ANSI) $(_label) -o _label

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mLabel\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_line: $(_line)
	@$(CC) $(ANSI) $(_line) -o _line

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------ \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mLine\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------ \033[38;2;55;200;55m] "
	@echo "\033[0m"

_progress: $(_progress)
	@$(CC) $(ANSI) $(_progress) -o _progress

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ---------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mProgress\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ---------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_notification: $(_notification)
	@$(CC) $(ANSI) $(_notification) -o _notification

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m -------------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mNotification\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m -------------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

_timer: $(_timer)
	@$(CC) $(ANSI) $(_timer) -o _timer

	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mTimer\033[0m\033[38;2;233;233;233m demo file compiled! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m ------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

test:
	@./_color
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing]"
	@sleep 5
	@echo "\033[0m"
	
	@./_general
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing.]"
	@sleep 5
	@echo "\033[0m"

	@./_bg
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing..]"
	@sleep 5
	@echo "\033[0m"

	@./_frame
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing...]"
	@sleep 5
	@echo "\033[0m"

	@./_label
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing....]"
	@sleep 5
	@echo "\033[0m"

	@./_line
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing.....]"
	@sleep 5
	@echo "\033[0m"

	@./_progress
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing......]"
	@sleep 5
	@echo "\033[0m"
	@clear

	@./_notification
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing.......]"
	@sleep 5
	@echo "\033[0m"
	@clear

	@./_timer
	@clear

	@echo "\033[38;2;55;200;55m"
	@echo "[...Test completed...]"
	@echo "\033[0m"

clean:
	@rm _*
	@echo ""
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m -------------------------------- \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[ \033[38;2;200;55;55m\033[4mAll\033[0m\033[38;2;233;233;233m compiled demo files cleaned! \033[38;2;55;200;55m] "
	@echo "\t\033[38;2;55;200;55m[\033[38;2;55;55;200m -------------------------------- \033[38;2;55;200;55m] "
	@echo "\033[0m"

# MADE BY @hanilr #