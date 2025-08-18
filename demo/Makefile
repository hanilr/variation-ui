# ---------------------------------------------------- #
# SINGLE-HEADER TERMINAL USER INTERFACE | VARIATION-UI #
#      VARIATION-UI-WIDGET LIBRARY DEMO MAKEFILE       #
# ---------------------------------------------------- #

CC = gcc
lib = ../vn_ui.h
demo = main.c

ifdef OS
	out = .exe
	rm = cmd /c del /F /Q
else
   	UNAME_S := $(shell uname -s)
   	ifeq ($(shell uname), Linux)
    	out = 
		rm = rm -f
		unix = ./
   	endif
endif

.PHONY: help compile clean

help:
	@echo ""
	@echo "[ Make List ]"
	@echo " 1. Show make list 'make' or 'make help'"
	@echo " 2. Compile and run 'make compile'"
	@echo " 3. Clean compiled file 'make clean'"
	@echo ""

compile: $(lib)
	@$(CC) $(demo) -o main$(out)
	@$(unix)main$(out)

	@echo ""
	@echo "[ ----------------------------------- ] "
	@echo "[ Successfully compiled and executed! ] "
	@echo "[ ----------------------------------- ] "
	@echo ""

clean:
	@$(rm) main$(out)

	@echo ""
	@echo "[ ---------------------- ] "
	@echo "[ Compiled file deleted! ] "
	@echo "[ ---------------------- ] "
	@echo ""

# MADE BY @hanilr #