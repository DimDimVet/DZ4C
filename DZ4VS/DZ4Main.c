#include <stdio.h>
#include <stdbool.h>
//
int valueIntGlobal[] = {651, 22, 57};
float valueFloatGlobal[] = {2.78, 518., 43.15432};
static int value = 5;
char controlChar[] = {'Y', 'y'};
//
void loadMenu();
void executorLogic();

/// @brief
/// @param isTypeVision
/// @param valueInt
/// @param sizeValueInt
/// @param valueFloat
/// @param sizeValueFloat
/// @return
bool consolePrintData1(bool isTypeVision, int valueInt[], size_t sizeValueInt, float valueFloat[], size_t sizeValueFloat);
void consolePrintData2();
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

    size_t countMassiv = sizeof(controlChar) / sizeof(controlChar[0]);

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

    if (consolePrintData1(false, valueIntLocal, sizeof(valueIntLocal) / sizeof(valueIntLocal[0]),
                          valueFloatLocal, sizeof(valueFloatLocal) / sizeof(valueFloatLocal[0])))
    {
        printf("\nconsolePrintData1 local data - ok\n\n");
    }

    if (consolePrintData1(true, valueIntGlobal, sizeof(valueIntGlobal) / sizeof(valueIntGlobal[0]),
                          valueFloatGlobal, sizeof(valueFloatGlobal) / sizeof(valueFloatGlobal[0])))
    {
        printf("\nconsolePrintData1 global data - ok\n\n");
    }

    int tempValue = value;
    
    for (int i = 0; i < tempValue; i++)
    {
        consolePrintData2();
    }
    printf("\nconsolePrintData2 data - ok\n\n");
}

bool consolePrintData1(bool isTypeVision, int valueInt[], size_t sizeValueInt, float valueFloat[], size_t sizeValueFloat)
{

    for (int i = 0; i < sizeValueInt; i++)
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

    for (int i = 0; i < sizeValueFloat; i++)
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
    return true;
}
void consolePrintData2()
{
    //old: value++;
    printf("Static int %i\n", value);
    value++;
}
