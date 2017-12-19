
#include <iostream>
#include <string.h>
using namespace std;

enum rules{
    //enumerating rules
    FIRST_RULE = 1,
    SECOND_RULE,
    THIRD_RULE,
    FOURTH_RULE
};

int main(int argc, char *argv[]){

    if(argc != 3){//controlling of amount of arguments is 3, if not exit.
        cout<< "please enter just 3 arguments" <<endl;
        exit(EXIT_FAILURE);
    };


    int dimention = atoi(argv[1]);//we convert information of dimention into integer type and assign to the variable dimention

    if(strlen(argv[2]) != dimention*dimention ){//controling if dimention and amount of given elements are compatible or not.
        cout<<"Please enter right amount of elements "<<endl;
        exit(EXIT_FAILURE);

    };

    int arr[20][20] = {};
    int  rule_num = 0;//holds the rule number which given values dont suit to
    int xIndex = 0, yIndex = 0;//holds  location of the first value that dont suit to rules

    for(int i = 0; i<dimention; i++){//filling the arr matrix by values that given by user, after converting char* typed values into int typed
        for(int j = 0; j<dimention; j++){
            char charelement = argv[2][(i)*dimention+j] - '0';//when (i)*dimention+j goes to dimention*dimention  for every j, we split it and pass into the row below it
                                                            //so we can order given values into matrix 
                                                            //(tr) liste seklinde verilen degerleri matriks haline getiriyoruz.
            int  intelement = (int)charelement;
            if(intelement>4){
                cout<<"You can not enter numbers greater than 4"<<endl;
                exit(EXIT_FAILURE);
            };
            arr[i][j] = intelement;
        };
    };
    
    /*check matrix according to rules*/
    for(int x = 0; x<dimention; x++){
         for(int y = 0; y < dimention; y++){

            if(arr[x+1][y] == 1){
                if(arr[x][y] == 2){
                    if(rule_num == 0){
                    rule_num =FIRST_RULE;
                    xIndex = x;
                    yIndex = y;
                    };
                };
            };

            if(arr[x][y-1] == 2){//checking for second rule,if dont suit, change the value of rule_num as SECOND_RULE
                if(arr[x][y] == 3){
                    if(rule_num == 0){
                        rule_num = SECOND_RULE;
                        xIndex = x;
                        yIndex = y;
                    };
                };
            };

            if(arr[x-1][y] == 3){//checking for third rule
                if(arr[x][y] == 4){
                    if(rule_num == 0){
                        rule_num = THIRD_RULE;
                        xIndex = x; 
                        yIndex = y;
                    };
                };
            };

            if(arr[x][y+1] == 4){//checking for fourth rule
                if(arr[x][y] == 1){
                    if(rule_num == 0){
                        rule_num = FOURTH_RULE;
                        xIndex = x;
                        yIndex = y;
                    };
                };
            };

        };
    };
    /*SHOWING RESULTS*/
    switch(rule_num){
        case 0:
            cout<<"ACCEPTED"<<endl;
            break;
        case 1:
            cout<<"NOT MATCH ["<<xIndex<<"]["<<yIndex<<"] : "<<arr[xIndex][yIndex]<<endl;
            cout<<"REASON : RULE "<<rule_num<<endl;
            break;
        case 2:
            cout<<"NOT MATCH ["<<xIndex<<"]["<<yIndex<<"] : "<<arr[xIndex][yIndex]<<endl;
            cout<<"REASON : RULE "<<rule_num<<endl;
            break;
        case 3:
            cout<<"NOT MATCH ["<<xIndex<<"]["<<yIndex<<"] : "<<arr[xIndex][yIndex]<<endl;
            cout<<"REASON : RULE "<<rule_num<<endl;
            break;
        case 4:
            cout<<"NOT MATCH ["<<xIndex<<"]["<<yIndex<<"] : "<<arr[xIndex][yIndex]<<endl;
            cout<<"REASON RULE "<<rule_num<<endl;
            break;
    };
};


