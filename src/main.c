#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <fxcg/serial.h>
#include "textinput.h"
// Refer to https://gitlab.com/taricorp/fx-cg-ui
// https://prizm.cemetech.net/Syscalls/Serial/Serial_Write/

void main(void) {
    //int key;
    Bdisp_AllClr_VRAM();
    locate_OS(0,0);
    //Print_OS("Press EXE to exit\n", 0, 0);
    if (Serial_IsOpen() != 1) {
        unsigned char mode[6] = {0, 5, 0, 0, 0, 0};    // 9600 bps 8n1
        Serial_Open(mode);
    }
    char* input[51] = {"\0"};
    unsigned int i = 0;
    while (1) {
        //GetKey(&key);
        getTextLine(*input, 50, 1, 1, 15, INPUT_MODE_TEXT);
        char* num[10] = {"\0"};
        itoa(i,num);
        locate_OS(1,3);
        Print_OS(num, TEXT_MODE_NORMAL, 0);
        i += 1;

        // if (key == KEY_CTRL_EXE) {
        //     unsigned int try = 0;
        //     while (Serial_Close(0) != 0) // Fail if pending transmission
        //     {
        //         Print_OS("Could not exit, pending transmission\n", 0, 0);

        //     }
            
        //     break;
        // }
    }
 
    return;
}
