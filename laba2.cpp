#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <clocale>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    const int MAX_ELEMENTS = 8;

    float m[MAX_ELEMENTS];
    int countZero = 0;
    float sumAfterMin = 0;
    int iMin;

    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        printf("m[%d] = ", i);
        scanf("%f", &m[i]);
    }

    iMin = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        if (fabs(m[i]) < 0.0001)
        {
            countZero++;
        }

        if (m[i] < m[iMin])
        {
            iMin = i;
        }
    }

    for (int i = iMin + 1; i < MAX_ELEMENTS; i++)
    {
        sumAfterMin += m[i];
    }

    printf("\nКоличество элементов, равных 0 = %d\n", countZero);
    printf("Сумма элементов после минимального = %.2f\n\n", sumAfterMin);

    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        for (int j = i + 1; j < MAX_ELEMENTS; j++)
        {
            if (fabs(m[i]) > fabs(m[j]))
            {
                float temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }

    printf("Отсортированный массив по возрастанию модулей:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        printf("%.2f ", m[i]);
    }
    printf("\n");

    return 0;
}
