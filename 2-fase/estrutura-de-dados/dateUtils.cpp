#include <stdio.h>
#include <time.h>

// Helpers internos para suporte às operações
static struct tm criarData(int ano, int mes, int dia) {
    struct tm d = {0};
    d.tm_year = ano - 1900;
    d.tm_mon = mes - 1;
    d.tm_mday = dia;
    d.tm_isdst = -1;
    mktime(&d);
    return d;
}

static struct tm addDaysToDate(struct tm d, int dias) {
    d.tm_mday += dias;
    mktime(&d);
    return d;
}

static int datasIguais(struct tm d1, struct tm d2) {
    return (d1.tm_year == d2.tm_year && 
            d1.tm_mon == d2.tm_mon && 
            d1.tm_mday == d2.tm_mday);
}

// 1. Calcula o domingo de Páscoa
struct tm pascoaDay(int year) {
    const int X = 24;
    const int Y = 5;
    
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = ((19 * a) + X) % 30;
    int e = ((2 * b) + (4 * c) + (6 * d) + Y) % 7;

    int dia, mes;
    if ((d + e) < 10) {
        dia = d + e + 22;
        mes = 3;
    } else {
        dia = d + e - 9;
        mes = 4;
    }
    return criarData(year, mes, dia);
}

// 2. Verifica se a data é feriado no Brasil (1 = Sim, 0 = Não)
int isHolidaysBrazil(struct tm d) {
    int year = d.tm_year + 1900;
    struct tm pascoa = pascoaDay(year);
    
    struct tm feriados[14];
    feriados[0] = pascoa;
    feriados[1] = addDaysToDate(pascoa, -2);  // Sexta-feira Santa
    feriados[2] = addDaysToDate(pascoa, -47); // Carnaval
    feriados[3] = addDaysToDate(pascoa, 60);  // Corpus Christi
    feriados[4] = addDaysToDate(pascoa, 50);  // Pentecostes
    
    // Feriados fixos
    feriados[5]  = criarData(year, 1, 1);
    feriados[6]  = criarData(year, 4, 21);
    feriados[7]  = criarData(year, 5, 1);
    feriados[8]  = criarData(year, 9, 7);
    feriados[9]  = criarData(year, 10, 12);
    feriados[10] = criarData(year, 11, 2);
    feriados[11] = criarData(year, 11, 15);
    feriados[12] = criarData(year, 12, 25);
    feriados[13] = criarData(year, 12, 31);

    for (int i = 0; i < 14; i++) {
        if (datasIguais(d, feriados[i])) {
            return 1;
        }
    }
    return 0;
}

// 3. Verifica se a data é dia útil (1 = Sim, 0 = Não)
int isWorkingDay(struct tm d) {
    if (isHolidaysBrazil(d)) {
        return 0;
    }
    return (d.tm_wday > 0 && d.tm_wday < 6);
}