#include <stdlib.h>
#include <string.h>

#define PATIENTS 4
#define TIMES 4
#define DATA_SIZE 16
int patients_len = 4, times_len = 4, data_size = 16;


int sbp_dbp_time_patient[PATIENTS][DATA_SIZE] = {
{   120, 125, 124, 132,   115, 135, 121, 142,   140, 135, 141, 129,  115, 151, 142, 122 }, //SBP
{    80,  75,  77,  83,   84,  79,  78,  83,    89,  77,  78,  81,   70,  77,  83,  83 }, //DBP
{     0,   1,   2,   3,    0,   1,   2,   3,    0,   1,   2,   3,     0,  1,  2,   3 },
{     0,   1,   2,   3,    1,   2,    3,   0,    2,   3,   0,   1,     3,   0,    1,   2 }
};

typedef struct {
    char *name;
    int index;
} Patient_index;

Patient_index create_patient(char *name, int index) {
    Patient_index patient;
    patient.name = malloc(sizeof(char) * strlen(name));
    strcpy(patient.name, name);
    patient.index = index;
    return patient;
}

Patient_index patients_index[PATIENTS];

void init_patients() {
    patients_index[0] = create_patient("Abacki", 0);
    patients_index[1] = create_patient("Babacki", 1);
    patients_index[2] = create_patient("Cabacki", 2);
    patients_index[3] = create_patient("Dabacki", 3);
}

char *get_patient_name_by_idx(int idx) {
    return patients_index[idx].name;
}

typedef struct {
    int time;
    int inx;
} Time;

Time create_time(int time, int inx) {
    Time t;
    t.time = time;
    t.inx = inx;
    return t;
}

Time time[TIMES];

void init_time() {
    time[0] = create_time(15, 0);
    time[1] = create_time(30, 1);
    time[2] = create_time(45, 2);
    time[3] = create_time(60, 3);
}

int get_time_by_idx(int idx) {
    return time[idx].time;
}