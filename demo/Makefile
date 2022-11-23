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
_draw = widget/vn_draw/main.c
_shell = widget/vn_shell/main.c

_all = $(_color) $(_general) $(_bg) $(_frame) $(_label) $(_line) $(_progress)

.PHONY: run test clean 

run: $(_all)
ifeq ($(OS),Windows_NT)
	@$(CC) $(ANSI) $(_color) -o _color.exe
	@$(CC) $(ANSI) $(_general) -o _general.exe
	@$(CC) $(ANSI) $(_bg) -o _bg.exe
	@$(CC) $(ANSI) $(_frame) -o _frame.exe
	@$(CC) $(ANSI) $(_label) -o _label.exe
	@$(CC) $(ANSI) $(_line) -o _line.exe
	@$(CC) $(ANSI) $(_progress) -o _progress.exe
	@$(CC) $(ANSI) $(_notification) -o _notification.exe
	@$(CC) $(ANSI) $(_timer) -o _timer.exe
	@$(CC) $(ANSI) $(_draw) -o _draw.exe
	@$(CC) $(ANSI) $(_shell) -o _shell.exe

	@echo ""
	@echo "[Compilation successfully completed!]"
else
	@$(CC) $(ANSI) $(_color) -o _color
	@$(CC) $(ANSI) $(_general) -o _general
	@$(CC) $(ANSI) $(_bg) -o _bg
	@$(CC) $(ANSI) $(_frame) -o _frame
	@$(CC) $(ANSI) $(_label) -o _label
	@$(CC) $(ANSI) $(_line) -o _line
	@$(CC) $(ANSI) $(_progress) -o _progress
	@$(CC) $(ANSI) $(_notification) -o _notification
	@$(CC) $(ANSI) $(_timer) -o _timer
	@$(CC) $(ANSI) $(_draw) -o _draw
	@$(CC) $(ANSI) $(_shell) -o _shell

	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[Compilation successfully completed!]"
	@echo "\033[0m"
endif

test:
ifeq ($(OS),Windows_NT)
	@_color.exe
	@echo "[Testing]"
	@timeout 5

	@_general.exe
	@echo "[Testing.]"
	@timeout 5

	@_bg.exe
	@echo "[Testing..]"
	@timeout 5

	@_frame.exe
	@echo "[Testing...]"
	@timeout 5

	@_label.exe
	@echo "[Testing....]"
	@timeout 5

	@_line.exe
	@echo "[Testing.....]"
	@timeout 5

	@_progress.exe
	@echo "[Testing......]"
	@timeout 5

	@_notification.exe
	@echo "[Testing.......]"
	@timeout 5

	@_draw.exe
	@echo "[Testing........]"
	@timeout 5

	@_shell.exe
	@_timer.exe

	@cls
	@echo "[...Test completed...]"
else
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

	@./_draw
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing........]"
	@sleep 5
	@echo "\033[0m"
	@clear

	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Shell Test] Please write a shell command."
	@sleep 5
	@./_shell
	@echo "\033[38;2;55;55;200m\033[1m"
	@echo "\n[Testing.........]"
	@sleep 5
	@clear

	@./_timer
	@clear

	@echo "\033[38;2;55;200;55m"
	@echo "[...Test completed...]"
	@echo "\033[0m"
endif

clean:
ifeq ($(OS),Windows_NT)
	@del *.exe
	@echo ""
	@echo "[All test files deleted!]"
else
	@rm _*
	@echo "\033[38;2;55;200;55m"
	@echo "\033[1m\033[4m[All test files deleted!]"
	@echo "\033[0m"
endif

# MADE BY @hanilr #