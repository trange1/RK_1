//
// Created by alex2 on 18.03.2023.
//
#include "tasks_rk1.h"
#include <iostream>
#include <vector>
#include "cstring"
#include "cmath"
using namespace std;
//
// Task1:
//
void WorkWithFile::readFromFile (const char* filename) {
    FILE *res = fopen(filename, "r");
    if(res) {
        while (fgets(dataOfFile, 2000, res) != nullptr){
        }
    }
    fclose(res);
}
void WorkWithFile::prepareTestFile(const char* filename) {
    FILE *res = fopen(filename, "w");
    fprintf(res, "%s","Testing text" ); //текст в исходном файле
    fclose(res);
}
WorkWithFile::WorkWithFile(const char* filename){
    prepareTestFile(filename);
    readFromFile (filename);
}
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}
void WorkWithFile::writeStatInfoToFile(const char* outFile){
    FILE *res = fopen(outFile, "w");
    int count[100];
    for (int i = 0; i<91; i++){
        count[i] = 0;
    }
    for(int i = 0; i < strlen(dataOfFile); i++) {
        count[int(dataOfFile[i])-33]++;
    }
    for(int i = 0; i < 91;i++){
        if (count[i]!=0)
            fprintf(res, "%c\t%i\n", char(i+33), count[i]);
    }
    fclose(res);
}
void task_1() {
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_task1.txt");
}
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
    char* bin = new char[33];
    int i = 0;
    while (number > 0) {
        bin[i++] = number % 2 + '0';
        number /= 2;
    }
    bin[i] = '\0';
    int len = strlen(bin);
    for (int j = 0; j < len / 2; j++) {
        char temp = bin[j];
        bin[j] = bin[len - j - 1];
        bin[len - j - 1] = temp;
    }
    return bin;

}
void task_2(){
    int number = 234; // Входное десятичное число
    writeToFile("result_task2.txt" , convertDecToBin(number));//Запись в файл(имя файла|конвертированное десят. число)
    delete[] convertDecToBin(number); //Очистка памяти
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
void task_3(){
    const char* binNum = "100011010111";
    char* hexNum = convertBinToHex(binNum);
    writeToFileHex("result_task3.txt", hexNum, binNum);
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
void task_4(){
    int height = 5; //Высота ёлочки
    buildTree(height);
}
//
// Task 5:
//
vector <pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount) {
    vector <pair <int, float> > result;
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += ar[i * colCount + j];
        }
        float aver = sum / colCount;
        result.push_back(make_pair(i, aver));
    }
    return result;
}
void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++)
        ar[i] = rand() % 100;

}
void task_5(){
    const int colCount = 5;    //Количество столбцов
    const int rowCount = 14;   //Количество строк
    float ar[colCount * rowCount];
    randFill(ar, colCount * rowCount);
    vector <pair <int, float> > result = averStr2DArray(ar, colCount, rowCount);
    fstream file("result_task5.txt", ios::out);
    if (file.is_open()) {
        for (auto pair : result) {
            file << "Row " << pair.first << " : " << fixed << setprecision(2) << pair.second << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}
