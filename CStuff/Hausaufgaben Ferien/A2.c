#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkbrackets2(char input[]);

int checkBrackets(char input[]);

int main()
{
    system("clear");
    char testInputs[10][14] = {
        "{[()]}",
        "(([[]]))",
        "([)]",
        "([]])",
        "(()))",
        "(()",
        "({[])}",
        "",
        "abc",
        "a[b(c)0{}]"};
    for (int i = 0; i < 10; i++)
    {
        char *input = testInputs[i];

        checkBrackets(input)
            ? printf("%d: %-14s .. Klammern ok\n", i, input)
            : printf("%d: %-14s .. Klammern falsch!\n", i, input);
    }
    return 0;
}
int checkBrackets(char input[])
{
    int bracket1[2] = {0};
    int bracket2[2] = {0};
    int bracket3[2] = {0};

    for (int i = 0; i < (strlen(input)); i++)
    // count the different types of brackets
    {
        if (input[i] == '(')
        {
            bracket1[0]++;
        }
        else if (input[i] == ')')
        {
            bracket1[1]++;
        }
        else if (input[i] == '[')
        {
            bracket2[0]++;
        }
        else if (input[i] == ']')
        {
            bracket2[1]++;
        }
        else if (input[i] == '{')
        {
            bracket2[0]++;
        }
        else if (input[i] == '}')
        {
            bracket2[1]++;
        }
    }
    //! If there is an uneven amount of the same brackets, return false
    if (bracket1[0] != bracket1[1])
    {
        return 0;
    }
    else if (bracket2[0] != bracket2[1])
    {
        return 0;
    }
    else if (bracket3[0] != bracket3[1])
    {
        return 0;
    }
    else
    {
        return checkbrackets2(input);
    }
}
int checkbrackets2(char input[])
//* If there are enough brackets, check the placement by putting the opening brackets into the memory array
//* If the next closing bracket != the last opening bracket, return 0 else reduce the index of the memory to be able to overwrite
//* Or check the element before it
{
    int input_index = 0;
    int memory_index = 0;
    char memory[strlen(input)]; // Make the array big enough just to be sure, halve of len should also be enogh

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[input_index] == '(')
        {
            memory[memory_index] = input[input_index];
            memory_index++;
            input_index++;
        }
        else if (input[input_index] == '[')
        {
            memory[memory_index] = input[input_index];
            input_index++;
            memory_index++;
        }
        else if (input[input_index] == '{')
        {
            memory[memory_index] = input[input_index];
            input_index++;
            memory_index++;
        }
        else if (input[input_index] == ')')
        {
            if (memory_index != 0 && memory[memory_index - 1] == '(')
            {
                memory_index--;
                input_index++;
            }
            else
            {
                return 0;
            }
        }
        else if (input[input_index] == ']')
        {
            if (memory_index != 0 && memory[memory_index - 1] == '[')
            {
                memory_index--;
                input_index++;
            }
            else
            {
                return 0;
            }
        }
        else if (input[input_index] == '}')
        {
            if (memory_index != 0 && memory[memory_index - 1] == '{')
            {
                memory_index--;
                input_index++;
            }
            else
            {
                return 0;
            }
        }
        else
        // If its a symbol other than ( ) [ ] { }
        {
            input_index++;
        }
    }
    return 1;
}
