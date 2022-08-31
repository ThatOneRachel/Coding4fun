#define LINHAS 20
#define COLUNAS 25
void carrega_mapa(char mapa[LINHAS][COLUNAS], int *linhas, int *colunas) {
    strcpy(mapa[0], "XXXXXXXXXX");
    strcpy(mapa[1], "X1 C  C2 X");
    strcpy(mapa[2], "XXHX  XX X");
    strcpy(mapa[3], "XCH    1 X");
    strcpy(mapa[4], "XXX HXHX X");
    strcpy(mapa[5], "X   H H  X");
    strcpy(mapa[6], "X  DH HC2X");
    strcpy(mapa[7], "X HXX XXXX");
    strcpy(mapa[8], "X H X   PX");
    strcpy(mapa[9], "XXXXXXXXXX");
    *linhas = 10;
    *colunas = 10;
}

