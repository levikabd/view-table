#include <curses.h>
#include <ncurses.h>
#include <locale.h>  
#include <string>
#include <vector>

typedef wchar_t CHAR;

// Структура для хранения данных таблицы
struct TableData {    
    wchar_t* id;    // identifier; //20 
    wchar_t* object;    // name;    //50
    //wchar_t* whereobject; // where "";
    wchar_t* indicator; //"age";    //50
    wchar_t* period;                //50
    wchar_t* value; //age;          //20
};

class VTable
{
private:
    std::vector<TableData> table;
public:
    // VTable();
    // ~VTable();

    // void setTable();

    void setDemoTable();

    // void getTable();

    void outTable();

};

