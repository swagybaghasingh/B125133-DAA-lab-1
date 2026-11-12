#include <stdio.h>

typedef struct {
    int start;
    int end;
} Meeting;

void sortStart(Meeting a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].start > a[j].start) {
                Meeting temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sortEnd(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting m[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and end time of meeting %d: ",
               i + 1);

        scanf("%d %d",
              &m[i].start,
              &m[i].end);
    }

    int start[n], end[n];

    for (int i = 0; i < n; i++) {
        start[i] = m[i].start;
        end[i] = m[i].end;
    }

    sortStart(m, n);
    sortEnd(end, n);

    int i = 0, j = 0;
    int rooms = 0;
    int maxRooms = 0;

    while (i < n) {

        if (m[i].start < end[j]) {
            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        else {
            rooms--;
            j++;
        }
    }

    printf("Minimum number of rooms = %d\n", maxRooms);

    return 0;
}