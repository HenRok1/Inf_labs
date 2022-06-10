#include "v3.h"

using namespace std;

// void case1(int otvet_prom, Education_Institution* education_institution, int otvet_global);
   

class Education_Institution {
    public:
        virtual string getStudent() = 0;
        virtual string getTeacher() = 0;
};

class School: public Education_Institution {
    private:
        int students;
        int teachers;
    public:
        School(int students, int teachers) : students(students), teachers(teachers) {}

        string getStudent() override {
            if (students > 2000)
                return "В школе учиться много людей";
            else if (students < 2000 && students > 1000)
                return "В школе учиться среднее количество людей";
            else return "В школе учиться меньше среднего людей";
        }
        string getTeacher() override {
            if (teachers > 100)
                return "В школе работают много учителей";
            else return "В школе работает среднее количество учителей";
        }
};

class Vuz: public Education_Institution {
    private:
        int students;
        int lecturer;
        int teachers;
        int years;

    public:
        Vuz(int students, int lecturer, int teachers, int years) : students(students), lecturer(lecturer), teachers(teachers), years(years) {}

        string getStudent() override {
            if (students > 20000)
                return "В вузе учиться много людей: ";
            else if (students < 20000 && students > 10000)
                return "В вузе учиться среднее количество людей: ";
            else return "В вузе учиться меньше среднего людей: ";
        }
        string getLecturer() {
            if (lecturer > 50)
                return "В вузе работают много лекторов: ";
            else return "В вузе работает среднее количество лекторов: ";
        }
        string getTeacher() override {
            if (teachers > 100)
                return "В вузе работают много преподавателей: ";
            else return "В вузе работает среднее количество преподавателей: ";
            }
        string getYear() {
            if (years > 2000)
                return "Ваш вуз построен совсем недавно: ";
            else
                return "Ваш вуз построен достаточно давно: ";
        }     
};

class University : public Education_Institution{
    private:
        int students;
        int teacher;
        int institute;
        int years;

    public:
        University(int students, int teacher, int institute , int years) : students(students), teacher(teacher), institute(institute), years(years) {}

        string getStudent() override {
            if (students > 20000)
                return "В университете учиться много людей";
            else if (students < 20000 && students > 10000)
                return "В университете учиться среднее количество людей";
            else return "В университете учиться меньше среднего людей";
        }
        string getTeacher() override {
            if (teacher > 50)
                return "В университете работают много преподавателей";
            else return "В университете работает среднее количество преподавателей";
        }
        string getInstitute() {
            if (institute > 10)
                return "В вашем университете много институтов";
            else
                return "В вашем университете среднее значение институтов";
        }
        string getYear() {
            if (years > 2000)
                return "Ваш университете построен совсем недавно";
            else
                return "Ваш университете построен достаточно давно";
        } 
};

class Institute : public Education_Institution {
    private:
        int students;
        int teacher;
        int years;
    public:
        Institute(int students, int lecturer , int years) : students(students), teacher(teacher), years(years) {}

        string getStudent() override {
            if (students > 20000)
                return "В институте учиться много людей";
            else if (students < 20000 && students > 10000)
                return "В институте учиться среднее количество людей";
            else return "В институте учиться меньше среднего людей";
        }
        string getTeacher() override {
            if (teacher > 50)
                return "В институте работают много лекторов";
            else return "В институте работает среднее количество лекторов";
        }
        string getYear() {
            if (years > 2000)
                return "Ваш институте построен совсем недавно";
            else
                return "Ваш институте построен достаточно давно";
        }
};

// void case1(int otvet_prom, Education_Institution* education_institution, int otvet_global) {
//     int flag;
//     while (otvet_prom != 0)
//         cout << "А теперь выведем данные о нашей школе" << endl;
//         cout << "1) Информация об обучающихся" << endl;
//         cout << "2) Информация об учителях" << endl;
//         cout << "3)Не хочу выбирать тут и хочу вернуться назад" << endl;
//         cin >> flag;
//         switch (flag)
//         {
//         case 1:
//             cout << "Информация об обучающихся: " << education_institution->getStudent() << endl;
//             break;
//         case 2:
//             cout << "Информация об учителях" << education_institution->getTeacher() << endl;
//             break;
//         default:
//             cout << "Хорошо, уходим из этого пункта" << endl;
//             otvet_prom = 0;
//             otvet_global = 0;
//             break;
//         }    
    
// }

int main() {
    setlocale(LC_ALL, "RUS");
    int otvet, otvet_global, otvet_prom, otvet_main = 1;
    int students, teachers, lecturer, years, institute;

    while (otvet_main != 0) {
        otvet_prom = 1;
        cout << "Выберете одно из учебных заведений или выйдете из программы: " << endl;
        cout << "1) Школа" << endl;
        cout << "2) Вуз" << endl;
        cout << "3) Университет" << endl;
        cout << "4) Институт" << endl;
        cout << "0) Выйти из программы" << endl;

        cin >> otvet_global;
		otvet_main = otvet_global;
		cout << endl;

        Education_Institution* education_institution;
        while (otvet_global == 1 || otvet_global == 2 || otvet_global == 3 || otvet_global == 4) {
			if (otvet_global == 1){
                cout << "Вы выбрали школу, введите для начала количество студентов: ";
                cin >> students;
                cout << "Введите количество учителей: ";
                cin >> teachers;
                cout << endl;

                education_institution = new School(students, teachers);
                School school_1(students, teachers);
                
                while (otvet_prom != 0) {
                    cout << "А теперь выведем данные о нашей школе" << endl;
                    cout << "1) Информация об обучающихся" << endl;
                    cout << "2) Информация об учителях" << endl;
                    cout << "3) Не хочу выбирать тут и хочу вернуться назад" << endl;
			
            		cin >> otvet;
					otvet_prom = otvet;

                    if (otvet == 1) {
                        cout << "Информация об обучающихся: " << education_institution->getStudent() << endl;
					}
					else if (otvet == 2) {
                        cout << "Информация об учителях" << education_institution->getTeacher() << endl;
					} else {
						cout << "Хорошо, уходим из этого пункта" << endl;
						otvet_prom = 0;
						otvet_global = 0;
					}
                }

            } else if (otvet_global == 2) {
                cout << "Вы выбрали ВУЗ, введите для начала количество студентов: ";
                cin >> students;
                cout << "Введите количество преподователей: ";
                cin >> teachers;
                cout << "Введите количество лекторов: ";
                cin >> lecturer;
                cout << "Введите год создания вуза: ";
                cin >> years;
                cout << endl;

                education_institution = new Vuz(students, lecturer, teachers, years);
                Vuz education_institution1(students, lecturer, teachers, years);
                
                while (otvet_prom != 0) {
                    cout << "А теперь выведем данные о нашем вузе" << endl;
                    cout << "1) Информация об обучающихся" << endl;
                    cout << "2) Информация о преподователях" << endl;
                    cout << "3) Информация о лекторах" << endl;
                    cout << "4) Инормация о годе создания" << endl;
                    cout << "5) Не хочу выбирать тут и хочу вернуться назад" << endl;
                    cin >> otvet;
                    otvet_prom = otvet;

                if (otvet == 1) 
                        cout << "Информация об обучающихся: " << education_institution->getStudent() << endl;
                 else if (otvet == 2) 
                    cout << "Информация о преподователях: " << education_institution->getTeacher() << endl;
                 else if (otvet == 3) 
                    cout << "Информаци о лекторах: " << education_institution1.getLecturer() << endl;
                 else if (otvet == 4) 
                    cout << "Инормация о годе создания: " << education_institution1.getYear() << endl;
                 else if (otvet = 5) {
                    cout << "Хорошо, уходим из этого пункта: " << endl;
                    otvet_prom = 0;
                    otvet_global = 0;
                    }
                }

            } else if (otvet_global == 3) {
                cout << "Вы выбрали университет, введите для начала количество студентов: ";
                cin >> students;
                cout << "Введите количество лекторов: ";
                cin >> lecturer;
                cout << "Введите количество институтов: ";
                cin >> institute;
                cout << "Введите год создания вуза: ";
                cin >> years;
                cout << endl;

                education_institution = new University(students, teachers, institute, years);
                University education_institution1(students, teachers, institute, years);

                while (otvet_prom != 0) {
                    cout << "А теперь выведем данные о нашем университете" << endl;
                    cout << "1) Информация об обучающихся" << endl;
                    cout << "2) Информация о преподователях" << endl;
                    cout << "3) Информация об институтах" << endl;
                    cout << "4) Инормация о годе создания" << endl;
                    cout << "5) Не хочу выбирать тут и хочу вернуться назад" << endl;
                    cin >> otvet;
                    otvet_prom = otvet;

                    if (otvet == 1) 
                        cout << "Информация об обучающихся: " << education_institution->getStudent() << endl;
                    else if (otvet == 2) 
                        cout << "Информация о преподователях: " << education_institution->getTeacher() << endl;
                    else if (otvet == 3) 
                        cout << "Информаци о лекторах: " << education_institution1.getInstitute() << endl;
                    else if (otvet == 4) 
                        cout << "Инормация о годе создания: " << education_institution1.getYear() << endl;
                    else if (otvet = 5) {
                        cout << "Хорошо, уходим из этого пункта: " << endl;
                        otvet_prom = 0;
                        otvet_global = 0;
                    }
                }
            } else if (otvet_global = 4) {
                cout << "Вы выбрали институт, введите для начала количество студентов: ";
                cin >> students;
                cout << "Введите количество лекторов: ";
                cin >> teachers;
                cout << "Введите год создания вуза: ";
                cin >> years;
                cout << endl;

                education_institution = new Institute(students, teachers, years);
                Institute education_institution1(students, teachers, years);

                while (otvet_prom != 0) {
                    cout << "А теперь выведем данные о нашем институте" << endl;
                    cout << "1) Информация об обучающихся" << endl;
                    cout << "2) Информация о преподователях" << endl;
                    cout << "3) Инормация о годе создания" << endl;
                    cout << "4) Не хочу выбирать тут и хочу вернуться назад" << endl;
                    cin >> otvet;
                    otvet_prom = otvet;

                    if (otvet == 1) 
                        cout << "Информация об обучающихся: " << education_institution->getStudent() << endl;
                    else if (otvet == 2) 
                        cout << "Информация о преподователях: " << education_institution->getTeacher() << endl;
                    else if (otvet == 3) 
                        cout << "Инормация о годе создания: " << education_institution1.getYear() << endl;
                    else if (otvet = 4) {
                        cout << "Хорошо, уходим из этого пункта: " << endl;
                        otvet_prom = 0;
                        otvet_global = 0;
                    }
                }
            } else if (otvet_global == 5) {
                cout << "Что то пошло не так" << endl;
                otvet_global = 0;
                otvet_main = 0;
                // break;
            }
        }
    }
    cout << "Программа завершена. Спасибо за тест";
    return 0;
}

