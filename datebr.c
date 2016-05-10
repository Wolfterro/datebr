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
	int dia_semana_int;
	int mes_nome_int;
	int horario_brasileiro_int;
	
	int segundo_int;
	int minuto_int;
	int hora_int;

	char dia_semana[16];
	char mes_nome[16];
	char horario_brasileiro[32];
	
	char segundo_corrigido[4];
	char minuto_corrigido[4];
	char hora_corrigida[4];

	time_t tempo = time(NULL);
	struct tm tm_tempo = *localtime(&tempo);

	// Definindo dia da semana
	// =======================
	dia_semana_int = tm_tempo.tm_wday;
	switch(dia_semana_int) {
		case 0:
			sscanf("Domingo", "%s", dia_semana);
			break;
		case 1:
			sscanf("Segunda-Feira", "%s", dia_semana);
			break;
		case 2:
			sscanf("Terça-Feira", "%s", dia_semana);
			break;
		case 3:
			sscanf("Quarta-Feira", "%s", dia_semana);
			break;
		case 4:
			sscanf("Quinta-Feira", "%s", dia_semana);
			break;
		case 5:
			sscanf("Sexta-Feira", "%s", dia_semana);
			break;
		case 6:
			sscanf("Sábado", "%s", dia_semana);
			break;
		default:
			sscanf("N/D", "%s", dia_semana);
			break;
	}

	// Definindo mês atual
	// ===================
	mes_nome_int = tm_tempo.tm_mon;
	switch(mes_nome_int) {
		case 0:
			sscanf("Janeiro", "%s", mes_nome);
			break;
		case 1:
			sscanf("Fevereiro", "%s", mes_nome);
			break;
		case 2:
			sscanf("Março", "%s", mes_nome);
			break;
		case 3:
			sscanf("Abril", "%s", mes_nome);
			break;
		case 4:
			sscanf("Maio", "%s", mes_nome);
			break;
		case 5:
			sscanf("Junho", "%s", mes_nome);
			break;
		case 6:
			sscanf("Julho", "%s", mes_nome);
			break;
		case 7:
			sscanf("Agosto", "%s", mes_nome);
			break;
		case 8:
			sscanf("Setembro", "%s", mes_nome);
			break;
		case 9:
			sscanf("Outubro", "%s", mes_nome);
			break;
		case 10:
			sscanf("Novembro", "%s", mes_nome);
			break;
		case 11:
			sscanf("Dezembro", "%s", mes_nome);
			break;
		default:
			sscanf("N/D", "%s", mes_nome);
			break;
	}

	// Definindo tipo de horário
	// =========================
	horario_brasileiro_int = tm_tempo.tm_isdst;
	if (horario_brasileiro_int == 0) {
		sscanf("Horário Brasileiro", "%[^\n]s", horario_brasileiro);
	}
	else if (horario_brasileiro_int < 0) {
		sscanf("N/D", "%[^\n]s", horario_brasileiro);
	}
	else {
		sscanf("Horário Brasileiro de Verão", "%[^\n]s", horario_brasileiro);
	}

	// Adicionando um zero a segundos menores que 10
	// =============================================
	segundo_int = tm_tempo.tm_sec;
	if (segundo_int < 10) {
		sprintf(segundo_corrigido, "0%d", segundo_int);
	}
	else {
		sprintf(segundo_corrigido, "%d", segundo_int);
	}

	// Adicionando um zero a minutos menores que 10
	// ============================================
	minuto_int = tm_tempo.tm_min;
	if (minuto_int < 10) {
		sprintf(minuto_corrigido, "0%d", minuto_int);
	}
	else {
		sprintf(minuto_corrigido, "%d", minuto_int);
	}

	// Adicionando um zero a horas menores que 10
	// ==========================================
	hora_int = tm_tempo.tm_hour;
	if (hora_int < 10) {
		sprintf(hora_corrigida, "0%d", hora_int);
	}
	else {
		sprintf(hora_corrigida, "%d", hora_int);
	}

	// Mostrando resultados na tela
	// ============================
	if (argv[1] == NULL) {
		printf("%s, %d de %s de %d - %s:%s:%s - %s\n", dia_semana, tm_tempo.tm_mday, mes_nome, tm_tempo.tm_year + 1900, hora_corrigida, minuto_corrigido, segundo_corrigido, horario_brasileiro);
	}
	else if (0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help")) {
		help();
	}
	else if (0 == strcmp(argv[1], "-d") || 0 == strcmp(argv[1], "--date")) {
		printf("%s, %d de %s de %d\n", dia_semana, tm_tempo.tm_mday, mes_nome, tm_tempo.tm_year + 1900);
	}
	else if (0 == strcmp(argv[1], "-t") || 0 == strcmp(argv[1], "--time")) {
		printf("%s:%s:%s\n", hora_corrigida, minuto_corrigido, segundo_corrigido);
	}
	else if (0 == strcmp(argv[1], "-dst") || 0 == strcmp(argv[1], "--daylight-saving-time")) {
		printf("%s\n", horario_brasileiro);
	}
	else {
		printf("Argumento desconhecido! Use -h ou --help para ajuda!\n");
	}

	return 0;
}