#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

class PrinterQueue
{
    // your attributes
    map<int, queue<string>, greater<int>> printerQueue;
public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        printerQueue[priority].push(fileName);
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        if (printerQueue.empty()) {
            cout << "No file to print" << endl;
            return;
        }

        auto it = printerQueue.begin();
        queue<string>& files = it->second;

        string fileName = files.front();
        files.pop();

        if (files.empty()) {
            printerQueue.erase(it);
        }

        cout << fileName << endl;
    }
};

int main() {
    PrinterQueue* myPrinterQueue = new PrinterQueue();
    myPrinterQueue->addNewRequest(1, "hello.pdf");
    myPrinterQueue->print();
    myPrinterQueue->print();
    myPrinterQueue->print();

    return 0;
}