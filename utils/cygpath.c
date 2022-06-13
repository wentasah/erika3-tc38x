#include <stdio.h>

/*
 * Dummy implementation of cygpath tool from Cygwin, which converts
 * Windows paths to Unix (i.e., MinGW compatible) path. The reason,
 * why this is needed is that Erika's RT Druid generates makefiles,
 * which call this command and we want to use the generated makefiles
 * from Aurix Studio. Aurix Studio uses MinGW make rather than Cygwin
 * make. Therefore, since we cannot influence how RT Druid generates
 * the makefiles, we simulate cygpath behavior and make the result
 * work with MinGW.
 *
 * After compilation, copy the generated cygpath.exe to
 * C:\Infineon\AURIX-Studio-1.5.2\plugins\com.infineon.aurix.tools_1.5.2\build_system\tools\make\cygpath.exe
 * (or similar path, where you installed the Aurix Studio).
 */

int main(int argc, char *argv[])
{
        for (int i = 1; i < argc; i++) {
                if (argv[i][0] == '-')
                        continue;
                for (char *p = argv[i]; *p != 0; p++) {
                        if (*p == '\\')
                                *p = '/';
                }
                printf("%s\n", argv[i]);
        }
        return 0;
}
