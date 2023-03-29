//
// Created by alex2 on 18.03.2023.
//

#ifndef RK1_TASKS_RK1_H
#define RK1_TASKS_RK1_H
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include <bits/stdc++.h>
#include <string>
#include <ctime>
class WorkWithFile {
private :
    char* dataOfFile = new char[20000];
    void readFromFile(const char* fileName);
    void prepareTestFile(const char* fileName);
public :
    WorkWithFile(const char* fileName);
    ~WorkWithFile();
    void writeStatInfoToFile(const char* outFile);
};

void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6und7();

void writeToFile(const char* fileName, const char* strNum);
char* convertDecToBin(int);
char* convertBinToHex(const char*);
void writeToFileHex(const char* , const char* , const char* );
void buildTree(int);

struct Node  {
    Node* next;
    Node* prev;
    int nameNode;	//имя узла
    static int countNodes;
};
class LinkedList {
private :
    Node* Head;
    Node* Tail;
public :
    LinkedList();
    ~LinkedList();

    void push_back(int nameNode);
    void writeToFileFromTail();
    void writeToFileFromHead();
    void insert(int nameNode, int position); // 7 Задание
};

#endif
