#---------------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: Compila o programa
# Autor		: Wesley Marques (wesleymarques@dcc.ufmg.br)
#---------------------------------------------------------------------------
# Opções	: make all - compila o programa
#		: make run - executa o programa
#		: make clean - remove objetos e executável
#               : make valgrind - executa o valgrind
#               : make commit - realiza um commit com a mensagem "update"
#---------------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

# input do programa
INPUT = input.txt

# nome do programa
NAME = tp2.out 

# gera a lista de arquivos-fonte (todos os .cpp no diretório src)
SRCS = $(wildcard $(SRC)/*.cpp)

# gera a lista de objetos a partir dos arquivos-fonte
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

# gera o executável
EXE = $(BIN)/$(NAME)

# compila o programa
all: $(EXE)

$(EXE): $(OBJS)
	@$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp $(wildcard $(INC)/*.h)
	@$(CC) $(CFLAGS) -o $@ -c $<

# executa o programa
run: $(EXE)
	@$(EXE) < $(INPUT)

# executa o valgrind
valgrind: $(EXE)
	@valgrind --leak-check=full --show-leak-kinds=all $(EXE) < $(INPUT)

# executa um commit
commit: 
	@git add .
	@git commit -m "update"
	@git push

# remove objetos e executável
clean:
	@rm -f $(EXE) $(OBJS) gmon.out
