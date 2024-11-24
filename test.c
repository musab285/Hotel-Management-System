#include<stdio.h>
#include<string.h>

int main(){
    struct hotel{
        char name[20];
        char type[10];
        int room;
        int days;
        int total;
    };

    char user[] = "zain";


    FILE *test = fopen("hotelrecord.txt", "r");
    if(test == NULL){
        printf("Error Occured");
    }
    else{
        struct hotel h;
        while(fscanf(test, "%s %s %d %d %d", h.name, h.type, &h.room, &h.days, &h.total) != EOF){
            if(strcmp(h.name, user) == 0){
                printf("Name: %s\nType: %s\nRoom: %d\nDays: %d\nTotal: %d\n", h.name, h.type, h.room, h.days, h.total);
            }
        }
        fclose(test);
    }
}