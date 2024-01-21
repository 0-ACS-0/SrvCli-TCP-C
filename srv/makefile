############################################
###General compiling makefile #############
###	Author: Antonio Carretero Sahuquillo ###
############################################

#Variables
CC = gcc
CFLAGS = -Wall -I $(INCD)

TRG = server

SRCD = src/
SRC = $(SRCD)server.c $(SRCD)srv_handle.c $(SRCD)cli_handle.c

INCD = inc/
INC = $(INCD)server.h $(INCD)srv_handle.h $(INCD)cli_handle.h

OBJD = obj/
OBJ = $(OBJD)server.o $(OBJD)srv_handle.o $(OBJD)cli_handle.o

BIND = bin/

#Tasks
target: $(TRG)

$(TRG): $(OBJ)
	@echo
	@echo [BIN-BUILD]: Generating binarie...
	@echo [BIN-BUILD]: Creating binarie directory...
	@mkdir -p $(BIND)
	@echo [BIN-BUILD]: Ensambling and linking objects...
	@$(CC) $(CFLAGS) $(OBJ) -o $(BIND)$(TRG).exe
	@echo [BIN-BUILD]: Binarie $@ finished!
	@echo

$(OBJD)%.o: $(SRCD)%.c
	@echo
	@echo [OBJ-BUILD]: Generating object...
	@echo [OBJ-BUILD]: Creating objects directory...
	@mkdir -p $(OBJD)
	@echo [OBJ-BUILD]: Compiling source...
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo [OBJ-BUILD]: Object $@ generated!

#Clean task
.PHONY: clean
clean:
	@echo
	@echo [CLEAN]: Cleaning workspace...
	@echo [CLEAN]: Removing obj/ directory and objects...
	@rm -rf $(OBJD)
	@echo [CLEAN]: Removing bin/ directory and binaries...
	@rm -rf $(BIND)
	@echo [CLEAN]: Workspace clean!
	@echo
