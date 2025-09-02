# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#       VARIATION-UI-BASE LIBRARY TEST MAKEFILE        #
# ---------------------------------------------------- #

CC = gcc
lib = ../../lib/vn_ui_base.h
code = code/main.c
color = color/main.c
print =  print/main.c

ifdef OS
   	out = .exe
	rm = cmd /c del /F /Q
else
   	UNAME_S := $(shell uname -s)
   	ifeq ($(shell uname), Linux)
      out = 
	  unix = ./
	  rm = rm -f
   	endif
endif

.PHONY: help compile clean code color print

help:
	@echo ""
	@echo "[ Make List ]"
	@echo " 1. Show make list 'make' or 'make help'"
	@echo " 2. Compile all files and run 'make compile'"
	@echo " 3. Clean all compiled files 'make clean'"
	@echo " 4. Only compile code and run 'make code'"
	@echo " 5. Only compile color and run 'make color'"
	@echo " 6. Only compile print and run 'make print'"
	@echo ""

compile: $(lib)
	@$(CC) $(code) -o t_code$(out)
	@$(CC) $(color) -o t_color$(out)
	@$(CC) $(print) -o t_print$(out)

	@echo ""
	@echo "[ ------------------- ] "
	@echo "[ All files compiled! ] "
	@echo "[ ------------------- ] "
	@echo ""

	@$(unix)t_code$(out)
	@$(unix)t_color$(out)
	@$(unix)t_print$(out)

	@echo ""
	@echo "[ ---------------------------- ] "
	@echo "[ All compiled files executed! ] "
	@echo "[ ---------------------------- ] "
	@echo ""

clean:
	@$(rm) t_code$(out)
	@$(rm) t_color$(out)
	@$(rm) t_print$(out)

	@echo ""
	@echo "[ --------------------------- ] "
	@echo "[ All compiled files deleted! ] "
	@echo "[ --------------------------- ] "
	@echo ""

code: $(lib)
	@$(CC) $(code) -o t_code$(out)
	@$(unix)t_code$(out)

	@echo ""
	@echo "[ ----------------------------------- ] "
	@echo "[ Code feature compiled and executed! ] "
	@echo "[ ----------------------------------- ] "
	@echo ""

color: $(lib)
	@$(CC) $(color) -o t_color$(out)
	@$(unix)t_color$(out)

	@echo ""
	@echo "[ ------------------------------------ ] "
	@echo "[ Color feature compiled and executed! ] "
	@echo "[ ------------------------------------ ] "
	@echo ""

print: $(lib)
	@$(CC) $(print) -o t_print$(out)
	@$(unix)t_print$(out)

	@echo ""
	@echo "[ ------------------------------------ ] "
	@echo "[ Print feature compiled and executed! ] "
	@echo "[ ------------------------------------ ] "
	@echo ""

# MADE BY @hanilr #
