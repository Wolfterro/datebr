/*
* The MIT License (MIT)
* 
* Copyright (c) 2016 Wolfgang Almeida <wolfgang.almeida@yahoo.com>
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Método: Menu de Ajuda
// =====================
void help() {

	printf("datebr: Hora e Data em Formato Padrão do Brasil\n");
	printf("-----------------------------------------------\n");
	printf("Uso: datebr [Argumento]\n\n");

	printf("Argumentos:\n");
	printf("-----------\n");
	printf("  -h   || --help\t\t\tMostra esta tela de ajuda\n");
	printf("  -d   || --date\t\t\tMostra apenas a data atual\n");
	printf("  -t   || --time\t\t\tMostra apenas o horário atual\n");
	printf("  -dst || --daylight-saving-time\tMostra apenas o tipo de horário atual\n");

	return;
}

// Método: O programa
// ==================
int main(int argc, char * argv[]) {

	// Declarações de variáveis
	// ========================
	char * dia_semana[6];
	char * mes_nome[11];
	char * horario_brasileiro[1];
	
	char segundo_corrigido[4];
	char minuto_corrigido[4];
	char hora_corrigida[4];

	time_t tempo = time(NULL);
	struct tm tm_tempo = *localtime(&tempo);

	// Definindo dia da semana
	// =======================
	dia_semana[0] = "Domingo";
	dia_semana[1] = "Segunda-Feira";
	dia_semana[2] = "Terça-Feira";
	dia_semana[3] = "Quarta-Feira";
	dia_semana[4] = "Quinta-Feira";
	dia_semana[5] = "Sexta-Feira";
	dia_semana[6] = "Sábado";
	
	// Definindo mês atual
	// ===================
	mes_nome[0] = "Janeiro";
	mes_nome[1] = "Fevereiro";
	mes_nome[2] = "Março";
	mes_nome[3] = "Abril";
	mes_nome[4] = "Maio";
	mes_nome[5] = "Junho";
	mes_nome[6] = "Julho";
	mes_nome[7] = "Agosto";
	mes_nome[8] = "Setembro";
	mes_nome[9] = "Outubro";
	mes_nome[10] = "Novembro";
	mes_nome[11] = "Dezembro";
	
	// Definindo tipo de horário
	// =========================
	horario_brasileiro[0] = "Horário Brasileiro";
	horario_brasileiro[1] = "Horário Brasileiro de Verão";
	
	// Adicionando um zero a segundos menores que 10
	// =============================================
	if (tm_tempo.tm_sec < 10) {
		sprintf(segundo_corrigido, "0%d", tm_tempo.tm_sec);
	}
	else {
		sprintf(segundo_corrigido, "%d", tm_tempo.tm_sec);
	}

	// Adicionando um zero a minutos menores que 10
	// ============================================
	if (tm_tempo.tm_min < 10) {
		sprintf(minuto_corrigido, "0%d", tm_tempo.tm_min);
	}
	else {
		sprintf(minuto_corrigido, "%d", tm_tempo.tm_min);
	}

	// Adicionando um zero a horas menores que 10
	// ==========================================
	if (tm_tempo.tm_hour < 10) {
		sprintf(hora_corrigida, "0%d", tm_tempo.tm_hour);
	}
	else {
		sprintf(hora_corrigida, "%d", tm_tempo.tm_hour);
	}

	// Mostrando resultados na tela
	// ============================
	if (argv[1] == NULL) {
		printf("%s, %d de %s de %d - %s:%s:%s - %s\n", dia_semana[tm_tempo.tm_wday], tm_tempo.tm_mday, mes_nome[tm_tempo.tm_mon], tm_tempo.tm_year + 1900, hora_corrigida, minuto_corrigido, segundo_corrigido, horario_brasileiro[tm_tempo.tm_isdst]);
	}
	else if (0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help")) {
		help();
	}
	else if (0 == strcmp(argv[1], "-d") || 0 == strcmp(argv[1], "--date")) {
		printf("%s, %d de %s de %d\n", dia_semana[tm_tempo.tm_wday], tm_tempo.tm_mday, mes_nome[tm_tempo.tm_mon], tm_tempo.tm_year + 1900);
	}
	else if (0 == strcmp(argv[1], "-t") || 0 == strcmp(argv[1], "--time")) {
		printf("%s:%s:%s\n", hora_corrigida, minuto_corrigido, segundo_corrigido);
	}
	else if (0 == strcmp(argv[1], "-dst") || 0 == strcmp(argv[1], "--daylight-saving-time")) {
		printf("%s\n", horario_brasileiro[tm_tempo.tm_isdst]);
	}
	else {
		printf("Argumento desconhecido! Use -h ou --help para ajuda!\n");
	}

	return 0;
}