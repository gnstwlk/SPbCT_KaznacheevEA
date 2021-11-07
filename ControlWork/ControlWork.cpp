#include <fcntl.h>           /* Подключаемые файлы */
#include <io.h>             /* Подключаемые файлы */
#include <stdlib.h>        /* Подключаемые файлы */
#include <stdio.h>        /* Подключаемые файлы */
#include <share.h>       /* Подключаемые файлы */
#include <iostream>     /* Подключаемые файлы */
#include <locale.h>    /* Подключаемые файлы */
#include <fstream>    /* Подключаемые файлы */
using namespace std; //Использование стандартного пространства имён
char buffer[60000];//Установка размера буфера, куда будут записываться считанные байты. Максимум 60000
// Начало программы
int main(void)
{
    setlocale(LC_ALL, "Russian"); //подключение русского языка
    char ToFile[256];//переменная для записи пути к создаваемому файлу
    cout << "Введите путь к файлу: ";//сообщение
    cin >> ToFile;//присвоение переменной введённого значения
    ofstream ofs(ToFile); //создаём файл
    ofs.close();//закрываем файл
    int fh, bytesread, bytesWritten, allbr = 0;
    /*
    первая переменная - дескриптор файла, ссылающийся на открытый файл
    вторая переменная - переменная для записи количесвта прочитанных байт
    третья переменная - переменная для записи всех прочитанных байт
    */
    cout << "Введите текст: ";//сообщение
    cin >> buffer;//вводим данные, которые будут записаны
    /* Открытие файла для записи */
    if (_sopen_s(&fh, ToFile, _O_RDWR | _O_CREAT,
        _SH_DENYNO, _S_IREAD | _S_IWRITE))
        return -1;
        if ((bytesWritten = _write(fh, buffer, 60000)) == -1)
        {
            switch (errno)
            {
            case EBADF:
                perror("Bad file descriptor!");
                break;
            case ENOSPC:
                perror("No space left on device!");
                break;
            case EINVAL:
                perror("Invalid parameter: buffer was NULL!");
                break;
            default:
                // An unrelated error occurred
                perror("Unexpected error!");
            }
        }
    _close(fh);//закрытие файла
    unsigned int nbytes = 1024;//максимальное число байт для чтения
    /* Открытие файла для чтения */
    if (_sopen_s(&fh, ToFile, _O_RDONLY, _SH_DENYNO, 0))
    {
        perror("Неудалось открыть файл");//Вывод сообщения об ошибке, если не удалось открыть файл.
        exit(1);
    }
    /* Чтения файла */
    if ((bytesread = _read(fh, buffer, nbytes)) <= 0)
        // первое чтение с проверкой условия, инициализируется переменная bytesread
        perror("Неудалось прочитать файл");//сообщение об ошибке, если не удалось прочитать файл
    else
        cout << endl << "***Вывожу данные буфера консоли***" << endl;
    for (int i = 0; i < 60000; i++)
    {
        cout << buffer[i];
    } cout << endl;
    do
    {
        allbr += bytesread;
        (bytesread = _read(fh, buffer, nbytes));
    } while (bytesread != 0);
    /*
    выполнение цикла do...while(...)
    пока функция _read не вернёт в переменную byteread значение 0
     1. К переменной allbr прибавляется значение переменной bytesread
     2. Функция _read возвращает значение (количество прочитанных байт либо 0)
     3. Переменной nbytes присваивается значение 1024
     В отсутствии условного оператора пункт 1 и 2 меняются местами,
     так как инициализация переменной призойдёт только в пункте 2
     Проверка на соответствие условию
    */
    _close(fh);//закрытие файла
    printf("Прочитано %u байт из файла\n", allbr);//вывод количества прочитанных байт
}