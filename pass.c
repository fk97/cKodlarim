#include <stdio.h>

int find_size_of_line(char line[]);

void reverse_line(char line[], int line_lenght);

void encrypt_open_msg();

void decrypt_secret_msg();

void menu();

int main()
{
	int i, asci, size;
   FILE *file = fopen ("open_msg.txt", "r");
   if ( file != NULL )
   {
      char line [ 1024 ]; /* or other suitable maximum line size */
      while (fgets (line, find_size_of_line(line), file) != NULL) /* read a line */
      {
      	size = find_size_of_line(line);
        fputs (line, stdout);
        reverse_line(line, size);
        for(i = 0; i <= size; i++){
        	if(line[i] == '*'){
        		line[i] = '*';
        	} else if(line[i] == '_'){
        		line[i] = '_';
        	} else {
        		asci =(int) line[i];
        		asci = asci - 5;
        		if(asci < 97){
        			asci = asci + 26;
        		}
        		line[i] = (char) asci;
        	}
        	
        }
        printf("%s\n", line);
      }
      fclose (file);
   }
   else
   {
      printf("Error!!!!.\n");
   }
   return 0;
}

int find_size_of_line(char line[])
{
	int i = 0;
	while(line[i] != '.'){
		i++;
	}

	return i+1;
}

void reverse_line(char line[], int line_lenght)
{
	char rev[1024];
	int start, end;

	end = line_lenght - 1;

	for(start = 0; start < line_lenght; start++){
		if(line[end] == '.'){
			rev[start] = '*';
		} else if(line[end] == ' '){
			rev[start] = '_';
		} else {
			rev[start] = line[end];
		}
		end--;
	}

	rev[line_lenght] = '\0';

	for(start = 0; start <= line_lenght; start++){
		line[start] = rev[start];
	}

	printf("%s\n", line);

}

void encrypt_open_msg()
{

}

void decrypt_secret_msg()
{

}

void menu()
{

}