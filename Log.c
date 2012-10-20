#include <stdio.h>
#include <stdarg.h>
#include "Log.h"


void loguear( const char* format, ... ) {


    FILE * fpLog;

    fpLog = fopen("logs.txt", "at");

	va_list args;
	va_start( args, format );
	vfprintf( fpLog, format, args );
	va_end( args );
	fprintf( fpLog, "\n" );

    fclose(fpLog);

}
