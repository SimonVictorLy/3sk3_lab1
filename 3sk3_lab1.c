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


void handle_sigint(int);	// handler for SIGINT/ctrl+c
void handle_sigtstp(int);	// handler for SIGTSTP/ctrl+z
void alarm_handle(int);		// handler for SIGALRM/alarm()

int main()
{

	if (signal(SIGINT, handle_sigint) == SIG_ERR) {		// assign handle to ctrl+c and check for errors
		printf("\ncan't catch SIGINT\n");
	}
	signal(SIGTSTP, handle_sigtstp);	// assign handle to ctrl+Z
	signal(SIGALRM, alarm_handle);		// assign handle to SIGALARM signal

	while (1) {

		sleep(2);			// wait 2 seconds 
		raise(SIGALRM);		// generate SIGALARM signal
	};

	return 0;
}

void handle_sigint(int signo) {
	//signal(SIGINT, handle_sigint); // defaults to SIG_DFL, must reinstall the handler again
	printf("\nCTRL+C pressed!\n");
}

void handle_sigtstp(int signo) {
	printf("\nCTRL+Z pressed!\n");
	exit(1); // exits inf while loop
}
void alarm_handle(int signo) {
	//signal(SIGALRM, alarm_handle); // defaults to SIG_DFL, must reinstall the handler again
	printf("Alarm\n");

}

