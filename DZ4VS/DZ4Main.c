#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
//
int valueIntGlobal[] = {651, 22, 57};
float valueFloatGlobal[] = {2.78, 518., 43.15432};

int valueIntLine[] = {23, 56, 73, 22};
int valueIntColumn[] = {443, 345, 21, 78};
float valueFloatLine[] = {1.27, 2.71, 3.14, 9.81};
float valueFloatColumn[] = {6.62, 1.6, 7.81, 5.68};
char strLine[] = {'S', 'k', 'i', 'l', 'l'};
char strColumn[] = {'B', 'o', 'x'};

int countMassiv = 0;
char controlChar[] = {'Y', 'y'};
//
void loadMenu();
void executorLogic();

/// @brief
/// @param isTypeVision - true Line, false Column
/// @param valueInt - int dataMassiv
/// @param valueFloat - float dataMassiv
/// @return
bool consolePrintData1(bool isTypeVision, int valueInt[], float valueFloat[]);
//
int main()
{
    loadMenu();
    return 0;
}
//
void loadMenu()
{
    printf("Start DZ4\n");
    printf("Executor program -> Press Y...\n");

    char pressButton;
    bool isStop = true;
    countMassiv = sizeof(controlChar) / sizeof(controlChar[0]);

    while (isStop)
    {

        pressButton = getch();
        printf("Press %c\n", pressButton);

        for (int i = 0; i < countMassiv; i++)
        {
            if (controlChar[i] == pressButton)
            {
                isStop = false;
            }
        }
    }

    printf("\n\n");
    executorLogic();
}

void executorLogic()
{
    int valueIntLocal[] = {15, 22, 518};
    float valueFloatLocal[] = {1.32, 0.1567, 287.154};

    if (consolePrintData1(false, valueIntLocal, valueFloatLocal))
    {
        printf("consolePrintData1 local data - ok\n");
    }
    if (consolePrintData1(true, valueIntGlobal, valueFloatGlobal))
    {
        printf("consolePrintData1 global data - ok\n");
    }
}
bool consolePrintData1(bool isTypeVision, int valueInt[], float valueFloat[])
{
    if (valueInt != NULL)
    {
        countMassiv=0;
        printf ("massiv1 =%i\n",countMassiv);
        int countMassiv = sizeof(valueInt) / sizeof(valueInt[0]);
        printf ("massiv =%i",countMassiv);
        for (int i = 0; i < countMassiv; i++)
        {
            if (isTypeVision)
            {
                printf("%i\t", valueInt[i]);
            } // line
            else
            {
                printf("%i\n", valueInt[i]);
            } // column
        }
        printf("\n");
    }

    if (valueFloat != NULL)
    {
        int countMassiv = sizeof(valueFloat) / sizeof(valueFloat[0]);

        for (int i = 0; i < countMassiv; i++)
        {
            if (isTypeVision)
            {
                printf("%f\t", valueFloat[i]);
            } // line
            else
            {
                printf("%f\n", valueFloat[i]);
            } // column
        }

        printf("\n\n");
    }

    return true;
}
