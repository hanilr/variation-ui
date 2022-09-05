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
_progress = widget/vn_progress/main.c

_all = $(_color) $(_general) $(_bg) $(_frame) $(label) $(_progress)

ifeq ($(OS),Windows_NT)
	delete = del
else
	delete = rm
endif

.PHONY: win_run win_clean uni_run uni_clean 

win_run: $(_all)
	$(CC) $(ANSI) $(_color) -o _color.exe
	$(CC) $(ANSI) $(_general) -o _general.exe
	$(CC) $(ANSI) $(_bg) -o _bg.exe
	$(CC) $(ANSI) $(_frame) -o _frame.exe
	$(CC) $(ANSI) $(_label) -o _label.exe
	$(CC) $(ANSI) $(_progress) -o _progress.exe

win_clean: _color.exe _general.exe _bg.exe _frame.exe _label.exe _progress.exe
	$(delete) *.exe

uni_run: $(_all)
	$(CC) $(ANSI) $(_color) -o _color
	$(CC) $(ANSI) $(_general) -o _general
	$(CC) $(ANSI) $(_bg) -o _bg
	$(CC) $(ANSI) $(_frame) -o _frame
	$(CC) $(ANSI) $(_label) -o _label
	$(CC) $(ANSI) $(_progress) -o _progress

uni_clean: _color _general _bg _frame _label _progress
	$(delete) _*

# MADE BY @hanilr #