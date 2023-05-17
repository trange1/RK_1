//
// Created by alex2 on 18.03.2023.
//
#include "tasks_rk1.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include "cmath"
using namespace std;
//
//Task 2:
//
void writeToFile(const char* fileName, const char* strNum) {
    ofstream outFile(fileName);      // открываем файл для записи
    if (outFile.is_open()) {
        outFile << strNum;
        outFile.close();
    }
    else {
        cout << "Unable to open file";
    }
}
char* convertDecToBin(int number){
    char* Bin[100];
    

}
//
// Task3:
//
char* convertBinToHex(const char* binNum) {
    int len = strlen(binNum);
    char* hexNum = new char[(len + 3) / 4 + 1]; //Размер массива для 16чного числа
    int pos = 0;
    for (int i = 0; i < len; i += 4) { //каждую тетраду в шестнадцатеричное число
        int num = 0;
        for (int j = i; j < i + 4; j++) {
            num = num * 2 + binNum[j] - '0';
        }
        if (num < 10) {
            hexNum[pos++] = char(num + '0');
        } else {
            hexNum[pos++] = char(num - 10 + 'A');
        }
    }
    hexNum[pos] = '\0';
    return hexNum;
}
void writeToFileHex(const char* fileName, const char* hexNum, const char* binNum) {
    ofstream outFile(fileName); // открываем файл для записи
    if (outFile.is_open()) {
        outFile << hexNum << '\t' << binNum; // записываем результат в файл
        outFile.close(); // закрываем файл
    }
    else {
        cout << "Unable to open file";
    }
}
void task_3(const char* binNum ){
    char* hexNum = convertBinToHex(binNum);
    cout << hexNum << endl;
    writeToFileHex("output.txt", hexNum, binNum);
    delete[] hexNum;
}
//
// Task4:
//
void buildTree(int height) {
    for (int i = 0; i < height; i++) {              //
        for (int j = 0; j < height - i - 1; j++) {  //Вывод пробелов
            cout << " ";                            //
        }
        for (int j = 0; j < 2 * i + 1; j++) {       //
            cout << "*";                            //Вывод звезд
    }                                               //
        cout << endl;
    }
}
void task_4(int height){
    buildTree(height);
}
//
// Task 5:
//


