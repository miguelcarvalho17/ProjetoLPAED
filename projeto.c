#include "projeto.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int id_edificio = 1;
int id_estudio = 1;
int id_agenda = 1;
int id_evento = 1;
int id_estadia = 1;


int main_projeto(int argc, const char *argv[]) {

    char agendasbin[] = "C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\agendasbin.txt";

    char fname[] = "C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\edificiosbin.txt";

    LISTAEDIFICIOS *e = create_lista_edificio();

    LISTAHOSPEDES *h = create_lista_hospedes();

    LISTAHISTORICOESTADIAS *he = create_lista_historico_estadias();

    PLATAFORMAS_ARRAY *pa = create_dyn_array_plataformas(4);

    REGRAS_ARRAY *ra = create_dyn_array_regras(10);

    char politica[] = "p1";

    insert_plataforma(pa, "Master", politica);
    insert_plataforma(pa, "Airbnb", politica);

    /** Criação dos edificios e seus estudios */

    insert_edificio(e, "PF Maia", 41.162392, -8.655714, "Avenida da Maia", 1.5, 5);

    insert_estudio(e, 1, 1, "t2", 50, 30, 600, 4);   // 2 ESTUDIOS PARA O PRIMEIRO EDIFICIO
    insert_estudio(e, 1, 2, "t3", 50, 60, 600, 4);

    insert_agenda(e, 1, 1, "MASTER", 7); // 2 AGENDAS PARA O PRIMEIRO ESTUDIO DO PRIMEIRO EDIFICIO
    insert_dia(e, 1, 1, 1, 1, 1, 2021);
    insert_dia(e, 1, 1, 1, 2, 1, 2021);

    insert_agenda(e, 1, 1, "AIRBNB", 7);
    insert_dia(e, 1, 1, 2, 3, 1, 2021);

    insert_agenda(e, 1, 2, "MASTER", 7); // 2 AGENDAS PARA O SEGUNDO ESTUDIO DO PRIMEIRO EDIFICIO
    insert_agenda(e, 1, 2, "AIRBNB", 7);

    insert_dia(e, 1, 2, 3, 4, 1, 2021);
    insert_dia(e, 1, 2, 4, 5, 1, 2021);


    DIAS data = {10, 1, 2021};
    insert_evento(e, "Limpeza", data, -1, 1, 1, 1, 2021);
    insert_evento(e, "Hospede", data, 1, 1, 1, 1, 2021);
    insert_evento(e, "Hospede", data, 2, 1, 2, 1, 2021);
    insert_evento(e, "Hospede", data, 3, 2, 3, 1, 2021);


    insert_evento(e, "Limpeza", data, -1, 3, 4, 1, 2021);
    insert_evento(e, "Hospede", data, 4, 3, 4, 1, 2021);
    insert_evento(e, "Hospede", data, 5, 3, 4, 1, 2021);
    insert_evento(e, "Hospede", data, 6, 4, 5, 1, 2021);

    DIAS datafim = {10, 1, 2021};
    DIAS dataf = {15, 1, 2021};


    insert_edificio(e, "PF Boavista", 41.162392, -8.655714, "Avenida da Boavista", 1.5, 5);
    insert_estudio(e,2,1,"T1", 100, 20, 400, 4);
    insert_estudio(e,2,2,"T2", 200, 40, 600,4);

    insert_agenda(e, 2, 3, "MASTER", 7);
    insert_dia(e, 2, 3, 5, 1, 1, 2021);

    DIAS d = {10, 1, 2021};
    insert_evento(e, "Limpeza", d, -1, 5, 1, 1, 2021);

    insert_dia(e, 2, 3, 5, 2, 1, 2021);

    insert_evento(e, "Hospede", d, 7, 5, 2, 1, 2021);

    insert_agenda(e, 2, 3, "AIRBNB", 7);
    insert_dia(e, 1, 3, 6, 3, 1, 2021);
    insert_evento(e, "Hospede", d, 8, 6, 3, 1, 2021);

    insert_agenda(e, 2, 4, "MASTER", 7);
    insert_dia(e, 2, 4, 7, 9, 1, 2021);
    insert_evento(e, "Hospede", d, 9, 7, 9, 1, 2021);

    /** Remove edificio */
    //remove_edificio(e, "PF Boavista");

    /** Edit edificio */
    //edit_edificio(e, 1, "Ribeira", 41.162392, -8.655714, "Ribeira", 1.5, 3);

    /** FIND ESTUDIO */
     //ESTUDIO *printestudio = find_estudio_dynarray_arrayestudios(e, 5);
     //printf("%d, %d, %s, %d\n", printestudio->id_estudio, printestudio->numero, printestudio->configuracao,
     //       printestudio->area);

    /** EDIT ESTUDIO */
    //edit_estudio(e,3,31,"T10",150,50, 950);

    /** Remove estudio */
    //remove_estudio_dynarray_arrayestudios(e,2,3);

    /** EDIT EVENTOS */
    //edit_evento(e,2,4,"Obras", d,-1);

    /** Imprimir lista */
    //print_listaEdificio(e);

    /** FIND EVENTOS */
    //EVENTO *fevento = find_evento(e,1,3);
    //printf("%s\n", fevento->tipo);

    /** Inserir hospedes */
    //insert_hospede(e, h, "Paulo", 1, 2, 1);
    //insert_hospede(e, h, "Daniel", 1, 3, 2);

    /** Remover hospedes */
    //remove_hospede(e,h,1,3,2);

    /** Editar hospedes */
    //edit_hospede(h,2,"Miguel");

    /** Imprimir hospedes */
    //print_listaHospedes(h);

    /** Inserir historico hospedes */
    //insert_historicoEstadias(e, h, he, "Paulo", 1, 1, 1, 1, 2021, 2, 1);
    //insert_historicoEstadias(e, h, he, "Daniel", 1, 1, 2, 1, 2021, 3, 2);

    /** Imprimir historico clientes */
    //print_listaHistorico(he);

    /** Escrever edificios e estudios txt */
    //escrever_edificios(e);

    /** Ler edificios e estudios txt */
    //read_edificios_txt(e);

    /** Escrever edificios e estudios bin */
    //escrever_edificios_bin(e, fname);

    /** Ler edificios e estudios bin */
    //ler_edificios_bin(e, fname);

    /** Inserir regra */
    //insert_regra(ra,1,"p1", 0.3);

    /** Escrever agenda txt */
    //escrever_agenda_txt(e, 1);
    //escrever_agenda_txt(e, 2);

    /** Ler agenda txt          VER   */
    //read_agenda_txt(e, 1, 1);

    /** Escrever agenda bin */
    //escrever_agenda_bin(e,agendasbin,1);

    /** Ler agenda bin */
    //read_agenda_bin(e,agendasbin, 1, 1);

    /** Escrever taxa ocupação edificio */
    //printf("Taxa de ocupacao do edificio: %.2f %% \n", get_studio_occupancy(e, 1, get_timestamp(1, 1, 2021), get_timestamp(15, 1, 2021)));

    /** Escrever taxa ocupação parque */
    //printf("Taxa total de ocupacao: %.2f %%", get_total_estudios_occupancy(e,get_timestamp(1, 1, 2021), get_timestamp(15, 1, 2021)));

    /** Escrever hospedes txt */
    //escrever_hospedes_txt(h);

    /** Find dia */
    //DIAS *p = find_dia_dynarray_arraydias(e, 1, 1, 1, 2021);
    //printf("%d", p->ano);

    /** Escrever historico estadias */
    //escrever_historico_estadias(he);

    /** Ler historico estadias */
    //read_historico_txt(e,h,he,1,1,2,1);

    return 0;
}

///----------------------------------------------------------EDIFICIOS--------------------------------------------------------------------------

LISTAEDIFICIOS *create_lista_edificio() {
    LISTAEDIFICIOS *le = (LISTAEDIFICIOS *) calloc(1, sizeof(LISTAEDIFICIOS));
    le->pedificios = NULL;

    return le;
}

void insert_edificio(LISTAEDIFICIOS *pg, char nome[MAX200], double latitude, double longitude,
                     char morada[MAX200], double preco_m2, int size_estudios) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    EDIFICIO *s = (EDIFICIO *) malloc(sizeof(EDIFICIO));
    s->id_edificio = id_edificio++;
    strcpy(s->nome, nome);
    s->latitude = latitude;
    s->longitude = longitude;
    strcpy(s->morada, morada);
    s->preco_m2 = preco_m2;
    ESTUDIO_ARRAY *estudiosarray = create_dynarray_array_estudios(size_estudios);
    s->array_estudios = *estudiosarray;
    s->next = NULL;

    EDIFICIO *pant = NULL, *pcurrent = pg->pedificios;
    while (pcurrent != NULL && id_edificio > pcurrent->id_edificio) {
        pant = pcurrent;
        pcurrent = pcurrent->next;
    }
    //INSERÇAO A CABEÇA
    if (pcurrent == pg->pedificios) {
        s->next = pg->pedificios;
        pg->pedificios = s;
        pg->num_edificios++;
        return;
    }
    //INSERÇÃO A MEIO OU NO FIM
    s->next = pcurrent;
    pant->next = s;
    pg->num_edificios++;
}

void edit_edificio(LISTAEDIFICIOS *pg, int id_edificio, char nome[MAX200], double latitude, double longitude,
                   char morada[MAX200], double preco_m2, int size_estudios) {
    EDIFICIO *pe = find_edificio(pg, id_edificio);
    if (pe != NULL) {
        pe->id_edificio = id_edificio;
        strcpy(pe->nome, nome);
        pe->latitude = latitude;
        pe->longitude = longitude;
        strcpy(pe->morada, morada);
        pe->preco_m2 = preco_m2;
        pe->array_estudios.size_estudios = size_estudios;
    }
}

EDIFICIO *find_edificio(LISTAEDIFICIOS *pg, int id) {

    EDIFICIO *pst = pg->pedificios;
    while (pst != NULL) {
        if (pst->id_edificio == id) {
            return pst;
        }
        pst = pst->next;
    }
    return NULL;
}

void remove_edificio(LISTAEDIFICIOS *pg, char name[]) {
    //NAO REMOVEMOS NADA SE A LISTA ESTIVER VAZIA
    if (pg->pedificios == NULL) {
        printf("Esse edificio nao existe.");
        return;
    }
    EDIFICIO *pant = NULL, *pcurrent = pg->pedificios;
    while (pcurrent != NULL && strcmp(name, pcurrent->nome) != 0) {
        pant = pcurrent;
        pcurrent = pcurrent->next;
    }
    //SE O NOME NAO EXISTIR
    if (pcurrent == NULL) {
        return;
    }
    //REMOÇÃO A CABEÇA
    if (pcurrent == pg->pedificios) {
        pg->pedificios = pcurrent->next;
        pg->num_edificios--;
        free(pcurrent);
        return;
    }
    pant->next = pcurrent->next;
    free(pcurrent);
    //DECREMENTAR O NUMERO DE EDIFICIOS
    pg->num_edificios--;
}

void write_string(FILE *fp, const char *str) {
    int str_len = strlen(str) + 1;
    fwrite(&str_len, sizeof(unsigned int), 1, fp);
    fwrite(str, sizeof(char), str_len, fp);
}

void read_string(FILE *fp, const char *str) {
    int str_size = 0;
    fread(&str_size, sizeof(unsigned int), 1, fp);
    fread(str, sizeof(char), str_size, fp);
}

void escrever_edificios_bin(LISTAEDIFICIOS *le, const char *fname) {
    FILE *fp = NULL;

    if ((fp = fopen(fname, "wb")) == NULL) {
        printf("Erro %s\n", fname);
        return;
    }

    fwrite(&le->num_edificios, sizeof(le->num_edificios), 1, fp);   //GUARDAR O NR edificios
    EDIFICIO *pe = le->pedificios;

    for (int i = 0; i < le->num_edificios; ++i) {
        fwrite((&pe->id_edificio), sizeof(int), 1, fp);
        write_string(fp, pe->nome);
        fwrite((&pe->latitude), sizeof(double), 1, fp);
        fwrite((&pe->longitude), sizeof(double), 1, fp);
        write_string(fp, pe->morada);
        fwrite((&pe->preco_m2), sizeof(double), 1, fp);


        ESTUDIO *pest = pe->array_estudios.pestudios;
        fwrite(&pe->array_estudios.n_estudios, sizeof(pe->array_estudios.n_estudios), 1, fp);
        for (int j = 0; j < pe->array_estudios.n_estudios; j++) {
            fwrite((&pest->id_estudio), sizeof(int), 1, fp);
            fwrite((&pest->numero), sizeof(int), 1, fp);
            write_string(fp, pest->configuracao);
            fwrite((&pest->area), sizeof(int), 1, fp);
            fwrite((&pest->preco_diaria), sizeof(float), 1, fp);
            fwrite((&pest->preco_mensal), sizeof(float), 1, fp);
            fwrite((&pest->array_agendas.n_agendas), sizeof(int), 1, fp);

            pest++;
        }
        pe = pe->next;
    }
    fclose(fp);
}

void escrever_edificios(LISTAEDIFICIOS *g) {
    EDIFICIO *pp = g->pedificios;
    FILE *fp = (fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\edificios.txt", "w"));

    if (fp != NULL) {
        fprintf(fp, "Numero de edificios:%d\n", g->num_edificios);
        while (pp != NULL) {
            fprintf(fp, "%d,%s,%s,%f,%f,%f\n", pp->id_edificio, pp->nome, pp->morada, pp->preco_m2,
                    pp->latitude,
                    pp->longitude);
            ESTUDIO *pc = pp->array_estudios.pestudios;
            fprintf(fp, "Numero de estudios:%d\n", pp->array_estudios.n_estudios);
            for (int i = 0;
                 i < pp->array_estudios.n_estudios; i++) {
                fprintf(fp, "%d,%d,%d,%s,%d,%f,%f,%d\n", pc->id_estudio, pc->numero, pp->id_edificio,
                        pc->configuracao, pc->area, pc->preco_diaria, pc->preco_mensal, pc->array_agendas.size_agendas);
                pc++;
            }
            pp = pp->next;
        }
        fclose(fp);
    } else {
        printf("Erro na abertura do ficheiro\n");
    }
}

LISTAEDIFICIOS *read_edificios_txt() {
    LISTAEDIFICIOS *g = create_lista_edificio();

    FILE *fp;

    if ((fp = fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\edificios.txt", "r")) == NULL) {
        printf("File not opened!\n");
        return NULL;
    }

    id_edificio = 1;
    id_estudio = 1;
    id_agenda = 1;
    id_evento = 1;

    int num_edificios = 0;
    fscanf(fp, "%*[^:]:%d\n", &num_edificios);

    for (int i = 0; i < num_edificios; i++) {
        char morada[MAX200], nome[MAX200];
        int n_estudios = 0;
        float latitude, longitude, preco_m2;

        fscanf(fp, "%*d,%[^,],%[^,],%f,%f,%f\n", nome, morada, &preco_m2, &latitude, &longitude);
        fscanf(fp, "%*[^:]:%d\n", &n_estudios);

        insert_edificio(g, nome, latitude, longitude, morada, preco_m2, n_estudios);

        EDIFICIO *fe = g->pedificios;
        while (fe->next != NULL) fe = fe->next;

        for (int j = 0; j < n_estudios; j++) {
            int numero, area, size_agendas;
            float preco_diaria, preco_mensal;
            char configuracao[30];

            fscanf(fp, "%*d,%d,%*d,%[^,],%d,%f,%f,%d\n", &numero, configuracao, &area, &preco_diaria, &preco_mensal,
                   &size_agendas);
            insert_estudio(g, fe->id_edificio, numero, configuracao, area, preco_diaria, preco_mensal, size_agendas);
        }
    }

    fclose(fp);

    print_listaEdificio(g);

    return g;
}

void ler_edificios_bin(LISTAEDIFICIOS *le, const char *fname) {
    le = create_lista_edificio();

    FILE *fp = NULL;
    if ((fp = fopen(fname, "rb")) == NULL) {
        printf("Erro %s\n", fname);
        return;
    }
    id_edificio = 1;
    id_estudio = 1;
    id_agenda = 1;
    id_evento = 1;

    int num_edificios = 0;
    fread(&num_edificios, sizeof(int), 1, fp);

    for (int i = 0; i < num_edificios; i++) {
        char morada[MAX200], nome[MAX200];
        int n_estudios = 0;
        double latitude, longitude, preco_m2;

        fseek(fp, sizeof(int), SEEK_CUR);
        read_string(fp, nome);
        fread(&latitude, sizeof(double), 1, fp);
        fread(&longitude, sizeof(double), 1, fp);
        read_string(fp, morada);
        fread(&preco_m2, sizeof(double), 1, fp);
        fread(&n_estudios, sizeof(int), 1, fp);

        insert_edificio(le, nome, latitude, longitude, morada, preco_m2, n_estudios);
        EDIFICIO *fe = le->pedificios;
        while (fe->next != NULL) fe = fe->next;

        for (int j = 0; j < n_estudios; j++) {
            int numero, area, n_agendas;
            float preco_diaria, preco_mensal;
            char configuracao[30];

            fseek(fp, sizeof(int), SEEK_CUR);
            fread(&numero, sizeof(int), 1, fp);
            read_string(fp, configuracao);
            fread(&area, sizeof(int), 1, fp);
            fread(&preco_diaria, sizeof(float), 1, fp);
            fread(&preco_mensal, sizeof(float), 1, fp);
            fread(&n_agendas, sizeof(int), 1, fp);

            insert_estudio(le, fe->id_edificio, numero, configuracao, area, preco_diaria, preco_mensal, n_agendas);
        }
    }

    fclose(fp);
    print_listaEdificio(le);

}

void print_listaEdificio(const LISTAEDIFICIOS *g) {
    EDIFICIO *pp = g->pedificios;
    while (pp != NULL) {
        printf("EDIFICIO: %d, %s, %lf, %lf, %s, %.2f\n", pp->id_edificio, pp->nome, pp->latitude, pp->longitude,
               pp->morada, pp->preco_m2);

        ESTUDIO *pc = pp->array_estudios.pestudios;
        for (int i = 0; i < pp->array_estudios.n_estudios; i++) {
            printf("\tEstudio:ID-> %d,Numero porta-> %d,Configuracao-> %s,Area-> %d, Preco diaria-> %.2f, Preco mensal->%.2f\n",
                   pc->id_estudio, pc->numero, pc->configuracao, pc->area, pc->preco_diaria, pc->preco_mensal);

            AGENDAS *pa = pc->array_agendas.pagenda;
            for (int j = 0; j < pc->array_agendas.n_agendas; j++) {
                printf("\t\tID agenda-> %d,Plataforma-> %s\n", pa->id_agenda, pa->plataforma);

                DIAS *pd = pa->array_dias.pdias;
                //LISTAEVENTOS *plista = pd->listaeventos;
                for (int k = 0; k < pa->array_dias.n_dias; k++) {
                    printf("\t\t\tData -> %d / %d / %d\n", pd->dia, pd->mes, pd->ano);

                    if (pd->listaeventos != NULL) {
                        EVENTO *pe = pd->listaeventos->peventos;
                        while (pe != NULL) {
                            printf("\t\t\t\tEVENTO:%d,%s, %d-%d-%d, %d-%d-%d, ID-Cliente:%d \n", pe->id_evento,
                                   pe->tipo, pd->dia,
                                   pd->mes, pd->ano, pe->datafim.dia, pe->datafim.mes, pe->datafim.ano, pe->id_cliente);
                            pe = pe->nextEvento;
                        }
                    }
                    pd++;
                }
                pa++;
            }
            pc++;
        }
        pp = pp->next;
    }
}


///----------------------------------------------------------ESTUDIOS--------------------------------------------------------------------------

ESTUDIO_ARRAY *create_dynarray_array_estudios(int initsize) {
    ESTUDIO *pestudios = (ESTUDIO *) calloc(initsize, sizeof(ESTUDIO));
    ESTUDIO_ARRAY *estudiosarray = (ESTUDIO_ARRAY *) calloc(1, sizeof(ESTUDIO_ARRAY));
    estudiosarray->pestudios = pestudios;
    estudiosarray->n_estudios = 0;
    estudiosarray->size_estudios = initsize;

    return estudiosarray;
}

void insert_estudio(LISTAEDIFICIOS *pg, int id, int numero, char configuracao[], int area,
                    float preco_diario, float preco_mensal, int size_agendas) {
    //FUNÇAO AUXILIAR
    EDIFICIO *pedificio = find_edificio(pg, id);

    if (pedificio != NULL) {

        if (pedificio->array_estudios.n_estudios >= pedificio->array_estudios.size_estudios) {
            if (pedificio->array_estudios.size_estudios == 0) {
                pedificio->array_estudios.size_estudios = 2;
            } else {
                pedificio->array_estudios.size_estudios += 2;
            }
            pedificio->array_estudios.pestudios = (ESTUDIO *) realloc(pedificio->array_estudios.pestudios,
                                                                      sizeof(ESTUDIO) *
                                                                      pedificio->array_estudios.size_estudios);
        }
        ESTUDIO *pestudio = pedificio->array_estudios.pestudios + pedificio->array_estudios.n_estudios;
        pestudio->id_estudio = id_estudio++;
        pestudio->numero = numero;

        strcpy(pestudio->configuracao, configuracao);
        pestudio->area = area;
        pestudio->preco_diaria = preco_diario;
        pestudio->preco_mensal = preco_mensal;
        AGENDAS_ARRAY *agendasarray = create_dynarray_array_agendas(size_agendas);
        pestudio->array_agendas = *agendasarray;

        pedificio->array_estudios.n_estudios++;
    }
}

void edit_estudio(LISTAEDIFICIOS *pg, int id_estudio, int numero, char configuracao[], int area, float preco_diario,
                  float preco_mensal) {
    ESTUDIO *pe = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    if (pe != NULL) {
        pe->id_estudio = id_estudio;
        strcpy(pe->configuracao, configuracao);
        pe->numero = numero;
        pe->area = area;
        pe->preco_diaria = preco_diario;
        pe->preco_mensal = preco_mensal;
    }
}

ESTUDIO *find_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_estudio) { // BINARY SEARCH
    EDIFICIO *pedificio = pg->pedificios;

    while (pedificio != NULL) {
        ESTUDIO *pst = pedificio->array_estudios.pestudios;
        int l = 0;
        int r = pedificio->array_estudios.n_estudios - 1;

        if (pst == NULL) {
            printf("* find_student_dynarray_arrayestudios(): Array estudios encontra-se vazio!\n");
            return pst;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (pst[m].id_estudio == id_estudio) {
                return &pst[m];
            }
            if (pst[m].id_estudio < id_estudio) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        pedificio = pedificio->next;
    }
    return NULL;
}

void remove_estudio_dynarray_arrayestudios(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio) {

    EDIFICIO *edificio = find_edificio(pg, id_edificio);
    ESTUDIO *aremover = find_estudio_dynarray_arrayestudios(pg, id_estudio);

    if (aremover != NULL) {
        aremover->numero = 0;
        aremover->area = 0;
        strcpy(aremover->configuracao, "");

    }
    for (int i = 0; i < edificio->array_estudios.n_estudios; ++i) {
        *aremover = *(aremover + 1);
        aremover++;
    }
    edificio->array_estudios.n_estudios--;
}


///----------------------------------------------------------AGENDAS--------------------------------------------------------------------------

AGENDAS_ARRAY *create_dynarray_array_agendas(int initsize) {
    AGENDAS *pagendas = (AGENDAS *) calloc(initsize, sizeof(AGENDAS));
    AGENDAS_ARRAY *agendasarray = (AGENDAS_ARRAY *) calloc(1, sizeof(AGENDAS_ARRAY));
    agendasarray->pagenda = pagendas;
    agendasarray->n_agendas = 0;
    agendasarray->size_agendas = initsize;

    return agendasarray;
}

void insert_agenda(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, char plataforma[], int size_dias) {
    EDIFICIO *pedificio = find_edificio(pg, id_edificio);
    ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    if (pedificio != NULL && pestudio != NULL) {
        AGENDAS *pagenda = pestudio->array_agendas.pagenda + pestudio->array_agendas.n_agendas;

        pagenda->id_agenda = id_agenda++;

        strcpy(pagenda->plataforma, plataforma);

        DIAS_ARRAY *diasarray = (DIAS_ARRAY *) create_dynarray_array_agendas(size_dias);
        pagenda->array_dias = *diasarray;

        pestudio->array_agendas.n_agendas++;
    }
}

AGENDAS *find_agenda_dynarray_arrayagendas(LISTAEDIFICIOS *pg, int id_agenda) { // BINARY SEARCH
    EDIFICIO *edificio = pg->pedificios;
    while (edificio != NULL) {
        ESTUDIO *pestudio = edificio->array_estudios.pestudios;
        for (int i = 0; i < edificio->array_estudios.n_estudios; i++) {
            AGENDAS *pst = pestudio->array_agendas.pagenda;
            int l = 0;
            int r = pestudio->array_agendas.n_agendas - 1;

            if (pst == NULL) {
                printf("* find_student_dynarray_arraydias(): Array dias encontra-se vazio!\n");
                return pst;
            }
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (pst[m].id_agenda == id_agenda) {

                    return &pst[m];
                }
                if (pst[m].id_agenda < id_agenda) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            pestudio++;
        }
        edificio = edificio->next;
    }

    return NULL;
}

void escrever_agenda_txt(LISTAEDIFICIOS* g, int agenda) {
    AGENDAS* a = find_agenda_dynarray_arrayagendas(g, agenda);

    FILE* file;
    if ((file = fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\agendas.txt", "w")) != NULL) {
        fprintf(file, "%d,%s,%d\n", a->id_agenda, a->plataforma, a->array_dias.n_dias);

        for (int i = 0; i < a->array_dias.n_dias; i++) {
            DIAS* d = a->array_dias.pdias + i;
            fprintf(file, "%d,%d,%d,%d\n", d->dia, d->mes, d->ano, d->listaeventos->num_eventos);

            EVENTO* e = d->listaeventos->peventos;
            while (e != NULL) {
                fprintf(file, "%d,%d,%s,%d,%d,%d\n", e->id_evento, e->id_cliente, e->tipo, e->datafim.dia, e->datafim.mes, e->datafim.ano);
                e = e->nextEvento;
            }
        }
    } else {
        printf("Erro na abertura do ficheiro\n");
    }
    fclose(file);
}

void read_agenda_txt(LISTAEDIFICIOS* g, int edificio, int estudio) {
    FILE* file;
    if ((file = fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\agendas.txt", "r")) != NULL) {
        int id, dias_count;
        char plataforma[40];

        fscanf(file, "%d,%[^,],%d\n", &id, plataforma, &dias_count);

        insert_agenda(g, edificio, estudio, plataforma, dias_count);
        AGENDAS* a = find_agenda_dynarray_arrayagendas(g, id_agenda - 1);

        for (int i = 0; i < dias_count; i++) {
            int dia, mes, ano, event_count;

            fscanf(file, "%d,%d,%d,%d\n", &dia, &mes, &ano, &event_count);
            insert_dia(g, edificio, estudio, id_agenda - 1, dia, mes, ano);

            for (int j = 0; j < event_count; j++) {
                int eid,  cliente, dia2, mes2, ano2;
                char tipo[20];

                fscanf(file, "%d,%d,%[^,],%d,%d,%d\n", &eid, &cliente, tipo, &dia2, &mes2, &ano2);

                DIAS dias;
                dias.ano = ano2;
                dias.dia = dia2;
                dias.mes = mes2;

                insert_evento(g, tipo, dias, cliente, id_agenda - 1, dia, mes, ano);
            }
        }
    }
    fclose(file);
}

void escrever_agenda_bin(LISTAEDIFICIOS *le, const char *agendabin, int agenda) {
    FILE *fp = NULL;

    AGENDAS *pa = find_agenda_dynarray_arrayagendas(le, agenda);

    if ((fp = fopen(agendabin, "wb")) == NULL) {
        printf("Erro %s\n", agendabin);
        return;
    }

    fwrite(&pa->id_agenda, sizeof(pa->id_agenda), 1, fp);
    write_string(fp, pa->plataforma);
    fwrite(&pa->array_dias.n_dias, sizeof(pa->array_dias.n_dias),1,fp);
    DIAS *pd = pa->array_dias.pdias;

    for (int i = 0; i < pa->array_dias.n_dias; ++i) {
        fwrite((&pa->array_dias.pdias->dia), sizeof(int), 1, fp);
        fwrite((&pa->array_dias.pdias->mes), sizeof(int), 1, fp);
        fwrite((&pa->array_dias.pdias->ano), sizeof(int), 1, fp);
        fwrite((&pa->array_dias.pdias->listaeventos->num_eventos), sizeof(int),1,fp);

        EVENTO *pev = pd->listaeventos->peventos;
        while (pev != NULL) {
            fwrite((&pev->id_evento), sizeof(int), 1, fp);
            write_string(fp, pev->tipo);
            fwrite((&pev->datafim.dia), sizeof(int), 1, fp);
            fwrite((&pev->datafim.mes), sizeof(int), 1, fp);
            fwrite((&pev->datafim.ano), sizeof(int), 1, fp);
            fwrite((&pev->id_cliente), sizeof(int), 1, fp);

            pev = pev->nextEvento;
        }
        pd++;
    }
    fclose(fp);
}

void read_agenda_bin(LISTAEDIFICIOS *le, const char *agendabin, int edificio, int estudio) {
    FILE *fp = NULL;

    if ((fp = fopen(agendabin, "rb")) == NULL) {
        printf("Erro %s\n", agendabin);
        return;
    }
    int id, dias_count;
    char plataforma[40];
    fread(&id, sizeof(id), 1, fp);
    read_string(fp, plataforma);
    fread(&dias_count,sizeof(dias_count),1,fp);

    insert_agenda(le, edificio, estudio, plataforma, dias_count);
    AGENDAS* a = find_agenda_dynarray_arrayagendas(le, id_agenda-1);

    for (int i = 0; i < dias_count; ++i) {
        int dia, mes, ano, num_eventos;
        fread((&ano), sizeof(int), 1, fp);
        fread((&mes), sizeof(int), 1, fp);
        fread((&dia), sizeof(int), 1, fp);
        fread((&num_eventos), sizeof(int), 1, fp);

        insert_dia(le,edificio,estudio,id-1, dia, mes, ano);

        for (int j = 0; j < num_eventos; j++) {
            int evento, cliente;
            DIAS f;
            char tipo[MAX20];
            fread((&evento), sizeof(int), 1, fp);
            read_string(fp, tipo);
            fread((&f.dia), sizeof(int), 1, fp);
            fread((&f.mes), sizeof(int), 1, fp);
            fread((&f.ano), sizeof(int), 1, fp);
            fread((&cliente), sizeof(int), 1, fp);

            insert_evento(le, tipo, f,cliente, id, dia, mes, ano);
        }
    }
    fclose(fp);
}


///----------------------------------------------------------DIAS--------------------------------------------------------------------------

DIAS_ARRAY *create_dynarray_array_dias(int initsize) {
    DIAS *pdias = (DIAS *) calloc(initsize, sizeof(DIAS));
    DIAS_ARRAY *diasarray = (DIAS_ARRAY *) calloc(1, sizeof(DIAS_ARRAY));
    diasarray->pdias = pdias;
    diasarray->n_dias = 0;
    diasarray->size_dias = initsize;

    return diasarray;
}

void insert_dia(LISTAEDIFICIOS *pg, int id_edificio, int id_estudio, int id_agenda, int dia, int mes, int ano) {
    EDIFICIO *pedificio = find_edificio(pg, id_edificio);
    ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    AGENDAS *pagenda = find_agenda_dynarray_arrayagendas(pg, id_agenda);

    if (pedificio != NULL && pestudio != NULL && pagenda != NULL) {
        DIAS *pdias = pagenda->array_dias.pdias + pagenda->array_dias.n_dias;
        pdias->dia = dia;

        pdias->mes = mes;

        pdias->ano = ano;

        pagenda->array_dias.n_dias++;

        LISTAEVENTOS *clistaeventos = create_lista_eventos();
        pagenda->array_dias.pdias->listaeventos = clistaeventos;
    }

}

DIAS diferenca_dias(int d1, int m1, int ano1, int d2, int m2, int ano2) {
    DIAS aux = {0, 0, 0};
    int day_diff, mon_diff, year_diff;
    if (d2 < d1) {
        // borrow days from february
        if (m2 == 3) {
            //  check whether year is a leap year
            if ((ano2 % 4 == 0 && ano2 % 100 != 0) || (ano2 % 400 == 0)) {
                d2 += 29;
            } else {
                d2 += 28;
            }
        }
            // borrow days from April or June or September or November
        else if (m2 == 5 || m2 == 7 || m2 == 10 || m2 == 12) {
            d2 += 30;
        }
            // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else {
            d2 += 31;
        }
        m2 = m2 - 1;
    }
    if (m2 < m1) {
        m2 += 12;
        ano2 -= 1;
    }
    day_diff = d2 - d1;
    mon_diff = m2 - m1;
    year_diff = ano2 - ano1;

    aux.dia = day_diff;
    aux.mes = mon_diff;
    aux.ano = year_diff;

    return aux;
}

DIAS *find_dia_dynarray_arraydias(LISTAEDIFICIOS *pg, int id_agenda, int dia, int mes, int ano) {
    EDIFICIO *edificio = pg->pedificios;
    while (edificio != NULL) {
        ESTUDIO *pestudio = edificio->array_estudios.pestudios;
        for (int i = 0; i < edificio->array_estudios.n_estudios; i++) {
            AGENDAS *pst = pestudio->array_agendas.pagenda;
            for (int k = 0; k < pestudio->array_agendas.n_agendas; k++) {
                if (pst->id_agenda == id_agenda) {
                    DIAS *pdia = pst->array_dias.pdias;
                    int l = 0;
                    int r = pst->array_dias.n_dias - 1;

                    if (pdia == NULL) {
                        printf("* find_dias_dynarray_arraydias(): Array dias encontra-se vazio!\n");
                        return pdia;
                    }
                    while (l <= r) {
                        int m = l + (r - l) / 2;
                        if (pdia[m].dia == dia && pdia[m].mes == mes && pdia[m].ano == ano) {

                            return &pdia[m];
                        }
                        if (pdia[m].dia < dia && pdia[m].mes <= mes && pdia[m].ano <= ano) {
                            l = m + 1;
                        } else {
                            if (m == 0) {
                                r = m;
                            }
                            r = m - 1;
                        }
                    }
                }
                pst++;
            }
            pestudio++;
        }
        edificio = edificio->next;
    }

    return NULL;
}


///----------------------------------------------------------EVENTOS--------------------------------------------------------------------------

LISTAEVENTOS *create_lista_eventos() {
    LISTAEVENTOS *leventos = (LISTAEVENTOS *) calloc(1, sizeof(LISTAEVENTOS));
    leventos->peventos = NULL;

    return leventos;
}

void insert_evento(LISTAEDIFICIOS *pg, const char *tipo, DIAS datafim,
                   int id_cliente, int id_agenda, int dia, int mes, int ano) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    // EDIFICIO *pedificio = find_edificio(pg, id_edificio);
    // ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    AGENDAS *pagenda = find_agenda_dynarray_arrayagendas(pg, id_agenda);
    DIAS *pdias = find_dia_dynarray_arraydias(pg, id_agenda, dia, mes, ano);

    if (pagenda != NULL && pdias != NULL) {
        EVENTO *s = (EVENTO *) malloc(sizeof(EVENTO));
        s->id_evento = id_evento++;
        strcpy(s->tipo, tipo);
        s->id_cliente = id_cliente;
        s->datafim.dia = datafim.dia;
        s->datafim.mes = datafim.mes;
        s->datafim.ano = datafim.ano;

        s->nextEvento = NULL;

        if (pdias->listaeventos == NULL) {
            pdias->listaeventos = create_lista_eventos();
        }
        LISTAEVENTOS *plista = pdias->listaeventos;

        EVENTO *pant = NULL, *pcurrent = plista->peventos;
        while (pcurrent != NULL && id_evento > pcurrent->id_evento) {
            pant = pcurrent;
            pcurrent = pcurrent->nextEvento;
        }
        //INSERÇAO A CABEÇA
        if (pcurrent == plista->peventos) {
            s->nextEvento = plista->peventos;
            plista->peventos = s;
            plista->num_eventos++;
            return;
        }
        //INSERÇÃO A MEIO OU NO FIM
        s->nextEvento = pcurrent;
        pant->nextEvento = s;
        plista->num_eventos++;
    }
}

void edit_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento, char tipo[], DIAS datafim, int id_cliente) {
    EVENTO *pevento = find_evento(pg, id_agenda, id_evento);
    if (pevento != NULL) {
        pevento->id_evento = id_evento;
        strcpy(pevento->tipo, tipo);
        pevento->datafim.dia = datafim.dia;
        pevento->datafim.mes = datafim.mes;
        pevento->datafim.ano = datafim.ano;
        pevento->id_cliente = id_cliente;
    }
}

void remove_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento) {
    AGENDAS *pagenda = find_agenda_dynarray_arrayagendas(pg, id_agenda);
    //NAO REMOVEMOS NADA SE A LISTA ESTIVER VAZIA
    if (pagenda->array_dias.pdias->listaeventos->peventos == NULL) {
        printf("Esse evento nao existe.");
        return;
    }
    EVENTO *pant = NULL, *pcurrent = pagenda->array_dias.pdias->listaeventos->peventos;
    while (pcurrent != NULL && pcurrent->id_evento != id_evento) {
        pant = pcurrent;
        pcurrent = pcurrent->nextEvento;
    }
    //SE O EVENTO NAO EXISTIR
    if (pcurrent == NULL) {
        return;
    }
    //REMOÇÃO A CABEÇA
    if (pcurrent == pagenda->array_dias.pdias->listaeventos->peventos) {
        pagenda->array_dias.pdias->listaeventos->peventos = pcurrent->nextEvento;
        pagenda->array_dias.pdias->listaeventos->num_eventos--;
        free(pcurrent);
        return;
    }
    pant->nextEvento = pcurrent->nextEvento;
    free(pcurrent);
    //DECREMENTAR O NUMERO DE EVENTOS
    pagenda->array_dias.pdias->listaeventos->num_eventos--;
}

EVENTO *find_evento(LISTAEDIFICIOS *pg, int id_agenda, int id_evento) {

    EDIFICIO *edificio = pg->pedificios;
    while (edificio != NULL) {
        ESTUDIO *pestudio = edificio->array_estudios.pestudios;
        for (int i = 0; i < edificio->array_estudios.n_estudios; i++) {
            AGENDAS *pst = pestudio->array_agendas.pagenda;
            for (int k = 0; k < pestudio->array_agendas.n_agendas; k++) {
                if (pst->id_agenda == id_agenda) {
                    DIAS *pdias = pst->array_dias.pdias;
                    for (int j = 0; j < pst->array_dias.n_dias; j++) {
                        EVENTO *pevento = pdias->listaeventos->peventos;
                        while (pevento != NULL) {
                            if (pevento->id_evento == id_evento) {
                                return pevento;
                            }
                            pevento = pevento->nextEvento;
                        }
                        pdias++;
                    }
                }
                pst++;
            }
            pestudio++;
        }
        edificio = edificio->next;
    }
    return NULL;
}


///----------------------------------------------------------HOSPEDES--------------------------------------------------------------------------


LISTAHOSPEDES *create_lista_hospedes() {
    LISTAHOSPEDES *lhospedes = (LISTAHOSPEDES *) calloc(1, sizeof(LISTAHOSPEDES));
    lhospedes->phospede = NULL;

    return lhospedes;
}

void
insert_hospede(LISTAEDIFICIOS *pg, LISTAHOSPEDES *pl, const char nome[], int id_agenda, int id_evento, int id_cliente) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    EVENTO *pevento = find_evento(pg, id_agenda, id_evento);

    if (pevento != NULL && pevento->id_cliente == id_cliente) {

        HOSPEDE *h = (HOSPEDE *) calloc(1, sizeof(HOSPEDE));
        h->id_cliente = pevento->id_cliente;
        //h->id_cliente = id_cliente;
        strcpy(h->nome_cliente, nome);

        h->pnext = NULL;

        HOSPEDE *pant = NULL, *pcurrent = pl->phospede;
        while (pcurrent != NULL && id_cliente > pcurrent->id_cliente) {
            pant = pcurrent;
            pcurrent = pcurrent->pnext;
        }
        //INSERÇAO A CABEÇA
        if (pcurrent == pl->phospede) {
            h->pnext = pl->phospede;
            pl->phospede = h;
            pl->num_hospedes++;

            return;
        }
        //INSERÇÃO A MEIO OU NO FIM
        h->pnext = pcurrent;
        pant->pnext = h;
        pl->num_hospedes++;
    }
}

void edit_hospede(LISTAHOSPEDES *pl, int id_cliente, char nome[]) {
    HOSPEDE *ph = find_hospede(pl, id_cliente);
    if (ph != NULL) {
        ph->id_cliente = id_cliente;
        strcpy(ph->nome_cliente, nome);
    }
}

HOSPEDE *find_hospede(LISTAHOSPEDES *pl, int id) {

    HOSPEDE *pst = pl->phospede;
    while (pst != NULL) {
        if (pst->id_cliente == id) {
            return pst;
        }
        pst = pst->pnext;
    }
    return NULL;
}

void remove_hospede(LISTAEDIFICIOS *pg, LISTAHOSPEDES *pl, int id_agenda, int id_evento, int id_cliente) {
    HOSPEDE *phospede = find_hospede(pl, id_cliente);
    //NAO REMOVEMOS NADA SE A LISTA ESTIVER VAZIA
    if (pl->phospede == NULL) {
        printf("Esse hospede nao existe.");
        return;
    }
    HOSPEDE *pant = NULL, *pcurrent = pl->phospede;
    while (pcurrent != NULL && pcurrent->id_cliente != id_cliente) {
        pant = pcurrent;
        pcurrent = pcurrent->pnext;
    }
    //SE O EVENTO NAO EXISTIR
    if (pcurrent == NULL) {
        return;
    }
    //REMOÇÃO A CABEÇA
    if (pcurrent == pl->phospede) {
        pl->phospede = pcurrent->pnext;
        pl->num_hospedes--;
        free(pcurrent);
        return;
    }
    pant->pnext = pcurrent->pnext;
    free(pcurrent);
    //DECREMENTAR O NUMERO DE hospedes
    pl->num_hospedes--;
}

void escrever_hospedes_txt(LISTAHOSPEDES *g) {

    HOSPEDE *ph = g->phospede;
    FILE *fp = (fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\hospedes.txt", "w"));

    if (fp != NULL) {
        fprintf(fp, "Numero de hospedes:%d\n", g->num_hospedes);
        while (ph != NULL) {
            fprintf(fp, "%d,%s\n", ph->id_cliente, ph->nome_cliente);

            ph = ph->pnext;
        }
        fclose(fp);
    } else {
        printf("Erro na abertura do ficheiro\n");
    }
}

LISTAHOSPEDES *read_hospedes_txt(LISTAEDIFICIOS *e, LISTAHOSPEDES *h, int id_agenda, int id_evento) {

    FILE *fp;

    if ((fp = fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\hospedes.txt", "r")) == NULL) {
        printf("File not opened!\n");
        return NULL;
    }

    int id_hospede = 0;
    char nome[MAX20];
    int num_hospedes = 0;

    fscanf(fp, "%*[^:]:%d\n", &num_hospedes);

    for (int i = 0; i < num_hospedes; i++) {
        char nome[MAX200];

        fscanf(fp, "%d,%s\n", &id_hospede, nome);

        insert_hospede(e,h, nome, id_agenda, id_evento, id_hospede);

    }
    fclose(fp);
    print_listaHospedes(h);
    return h;
}

void print_listaHospedes(const LISTAHOSPEDES *h) {
    HOSPEDE *ph = h->phospede;
    printf("%d\n", h->num_hospedes);
    while (ph != NULL) {
        printf("Hospede: %d, %s\n", ph->id_cliente, ph->nome_cliente);
        ph = ph->pnext;
    }
}


///----------------------------------------------------------HISTORICO HOSPEDES--------------------------------------------------------------------------


LISTAHISTORICOESTADIAS *create_lista_historico_estadias() {
    LISTAHISTORICOESTADIAS *lea = (LISTAHISTORICOESTADIAS *) calloc(1, sizeof(LISTAHISTORICOESTADIAS));
    lea->pHestadias = NULL;

    return lea;
}

void insert_historicoEstadias(LISTAEDIFICIOS *pg, LISTAHOSPEDES *pl, LISTAHISTORICOESTADIAS *he, const char nome[],
                              int id_estudio, int id_agenda, int dia, int mes, int ano, int id_evento, int id_hospede) {
    //TEMOS A LISTA EDIFICIOS A APONTAR PARA NULL
    //QUEREMOS COLOCAR A LISTA A APONTAR PARA OS EDIFICIOS
    //EDIFICIO CRIADO
    ESTUDIO *pestudio = find_estudio_dynarray_arrayestudios(pg, id_estudio);
    DIAS *pdia = find_dia_dynarray_arraydias(pg, id_agenda, dia, mes, ano);
    HOSPEDE *phospede = find_hospede(pl, id_hospede);
    EVENTO *pevento = find_evento(pg, id_agenda, id_evento);

    if (phospede != NULL && phospede->id_cliente == id_hospede) {

        HISTORICOESTADIAS *hestadias = (HISTORICOESTADIAS *) calloc(1, sizeof(HISTORICOESTADIAS));
        int dias;
        hestadias->id_estadia = id_estadia++;
        strcpy(hestadias->nome_cliente, phospede->nome_cliente);
        hestadias->dataEntrada.dia = pdia->dia;
        hestadias->dataEntrada.mes = pdia->mes;
        hestadias->dataEntrada.ano = pdia->ano;

        hestadias->dataSaida.dia = pevento->datafim.dia;
        hestadias->dataSaida.mes = pevento->datafim.mes;
        hestadias->dataSaida.ano = pevento->datafim.ano;
        DIAS diferenca = diferenca_dias(pdia->dia, pdia->mes, pdia->ano, pevento->datafim.dia, pevento->datafim.mes,
                                        pevento->datafim.ano);
        if (diferenca.mes >= 1 && diferenca.dia > 0) {
            hestadias->preco =
                    (pestudio->preco_mensal * (float) diferenca.mes) + (pestudio->preco_diaria * (float) diferenca.dia);
        } else if (diferenca.mes < 1) {
            hestadias->preco = pestudio->preco_diaria * (float) diferenca.dia;
        }
        hestadias->pnext_estadia = NULL;

        HISTORICOESTADIAS *pant = NULL, *pcurrent = he->pHestadias;
        while (pcurrent != NULL && id_estadia > pcurrent->id_estadia) {
            pant = pcurrent;
            pcurrent = pcurrent->pnext_estadia;
        }
        //INSERÇAO A CABEÇA
        if (pcurrent == he->pHestadias) {
            hestadias->pnext_estadia = he->pHestadias;
            he->pHestadias = hestadias;
            he->num_estadias++;

            return;
        }
        //INSERÇÃO A MEIO OU NO FIM
        hestadias->pnext_estadia = pcurrent;
        pant->pnext_estadia = hestadias;
        he->num_estadias++;
    }

}

void escrever_historico_estadias(LISTAHISTORICOESTADIAS *he) {
    HISTORICOESTADIAS *pp = he->pHestadias;
    FILE *fp = (fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\historico_estadias.txt", "w"));

    if (fp != NULL) {
        fprintf(fp, "Numero de estadias:%d\n", he->num_estadias);
        while (pp != NULL) {
            fprintf(fp, "%s,%d, Data de entrada:%d-%d-%d, Data de saida:%d-%d-%d, Preco:%f\n", pp->nome_cliente,pp->id_estadia,pp->dataEntrada.dia,pp->dataEntrada.mes,pp->dataEntrada.ano, pp->dataSaida.dia, pp->dataSaida.mes, pp->dataSaida.ano,
                    pp->preco);
            pp = pp->pnext_estadia;
        }
        fclose(fp);
    } else {
        printf("Erro na abertura do ficheiro\n");
    }
}

LISTAHISTORICOESTADIAS *read_historico_txt(LISTAEDIFICIOS *pg, LISTAHOSPEDES *pl,LISTAHISTORICOESTADIAS *he, int id_estudio, int id_agenda, int id_evento, int id_hospede) {

    FILE *fp;

    if ((fp = fopen("C:\\Users\\carva\\CLionProjects\\ProjetoLPAED\\Ficheiros\\historico_estadias.txt", "r")) == NULL) {
        printf("File not opened!\n");
        return NULL;
    }

    int estadia, dia, mes, ano;
    char nome[MAX20];
    int num_estadias = 0;

    fscanf(fp, "%*[^:]:%d\n", &num_estadias);

    for (int i = 0; i < num_estadias; i++) {
        fscanf(fp, "%s,%d,%*[^:]:%d-%d-%d\n",nome, &estadia, &dia, &mes, &ano);

        insert_historicoEstadias(pg, pl,he,nome, id_estudio,id_agenda,dia, mes, ano, id_evento, id_hospede);

    }
    fclose(fp);
    print_listaHistorico(he);
    return he;
}

void print_listaHistorico(const LISTAHISTORICOESTADIAS *he) {
    HISTORICOESTADIAS *ph = he->pHestadias;
    printf("%d\n", he->num_estadias);
    while (ph != NULL) {
        printf("Hospede: %s, %d,Data de entrada-> %d-%d-%d, Data de saida-> %d-%d-%d, Preco: %.2f euros\n",
               ph->nome_cliente, ph->id_estadia, ph->dataEntrada.dia, ph->dataEntrada.mes, ph->dataEntrada.ano,
               ph->dataSaida.dia, ph->dataSaida.mes, ph->dataSaida.ano, ph->preco);
        ph = ph->pnext_estadia;
    }
}


///----------------------------------------------------------TAXA DE OCUPAÇÃO--------------------------------------------------------------------------

int is_estudio_occupied(ESTUDIO *es, int from, int to) {
    for (int j = 0; j < es->array_agendas.n_agendas; j++) {
        AGENDAS *ag = es->array_agendas.pagenda + j;
        for (int k = 0; k < ag->array_dias.n_dias; k++) {
            DIAS *di = ag->array_dias.pdias + k;

            EVENTO *ev = di->listaeventos->peventos;
            while (ev != NULL) {
                if (ev->id_cliente >= 0 && is_between(ev->datafim, from, to) == 1) {
                    return 1;
                }
                ev = ev->nextEvento;
            }
        }
    }
    return 0;
}

int is_between(DIAS date, int from, int to) {
    int ts = get_timestamp(date.dia, date.mes, date.ano); // guarda em ts o total de dias da nossa datafim
    if (ts >= from && ts <= to) {
        return 1;       // se o total de dias da data for maior que a data de inicio e menor que a de saida significa que o nosso evento esta entre as datas a ser procuradas.
        // return 1 se sim
    } else {
        return 0;
    }
}

int get_timestamp(int day, int month, int year) {
    return day + month * 31 + year * 12 * 31;           // 1 + 1*31 + 2021*12*31= 5000  5005
}

// Edificio
float get_studio_occupancy(LISTAEDIFICIOS *pe, int edificio, int from, int to) {
    int aux = 0;

    EDIFICIO *e = find_edificio(pe, edificio);
    for (int i = 0; i < e->array_estudios.n_estudios; i++) {
        aux = aux + is_estudio_occupied(e->array_estudios.pestudios + i, from, to);
    }
    float ocupacao = (float) aux / (float) e->array_estudios.n_estudios;

    ocupacao *= 100;

    return ocupacao;
}

//Parque dos edificios
float get_total_estudios_occupancy(LISTAEDIFICIOS *pe, int from, int to) {
    int aux = 0;
    int num_estudios = 0;
    EDIFICIO *e = pe->pedificios;
    while (e != NULL) {
        for (int i = 0; i < e->array_estudios.n_estudios; ++i) {
            aux = aux + is_estudio_occupied(e->array_estudios.pestudios + i, from, to);
        }
        num_estudios += e->array_estudios.n_estudios;
        e = e->next;
    }
    float ocupacao = (float) aux / (float) num_estudios;
    ocupacao *= 100;
    return ocupacao;
}


///----------------------------------------------------------PLATAFORMAS E REGRAS--------------------------------------------------------------------------

PLATAFORMAS_ARRAY *create_dyn_array_plataformas(int initsize) {
    PLATAFORMA *pp = (PLATAFORMA *) calloc(initsize, sizeof(PLATAFORMA));
    PLATAFORMAS_ARRAY *pa = (PLATAFORMAS_ARRAY *) calloc(1, sizeof(PLATAFORMAS_ARRAY));
    pa->pplataforma = pp;
    pa->n_plataformas = 0;
    pa->size_plataformas = initsize;

    return pa;
}

void insert_plataforma(PLATAFORMAS_ARRAY *pa, char nome[], char politica[]) {
    PLATAFORMA *p = pa->pplataforma;
    int i;
    for (i = 0; i < pa->size_plataformas; ++i) {
        if (p->nome == NULL) {
            p->nome = (char *) malloc(strlen(nome) + 1);
            strcpy(p->nome, nome);
            strcpy((char *) p->politicas, politica);
            return;
        }
        p++;
    }
    if (i == pa->n_plataformas) {
        int oldsize = pa->n_plataformas;
        int newsize = pa->n_plataformas + 2;
        pa->pplataforma = (PLATAFORMA *) realloc(pa->pplataforma, newsize * sizeof(PLATAFORMA));
        for (i = oldsize; i < newsize; ++i) {
            p->nome = NULL;
            strcpy((char *) p->politicas, "");
        }
        p = pa->pplataforma + oldsize;
        strcpy(p->nome, nome);
        strcpy((char *) p->politicas, politica);
    }
}

REGRAS_ARRAY *create_dyn_array_regras(int initsize) {
    REGRAS *pr = (REGRAS *) calloc(initsize, sizeof(REGRAS));
    REGRAS_ARRAY *pra = (REGRAS_ARRAY *) calloc(1, sizeof(REGRAS_ARRAY));
    pra->pregras = pr;
    pra->n_regras = 0;
    pra->size_regras = initsize;

    return pra;
}

void insert_regra(REGRAS_ARRAY *pra, int id, char tipo[], double taxa) {
    REGRAS *pr = pra->pregras;
    int i;
    for (i = 0; i < pra->n_regras; ++i) {
        strcpy(pr->tipo, tipo);
        pr->id = id;
        pr->taxa = taxa;
        pr++;
    }

    if (i == pra->size_regras) {
        int oldsize = pra->size_regras;
        int newsize = pra->size_regras + 2;
        pra->pregras = (REGRAS *) realloc(pra->pregras, newsize * sizeof(REGRAS));
        for (i = oldsize; i < newsize; ++i) {
            strcpy(pr->tipo, "");
            pr->id = 0;
            pr->taxa = 0;
        }
        pr = pra->pregras + oldsize;
        strcpy(pr->tipo, tipo);
        pr->id = id;
        pr->taxa = taxa;
    }
}

void edit_regra(REGRAS_ARRAY *pra, int id, char tipo[], double taxa) {
    REGRAS *pe = find_regra_dynarray_arrayregras(pra, id);
    if (pe != NULL) {
        pe->id = id;
        strcpy(pe->tipo, tipo);
        pe->taxa = taxa;
    }
}

REGRAS *find_regra_dynarray_arrayregras(REGRAS_ARRAY *pra, int id_regra) { // BINARY SEARCH
    REGRAS *pregra = pra->pregras;

    for (int i = 0; i < pra->n_regras; ++i) {
        int l = 0;
        int r = pra->n_regras - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (pregra[i].id == id_estudio) {
                return pregra;
            }
            if (pregra[i].id < id_estudio) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        pregra++;
    }
    return NULL;
}

PLATAFORMA *find_plataforma_dynarray_arrayplataformas(PLATAFORMAS_ARRAY *pa, char nome[]) { // BINARY SEARCH
    PLATAFORMA *pp = pa->pplataforma;

    if (pp == NULL) {
        printf("*find_plataforma_dynarray_arrayplataformas(): nao tem plataformas para procurar");
        return pp;
    }
    for (int i = 0; i < pa->n_plataformas && pp->nome != NULL && strcmp(pp->nome, nome) != 0; ++i) {
        pp++;
    }
    return (pp->nome != NULL && strcmp(pp->nome, nome) == 0 ? pp : NULL);
}