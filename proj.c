#include<stdio.h>
#include<string.h>

int checkUser(char name[], char password[]){
    FILE *users = fopen("records.txt", "r");

    if(users == NULL){
        printf("Error Occured");
    }
    else{
        char name_in[20];
        char pass_in[8];
        char unused;

        while(fgets(name_in, sizeof(name_in), users) != NULL ){
        	
        	name_in[strcspn(name_in, "\n")] = '\0';  // replaces \n with \0 to mark the end of name
            fgets(pass_in, sizeof(pass_in)+1, users);
            pass_in[strcspn(pass_in, "\n")] = '\0'; // replaces \n with \0 to mark the end of password
            
            if(strcmp(name, name_in)==0){
                if(strcmp(password, pass_in)==0){
                    printf("Logged in successfully!\n");
                    fclose(users);
                    return 1;
                }else{
                    printf("Incorrect Password\n");
					return 0;
                }
            }
        }
		printf("User not found\n");
		fclose(users);
		return 0;
    }
};

int createUser(char name[], char password[]){
	FILE *users = fopen("records.txt", "a");
	
	if(users == NULL){
		printf("Error Occured\n");
		return 0;
	}else{
		fputs(name, users);
		fputs(password, users);
		return 1;
	}
}

int main(){
    char name[20]; 
    char pass[8];
    int choice;
    
    printf("Select an Option\n");
    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("3. Exit");
    
    scanf("%d", &choice);
    
    switch(choice){
    	case 1:
    		do{
        		printf("Enter username: ");
        		scanf("%s", &name);
        		printf("Enter Password: ");
        		scanf("%s", &pass);
    		}while(checkUser(name, pass) == 0);
    		break;
    	case 2:
    		do{
        		printf("Enter username: ");
        		scanf("%s", &name);
        		printf("Enter Password: ");
        		scanf("%s", &pass);
        		strcat(name, "\n");
        		strcat(pass, "\n");
    		}while(createUser(name, pass) == 0);
    	    break;
    	case 3:
    		return 0;
	}
	
    
    
    
}