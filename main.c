#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define RETURN return 0

void menu();
void help_menu();
void print_mass(int *mass, int size);
void mass_rand(int *mass_N,int size);
int comp(const void *i, const void *j);
void search_Null(int *mass_C,int size);
void sort_bubble(int *mass_N, int size);
void del_element(int *mass_N, int size);
int binarysearch(int a, int *mass, int n);
void input_mass_Null(int *mass_C,int size);
void search_same_element(int *mass_C, int size);
int common_elements(int *mass_A, int *mass_B, int size);
int check_same_element(int *mass_A, int *mass_B, int size);
void input_mass(int *mass_A,int *mass_B, int *mass_C,int size_A,int size_B);
void all_element_mass_A(int *mass_C, int *mass_A, int *mass_B, int size_A, int size_B);
void all_element_mass_A_and_B(int *mass_C, int *mass_A, int *mass_B, int size_A, int size_B);

int main() {

    int size_A, size_B, size_C;
    int number;
    char help;

    menu();
    scanf("%s",&help);
    if(help == 'h'){
        help_menu();
    }

    printf("Set the size of the array A: ");
    scanf("%d",&size_A);

    printf("Set the size of the array: ");
    scanf("%d",&size_B);

    size_C = size_A + size_B;

    int mass_A[size_A];
    int mass_B[size_B];
    int mass_C[size_C];

    input_mass_Null(mass_C,size_C);
    mass_rand(mass_A,size_A);
    mass_rand(mass_B,size_B);

    printf("Choose the option you want:");
    scanf("%d", &number);

    printf("\nMass A: ");
    print_mass(mass_A, size_A);
    printf("\n");

    printf("Mass B: ");
    print_mass(mass_B, size_B);
    printf("\n");

    switch (number) {
        case 1:
            printf("Mass C ");
            input_mass(mass_A, mass_B, mass_C, size_A,size_B);
            qsort(mass_C,size_C, sizeof(int),comp);
            del_element(mass_C, size_C);
            qsort(mass_C,size_C, sizeof(int),comp);
            print_mass(mass_C, size_C);
            RETURN;
        case 2:
            input_mass(mass_A, mass_B, mass_C, size_A,size_B);
            qsort(mass_C,size_C, sizeof(int),comp);
            printf("Mass C ");
            qsort(mass_C,size_C, sizeof(int),comp);
            search_same_element(mass_C, size_C);
            print_mass(mass_C, size_C);
            RETURN;
        case 3:
            printf("Mass C ");
            all_element_mass_A(mass_C, mass_A, mass_B, size_A,size_B);
            print_mass(mass_C, size_C);
            RETURN;
        case 4:
            printf("Mass C ");
            all_element_mass_A_and_B(mass_C, mass_A, mass_B, size_A,size_B);
            print_mass(mass_C, size_C);
            RETURN;
        case 5:
            qsort(mass_A,size_A, sizeof(int),comp);
            qsort(mass_B,size_B, sizeof(int),comp);
            if (check_same_element(mass_A, mass_B, size_A))
                return printf("Array B contains each element of array A.");
            return printf("Array B does not contain every element of array A.");
        case 6:
            if (check_same_element(mass_A, mass_B, size_A))
                return printf("Array A and B are the same.");
            return printf("Array A and B are not the same.");
        case 7:
            if (!common_elements(mass_A, mass_B, size_A))
                return printf("Not true.\nArrays A and B have common elements.");
            return printf("Right.\nArrays A and B have common elements.");
        case 8:
            printf("Mass C ");
            input_mass(mass_A, mass_B, mass_C, size_A,size_B);
            qsort(mass_C,size_C, sizeof(int),comp);
            print_mass(mass_C, size_C);
            RETURN;
        case 9:
            printf("Mass C ");
            input_mass(mass_A, mass_B, mass_C, size_A,size_B);
            qsort(mass_C,size_C, sizeof(int),comp);
            search_same_element(mass_C, size_C);
            print_mass(mass_C, size_C);
            RETURN;
        case 10:
            printf("Mass C ");
            int count = 0;
            //input_mass(mass_A, mass_B, mass_C, SIZE);
            for(int i = 0; i < size_A;i++){
                number = binarysearch(mass_A[i],mass_B,size_A);
                if(number != 1){
                    if(mass_A[i] != 0){
                        mass_C[count++] = mass_A[i];
                    }
                }
            }
            qsort(mass_C,size_C, sizeof(int),comp);
            search_Null(mass_C,size_C);
            RETURN;
        case 11:
            printf("Mass C ");
            int count_two = 0;
            for(int i = 0; i < size_B;i++){
                number = binarysearch(mass_B[i],mass_A,size_B);
                if(number != 1){
                    if(mass_A[i] != 0){
                        mass_C[count_two++] = mass_B[i];
                    }
                }
            }

            for(int i = 0; i < size_A;i++){
                number = binarysearch(mass_A[i],mass_B,size_A);
                if(number != 1){
                    if(mass_A[i] != 0){
                        mass_C[count_two++] = mass_A[i];
                    }
                }
            }
            qsort(mass_C,size_C, sizeof(int),comp);
            search_Null(mass_C,size_C);
            RETURN;
        case 12:
            qsort(mass_A,size_A, sizeof(int),comp);
            qsort(mass_B,size_B, sizeof(int),comp);
            if (check_same_element(mass_A, mass_B, size_A))
                return printf("Array B contains each element of array A.");
            return printf("Array B does not contain every element of array A.");
    }
}

void mass_rand(int *mass_N,int size){
    for(int i=0; i< size ; i++){
        a: mass_N[i]=1+rand()%10;
        for (int j=0; j<i; j++)
            if (mass_N[j]==mass_N[i]) goto a;
    }
}

void search_Null(int *mass_C,int size){
    for(int i = 0; i < size;i++){
        if(mass_C[i] != 0)
            printf("%d ",mass_C[i]);
    }
}

int binarysearch(int a, int *mass, int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
            high = middle - 1;
        else if (a > mass[middle])
            low = middle + 1;
        else
            return 1;
    }
    return -1;
}

int comp(const void *i, const void *j){
    return *(int *)i - *(int *)j;
}

int common_elements(int *mass_A, int *mass_B, int size){
    bool flag = false;
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (mass_A[i] == mass_B[j]) {
                 flag = true;
                return flag;
            }
        }
    }
    return flag;
}

int check_same_element(int *mass_A, int *mass_B, int size){
    int i = 0;
    int count = 0;
    bool flag = false;
    while(i != size){
        if(mass_A[i] == mass_B[i]){
            count++;
        }
        i++;
    }
    if(count == size){
        flag = true;
        return flag;
    }
    return flag;
}


void all_element_mass_A(int *mass_C, int *mass_A, int *mass_B, int size_A, int size_B){
    int count = 0;
    for(int i = 0; i < size_A;i++){
        bool flag = false;
        for(int j = 0; j < size_B;j++){
            if(mass_A[i] == mass_B[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            if(mass_C[count] != mass_A[i]){
                mass_C[count] = mass_A[i];
                count++;
            }
        }
    }
}

void all_element_mass_A_and_B(int *mass_C, int *mass_A, int *mass_B, int size_A, int size_B) {
    int count = 0;
    for(int i = 0; i < size_A;i++){
        bool flag = false;
        for(int j = 0; j < size_B;j++){
            if(mass_A[i] == mass_B[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            if(mass_C[count] != mass_A[i]){
                mass_C[count] = mass_A[i];
                count++;
            }
        }
    }
    for(int i = 0; i < size_B;i++){
        bool flag = false;
        for(int j = 0; j < size_A;j++){
            if(mass_B[i] == mass_A[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            if(mass_C[count] != mass_B[i]){
                mass_C[count] = mass_B[i];
                count++;
            }
        }
    }

}

void search_same_element(int *mass_C, int size){
    int count = 0, index = 0;
    int mass_element[size];
    for(int i = 0; i < size; i++){
        if(mass_C[i] == mass_C[i+1]){
            mass_element[index++] = mass_C[i];
            count++;
        }
        mass_C[i]=0;
    }
    for(int i = 0; i < count; i++){
        mass_C[i] = mass_element[i];
    }
}

void del_element(int *mass_N, int size){
    for(int i = 0; i < size; i++){
        if(mass_N[i] == mass_N[i+1]){
            mass_N[i+1] = 404;
        }
    }
}

void input_mass(int *mass_A,int *mass_B, int *mass_C,int size_A,int size_B){
    int c_index = 0;
    for (int i = 0; i < size_A; i++)
        mass_C[c_index++] = mass_A[i];
    for (int i = 0; i < size_B; i++)
        mass_C[c_index++] = mass_B[i];
}

void input_mass_Null(int *mass_C,int size){
    for(int i = 0; i < size; i++){
        mass_C[i] = 0;
    }
}

void print_mass(int *mass, int size){
    for (int i = 0; i < size; i++){
        printf("%d ",mass[i]);
    }
}

void sort_bubble(int *mass_N, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(mass_N[j] < mass_N[j+1]){
                int time = mass_N[j];
                mass_N[j] = mass_N[j+1];
                mass_N[j+1] = time;
            }
        }
    }
}


void menu(){
    printf("--------------------------");
    printf("\n| Welcome to my program|");
    printf("\n------------------------");
    printf("\nPress for help h.");
    printf("\nHelp is not needed press any other button.");
}

void help_menu(){
    printf("____________________________________________________________________________");
    printf("\n| Choose the desired version of the program");
    printf("\n| 1) Get array C containing all elements of arrays A and B without repetition.");
    printf("\n| 2) Get array C containing all such elements that are in both array A and array B.");
    printf("\n| 3) Get array C containing all the elements of array A that are not in B.");
    printf("\n| 4) Get array C containing all the elements of array\n|A that are not in B and all the elements of array B that are not in A.");
    printf("\n| 5) Determine if array B contains each element of array A.");
    printf("\n| 6) Determine whether it is true that the arrays A and B consist of the same elements.");
    printf("\n| 7) Determine if arrays A and B have no common elements.");
    printf("\n| 8) Get an array C, sorted in ascending order,\n|containing all the elements of arrays A and B.");
    printf("\n| 9) Get an array C, sorted in ascending order,\n|containing all such elements that are in both array A and array B.");
    printf("\n| 10) Get an array C, sorted in ascending order,\n|containing all the elements of array A that are not in B.");
    printf("\n| 11) Get an array C, sorted in ascending order,\n|containing all the elements of array A that are not in B and all the elements of array B that are not in A.");
    printf("\n| 12) Determine if array B contains each element of array A.\n");
}


