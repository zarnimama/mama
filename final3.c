#include<stdio.h>
struct Db{
    char user_name[30];
    char user_email[30];
    char user_pass[30];
    int user_phone;
};
struct for_{
    char email[30];
    char pass[30];
};
struct for_ log_in[1];
struct Db data[5];
void menu();
void login();
void logout();
void for_delete_registration();
int login_checking(char l_email[30],char l_pass[30]);
int n=0,c=0;
int z=0,x=0;
int compare_two_charArray(char first[30],char second[30]);
int size_of_charArray(char arr[30]);
int registration_checking(char checking_email[30]);
void registration();
void delete_registration();
void for_update();
void copy_two_charArray(char first[30],char second[30]);
int r_user_count=0;            // counting user registered accounts
int g_login_check=-1;          // checking login
int g_registration_check=1;    // checking registration
int login_count=0;             // counting login
int g_delete_check=-1;         // checking delete registered accounts
int main(){
    menu();     //menu means that you can choose options like restaurants menu book!
    return 0;
}
void menu(){
    while(1) {
        int option = 0;
        printf("Welcome !\nIf you want to Login press 1\nIf you want to Register press 2\nIf you want to Logout press 3\nIf you want to Delete registered account press 4\nEnter:");
        scanf("%d",&option);
        if (option == 1) {
            login();
        } else if (option == 2) {
            registration();
        } else if(option==3){
            logout();
        }else if(option==4) {
            for_delete_registration();
        }else{
            printf("Wrong Option!\n");
        }
    }
}

void login(){
    char l_email[30]; //l_email means login email
    char l_pass[30]; //l_pass means login password
    if(r_user_count>0){
        if (login_count == 0) {
            printf("\n\nEnter your email address to login:");
            scanf(" %[^\n]", &l_email);
            printf("Enter your password to login:");
            scanf(" %[^\n]", &l_pass);
            printf("Login Email: %s\n", l_email);
            printf("Login Password: %s\n\n", l_pass);
            login_checking(l_email,l_pass);
            if (g_login_check != -1) {
                printf("Login Success!\n\n");
                copy_two_charArray(log_in[0].email, l_email);
                copy_two_charArray(log_in[0].pass, l_pass);
                printf("Login Checking for email: %s\nLogin Checking for password: %s\n\n", log_in[0].email,
                       log_in[0].pass);
                login_count++;
                menu();
            } else {
                printf("Login Fail!\n\n");
                menu();
            }
        } else {
            printf("\nSorry,Please logout current account!\n\n");
            menu();
        }
    }else{
        printf("\nSorry,you are not registered any account!\nPlease,registration first!\n\n");
        menu();
    }
}
int login_checking(char l_email_check[30],char l_pass_check[30]) {
    for( n=0;n<=r_user_count+1;n++){
        int email_check= compare_two_charArray(data[n].user_email,l_email_check);
        if(email_check==1){
            break;
        }
    }
    for( c=0;c<=r_user_count+1;c++){
        int pass_check= compare_two_charArray(data[c].user_pass,l_pass_check);
        if(pass_check==1){
            break;
        }
    }
    if(n>=r_user_count&&c>=r_user_count){
        return g_login_check=-1;
    }else if(n==c){
        return g_login_check=n;
    }
    else{
        g_login_check=-1;
    }
}
int compare_two_charArray(char first[30],char second[30]){
    int size1=size_of_charArray(first);
    int size2=size_of_charArray(second);
    int sameCount=0;
    if(size1==size2){
        for(int i=0;i<size1;i++){
            if(first[i]==second[i]){
                sameCount++;
            }
        }
    }else{
        return 0;
    }
    if(sameCount==size2){
        return 1;
    }else{
        return 0;
    }
}
int size_of_charArray(char arr[30]){
    int size=0;
    for(int i=0;arr[i]!='\0';i++){
        size++;
    }
    return size;
}
int registration_checking(char checking_email[30]) {
    int d=0;
    if (r_user_count > 0) {
        while (d < r_user_count) {
            d++;
            int email_check = compare_two_charArray(data[d-1].user_email, checking_email);
            if (email_check == 0) {
                g_registration_check = 1;
            }else{
                g_registration_check = 0;
            }
        }
    }
}
void registration() {
    char r_name[30];      //r_name means register user name
    char r_email[30];    //r_email means register email
    char r_pass[30];    //r_pass means register password
    int r_phone=0;     //r_phone means register phone number
    if(r_user_count==5){
        printf("\nWe didn't allow more than 5 user!\nBut you can delete registered account!\n\n");
        for_delete_registration();
        if(g_delete_check!=-1) {
            printf("\n\nDelete registered account Success!\n");
            for (int i = 0; i < 30; i++){
                data[x].user_name[i] = '\0';
                data[x].user_email[i] = '\0';
                data[x].user_pass[i] = '\0';
                data[x].user_phone = 0;
            }
            r_user_count--;
            for_update();
        }else{
            printf("\nDelete registered account Fail!\n\n");
            for_delete_registration();
        }
    }else{
        printf("\n\nEnter your user name to register:");
        scanf(" %[^\n]", &r_name);
        printf("Enter your email address to register:");
        scanf(" %[^\n]", &r_email);
        printf("Enter your email password to register at lease 6 characters:");
        scanf(" %[^\n]", &r_pass);
        int check_for_pass = size_of_charArray(r_pass);
        if (check_for_pass >= 6) {
            printf("Enter your phone number to register:");
            scanf(" %d", &r_phone);
            registration_checking(r_email);
            if (g_registration_check == 1) {
                printf("\nRegistration Success!");
                copy_two_charArray(data[r_user_count].user_name, r_name);
                printf("\n\nChecking for user name: %s\n", data[r_user_count].user_name);
                copy_two_charArray(data[r_user_count].user_email, r_email);
                printf("Checking for email address: %s\n", data[r_user_count].user_email);
                copy_two_charArray(data[r_user_count].user_pass, r_pass);
                printf("Checking for password: %s\n", data[r_user_count].user_pass);
                data[r_user_count].user_phone = r_phone;
                printf("Checking for phone number: %d\n\n", data[r_user_count].user_phone);
                r_user_count++;
            } else {
                printf("\nRegistration Fail!\nThis email is already registered!\nTry another account!\n");
                registration();
            }
        } else {
            printf("\nYour password '%s' is so weak!\nPlease redefine!\n", r_pass);
            registration();
        }
    }
}
void delete_registration(){
    char d_email[30]; //d_email means delete email
    char d_pass[30];  //d_pass means delete password
    printf("\nEnter email that you want to delete from registration:");
    scanf(" %[^\n]",&d_email);
    printf("Enter password that you want to delete from registration:");
    scanf(" %[^\n]",&d_pass);
    for( z=0;z<=r_user_count;z++){
        int email_check= compare_two_charArray(data[z].user_email,d_email);
        if(email_check==1){
            break;
        }
    }
    for( x=0;x<=r_user_count;x++){
        int pass_check= compare_two_charArray(data[x].user_pass,d_pass);
        if(pass_check==1){
            break;
        }
    }
    if(z>=r_user_count&&x>=r_user_count){
        g_delete_check=-1;
    }else if(z==x){
        g_delete_check=z;
    }else{
        g_delete_check=-1;
    }
}
void for_update(){
    char u_name[30];
    char u_email[30];
    char u_pass[30];
    int u_phone=0;
    printf("\n\nEnter your user name to register:");
    scanf(" %[^\n]", &u_name);
    printf("Enter your email address to register:");
    scanf(" %[^\n]",&u_email);
    printf("Enter your email password to register at lease 6 characters:");
    scanf(" %[^\n]",&u_pass);
    int check_for_pass = size_of_charArray(u_pass);
    if (check_for_pass >= 6) {
        printf("Enter your phone number to register:");
        scanf("%d", &u_phone);
        registration_checking(u_email);
        if (g_registration_check == 1) {
            printf("\n\nRegistration Success!");
            copy_two_charArray(data[x].user_name, u_name);
            printf("\n\nChecking for user name: %s\n", data[x].user_name);
            copy_two_charArray(data[x].user_email, u_email);
            printf("Checking for email address: %s\n", data[x].user_email);
            copy_two_charArray(data[x].user_pass, u_pass);
            printf("Checking for password: %s\n", data[x].user_pass);
            data[x].user_phone = u_phone;
            printf("Checking for phone number: %d\n\n", data[x].user_phone);
            r_user_count++;
        } else {
            printf("Registration Fail!\nThis email is already registered!\nTry another account!\n\n");
            registration();
        }
    } else {
        printf("\nYour password '%s' is so weak!\nPlease redefine!\n", u_pass);
        registration();
    }
}
void for_delete_registration(){
    if(r_user_count>0) {
        delete_registration();
        if (g_delete_check != -1) {
            printf("\nDelete registered account Success!\n");
            for (int i = 0; i < 30; i++) {
                data[x].user_name[i] = '\0';
                data[x].user_email[i] = '\0';
                data[x].user_pass[i] = '\0';
                data[x].user_phone = 0;
            }
            r_user_count--;
            for_update();
            menu();
        } else {
            printf("\nDelete registered account Fail!\n\n");
            menu();
        }
    }else{
        printf("\n\nSorry,you are not registered any account!\nPlease registration first!\n\n");
        menu();
    }
}
void copy_two_charArray(char first[30],char second[30]) {
    int i=0;
    while(second[i]!='\0'){
        first[i]=second[i];
        i++;
    }
}
void logout() {
    char o_email[30]; //o_email means logOut email
    char o_pass[30];  //o_pass means logOut password
    if (login_count == 1) {
        printf("\nEnter your email address that you want to logout:");
        scanf(" %[^\n]", &o_email);
        printf("Enter your email password that your want to logout:");
        scanf(" %[^\n]", &o_pass);
        int email_check = compare_two_charArray(log_in[0].email, o_email);
        int pass_check = compare_two_charArray(log_in[0].pass, o_pass);
        if (email_check == 0 && pass_check == 0) {
            printf("Logout Fail!\n\n");
            menu();
        } else if (email_check == 1 && pass_check == 1) {
            printf("\nLogout Success!\n\n");
            login_count--;
            menu();
        } else{
            printf("\nLogout Fail!\n\n");
            menu();
        }
    }else{
        printf("\nYou are not login any account!\n\n");
        menu();
    }
}