#include "monty.h"

/**
  * read_file - read monty file line by line, call tokenization function
  * send the output op arg to run function.
  * @fname: pointer to a file name.
  * Return: sucess code in success else failure code
  */
int read_file(char *fname)
{
	/**   1- open a file
	      2- if fail to open:
	      3-    return error no. to the main
	      4- else:
	      5-     get line by line from a file
	      6-     send a line to the tokenization function:
	      7- send op to run function 
	      8- if success and all run without error return 0 to the main function
	 **/
}
/**
  * get_op - tokenization the line
  * @line: pointer to pointer to the input line
  * Return: token to operation
  */
char *get_op(char **line)
{
	/**
               tokenization:
	       1- ignore space
	       2- ignore any addational input after the
	       op arg input
	       3- return a tok to op
	  **/
}
