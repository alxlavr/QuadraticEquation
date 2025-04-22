#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <windows.h>

uint8_t quad_equation(float a, float b, float c, float *result);

int main()
{
    char ch = 0;
    float a = 0;
    float b = 0;
    float c = 0;
    float result[2] = {0, 0};
    uint8_t res = 0;

    SetConsoleCP(1251);        /** установка кодовой страницы win-cp 1251 в поток ввода **/
    SetConsoleOutputCP(1251);  /** установка кодовой страницы win-cp 1251 в поток вывода **/
    while(1) {
        printf("Программа нахождения корней квадратного уравнения вида\n\r");
        printf("          a * x^2 + b * x + c = 0\n\r");
        printf("Для решения уравления введите коэффициенты a, b, c.\n\r");
        printf("Введите коэффициент a > ");
        scanf("%f", &a);
        printf("Введите коэффициент b > ");
        scanf("%f", &b);
        printf("Введите коэффициент c > ");
        scanf("%f", &c);
        res = quad_equation(a, b, c, result);
        switch(res) {
        case 0:
            printf("Корни уравления отсутствуют.\n\r");
            break;
        case 1:
            printf("Уравнение имеет один корень:\n\r");
            printf("x1 = %f.\n\r", result[0]);
            break;
        case 2:
            printf("Уравнение имеет два корня:\n\r");
            printf("x1 = %f;\n\r", result[0]);
            printf("x2 = %f.\n\r", result[1]);
            break;
        default:
            printf("Что-то пошло не так!!!\n\r");
        }
        printf("Для решения другого уравнения введите символ n.\n\r");
        printf("Для выхода введите символ q.\n\r");
        while(1) {
            if(ch != '\n' && ch != '\r') printf("Введите символ > ");
            scanf("%c", &ch);
            if(ch == 'q' || ch == 'Q' || ch == 'й' || ch == 'Й') return 0;
            if(ch == 'n' || ch == 'N' || ch == 'т' || ch == 'Т') break;

        }
    }

    return 0;
}

/*!
 * \brief            Функция вычисления корней квадратного уравнения.
 * \details          Функция на основе коэффициентов a, b, c вычисляет наличие корней уравления и
 *                   в случае их наличия возвращает количество корней в уравнении и значение этих корней.
 * \param a          Коэффициент при x^2.
 * \param b          Коэффициент при x.
 * \param c          Коэффициент свободного члена.
 * \param *result    Ссылка на массив для хранения вычисленных корней уравнения.
 * \retval           Возвращает 0 - если корней нет, 1 - если корень один, 2 - если корня два.
 */

uint8_t quad_equation(float a, float b, float c, float *result) {
    float D = 0;
    D = b * b - 4 * a * c;                        // Вычисляем дискриминант.
    if(D < 0) return 0;                           // Если дискриминант меньше нуля - корней нет, возвращаем 0.
    if(D == 0) {                                  // Если дискриминант равен нулю - один корень.
        result[0] = (-1 * b) / (a * 2);           // Вычисляем корень.
        return 1;                                 // Возвращаем 1.
    }                                             // В ином случае два корня.
    result[0] = ((-1 * b) + sqrt(D)) / (a * 2);   // Вычисляем первый корень.
    result[1] = ((-1 * b) - sqrt(D)) / (a * 2);   // Вычисляем второй корень.
    return 2;                                     // Возвращаем 2.
}
