# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#      VARIATION-UI-WIDGET LIBRARY TEST MAKEFILE       #
# ---------------------------------------------------- #

CC = gcc
lib = ../../lib/vn_ui_widget.h
background = background/main.c
frame = frame/main.c
label = label/main.c
line = line/main.c
notification = notification/main.c
progress = progress/main.c

ifdef OS
   	out = .exe
	rm = cmd /c del /F /Q
	wait = powershell -Command "Start-Sleep -Seconds 1"
else
   	UNAME_S := $(shell uname -s)
   	ifeq ($(shell uname), Linux)
      out = 
	  unix = ./
	  rm = rm -f
	  wait = sleep 1
   	endif
endif

.PHONY: help compile clean background frame label line notification progress

help:
	@echo ""
	@echo "[ Make List ]"
	@echo " 1. Show make list 'make' or 'make help'"
	@echo " 2. Compile all files and run 'make compile'"
	@echo " 3. Clean all compiled files 'make clean'"
	@echo " 4. Only compile background and run 'make background'"
	@echo " 5. Only compile frame and run 'make frame'"
	@echo " 6. Only compile label and run 'make label'"
	@echo " 7. Only compile line and run 'make line'"
	@echo " 8. Only compile notification and run 'make notification'"
	@echo " 9. Only compile progress and run 'make progress'"
	@echo ""

compile: $(lib)
	@$(CC) $(background) -o background$(out)
	@$(CC) $(frame) -o frame$(out)
	@$(CC) $(label) -o label$(out)
	@$(CC) $(line) -o line$(out)
	@$(CC) $(notification) -o notification$(out)
	@$(CC) $(progress) -o progress$(out)

	@echo ""
	@echo "[ ------------------- ] "
	@echo "[ All files compiled! ] "
	@echo "[ ------------------- ] "
	@echo ""

	@$(unix)background$(out)
	@$(wait)
	@$(unix)frame$(out)
	@$(wait)
	@$(unix)label$(out)
	@$(wait)
	@$(unix)line$(out)
	@$(wait)
	@$(unix)notification$(out)
	@$(wait)
	@$(unix)progress$(out)
	@$(wait)

	@echo ""
	@echo "[ ---------------------------- ] "
	@echo "[ All compiled files executed! ] "
	@echo "[ ---------------------------- ] "
	@echo ""

clean:
	@$(rm) background$(out)
	@$(rm) frame$(out)
	@$(rm) label$(out)
	@$(rm) line$(out)
	@$(rm) notification$(out)
	@$(rm) progress$(out)

	@echo ""
	@echo "[ --------------------------- ] "
	@echo "[ All compiled files deleted! ] "
	@echo "[ --------------------------- ] "
	@echo ""

background: $(lib)
	@$(CC) $(background) -o background$(out)
	@$(unix)background$(out)
	@$(wait)

	@echo ""
	@echo "[ ----------------------------------------- ] "
	@echo "[ Background feature compiled and executed! ] "
	@echo "[ ----------------------------------------- ] "
	@echo ""

frame: $(lib)
	@$(CC) $(frame) -o frame$(out)
	@$(unix)frame$(out)
	@$(wait)

	@echo ""
	@echo "[ ------------------------------------ ] "
	@echo "[ Frame feature compiled and executed! ] "
	@echo "[ ------------------------------------ ] "
	@echo ""

label: $(lib)
	@$(CC) $(label) -o label$(out)
	@$(unix)label$(out)
	@$(wait)

	@echo ""
	@echo "[ ------------------------------------ ] "
	@echo "[ Label feature compiled and executed! ] "
	@echo "[ ------------------------------------ ] "
	@echo ""

line: $(lib)
	@$(CC) $(line) -o line$(out)
	@$(unix)line$(out)
	@$(wait)

	@echo ""
	@echo "[ ----------------------------------- ] "
	@echo "[ Line feature compiled and executed! ] "
	@echo "[ ----------------------------------- ] "
	@echo ""

notification: $(lib)
	@$(CC) $(notification) -o notification$(out)
	@$(unix)notification$(out)
	@$(wait)

	@echo ""
	@echo "[ ------------------------------------------- ] "
	@echo "[ Notification feature compiled and executed! ] "
	@echo "[ ------------------------------------------- ] "
	@echo ""

progress: $(lib)
	@$(CC) $(progress) -o progress$(out)
	@$(unix)progress$(out)
	@$(wait)

	@echo ""
	@echo "[ --------------------------------------- ] "
	@echo "[ Progress feature compiled and executed! ] "
	@echo "[ --------------------------------------- ] "
	@echo ""

# MADE BY @hanilr #