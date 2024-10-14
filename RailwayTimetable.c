#include <stdio.h>

int main() {
    char cur_time[6];
    scanf("%s", cur_time);
    int current = (cur_time[0] - '0') * 600 + (cur_time[1] - '0') * 60 + (cur_time[3] - '0') * 10 + (cur_time[4] - '0');
    int trains;
    scanf("%d", &trains);
    int ans;
    int last = 1000000;
    for (int i = 0; i < trains; i++) {
        int train_number, times;
        char train_time[6];
        scanf("%d %s %d", &train_number, train_time, &times);
        int train = (train_time[0] - '0') * 600 + (train_time[1] - '0') * 60 + (train_time[3] - '0') * 10 + (train_time[4] - '0');
        if (train >= current && train + times < last) {
            ans = train_number;
            last = train + times;
        }
    }
    printf("%d\n", ans);
    return 0;
}