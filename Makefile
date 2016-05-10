SRC = datebr.c
CC = cc
BIN = datebr
INSTALLPATH = /usr/local/bin/
CFLAGS = -Wall

datebr : ${SRC}

	@echo "Compilando ${SRC}"
	@echo "CC ${CFLAGS} ${LDFLAGS} ${SRC}"
	@${CC} ${CFLAGS} ${LDFLAGS} ${SRC} -o ${BIN}

install : ${BIN}

	@echo "Instalando binário em ${INSTALLPATH}${BIN}"
	@cp ${BIN} ${INSTALLPATH}
	@chmod 755 ${INSTALLPATH}${BIN}
	@echo "Instalado"

uninstall :

	@echo "Desinstalando binário (${INSTALLPATH}${BIN})"
	@rm -f ${INSTALLPATH}${BIN}
	@echo "${BIN} desinstalado"

clean :

	@echo "Limpando ${BIN}"
	@rm ${BIN}
	@echo "${BIN} limpo"

