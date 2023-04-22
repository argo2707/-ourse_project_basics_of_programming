# Course_project_basics_of_programming
*Данная работы была написана на 2 курсе обучения в университете*

## Цель проектирования
Целью курсового проектирования является закрепление теоретических и практических знаний, полученных на лекционных, лабораторных и практических занятиях по курсу, а также получение навыков разработки, отладки и тестирования программ на алгоритмических языках программирования.
## Постановка задачи
1. Задачей курсового проекта является разработка программы «Учёт успеваемости студентов» с использованием заданных структур данных, которая позволяет вводить информацию, хранить её в файле, осуществлять поиск, модификацию, сортировку и удаление данных.
2. Тип хранимой информации и задание на поиск определяются в соответствии с номером варианта

#### *Вариант:*
Данные о студентах хранятся в структуре STUDENT, содержащей следующие поля:
- Фамилия и инициалы;
- Номер группы;
- Успеваемость (массив из пяти элементов)
Задание на поиск: найти студентов, чей средний бал не меньше указанного пользователем значения.


## Описание структуры данных
Данные о студентах хранятся в структуре *STUDENT*
````
struct STUDENT
{
	char* fio;		// фамилия 
	char* init;	 	//инициалы
	int number;		// номер группы
	int perform[5];	// успеваемость 
};
````
База данных хранится на диске в виде текстового файла в формате TXT. В программе данные хранятся в виде статического массива. 
````
STUDENT data[300];
````
Имя и инициалы хранятся в виде массивов символов (char), номер группы в виде целого числа (int), успеваемость в виде массива пяти целочисленных чисел.

**Ограничения на данные**: поле fio содержит только символы кириллицы (без ё); поле init содержит 1 и 3 символы кириллицы, а 2 и 4 – точка; поле number – целочисленное число от 1000 до 9999; поле perform – целочисленный массив из 5-ти элементов размерностью от 0 до 5.

Программа, разработанная в курсовой работе, демонстрирует автоматизацию учета успеваемости студентов. Помимо учета успеваемости студентов, она так же выполняет поиск студентов, редактирование любых данных студента или удаление всех данных студента из архива. При запуске программы пользователь вводит данные, которые проверяются на корректность для предотвращения ошибок в ходе работы программы. Еще программа по заданию должна выполнять следующие задачи:
-	Добавление новых студентов
-	Редактирование данных студента
-	Удаление из списка все данные о студенте
-	Поиск студента по фамилии
-	Сортировка данных студентов по алфавиту
-	Добавление данных в файл
-	Поиск студентов, у которых средний балл не ниже введенного
-	Вывод на экран список всех данных всех студентов

Так же в программе присутствует пользовательский интерфейс, который позволяет выполнять данные задачи.

Требования к надежности:
o	Корректность данных, которые ввел пользователь
o	Сохранение данных в файле, чтобы не было потери информации при закрытии программы.
## Описание программы и созданных функций
Программа реализована на языке С++ в виде консольного приложения. В главной функции main() реализовано меню пользователя, в котором каждому действию соответствует определенная цифра. Реализованы следующие функции для работы с данными: добавление, редактирование, удаление, поиск по фамилии, сортировка, добавление в файл, поиск студентов по среднему баллу, вывод на экран. 
#### Функция main()
В главной функции программы находится цикл, который выполняет различные функции, выбранные пользователем, до тех пор, пока мы не вводим определенное число, указывающее на выход.
#### Добавление:add()
Функция выполняет добавление записи в список студентов. Так же выполняется проверка введенных данных на корректность. Номер группы должен состоять из 4 цифр. Баллы должны быть в диапазоне от 0 до 5. Если введены не корректные данные, то предлагается ввести данные повторно. После корректно введенных данных, они добавляются в список.
#### Редактирование:Edit()
Сначала происходит поиск данных по фамилии, номеру группы. Так же проводится корректность данных. Выводится предложение  изменить запись. Если  данный студент не найден в списке, выводится сообщение. 
#### Удаление:Delete()
Сначала происходит поиск данных по фамилии, номеру группы. Если данный студент найден, то производится удаление. Если студент не найден, то выводится сообщение.
#### Поиск по фамилии: Search()
Сначала происходит поиск данных по фамилии,  если пользователь подтверждает, что это тот студент, которого он искал, то выводятся данные на экран. Если студент не найден, то выводится сообщение.
#### Поиск студентов по среднему баллу: aversear()
Сначала происходит поиск данных по средним баллам, которые не меньше указанного, и выводятся данные на экран. Если студенты не найден, то выводится сообщение.
#### Сортировка:sort()
Сортировка производится, использую фамилию, по алфавиту.
#### Добавление в файл:addfail()
При использовании функции производится вывод в файл.
#### Вывод на экран:output()
В виде таблицы выводятся данные.

*Пример:*

Фамилия и инициалы          Номер группы             Успеваемость

Иванов И.И                                   4932                         5,4,3,5,4
##	Описание пользовательского интерфейса
При запуске программы на экран выводится консольное приложение с меню пользователя. При нажатии на клавиатуре на определенную цифру выполняется соответствующая функция.

Пример пользовательского интерфейса:

![image](https://user-images.githubusercontent.com/79849850/233797497-3cd8acbb-7adc-4435-a468-7deb8194ee99.png)

<h6 align="center">Рис.1.Пользовательский интерфейс</h6>

