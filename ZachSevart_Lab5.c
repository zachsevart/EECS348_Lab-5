#include <stdio.h>

float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


void print_sales() {
    printf("\nMonthly sales report for 2022:\n");
    printf("%-11s %s\n", "Month", "Sales");
    for(int i=0; i<12; i++)
        printf("%-11s $%.2f\n", months[i], sales[i]);
}

void calc_min_max_avg() {
    float min = sales[0], max = sales[0], sum = 0;
    int min_month = 0, max_month = 0;

    for(int i=1; i<12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            min_month = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            max_month = i;
        }
        sum += sales[i];
    }
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
    printf("Average sales: $%.2f\n", sum/12);
}

void moving_averages() {
    float sum;
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 5; i < 12; i++) {
        sum = 0;
        for (int j = i - 5; j <= i; j++)
            sum += sales[j];
        printf("%-9s - %-9s: $%.2f\n", months[i - 5], months[i], sum / 6);
    }
}

void sorted_sales() {
    float sorted[12], temp;
    int j;
    sorted[0] = sales[0];

    for(int i=1; i<12; i++) {
        j = i-1;
        temp = sales[i];
        while (temp>sorted[j] && j>=0) {
            sorted[j+1] = sorted[j];
            j--;
        }
        sorted[j+1] = temp;
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-9s  %s\n", "Month", "Sales");
    for(int i=0; i<12; i++) {
        for(int j=0; j<12; j++)
            if(sorted[i] == sales[j])
                printf("%-9s  $%.2f\n", months[j], sorted[i]);
    }
}

void main() {
    read_sales();
    print_sales();
    calc_min_max_avg();
    moving_averages();
    sorted_sales();
}




#include <stdio.h>

int main() {
    int total_score, td, fg, safety, td_2pt, td_fg;

    do {
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &total_score);

        if (total_score <= 1) {
            printf("The program has terminated.\n");
            return 0;
        } else {
            printf("\nPossible combinations of scoring plays:\n");
            for(td_2pt = 0; td_2pt <= total_score/8; td_2pt++) {
                for(td_fg = 0; td_fg <= (total_score - td_2pt*8)/7; td_fg++ ) {
                    for(td = 0; td <= (total_score - td_2pt*8 - td_fg*7)/6; td++) {
                        for(fg = 0; fg <= (total_score - td_2pt*8 - td_fg*7 - td*6)/3; fg++) {
                            safety = total_score - td_2pt*8 - td_fg*7 - td*6 - fg*3;
                            if(safety >= 0) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

    } while (total_score > 1);

    return 0;
}

