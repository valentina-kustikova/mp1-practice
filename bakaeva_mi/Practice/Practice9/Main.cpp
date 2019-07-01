#include "ToDoList.h"
#include "Task.h"
#include "Date.h"
#include "Time.h"
#include "conio.h"
#include "Exception.h"
using namespace std;

int main()
{
    ToDoList List;
    Date YourDate;

    try
    {
        List.read();
        cin >> YourDate;
        List.print(YourDate);
    }
    catch (Exception exp)
    {
        exp.Print();
    }
}