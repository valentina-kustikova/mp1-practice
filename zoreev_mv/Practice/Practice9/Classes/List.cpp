#include <iostream>
#include <fstream>
#include "../Headers/List.h"
#include "../Headers/Time.h"
#include "../Headers/Date.h"


using namespace std;

list_item::list_item()
{
    value = NULL;
    next = NULL;
}

list_item::list_item(task* temp)
{
    value = temp;
    next = NULL;
}

list_item::list_item(list_item& temp)
{
    value = temp.value;
    next = NULL;
}

list_item::~list_item()
{
    delete value;
}

calendar::calendar()
{
    head = NULL;
}

calendar::calendar(const calendar& temp)
{
    head = NULL;
}

calendar::~calendar()
{
    list_item *con, *del;
    for (list_item* i = head; i; i = con)
    {
        con = i->next;
        del = i;
        delete del;
    }
}
void calendar::create()
{
    task* temp_task;
    int control;
    cout << "You whant to add full day task? 1 for yes, 0 for no ";
    do
    {
        cin >> control;
    } while ((control != 1) && (control != 0));

    if (control)
    {
        temp_task = new task_day();
        temp_task->input();
    }
    else
    {
        temp_task = new task_std();
        temp_task->input();
    }

    //Если вставляем первый
    if (head == NULL)
    {
        head = new list_item;
        if (control)
        {
            head->value = temp_task;
        }
        else
        {
            head->value = temp_task;
        }
        return;
    }

    //Если надо заменить первого
    if ((temp_task->getDate() < head->value->getDate()) || ((temp_task->getDate() == head->value->getDate()) && (temp_task->getTime() < head->value->getTime())))
    {
        list_item* ins_item = new list_item;
        ins_item->next = head;
        head = ins_item;
        ins_item->value = temp_task;
        return;
    }

    //Тот случай когда надо подогнать по времени и дате
    list_item* i = head;
    for (; ((i->next != nullptr) && ((temp_task->getDate() > i->next->value->getDate()) || ((temp_task->getDate() == i->next->value->getDate()) && (temp_task->getTime() > i->next->value->getTime())))); i = i->next)
    {
    }
    list_item* ins_item = new list_item;
    ins_item->next = i->next;
    i->next = ins_item;
    ins_item->value = temp_task;
    return;
}

void calendar::clear()
{
    list_item *i,*con, *del;
    i = head;
    head = NULL;
    for (i; i; i = con)
    {
        con = i->next;
        del = i;
        delete del;
    }
}

void calendar::remove()
{
    date temp_date;
    time temp_time;
    int control;
    list_item *i = head, *del;
    cout << "You whant to remove full day task? 1 for yes, 0 for no ";
    do
    {
        cin >> control;
    } while ((control != 1) && (control != 0));
    if (!control)  
    {
        cout << "Input event date ";
        temp_date.input();
        cout << "Input event time ";
        temp_time.input();
        if ((head->value->getDate() == temp_date) && (head->value->getTime() == temp_time))
        {
            del = head;
            head = head->next;
            delete del;
            return;
        }
        for (i = head; (i->next != NULL) && !((i->next->value->getDate() == temp_date) && (i->next->value->getTime() == temp_time)); i = i->next)
        {
        }
        if (i == NULL)
        {
            cout << "Элемент не найден";
            return;
        }
        del = i->next;
        i->next = del->next;
        delete del;
    }
    else
    {
        cout << "Input event date ";
        temp_date.input();
        if ((head->value->getDate() == temp_date) && (head->value->getTime() == 1440))
        {
            del = head;
            head = head->next;
            delete del;
            return;
        }
        for (i = head; (i->next != NULL) && !((i->next->value->getDate() == temp_date) && (i->next->value->getTime() == 1440)); i = i->next);
        {
        }
        if (i == NULL)
        {
            cout << "Элемент не найден";
            return;
        }
        del = i->next;
        i->next = del->next;
        delete del;
    }
    
}

void calendar::print()
{
    date print_date;
    cout << "Input day to show ";
    print_date.input();
    list_item* i = head;
    if (i == NULL)
    {
        cout << "Your to do list is empty" << endl;
        return;
    }
    for (; (i != NULL) && !(i->value->getDate() == print_date); i = i->next);
    {
    }
    if (i == NULL)
    {
        cout << "Tasks for this day unfounded" << endl;
        return;
    }

    for (;(i != NULL) && (i->value->getDate() == print_date && i->value->isStd()); i = i->next)
    {
        i->value->print();
        cout << endl;
    }
    if ((i != NULL) && (i->value->getDate() == print_date))
    {
        cout << "Whole day tasks" << endl;
    }
    for (; (i != NULL) && (i->value->getDate() == print_date); i = i->next)
    {
        i->value->print();
        cout << endl;
    }
}

void calendar::fread()
{
    ifstream file;
    int type;
    string path;
    cout << "Enter path to .cal file ";
    getchar();
    getline(cin, path);
    file.open(path);
    if (!file.is_open())
    {
        cout << "Open error" << endl;
        return;
    }
    clear();
    //Чтение с записью в head
    if (!file.eof())
    {
        file >> type;
        if (type)
        {
            head = new list_item;
            head->value = new task_std;
            head->value->fread(file);
        }
        else
        {
            head = new list_item;
            head->value = new task_day;
            head->value->fread(file);
        }
    }

    //Чтение остальных
    for (list_item* i = head; !file.eof(); i = i->next)
    {
        file >> type;
        if (type)
        {
            i->next = new list_item;
            i->next->value = new task_std;
            i->next->value->fread(file);
        }
        else
        {
            i->next = new list_item;
            i->next->value = new task_day;
            i->next->value->fread(file);
        }
    }
    file.close();
}

void calendar::fwrite()
{
    ofstream file;
    string path;
    getchar();
    cout << "Enter path to .cal file ";
    getline(cin, path);
    file.open(path);
    if (!file.is_open())
    {
        cout << "Open error" << endl;
        return;
    }
    for (list_item* i = head; i; i = i->next)
    {
        file << i->value->isStd() << ' ';
        i->value->fwrite(file);
        file << endl;
    }
    file.close();
}