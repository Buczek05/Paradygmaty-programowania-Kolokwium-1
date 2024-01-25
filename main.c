#include <stdio.h>
#include <math.h>
#include "data.c"

typedef struct {
    int pressure;
    int time;
    char *patient_name;
} Data;

int **get_avg_pressure_table() {
    int **avg_pressure;
    avg_pressure = malloc(sizeof(int *) * PATIENTS);
    for (int i = 0; i < patients_len; i++) {
        avg_pressure[i] = malloc(sizeof(int) * TIMES);
    }
    return avg_pressure;
}

int calculate_pressure(int sbp, int dbp) {
    return floor((1.0 / 3.0) * sbp + (2.0 / 3.0) * dbp);
}

int **get_filled_avg_table(){
    int **avg_pressure = get_avg_pressure_table();
    for (int i = 0; i < patients_len; i++) {
        for (int j = 0; j < times_len; j++) {
            int sbp = sbp_dbp_time_patient[0][i];
            int dbp = sbp_dbp_time_patient[1][i];
            int pressure = calculate_pressure(sbp, dbp);
            avg_pressure[i][j] = pressure;
        }
    }
    return avg_pressure;
}

void print_avg_table(int **avg_pressure) {
    int i, j;
    printf("%-30s", "cisnienie srednie");
    for (j = 0; j < times_len; j++) {
        printf(" %5d min", time[j].time);
    }
    printf("\n");
    for (i = 0; i < patients_len; i++) {
        for (j = -1; j < times_len; j++) {
            if (j == -1){
                printf("%-30s", get_patient_name_by_idx(i));
                continue;
            }
            printf("%10d", avg_pressure[i][j]);
        }
        printf("\n");
    }
}

void print_sorted_pressure_for_patient(int patient_idx){
    int i;
    printf("Cisnienie dla pacjenta %s: ", get_patient_name_by_idx(patient_idx));
    for (i = 0; i < data_size; i++){
        if (sbp_dbp_time_patient[3][i] == patient_idx){
            printf("%d\t", calculate_pressure(sbp_dbp_time_patient[0][i], sbp_dbp_time_patient[1][i]));
        }
    }
    printf("\n");
}
void print_min_avg_for_patient(int patient_idx){
    int min = 99999, min_minutes_idx, i, pressure, total_len=0, total_pressure=0;
    for (i = 0; i < data_size; i++){
        if (sbp_dbp_time_patient[3][i] == patient_idx){
            pressure = calculate_pressure(sbp_dbp_time_patient[0][i], sbp_dbp_time_patient[1][i]);
            total_pressure += pressure;
            total_len++;
            if (min > pressure){
                min = pressure;
                min_minutes_idx = sbp_dbp_time_patient[2][i];
            }
        }
    }
    printf("minimalne cisnienie dla %s bylo w %d minucie i wynosilo %d mm Hg, a wartosc srednia byla %f\n",
           get_patient_name_by_idx(patient_idx), get_time_by_idx(min_minutes_idx), min, (float)total_pressure/(float)total_len);
}

Data *get_all_data() {
    // gdzies jest blad§
    Data data[DATA_SIZE];
    for (int i = 0; i < data_size; i++){
        char *name = get_patient_name_by_idx(sbp_dbp_time_patient[3][i]);
        data[i].patient_name = malloc(sizeof(char) * strlen(name));
        data[i].time = get_time_by_idx(sbp_dbp_time_patient[2][i]);
        data[i].pressure = calculate_pressure(sbp_dbp_time_patient[0][i], sbp_dbp_time_patient[1][i]);
    }
    return data;
}

void print_data_to_console_and_file(Data data){
    FILE *file = fopen("wyniki.txt", "w");
    if (!file){
        printf("Nie udalo sie otworzyc pliku");
    }
    fprintf("%s: %d", data.patient_name, data.pressure);
    printf("%s: %d", data.patient_name, data.pressure);
}


int main() {
    init_patients();
    init_time();
    int **avg_pressure = get_filled_avg_table();
    int patient_idx, data_idx;
    print_avg_table(avg_pressure);
    printf("Wybierz id pacjenta: ");
    scanf("%d", &patient_idx);
    print_sorted_pressure_for_patient(patient_idx);
    printf("Wybierz id pacjenta: ");
    scanf("%d", &patient_idx);
    print_min_avg_for_patient(patient_idx);
    Data *data = get_all_data();
    printf("Wybierz id danych: ");
    scanf("%d", &data_idx);
    print_data_to_console_and_file(data[data_idx]);
    return 0;
}
