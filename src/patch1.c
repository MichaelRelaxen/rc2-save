#include "rc2-save.h"

void _start(void) 
{
    api_mod = 1;

    if (api_setaside == 1) {

        // set aside file
        api_setaside = 0;
        for(api_i = 0; api_i < 0x200000; api_i += 0x8000) {
            memcpy((void*)((int)api_aside_buf + api_i), (void*)((int)savedata_buf + api_i), 0x8000);
        }
    }

    if (api_load == 1) {
        // load set aside file
        if (*(int*)api_aside_buf == 0) {
            // oops! client requested load before setting aside file
            // set aside the file first
            for(api_i = 0; api_i < 0x200000; api_i += 0x8000) {
                memcpy((void*)((int)api_aside_buf + api_i), (void*)((int)savedata_buf + api_i), 0x8000);
            }
        }

        perform_load(0, api_aside_buf);
        api_load = 0;
    }
	
	if (api_autosave == 1) {
		save_handler(AUTOSAVE); 
		api_autosave = 0;
	}
	
	return;
	
}