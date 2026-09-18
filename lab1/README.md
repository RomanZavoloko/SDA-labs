# **Міністерство освіти і науки України** 

# **Національний технічний університет України** 

**«Київський політехнічний інститут імені Ігоря Сікорського»** 

**Факультет інформатики та обчислювальної техніки** 

# **Кафедра обчислювальної техніки** 

# **Лабораторна робота №1** 

з дисципліни 

«Структури даних і алгоритми» 

Виконав: Перевірив: Студент групи ІО-64 Русінов Володимир Володимирович Заволоко Роман Костянтинович 

номер у списку групи: 8 

Київ 2026 

# **Мета** 

Метою лабораторної роботи «Розгалужені алгоритми» є засвоєння теоретичного матеріалу та набуття практичних навичок використання керуючих конструкцій розгалуження та булевих (логічних) операцій. 

# **Постановка задачі** 

Задано дійсне число x. Визначити значення заданої за варіантом кусковонеперервної функції y(x), якщо воно існує, або вивести на екран повідомлення про неіснування функції для заданого x. 

Розв’язати задачу **двома способами** (написати дві програми): 

1. У програмі дозволяється використовувати тільки одиничні операції порівняння (=, <>, <, <=, >, >=) і **не дозволяється** використовувати булеві (логічні) операції (not, and, or тощо); 

2. У програмі необхідно **обов’язково** використати булеві (логічні) операції (not, and, or тощо); використання булевих операцій не повинно бути надлишковим. 

# **Завдання за варіантом:** 

Варіант 8: 



<!-- Start of picture text -->
{ —6x2 [0,7)<br>y=4 + 8 ,x e<br>| —x3/x3/7+10 ,x € (—,-10]U[11, +)<br><!-- End of picture text -->

# **Aлгоритм 1:** 

# **Блок схема алгоритму 1:**
![Блок-схема 1](scheme1.svg)


<!-- Start of picture text -->
Begin<br>input x<br>false true<br>x >= 11<br>false true<br>y = -x^3/7 + 10<br>х>=0<br>false true false true<br>x <= -10 x < 7<br>Output y<br>y = -x^3/7 + 10 y = -6*x^2 + 8<br>Output<br>"no value for x"<br>Output<br>"no value for x"<br>Output y Output y<br>End<br><!-- End of picture text -->

# **Код:** 

#include <stdio.h> 

int main(void) { float x, y; printf("Please enter x: "); 

scanf("%f", &x); 

if (x >= 11) { y = -x * x * x / 7 + 10; printf("%.2f\n", y); } else if (x >= 0) { if (x < 7) { y = -6 * x * x + 8; printf("%.2f\n", y); } else { printf("No value for x\n"); } } else if (x <= -10) { y = -x * x * x / 7 + 10; printf("%.2f\n", y); } else { printf("No value for x\n"); } return 0; } **Приклад роботи програми:** 



<!-- Start of picture text -->
Please enter x:<br>-1132.86<br><!-- End of picture text -->





<!-- Start of picture text -->
Please enter x:<br>1152.86<br><!-- End of picture text -->



<!-- Start of picture text -->
Please enter x:<br>No value for x<br><!-- End of picture text -->

# **Алгоритм 2: 
# Блок схема алгоритму 2:
![Блок-схема 2](scheme2.svg)



<!-- Start of picture text -->
BEGIN<br>Input x<br>true false<br>x >= 11 || x <= -10<br>true<br>y = -x^3 / 7 + 10 x >= 0 && x < 7<br>false<br>y = -6*x^2 + 8<br>Output "no value for x"<br>Output y Output y<br>END<br><!-- End of picture text -->

**Код:** #include <stdio.h> 

int main(void) { float x, y; printf("Please enter x: "); scanf("%f", &x); if (x >= 11 || x <= -10) { y = -x * x * x / 7 + 10; printf("%.2f\n", y); } else if (x >= 0 && x < 7) { y = -6 * x * x + 8; printf("%.2f\n", y); } else { printf("No value for x\n"); } 

return 0; } **Приклад роботи програми:** 



<!-- Start of picture text -->
Please enter x:<br><!-- End of picture text -->





<!-- Start of picture text -->
Please enter x:<br><!-- End of picture text -->



<!-- Start of picture text -->
Please enter x:<br><!-- End of picture text -->

# **Висновок:** 

Виконуючи цю лабораторну роботу, я ознайомився з основами програмування на мові С, які потрібні для написання коду. Також я познайомився з використанням Draw.Io Під час виконання лабораторної роботи ніяких проблем не виникло. 

