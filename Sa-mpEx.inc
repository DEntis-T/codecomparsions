#define SAMPEX_INCLUDED_FILE 1

new sampex_version = 1;

stock sampex_okay()
{
	new verstring[10];
	format(verstring,10,"%i.0",sampex_version);
    	print(".");
    	print(".");
    	print(".");
	print("I~--------------------------------------------------------~I");
	print("I");
	
	printf("I	Sa-mpEx > version: %s",verstring);
	
	print("I");
	
	print("I	Successfully loaded the library! ");
	print("I 	By: DentisT 'Unity' & Brace ");
	
	print("I");
	print("I~--------------------------------------------------------~I");
	print(".");
	print(".");
	print(".");
}