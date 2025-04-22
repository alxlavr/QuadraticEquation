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

    SetConsoleCP(1251);        /** ��������� ������� �������� win-cp 1251 � ����� ����� **/
    SetConsoleOutputCP(1251);  /** ��������� ������� �������� win-cp 1251 � ����� ������ **/
    while(1) {
        printf("��������� ���������� ������ ����������� ��������� ����\n\r");
        printf("          a * x^2 + b * x + c = 0\n\r");
        printf("��� ������� ��������� ������� ������������ a, b, c.\n\r");
        printf("������� ����������� a > ");
        scanf("%f", &a);
        printf("������� ����������� b > ");
        scanf("%f", &b);
        printf("������� ����������� c > ");
        scanf("%f", &c);
        res = quad_equation(a, b, c, result);
        switch(res) {
        case 0:
            printf("����� ��������� �����������.\n\r");
            break;
        case 1:
            printf("��������� ����� ���� ������:\n\r");
            printf("x1 = %f.\n\r", result[0]);
            break;
        case 2:
            printf("��������� ����� ��� �����:\n\r");
            printf("x1 = %f;\n\r", result[0]);
            printf("x2 = %f.\n\r", result[1]);
            break;
        default:
            printf("���-�� ����� �� ���!!!\n\r");
        }
        printf("��� ������� ������� ��������� ������� ������ n.\n\r");
        printf("��� ������ ������� ������ q.\n\r");
        while(1) {
            if(ch != '\n' && ch != '\r') printf("������� ������ > ");
            scanf("%c", &ch);
            if(ch == 'q' || ch == 'Q' || ch == '�' || ch == '�') return 0;
            if(ch == 'n' || ch == 'N' || ch == '�' || ch == '�') break;

        }
    }

    return 0;
}

/*!
 * \brief            ������� ���������� ������ ����������� ���������.
 * \details          ������� �� ������ ������������� a, b, c ��������� ������� ������ ��������� �
 *                   � ������ �� ������� ���������� ���������� ������ � ��������� � �������� ���� ������.
 * \param a          ����������� ��� x^2.
 * \param b          ����������� ��� x.
 * \param c          ����������� ���������� �����.
 * \param *result    ������ �� ������ ��� �������� ����������� ������ ���������.
 * \retval           ���������� 0 - ���� ������ ���, 1 - ���� ������ ����, 2 - ���� ����� ���.
 */

uint8_t quad_equation(float a, float b, float c, float *result) {
    float D = 0;
    D = b * b - 4 * a * c;                        // ��������� ������������.
    if(D < 0) return 0;                           // ���� ������������ ������ ���� - ������ ���, ���������� 0.
    if(D == 0) {                                  // ���� ������������ ����� ���� - ���� ������.
        result[0] = (-1 * b) / (a * 2);           // ��������� ������.
        return 1;                                 // ���������� 1.
    }                                             // � ���� ������ ��� �����.
    result[0] = ((-1 * b) + sqrt(D)) / (a * 2);   // ��������� ������ ������.
    result[1] = ((-1 * b) - sqrt(D)) / (a * 2);   // ��������� ������ ������.
    return 2;                                     // ���������� 2.
}
