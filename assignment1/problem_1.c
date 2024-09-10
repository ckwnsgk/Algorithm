#define _CRT_SECURE_NO_WARNINGS
#define MAX_APPOINTMENTS 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� �ð��� �����ϴ� ����ü
typedef struct {
    int start_hour; 
    int start_min;
    int end_hour;
    int end_min; 
    char lecture[100];
} Appointment;

// ���� �ð��� ���� �ð� ������ �����ϴ� �� �Լ�
int compareAppointments(const void* a, const void* b) {
    Appointment* app1 = (Appointment*)a;
    Appointment* app2 = (Appointment*)b;
    if (app1->start_hour != app2->start_hour) {
        return app1->start_hour - app2->start_hour;
    }
    return app1->start_min - app2->start_min;
}

int main() {
    int num_appointments = 0;
    int day_count = 1;

    printf("please enter the number of class : ");
    while (scanf("%d", &num_appointments) == 1) 
    {
        Appointment appointments[MAX_APPOINTMENTS];
        for (int i = 0; i < num_appointments; i++) {
            printf("%d - ",i+1);
            scanf("%d:%d %d:%d %s", &appointments[i].start_hour, &appointments[i].start_min,&appointments[i].end_hour, &appointments[i].end_min , appointments[i].lecture);
        }

        // ���� �ð��� ���� �ð� ������ ����
        qsort(appointments, num_appointments, sizeof(Appointment), compareAppointments);

        int max_nap_duration = 0;
        int max_nap_start_hour = appointments[0].end_hour;
        int max_nap_start_min = appointments[0].end_min;
        char max_nap_lecture[100];
        strcpy(max_nap_lecture, appointments[0].lecture);

        // ���� ������ ���� �ð� ���
        for (int i = 0; i < num_appointments - 1; i++) {
            int duration = (appointments[i + 1].start_hour - appointments[i].end_hour) * 60 +
                (appointments[i + 1].start_min - appointments[i].end_min);
            if (duration > max_nap_duration) {
                max_nap_duration = duration;
                max_nap_start_hour = appointments[i].end_hour;
                max_nap_start_min = appointments[i].end_min;
                strcpy(max_nap_lecture, appointments[i].lecture);
            }
        }

        // ��� ���
        printf("Day #%d: the longest nap starts at %02d:%02d and will last for ", day_count++, max_nap_start_hour, max_nap_start_min);
        if (max_nap_duration < 60) {
            printf("%d minutes.\n", max_nap_duration);
        }
        else {
            printf("%d hours and %d minutes.\n", max_nap_duration / 60, max_nap_duration % 60);
        }
    }

    return 0;
}