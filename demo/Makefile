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

.PHONY: run clean 

run: $(_all)
ifeq ($(OS),Windows_NT)
	$(CC) $(ANSI) $(_color) -o _color.exe
	$(CC) $(ANSI) $(_general) -o _general.exe
	$(CC) $(ANSI) $(_bg) -o _bg.exe
	$(CC) $(ANSI) $(_frame) -o _frame.exe
	$(CC) $(ANSI) $(_label) -o _label.exe
	$(CC) $(ANSI) $(_progress) -o _progress.exe	
else
	$(CC) $(ANSI) $(_color) -o _color
	$(CC) $(ANSI) $(_general) -o _general
	$(CC) $(ANSI) $(_bg) -o _bg
	$(CC) $(ANSI) $(_frame) -o _frame
	$(CC) $(ANSI) $(_label) -o _label
	$(CC) $(ANSI) $(_progress) -o _progress	
endif

clean:
ifeq ($(OS),Windows_NT)
	del *.exe
else
	rm _*
endif

# MADE BY @hanilr #