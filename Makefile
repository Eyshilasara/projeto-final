CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=locadora

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
RM = -del

./${TARGET}: ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/ArquivoClientes.o  ${BUILD_DIR}/Gerenciador_de_arquivos.o ${BUILD_DIR}/controle_locacao.o ${BUILD_DIR}/cadastroMidia.o ${BUILD_DIR}/disco.o ${BUILD_DIR}/dvd.o ${BUILD_DIR}/filme.o ${BUILD_DIR}/fitaVideo.o ${BUILD_DIR}/jogo.o ${BUILD_DIR}/midia.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ./${TARGET}

${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o $@

${BUILD_DIR}/main.o:  ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Rule for cleaning files generated during compilation.

clean:
	$(RM) /Q /F $(BUILD_DIR)/*.o
	$(RM) /Q /F $(TARGET).exe