#include <chrono>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

void naive_var(std::string& str)
{
    int arr[26] = {0};
    char curent;
    
    for(char current: str) 
    {
        if (curent == 'A' || curent == 'a') {
            arr[0]++; }
        else if (curent == 'B' || curent == 'b') {
            arr[1]++; }
        else if (curent == 'C' || curent == 'c') {
            arr[2]++; }
        else if (curent == 'D' || curent == 'd') {
            arr[3]++; }
        else if (curent == 'E' || curent == 'e') {
            arr[4]++; }
        else if (curent == 'F' || curent == 'f') {
            arr[5]++; }
        else if (curent == 'G' || curent == 'g') {
            arr[6]++; }
        else if (curent == 'H' || curent == 'h') {
            arr[7]++; }
        else if (curent == 'I' || curent == 'i') {
            arr[8]++; }
        else if (curent == 'J' || curent == 'j') {
            arr[9]++; }
        else if (curent == 'K' || curent == 'k') {
            arr[10]++; }
        else if (curent == 'L' || curent == 'l') {
            arr[11]++; }
        else if (curent == 'M' || curent == 'm') {
            arr[12]++; }
        else if (curent == 'N' || curent == 'n') {
            arr[13]++; }
        else if (curent == 'O' || curent == 'o') {
            arr[14]++; }
        else if (curent == 'P' || curent == 'p') {
            arr[15]++; }
        else if (curent == 'Q' || curent == 'q') {
            arr[16]++; }
        else if (curent == 'R' || curent == 'r') {
            arr[17]++; }
        else if (curent == 'S' || curent == 's') {
            arr[18]++; }
        else if (curent == 'T' || curent == 't') {
            arr[19]++; }
        else if (curent == 'U' || curent == 'u') {
                arr[20]++; }
        else if (curent == 'V' || curent == 'v') {
                arr[21]++; }
        else if (curent == 'W' || curent == 'w') {
                arr[22]++; }
        else if (curent == 'X' || curent == 'x') {
                arr[23]++; }
        else if (curent == 'Y' || curent == 'y') {
                arr[24]++; }
        else if (curent == 'Z' || curent == 'z') {
                arr[25]++; }
    }
}

void kirill_var(std::string& str)
{
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int count = 0;

    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c){ return std::tolower(c); });

    for(int i = 0; alpha[i]; i++)
    {
        for(char curr_char: str)
            if(alpha[i] == curr_char)
                count++;

        count = 0;
    }
}

void ruslan_var(std::string& str)
{
    char answ[26] = {0};

    for(char curr_char: str)
        answ[   
                + (int)curr_char
                - (int)(curr_char < 'a') * (int)'A' 
                - (int)(curr_char > 'Z') * (int)'a'
            ]++;
}

int main()
{   
    std::string text;
    std::ifstream infile("str.txt");
    std::getline(infile, text);

    using namespace std::chrono;


    auto start = high_resolution_clock::now();
    kirill_var(text);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Kirill's var: " << duration.count() << std::endl;

    std::cout << std::endl;

    start = high_resolution_clock::now();
    ruslan_var(text);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Ruslan's var: " << duration.count() << std::endl;

    std::cout << std::endl;

    start = high_resolution_clock::now();
    naive_var(text);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Naive var:    " << duration.count() << std::endl;

    return 0;
}
