#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
class Task
{
public:
    string description;
    bool completed;
    string title;
    Task(const string &tit, const string &desc) : description(desc), completed(false), title(tit) {}
};

class ToDoList
{
private:
    vector<Task> tasks;
    string date = __DATE__;

    int search(const string &title)
    {
        int index = -1;
        // searchig for index
        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].title == title)
            {
                index = i;
                break;
            }
        }
        return index;
    }

public:
    // To add task
    void addTask(const string &title, const string &desc)
    {

        int index = search(title);
        if (index == -1)
        {
            Task newTask(title, desc);
            tasks.push_back(newTask);
            cout << "Task added!" << endl;
        }
        else
        {
            cout << "Title alreay exist try with another task tile" << endl;
        }
    }

    void markTaskAsCompleted(const string &comp_title)
    {

        // marking as read if index found
        int index = search(comp_title);
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].completed = true;
            cout << "Task marked as completed!\n";
        }
        else
        {
            cout << "Invalid task title.\n";
        }
    }

    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks to display.\n";
            return;
        }

        cout << "Tasks:\n";
        cout << "Date: " << date << endl;
        // table
        int colWidth = 40;
        cout << setfill('*') << setw(3 * colWidth) << "*" << endl;
        cout << setfill(' ') << fixed;
        cout << setw(3) << "Index" << setw(colWidth) << "Title" << setw(colWidth) << "Description" << endl;
        cout << setfill('*') << setw(3 * colWidth) << "*" << endl;
        cout << setfill(' ') << fixed;
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << setprecision(0) <<i + 1 << ". ";
            if (tasks[i].completed)
            {
                cout << "[Completed] ";
            }
             cout << setprecision(4) << setw(colWidth)
                 << tasks[i].title << setw(colWidth) << tasks[i].description << endl;
        }
    }

    void removeTask(const string del_title)
    {
        int index = search(del_title);
        if (index >= 0 && index < tasks.size())
        {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed!\n";
        }
        else
        {
            cout << "Invalid task title.\n";
        }
    }
};

int main()
{
    ToDoList todo;

    while (true)
    {
        cout << "To-Do List Application" << endl;
        ;
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Remove Task\n";
        // cout<<"5. "
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cin.ignore(); // Clear newline from buffer
            string description;
            string title;
            cout << "Enter task title: ";
            std::getline(cin, title);
            cout << "Enter task description: ";
            std::getline(cin, description);
            todo.addTask(title, description);
            break;
        }
        case 2:
        {
            // cout << "Enter task index: ";
            // int index;
            // cin >> index;
            // todo.markTaskAsCompleted(index);
            cout << "Enter task title which you have completed: ";
            string comp_title;
            cin >> comp_title;
            todo.markTaskAsCompleted(comp_title);
            break;
        }
        case 3:
        {
            todo.viewTasks();
            break;
        }
        case 4:
        {
            cout << "Enter task title which you want to delete: ";
            string del_title;
            cin >> del_title;
            todo.removeTask(del_title);
            break;
        }
        case 5:
            cout << "Exiting.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
