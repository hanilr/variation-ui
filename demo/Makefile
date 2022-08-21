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
	_all_out = color.exe general_function.exe bg.exe frame.exe label.exe progress.exe
	delete = del
else
	_all_out = color general_function bg frame label progress
	delete = rm
endif

.PHONY: win_run win_clean uni_run uni_clean 

win_run: $(_all)
	$(CC) $(ANSI) $(_color) -o color.exe
	$(CC) $(ANSI) $(_general) -o general_function.exe
	$(CC) $(ANSI) $(_bg) -o bg.exe
	$(CC) $(ANSI) $(_frame) -o frame.exe
	$(CC) $(ANSI) $(_label) -o label.exe
	$(CC) $(ANSI) $(_progress) -o progress.exe

win_clean: $(_all_out)
	$(delete) color.exe
	$(delete) general_function.exe
	$(delete) bg.exe
	$(delete) frame.exe
	$(delete) label.exe
	$(delete) progress.exe

uni_run: $(_all)
	$(CC) $(ANSI) $(_color) -o color
	$(CC) $(ANSI) $(_general) -o general_function
	$(CC) $(ANSI) $(_bg) -o bg
	$(CC) $(ANSI) $(_frame) -o frame
	$(CC) $(ANSI) $(_label) -o label
	$(CC) $(ANSI) $(_progress) -o progress

uni_clean: $(_all_out)
	$(delete) color
	$(delete) general_function
	$(delete) bg
	$(delete) frame
	$(delete) label
	$(delete) progress

# MADE BY @hanilr #
