// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "facultativ.h"

Facultativ::Facultativ(const int id, const int id_teacher, const QString discipline_name, const QString teacher_Name, const QString teacher_Surname)
{
    ID = id;
    ID_Teacher = id_teacher;
    Discipline_Name = discipline_name;
    Teacher_Name = teacher_Name;
    Teacher_Surname = teacher_Surname;
}

Facultativ::Facultativ()
{

}
