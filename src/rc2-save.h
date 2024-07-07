#ifndef RC2_SAVE_H
    #define RC2_SAVE_H
	
	#define SAVEMENU 0
	#define LOADMENU 1
	#define AUTOSAVE 3

    // Game functions
    #define memcpy ((void (*)(void*, void*, int))0x10d4ffc)
    #define perform_load ((void (*)(int, void*))0x83250)	
	#define save_handler ((void (*)(int))0x82e08)

    // Game addresses
    #define savedata_info (*((void**)0x1410E50))
    #define savedata_buf (*(void**)((int)savedata_info + 4))

    // I/O addresses
	#define api_autosave (*(char*)0x10CD71C)
    #define api_mod (*(char*)0x10CD71D)
    #define api_load (*(char*)0x10CD71E)
    #define api_setaside (*(char*)0x10CD71F)
    #define api_i (*((int*)0x10CD720))

    #define api_aside_buf ((void*)0x1C00000)

#endif // RC2_SAVE_H