/*
SFWRENG 3SH3: Operating Systems
Lab1: Unix Signals

Objectives:
 1.	The SIGALRM that handles a timer that wakes up each 2 seconds. You may use the
		sleep and raise systems calls in an innite while loop to create a timer.
		When your program receives SIGALRM, it should print \Alarm".
 2.	The SIGINT signal by printing \CTRL+C pressed!"
 3.	The SIGTSTP signal by printing \CTRL+Z pressed!" and then exiting the program.

Name: Simon Ly
MAC ID: lysv
Student ID: 001410173
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void ISR_handler(int);	// handler for SIGINT/ctrl+c, SIGTSTP/ctrl+z and SIGALRM/alarm()

int main()
{
	// Check for errors
	if (	signal(SIGINT, ISR_handler)  == SIG_ERR ||
		signal(SIGTSTP, ISR_handler) == SIG_ERR ||	
		signal(SIGALRM, ISR_handler) == SIG_ERR){		
		printf("\ncan't catch signals\n"); // Print statement if an error occurs
	}
	else{
		// Infinite while loop until CTRL+Z is pressed
		while (1) {

			sleep(2);		// wait 2 seconds 
			raise(SIGALRM);		// generate SIGALARM signal
		};
	}
	return 0;
}



void ISR_handler(int signo){
	switch(signo){
	case SIGINT:
		printf("\nCTRL+C pressed!\n"); // Print statement for when CTRL+C is pressed
		break;
	case SIGTSTP:
		printf("\nCTRL+Z pressed!\n");	// Print statement for when CTRL+Z is pressed
		exit(1); // exits inf while loop	
		break;
	case SIGALRM:
		printf("Alarm\n"); // Print statement for when SIGALRM flag is raised
		break;
	default:
	printf("Otherwise"); // Outcome will not be reached
	}
}
