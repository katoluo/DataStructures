#include <stdio.h>
#include <string.h>
#include <stdarg.h> // 提供宏va_list、va_start、va_arg、va_end
#include <ctype.h>  // 提供isprint原型
#include "Status.h"

/* 全局变量 */
// 是否使用debug模式。测试时可设置为TRUE，发布时可设置为FALSE(修改debug值后，一般需要重新生成静态库)。
Boolean debug = TRUE;

int ReadData(FILE *fp, char *format, ...)
{
    ;
}

/*
 * 摁下回车键以继续运行。
 *
 * 通常在测试阶段时，需要让每一步测试都暂停下来，以观察其输出，此时可以让debug=TRUE。
 * 在发布时，可以让debug=FALSE，此时各个测试块将不会暂停。
 */
void PressEnterToContinue(Boolean debug)
{
    fflush(stdin);

    // 处于测试阶段时，可以让debug=TRUE，手动输入换行，以便让程序暂停下来，观察每一步的输出
    if (debug)
    {
        printf("\nPress enter to continue...");
        getchar();
    }
    else
        printf("\n");

    fflush(stdin);
}

/*
 * 函数暂停一段时间。
 *
 * time不代表具体的时间，只是代表一段时间间隔，
 * 通过调节time的大小，可以使程序暂停适当的时间后继续运行。
 */
void Wait(long time)
{
    double i;

    if (time < 0)
        time = -time;

    for (i = 0.01; i <= 100000.0 * time; i += 0.01)
        ;
}

/*
 * 跳过空白，寻找下一个"可读"符号。
 *
 * 此方法常用在读取字符的语句之前，这会跳过遇到目标字符之前的空白符号，
 * 比如跳过'\r'、'\n'、'\r\n'、' '、'\t'、'\f'。
 */
void skipBlank(FILE *fp)
{
    int ch;

    if (fp == NULL)
        return;

    while ((ch = getc(fp)) != EOF)
    {
        // 如果遇到ANSI码之外的符号，比如汉字，则直接跳过
        if (ch >= 0 && ch <= 127)
        {
            // 如果遇到的ANSI码不是空白，比如'\r'、'\n'、'\r\n'、' '、'\t'、'\f'，则表示该符号"可读"
            if (ch != '\r' && ch != '\n' && ch != ' ' && ch != '\t' && ch != '\f')
            {
                // 将"可读"符号放入输入流，以待后续工具来读它
                ungetc(ch, fp);
                break; // 可以跳出循环了，因为已经找到了"可读"符号
            }
        }
    }
}