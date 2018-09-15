EXEC=utilc
SRC_DIR=src/
BUILD_DIR=build/
SRC=$(notdir $(wildcard $(SRC_DIR)*.c))
OBJ=$(addprefix $(BUILD_DIR), $(SRC:.c=.o))
H=$(wildcard $(SRC_DIR)*.h)
CFLAGS=-fPIC -O2 -Wall -Wextra -ansi
LIBS=

all:testBuild lib
testBuild:
	@if [ -d $(BUILD_DIR) ];	then	echo;else mkdir $(BUILD_DIR);	fi;
$(EXEC):$(OBJ)
	@echo "\e[1;32mLinking ..."
	@gcc $(OBJ) -o $(EXEC) $(LIBS)
	@echo "\e[1;35mEnd of compilation"
	@echo "\e[0;37m"
$(BUILD_DIR)%.o:$(SRC_DIR)%.c $(H)
	@echo "\e[0;36mCompiling $<"
	@gcc -o $@ -c $(CFLAGS) $<
lib:$(OBJ)
	gcc -shared -fPIC $^ -o lib$(EXEC).so
	sudo cp lib$(EXEC).so /usr/local/lib
	sudo mkdir -p /usr/local/include/$(EXEC)
	sudo cp $(H) /usr/local/include/$(EXEC)
clean:
	rm -rf *~* *#* $(SRC_DIR)*~* $(SRC_DIR)*#*
clear:clean
	rm -rf $(BUILD_DIR)* $(EXEC)
