#include <curses.h>
#include <ncurses.h>
#include <locale.h>  
#include <string>
#include <vector>

#include "view-table.h"

typedef wchar_t CHAR;

// // Структура для хранения данных таблицы
// struct TableData {    
//     wchar_t* id;    // identifier; //20 
//     wchar_t* object;    // name;    //50
//     //wchar_t* whereobject; // where "";
//     wchar_t* indicator; //"age";    //50
//     wchar_t* period;                //50
//     wchar_t* value; //age;          //20
// };


// class VTable
// {
// private:
//     std::vector<TableData> table;

// public:
//     // VTable();
    // ~VTable();

    //void VTable::setTable();

    // void VTable::setDemoTable();

    // void VTable::getTable();

    //void VTable::outTable(WINDOW *win, int rows, int cols, int offsety, int offsetx);

//};


void VTable::setDemoTable()
{
    TableData data0  = {L"", L"Иван Петров",    L"age", L"", L"25"};
    TableData data1  = {L"", L"Анна Сидорова",  L"age", L"", L"30"};
    TableData data2  = {L"", L"Петр Иванов",    L"age", L"", L"22"};
    TableData data3  = {L"", L"Мария Козлова",  L"age", L"", L"28"};

    table.push_back(data0);
    table.push_back(data1);
    table.push_back(data2);
    table.push_back(data3);    
};

void VTable::outTable()
{

    // Инициализация ncurses
    setlocale(LC_ALL, "ru_RU.UTF-8") ; 
    initscr();
    curs_set(0);  // Скрываем курсор
    start_color();  // Инициализация цветов
    
    // // Получаем размеры окна
    // int height, width;
    // getmaxyx(win, height, width);

    // Создаем окно
    const int width = 197;
    const int height = 15;
    // int offsetx = (COLS - width) / 2;
    // int offsety = (LINES - height) / 2;
    // WINDOW *win = newwin(height, width, offsety, offsetx);
    // outDataTable(win, width, height, offsety, offsetx);
    WINDOW *win = newwin(height, width, 0, 0);


    // Устанавливаем цвета (опционально)
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    wbkgd(win, COLOR_PAIR(1));    
    // Очищаем окно
    wclear(win);

    // Создаем тестовые данные для таблицы
    
    // Рисуем рамку вокруг окна
    box(win, 0, 0);

    for(int k = 2; k < width; k++) {
        mvaddch(1, k, ACS_HLINE);
    };

    mvaddwstr(2, 3, L"id");         // 3-22
    mvaddwstr(2, 24, L"Объект");    // 24-73
    mvaddwstr(2, 75, L"Показатель");    // 75-124
    mvaddwstr(2, 126, L"Период");       // 126-175
    mvaddwstr(2, 177, L"Значение");     // 177-196
    mvaddch(2,2, ACS_VLINE);
    mvaddch(2,23, ACS_VLINE);
    mvaddch(2,74, ACS_VLINE);
    mvaddch(2,125, ACS_VLINE);
    mvaddch(2,176, ACS_VLINE);
    mvaddch(2,197, ACS_VLINE);
    
    //mvaddstr(3, 1, "------------------------------------------------");
    
    // Выводим данные таблицы
    int row = 3;
    for (const auto& item : table) {

        for(int k = 2; k < width-1; k++) {
            mvaddch(row, k, ACS_HLINE);
        };      
        mvaddch(row,2, ACS_PLUS);
        mvaddch(row,23, ACS_PLUS);
        mvaddch(row,74, ACS_PLUS);
        mvaddch(row,125, ACS_PLUS);
        mvaddch(row,176, ACS_PLUS);
        mvaddch(row,197, ACS_PLUS);
  
        row++;

        std::wstring sid = item.id;
        sid=sid.substr(0,20);
        wchar_t* id = const_cast<wchar_t*>(sid.c_str());
        mvaddwstr(row, 3, id);
        
        std::wstring sname = item.object;
        sname=sname.substr(0,20);
        wchar_t* name = const_cast<wchar_t*>(sname.c_str());
        mvaddwstr(row, 24, name);

        std::wstring sindicator = item.indicator;
        wchar_t* indicator = const_cast<wchar_t*>(sindicator.c_str());
        mvaddwstr(row, 75, indicator);

        std::wstring speriod = item.period;
        wchar_t* period = const_cast<wchar_t*>(speriod.c_str());
        mvaddwstr(row, 126, period);

        std::wstring svalue = item.value;
        wchar_t* value = const_cast<wchar_t*>(svalue.c_str());
        mvaddwstr(row, 177, value);

        mvaddch(row,2, ACS_VLINE);
        mvaddch(row,23, ACS_VLINE);
        mvaddch(row,74, ACS_VLINE);
        mvaddch(row,125, ACS_VLINE);
        mvaddch(row,176, ACS_VLINE);
        mvaddch(row,197, ACS_VLINE);

        row++;
    };

    for(int k = 2; k < width-1; k++) 
    {
        mvaddch(row, k, ACS_HLINE);
    };

    wrefresh(win);

    getch();

    delwin(win);
    endwin();

};
